#pragma once

#include <wtypes.h>

namespace System
{
	class FCallExtension
	{
	public:
		static void FCallToCurrency(CY* result, DECIMAL d);
		static void FCallToDecimal(DECIMAL* result, CY c);
		static HRESULT DecimalCanonicalize(DECIMAL* dec);
	};
}
