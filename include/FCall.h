#pragma once

#include <stdint.h>
#include <cstdint>
#include <string>
#include <wtypes.h>
#include "Decimal.h"

namespace System
{
#define DECIMAL_SCALE(dec)       ((dec).u.u.scale)
#define DECIMAL_SIGN(dec)        ((dec).u.u.sign)
#define DECIMAL_SIGNSCALE(dec)   ((dec).u.signscale)
#define DECIMAL_LO32(dec)        ((dec).v.v.Lo32)
#define DECIMAL_MID32(dec)       ((dec).v.v.Mid32)
#define DECIMAL_HI32(dec)        ((dec).Hi32)

#define DECIMAL_NEG ((uint8_t)0x80)
#define DECIMAL_ADD  0x00

#define SCALE_BITINDEX		(24)
#define SIGN_BITINDEX		(31)
#define FRACTION_MASK		(0x00FFFFFF)
#define FRACTION_BITINDEX	(0)
#define DECIMAL_PRECISION 29
#define MIN_BUFFER_SIZE 105

#ifdef LIBEXPORT_CODEGEN_API
# define LIBCODEGEN_API EXPORT
#elif LIBIMPORT_CODEGEN_API
# define LIBCODEGEN_API IMPORT
#else
# define LIBCODEGEN_API
#endif


#define LITTLE_ENDIAN 1
#define BIG_ENDIAN 2
#define BYTE_ORDER LITTLE_ENDIAN

#if !DEBUG
#define ASSERT(expr) (void(0))
#elif TARGET_WINDOWS || TARGET_XBOXONE || TARGET_WINRT
#include <crtdbg.h>
#define ASSERT(expr) \
    _ASSERTE(expr)
#else
#define ASSERT(expr) \
    assert(expr)
#endif


	typedef struct Il2CppDecimal
	{
		union
		{
			struct
			{
				BYTE scale;
				BYTE sign;
			} u;

			USHORT signscale;
		} u;

		ULONG Hi32;

		union
		{
			struct
			{
				ULONG Lo32;
				ULONG Mid32;
			} v;

			ULONGLONG Lo64;
		} v;
	} Il2CppDecimal;

	class FCall
	{
	public:
		static double FCallToDouble(Il2CppDecimal d);
		static int32_t FCallCompare(Il2CppDecimal* left, Il2CppDecimal* right);
		static int32_t FCallToInt32(Il2CppDecimal d);
		static int32_t GetHashCode(Il2CppDecimal* _this);
		static float ToSingle(Il2CppDecimal d);
		static void ConstructorDouble(Il2CppDecimal* _this, double value);
		static void ConstructorFloat(Il2CppDecimal* _this, float value);
		static void FCallAddSub(Il2CppDecimal* left, Il2CppDecimal* right, uint8_t sign);
		static void FCallDivide(Il2CppDecimal* left, Il2CppDecimal* right);
		static void FCallFloor(Il2CppDecimal* d);
		static void FCallMultiply(Il2CppDecimal* d1, Il2CppDecimal* d2);
		static void FCallRound(Il2CppDecimal* d, int32_t decimals);
		static void FCallTruncate(Il2CppDecimal* d);


		static double FCallToDouble(Decimal d);
		static int32_t FCallCompare(Decimal* left, Decimal* right);
		static int32_t FCallToInt32(Decimal* d);
		static int32_t GetHashCode(Decimal* _this);
		static float ToSingle(Decimal d);
		static void ConstructorDouble(Decimal* _this, double value);
		static void ConstructorFloat(Decimal* _this, float value);
		static void FCallAddSub(Decimal* left, Decimal* right, uint8_t sign);
		static void FCallDivide(Decimal* left, Decimal* right);
		static void FCallFloor(Decimal* d);
		static void FCallMultiply(Decimal* d1, Decimal* d2);
		static void FCallRound(Decimal* d, int32_t decimals);
		static void FCallTruncate(Decimal* d);


	private:
		static void RaiseOverflowException();
		static void RaiseDivideByZeroException();
		static void RaiseArgumentOutOfRangeException(std::string c);
	};
}
