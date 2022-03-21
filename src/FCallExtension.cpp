#include "include/FCallExtension.h"

#include <cassert>
#include <crtdbg.h>
#include <Windows.h>

#include "include/Exception.h"


namespace System
{
#define DECIMAL_HI32(dec)        ((dec).Hi32)

	void FCallExtension::FCallToCurrency(CY* result, DECIMAL d)
	{
		// GC is only triggered for throwing, no need to protect result
		HRESULT hr = VarCyFromDec(&d, result);
		if (FAILED(hr))
		{
			_ASSERTE(hr != E_INVALIDARG);
			throw System::OverflowException("Overflow_Currency");
		}
	}

	void FCallExtension::FCallToDecimal(DECIMAL* result, CY c)
	{
		_ASSERTE(result);
		HRESULT hr = VarDecFromCy(c, result);
		if (FAILED(hr))
		{
			// Didn't expect to get here.  Update code for this HR.
			_ASSERTE(S_OK == hr);
			//COMPlusThrowHR(hr);
		}

		if (FAILED(DecimalCanonicalize(result)))
			throw System::OverflowException("Overflow_Currency");


		result->wReserved = 0;
	}

	HRESULT FCallExtension::DecimalCanonicalize(DECIMAL* dec)
	{
		// Clear the VARENUM field
		(*(USHORT*)dec) = 0;

		// Remove trailing zeros:
		DECIMAL temp;
		DECIMAL templast;
		temp = templast = *dec;

		// Ensure the hi 32 bits are empty (should be if we came from a currency)
		if ((DECIMAL_HI32(temp) != 0) || (temp.scale > 4))
			return (int)0x8002000a;

		// Return immediately if dec represents a zero.
		if (temp.Lo32 == 0 && temp.Mid32 == 0)
			return S_OK;

		// Compare to the original to see if we've
		// lost non-zero digits (and make sure we don't overflow the scale BYTE)

#ifdef _PREFAST_
#pragma warning(push)
#pragma warning(disable:6219) // "Suppress PREFast warning about Implicit cast between semantically different integer types" 
#endif
		while ((temp.scale <= 4) && (VARCMP_EQ == VarDecCmp(dec, &temp)))
		{
#ifdef _PREFAST_
#pragma warning(pop)
#endif
			templast = temp;

			// Remove the last digit and normalize.  Ignore temp.Hi32
			// as Currency values will have a max of 64 bits of data.
			temp.scale--;
			UINT64 temp64 = (((UINT64)temp.Mid32) << 32) + temp.Lo32;
			temp64 /= 10;

			temp.Mid32 = (ULONG)(temp64 >> 32);
			temp.Lo32 = (ULONG)temp64;
		}
		*dec = templast;

		return S_OK;
	}
}
