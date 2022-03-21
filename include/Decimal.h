#pragma once

#include <stdint.h>
#include <string>

#include "BaseType.h"
#include "CQuickBytesBase.h"


// Summary:
//     Specifies how mathematical rounding methods should process a number that
//     is midway between two numbers.
enum class MidpointRoundings
{
	// Summary:
	//     When a number is halfway between two others, it is rounded toward the nearest
	//     even number.
	ToEven = 0,
	//
	// Summary:
	//     When a number is halfway between two others, it is rounded toward the nearest
	//     number that is away from zero.
	AwayFromZero = 1,
};

enum class NumberStyles
{
	// Bit flag indicating that leading whitespace is allowed. Character values
	// 0x0009, 0x000A, 0x000B, 0x000C, 0x000D, and 0x0020 are considered to be
	// whitespace.

	None = 0x00000000,

	AllowLeadingWhite = 0x00000001,

	AllowTrailingWhite = 0x00000002,
	//Bitflag indicating trailing whitespace is allowed.

	AllowLeadingSign = 0x00000004,
	//Can the number start with a sign char.  
	//Specified by NumberFormatInfo.PositiveSign and NumberFormatInfo.NegativeSign

	AllowTrailingSign = 0x00000008,
	//Allow the number to end with a sign char

	AllowParentheses = 0x00000010,
	//Allow the number to be enclosed in parens

	AllowDecimalPoint = 0x00000020,
	//Allow a decimal point

	AllowThousands = 0x00000040,
	//Allow thousands separators (more properly, allow group separators)

	AllowExponent = 0x00000080,
	//Allow an exponent

	AllowCurrencySymbol = 0x00000100,
	//Allow a currency symbol.

	AllowHexSpecifier = 0x00000200,
	//Allow specifiying hexadecimal.
	//Common uses.  These represent some of the most common combinations of these flags.


	Integer = AllowLeadingWhite | AllowTrailingWhite | AllowLeadingSign,

	HexNumber = AllowLeadingWhite | AllowTrailingWhite | AllowHexSpecifier,

	Number = AllowLeadingWhite | AllowTrailingWhite | AllowLeadingSign | AllowTrailingSign |
	AllowDecimalPoint | AllowThousands,

	Float = AllowLeadingWhite | AllowTrailingWhite | AllowLeadingSign |
	AllowDecimalPoint | AllowExponent,

	Currency = AllowLeadingWhite | AllowTrailingWhite | AllowLeadingSign | AllowTrailingSign |
	AllowParentheses | AllowDecimalPoint | AllowThousands | AllowCurrencySymbol,

	Any = AllowLeadingWhite | AllowTrailingWhite | AllowLeadingSign | AllowTrailingSign |
	AllowParentheses | AllowDecimalPoint | AllowThousands | AllowCurrencySymbol | AllowExponent,
};


namespace System
{
	struct Currency;

	class Decimal
	{
		// Number of bits scale is shifted by.
		static const int ScaleShift = 16;
		// The maximum power of 10 that a 32 bit integer can store
		static const Int32 MaxInt32Scale = 9;

		int flags;
		int hi;
		int lo;
		int mid;

	public:
		// Constant representing the Decimal value 0.
		static Decimal Zero;
		static Decimal One;
		static Decimal MinusOne;
		static Decimal NearNegativeZero;
		static Decimal NearPositiveZero;
		static Decimal MaxValue;
		static Decimal MinValue;

		Decimal();

		Decimal(int value);

		Decimal(unsigned int value);

		Decimal(long long value);

		Decimal(unsigned long long value);

		Decimal(float value);

		Decimal(double value);

		//danh sách các bit được tạo ra từ hàm GetBits. flas là dữ liệu đã được shift bit 
		Decimal(int* bits);

		//tương tự như hàm setbit nhưng dữ liệu scale là bit chính xác không cần shift
		Decimal(int lo, int mid, int hi, bool isNegative, byte scale);

		Decimal(const char* input);

		Decimal(const wchar_t* input);

		// Returns the absolute value of the given Decimal. If d is
		// positive, the result is d. If d is negative, the result
		// is -d.
		//
		static Decimal Abs(Decimal d);

		static Decimal Add(Decimal d1, Decimal d2);

		static Decimal Ceiling(Decimal d);

		static int Compare(Decimal d1, Decimal d2);

		int CompareTo(Decimal value);

		static Decimal Divide(Decimal d1, Decimal d2);

		bool Equals(Decimal value);

		int GetHashCode();

		static bool Equals(Decimal d1, Decimal d2);

		static Decimal Floor(Decimal d);

		std::wstring ToString();

		std::wstring ToString(const std::wstring& format);

		std::wstring ToString(const std::wstring& format, const std::wstring& provider);

		static Decimal Parse(const char* s);

		static Decimal Parse(const wchar_t* s);

		static bool TryParse(const std::string& s, Decimal* result);

		static bool TryParse(const std::string& s, Decimal* result, NumberStyles number_styles, const std::wstring& provider);

		static int* GetBits(Decimal d);

		static void GetBytes(Decimal d, byte* buffer);

		static Decimal ToDecimal(byte* buffer);

		static Decimal Max(Decimal d1, Decimal d2);

		static Decimal Min(Decimal d1, Decimal d2);

		static Decimal Remainder(Decimal d1, Decimal d2);

		static Decimal Multiply(Decimal d1, Decimal d2);

		static Decimal Negate(Decimal d);

		static Decimal Round(Decimal d);

		static Decimal Round(Decimal d, int decimals);

		static Decimal Round(Decimal d, MidpointRoundings mode);

		static Decimal Round(Decimal d, int decimals, MidpointRoundings mode);

		static Decimal Subtract(Decimal d1, Decimal d2);

		static byte ToByte(Decimal value);

		static bool TryToByte(Decimal value, byte& result);

		static signed char ToSByte(Decimal value);

		static bool TryToSByte(Decimal value, signed char& result);

		static short ToInt16(Decimal value);

		static bool TryToInt16(Decimal value, short& result);

		static int ToInt32(Decimal d);

		static bool TryToInt32(Decimal d, int& result);

		static long long ToInt64(Decimal d);

		static bool TryToInt64(Decimal d, long long& result);

		static UInt16 ToUInt16(Decimal value);

		static bool TryToUInt16(Decimal value, UInt16& result);

		static UInt32 ToUInt32(Decimal d);

		static bool TryToUInt32(Decimal d, UInt32& result);

		static unsigned long long ToUInt64(Decimal d);

		static bool TryToUInt64(Decimal d, unsigned long long& result);

		static double ToDouble(Decimal d);

		static float ToSingle(Decimal d);

		static Decimal Truncate(Decimal d);

		static long long ToOACurrency(Decimal value);

		static Decimal FromOACurrency(long long cy);

		static int GetScale(Decimal cy);

		static bool IsZero(Decimal cy);


		Decimal operator+() const;

		Decimal operator-() const;

		Decimal& operator--();

		Decimal& operator++();

		Decimal operator--(int);

		Decimal& operator++(int);

		Decimal& operator+=(const Decimal& d2);

		Decimal& operator-=(const Decimal& d2);

		Decimal& operator*=(const Decimal& decimal);

		Decimal& operator/=(const Decimal& decimal);

		Decimal& operator%=(const Decimal& decimal);

		friend Decimal operator+(Decimal d1, Decimal d2);

		friend Decimal operator-(Decimal d1, Decimal d2);

		friend Decimal operator*(Decimal d1, Decimal d2);

		friend Decimal operator/(Decimal d1, Decimal d2);

		friend Decimal operator%(Decimal d1, Decimal d2);

		friend bool operator==(Decimal d1, Decimal d2);

		friend bool operator!=(Decimal d1, Decimal d2);

		friend bool operator<(Decimal d1, Decimal d2);

		friend bool operator<=(Decimal d1, Decimal d2);

		friend bool operator>(Decimal d1, Decimal d2);

		friend bool operator>=(Decimal d1, Decimal d2);

		static DECIMAL ToDECIMAL(Decimal* d);
		static Decimal ToDecimal(DECIMAL* d);


	private:
		Decimal(Currency value);
		// Private Not shift flas
		Decimal(int lo, int mid, int hi, int flags);

		static Currency ToCurrency(Decimal d);

		void SetBits(int* bits, int length);


		// This method does a 'raw' and 'unchecked' addition of a UInt32 to a Decimal in place. 
		// 'raw' means that it operates on the internal 96-bit unsigned integer value and 
		// ingores the sign and scale. This means that it is not equivalent to just adding
		// that number, as the sign and scale are effectively applied to the UInt32 value also.
		// 'unchecked' means that it does not fail if you overflow the 96 bit value.
		static void InternalAddUInt32RawUnchecked(Decimal& value, UInt32 i);

		// This method does an in-place division of a decimal by a UInt32, returning the remainder. 
		// Although it does not operate on the sign or scale, this does not result in any 
		// caveat for the result. It is equivalent to dividing by that number.
		static UInt32 InternalDivRemUInt32(Decimal& value, UInt32 divisor);

		// Does an in-place round the specified number of digits, rounding mid-point values
		// away from zero
		static void InternalRoundFromZero(Decimal& d, int decimalCount);

	protected:
		friend class ComNumber;
		friend struct Currency;
		friend class FCall;
		friend struct Il2CppDecimal;
	};
}
