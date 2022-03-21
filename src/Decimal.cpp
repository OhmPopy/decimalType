#include "include/Decimal.h"
#include <cmath>
#include "include/ComCultureInfo.h"
#include "include/ComNumberRaw.h"
#include "include/Currency.h"
#include "include/Exception.h"
#include "include/FCall.h"
#include "include/FCallExtension.h"

namespace System
{
#define POWER10_MAX     9
	static const uint32_t Powers10[POWER10_MAX + 1] =
	{
		1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000
	};

#define SignMask			(0x80000000)
#define ScaleMask			(0x00FF0000)

	Decimal Decimal::Zero = 0;
	Decimal Decimal::One = 1;
	Decimal Decimal::MinusOne = -1;
	Decimal Decimal::NearNegativeZero = Parse(L"-0.000000000000000000000000001");
	Decimal Decimal::NearPositiveZero = Parse(L"+0.000000000000000000000000001");
	Decimal Decimal::MaxValue = Parse(L"79228162514264337593543950335");
	Decimal Decimal::MinValue = Parse(L"-79228162514264337593543950335");

	Decimal::Decimal(): flags(0), hi(0), lo(0), mid(0)
	{
	}

	Decimal::Decimal(int value): hi(0), mid(0)
	{
		//  JIT today can't inline methods that contains "starg" opcode.
		//  For more details, see DevDiv Bugs 81184: x86 JIT CQ: Removing the inline striction of "starg".
		int value_copy = value;
		if (value_copy >= 0)
		{
			flags = 0;
		}
		else
		{
			flags = SignMask;
			value_copy = -value_copy;
		}
		lo = value_copy;
	}

	Decimal::Decimal(unsigned int value): flags(0), hi(0), lo((int)value), mid(0)
	{
	}

	Decimal::Decimal(long long value): hi(0)
	{
		//  JIT today can't inline methods that contains "starg" opcode.
		//  For more details, see DevDiv Bugs 81184: x86 JIT CQ: Removing the inline striction of "starg".
		long long value_copy = value;
		if (value_copy >= 0)
		{
			flags = 0;
		}
		else
		{
			flags = SignMask;
			value_copy = -value_copy;
		}
		lo = (int)value_copy;
		mid = (int)(value_copy >> 32);
	}

	Decimal::Decimal(unsigned long long value): flags(0), hi(0)
	{
		lo = (int)value;
		mid = (int)(value >> 32);
	}

	Decimal::Decimal(float value)
	{
		FCall::ConstructorFloat(this, value);
	}

	Decimal::Decimal(double value)
	{
		FCall::ConstructorDouble(this, value);
	}

	Decimal::Decimal(Currency value)
	{
		const Decimal temp = Currency::ToDecimal(value);
		this->lo = temp.lo;
		this->mid = temp.mid;
		this->hi = temp.hi;
		this->flags = temp.flags;
	}

	long long Decimal::ToOACurrency(Decimal value)
	{
		return Currency(value).ToOACurrency();
	}

	Decimal Decimal::FromOACurrency(long long cy)
	{
		return Currency::ToDecimal(Currency::FromOACurrency(cy));
	}

	Decimal::Decimal(int* bits): flags(0), hi(0), lo(0), mid(0)
	{
		SetBits(bits, 4); //4 khong biet duoc nhung de tam la 4 da
	}

	void Decimal::SetBits(int* bits, int length)
	{
		if (bits == NULL)
			throw ArgumentNullException("bits");
		if (length == 4)
		{
			int f = bits[3];
			if ((f & ~(SignMask | ScaleMask)) == 0 && (f & ScaleMask) <= 28 << 16)
			{
				lo = bits[0];
				mid = bits[1];
				hi = bits[2];
				flags = f;
				return;
			}
		}
		throw ArgumentException("Arg_DecBitCtor");
	}

	Decimal::Decimal(int lo, int mid, int hi, bool isNegative, byte scale): hi(hi), lo(lo), mid(mid)
	{
		if (scale > 28)
			throw ArgumentOutOfRangeException("scale", "ArgumentOutOfRange_DecimalScale");
		this->flags = (int)scale << 16;
		if (isNegative)
			this->flags |= SignMask;
	}

	Decimal::Decimal(const char* input) : flags(0), hi(0), lo(0), mid(0)
	{
		*this = Parse(input);
	}

	Decimal::Decimal(const wchar_t* input): flags(0), hi(0), lo(0), mid(0)
	{
		*this = Parse(input);
	}

	Decimal::Decimal(int lo, int mid, int hi, int flags)
	{
		if ((flags & ~(SignMask | ScaleMask)) == 0 && (flags & ScaleMask) <= 28 << 16)
		{
			this->lo = lo;
			this->mid = mid;
			this->hi = hi;
			this->flags = flags;
			return;
		}
		throw ArgumentException("Arg_DecBitCtor");
	}

	Decimal Decimal::Abs(Decimal d)
	{
		return Decimal(d.lo, d.mid, d.hi, d.flags & ~SignMask);
	}

	Decimal Decimal::Add(Decimal d1, Decimal d2)
	{
		FCall::FCallAddSub(&d1, &d2, DECIMAL_ADD);
		return d1;
	}

	Decimal Decimal::Ceiling(Decimal d)
	{
		return -Floor(-d);
	}

	int Decimal::Compare(Decimal d1, Decimal d2)
	{
		return FCall::FCallCompare(&d1, &d2);
	}

	int Decimal::CompareTo(Decimal value)
	{
		return FCall::FCallCompare(this, &value);
	}

	Decimal Decimal::Divide(Decimal d1, Decimal d2)
	{
		FCall::FCallDivide(&d1, &d2);
		return d1;
	}

	bool Decimal::Equals(Decimal value)
	{
		return FCall::FCallCompare(this, &value) == 0;
	}

	int Decimal::GetHashCode()
	{
		return FCall::GetHashCode(this);
	}

	bool Decimal::Equals(Decimal d1, Decimal d2)
	{
		return FCall::FCallCompare(&d1, &d2) == 0;
	}

	Decimal Decimal::Floor(Decimal d)
	{
		FCall::FCallFloor(&d);
		return d;
	}

	std::wstring Decimal::ToString()
	{
		DECIMAL ds = ToDECIMAL(this);
		const auto result = COMNumber::FormatDecimal(NumberFormatInfo::InvariantNumberFormat(), NULL, &ds);
		auto text = result->ToString();
		delete result;
		return text;
	}

	std::wstring Decimal::ToString(const std::wstring& format)
	{
		DECIMAL ds = ToDECIMAL(this);
		StringObject format_ptr(format.c_str());
		const auto result = COMNumber::FormatDecimal(NumberFormatInfo::InvariantNumberFormat(), &format_ptr, &ds);
		auto text = result->ToString();
		delete result;
		return text;
	}

	std::wstring Decimal::ToString(const std::wstring& format, const std::wstring& provider)
	{
		DECIMAL ds = ToDECIMAL(this);
		StringObject format_ptr(format.c_str());
		const auto result = COMNumber::FormatDecimal(ComCultureInfo::CreateSpecificCulture(provider)->NumberFormat(), &format_ptr, &ds);
		auto text = result->ToString();
		delete result;
		return text;
	}

	Decimal Decimal::Parse(const char* s)
	{
		DECIMAL ds;
		StringObject format_ptr(s);
		COMNumber::ParseDecimal(NumberFormatInfo::InvariantNumberFormat(), (int)NumberStyles::Number, &format_ptr, &ds);
		const Decimal decimal = ToDecimal(&ds);
		return decimal;
	}

	Decimal Decimal::Parse(const wchar_t* s)
	{
		DECIMAL ds;
		StringObject format_ptr(s);
		COMNumber::ParseDecimal(NumberFormatInfo::InvariantNumberFormat(), (int)NumberStyles::Number, &format_ptr, &ds);
		const Decimal decimal = ToDecimal(&ds);
		return decimal;
	}

	bool Decimal::TryParse(const std::string& s, Decimal* result)
	{
		DECIMAL ds;
		StringObject format_ptr(s.c_str());
		if (COMNumber::TryParseDecimal(NumberFormatInfo::InvariantNumberFormat(), (int)NumberStyles::Number, &format_ptr, &ds))
		{
			*result = ToDecimal(&ds);
			return true;
		}
		return false;
	}

	bool Decimal::TryParse(const std::string& s, Decimal* result, NumberStyles number_styles, const std::wstring& provider)
	{
		DECIMAL ds;
		StringObject format_ptr(s.c_str());
		if (COMNumber::TryParseDecimal(ComCultureInfo::CreateSpecificCulture(provider)->NumberFormat(), (int)number_styles, &format_ptr, &ds))
		{
			*result = ToDecimal(&ds);
			return true;
		}
		return false;
	}

	int* Decimal::GetBits(Decimal d)
	{
		return new int[4]{d.lo, d.mid, d.hi, d.flags};
	}

	void Decimal::GetBytes(Decimal d, byte* buffer)
	{
		if (buffer != NULL)
		{
			buffer[0] = (byte)d.lo;
			buffer[1] = (byte)(d.lo >> 8);
			buffer[2] = (byte)(d.lo >> 16);
			buffer[3] = (byte)(d.lo >> 24);

			buffer[4] = (byte)d.mid;
			buffer[5] = (byte)(d.mid >> 8);
			buffer[6] = (byte)(d.mid >> 16);
			buffer[7] = (byte)(d.mid >> 24);

			buffer[8] = (byte)d.hi;
			buffer[9] = (byte)(d.hi >> 8);
			buffer[10] = (byte)(d.hi >> 16);
			buffer[11] = (byte)(d.hi >> 24);

			buffer[12] = (byte)d.flags;
			buffer[13] = (byte)(d.flags >> 8);
			buffer[14] = (byte)(d.flags >> 16);
			buffer[15] = (byte)(d.flags >> 24);
		}
	}

	Decimal Decimal::ToDecimal(byte* buffer)
	{
		if (buffer == NULL) throw Exception("[ToDecimal]buffer != null && buffer.Length >= 16");
		const int lo = (int)buffer[0] | (int)buffer[1] << 8 | (int)buffer[2] << 16 | (int)buffer[3] << 24;
		const int mid = (int)buffer[4] | (int)buffer[5] << 8 | (int)buffer[6] << 16 | (int)buffer[7] << 24;
		const int hi = (int)buffer[8] | (int)buffer[9] << 8 | (int)buffer[10] << 16 | (int)buffer[11] << 24;
		const int flags = (int)buffer[12] | (int)buffer[13] << 8 | (int)buffer[14] << 16 | (int)buffer[15] << 24;
		return Decimal(lo, mid, hi, flags);
	}

	Decimal Decimal::Max(Decimal d1, Decimal d2)
	{
		return FCall::FCallCompare(&d1, &d2) >= 0 ? d1 : d2;
	}

	Decimal Decimal::Min(Decimal d1, Decimal d2)
	{
		return FCall::FCallCompare(&d1, &d2) < 0 ? d1 : d2;
	}

	Decimal Decimal::Remainder(Decimal d1, Decimal d2)
	{
		// OleAut doesn't provide a VarDecMod.            

		// In the operation x % y the sign of y does not matter. Result will have the sign of x.
		d2.flags = d2.flags & ~SignMask | d1.flags & SignMask;


		// This piece of code is to work around the fact that Dividing a decimal with 28 digits number by decimal which causes
		// causes the result to be 28 digits, can cause to be incorrectly rounded up.
		// eg. Decimal.MaxValue / 2 * Decimal.MaxValue will overflow since the division by 2 was rounded instead of being truncked.
		if (Abs(d1) < Abs(d2))
		{
			return d1;
		}
		d1 -= d2;

		if (d1 == 0)
		{
			// The sign of D1 will be wrong here. Fall through so that we still get a DivideByZeroException
			d1.flags = d1.flags & ~SignMask | d2.flags & SignMask;
		}

		// Formula:  d1 - (RoundTowardsZero(d1 / d2) * d2)            
		const Decimal dividedResult = Truncate(d1 / d2);
		const Decimal multipliedResult = dividedResult * d2;
		Decimal result = d1 - multipliedResult;
		// See if the result has crossed 0
		if ((d1.flags & SignMask) != (result.flags & SignMask))
		{
			if (NearNegativeZero <= result && result <= NearPositiveZero)
			{
				// Certain Remainder operations on decimals with 28 significant digits round
				// to [+-]0.000000000000000000000000001m instead of [+-]0m during the intermediate calculations. 
				// 'zero' results just need their sign corrected.
				result.flags = result.flags & ~SignMask | d1.flags & SignMask;
			}
			else
			{
				// If the division rounds up because it runs out of digits, the multiplied result can end up with a larger
				// absolute value and the result of the formula crosses 0. To correct it can add the divisor back.
				result += d2;
			}
		}

		return result;
	}

	Decimal Decimal::Multiply(Decimal d1, Decimal d2)
	{
		FCall::FCallMultiply(&d1, &d2);
		return d1;
	}

	Decimal Decimal::Negate(Decimal d)
	{
		return Decimal(d.lo, d.mid, d.hi, d.flags ^ SignMask);
	}

	Decimal Decimal::Round(Decimal d)
	{
		return Round(d, 0);
	}

	Decimal Decimal::Round(Decimal d, int decimals)
	{
		FCall::FCallRound(&d, decimals);
		return d;
	}

	Decimal Decimal::Round(Decimal d, MidpointRoundings mode)
	{
		return Round(d, 0, mode);
	}

	Decimal Decimal::Round(Decimal d, int decimals, MidpointRoundings mode)
	{
		if (decimals < 0 || decimals > 28)
			throw ArgumentOutOfRangeException("decimals", "ArgumentOutOfRange_DecimalRound");
		if (mode < MidpointRoundings::ToEven || mode > MidpointRoundings::AwayFromZero)
		{
			throw ArgumentException("Argument_InvalidEnumValue", "mode");
		}

		if (mode == MidpointRoundings::ToEven)
		{
			FCall::FCallRound(&d, decimals);
		}
		else
		{
			InternalRoundFromZero(d, decimals);
		}
		return d;
	}

	Decimal Decimal::Subtract(Decimal d1, Decimal d2)
	{
		FCall::FCallAddSub(&d1, &d2, DECIMAL_NEG);
		return d1;
	}

	byte Decimal::ToByte(Decimal value)
	{
		unsigned int temp;
		try
		{
			temp = ToUInt32(value);
		}
		catch (System::OverflowException e)
		{
			throw System::OverflowException("Overflow_Byte");
		}
		if (temp < 0 || temp > 255)
			throw System::OverflowException("Overflow_Byte");
		return (byte)temp;
	}

	bool Decimal::TryToByte(Decimal value, byte& result)
	{
		unsigned int temp;
		if (!TryToUInt32(value, temp))
			return false;
		if (temp < 0 || temp > 255)
			return false;
		result = (byte)temp;
		return true;
	}

	signed char Decimal::ToSByte(Decimal value)
	{
		int temp;
		try
		{
			temp = ToInt32(value);
		}
		catch (System::OverflowException e)
		{
			throw System::OverflowException("Overflow_SByte");
		}
		if (temp < SCHAR_MIN || temp > SCHAR_MAX)
			throw System::OverflowException("Overflow_SByte");
		return (signed char)temp;
	}

	bool Decimal::TryToSByte(Decimal value, signed char& result)
	{
		int temp;
		if (!TryToInt32(value, temp))
			return false;
		if (temp < SCHAR_MIN || temp > SCHAR_MAX)
			return false;
		result = (signed char)temp;
		return true;
	}

	short Decimal::ToInt16(Decimal value)
	{
		int temp;
		try
		{
			temp = ToInt32(value);
		}
		catch (System::OverflowException e)
		{
			throw System::OverflowException("Overflow_Int16");
		}
		if (temp < SHRT_MIN || temp > SHRT_MAX)
			throw System::OverflowException("Overflow_Int16");
		return (short)temp;
	}

	bool Decimal::TryToInt16(Decimal value, short& result)
	{
		int temp;
		if (!TryToInt32(value, temp))
			return false;
		if (temp < SHRT_MIN || temp > SHRT_MAX)
			return false;
		result = (short)temp;
		return true;
	}

	Currency Decimal::ToCurrency(Decimal d)
	{
		CY cy;
		const DECIMAL ds = ToDECIMAL(&d);
		FCallExtension::FCallToCurrency(&cy, ds);

		Currency result;
		result.m_value = cy.int64;

		return result;
	}

	int Decimal::ToInt32(Decimal d)
	{
		if ((d.flags & ScaleMask) != 0) FCall::FCallTruncate(&d);
		if (d.hi == 0 && d.mid == 0)
		{
			int i = d.lo;
			if (d.flags >= 0)
			{
				if (i >= 0) return i;
			}
			else
			{
				i = -i;
				if (i <= 0) return i;
			}
		}
		throw System::OverflowException("Overflow_Int32");
	}

	bool Decimal::TryToInt32(Decimal d, int& result)
	{
		if ((d.flags & ScaleMask) != 0) FCall::FCallTruncate(&d);
		if (d.hi == 0 && d.mid == 0)
		{
			int i = d.lo;
			if (d.flags >= 0)
			{
				if (i >= 0)
				{
					result = i;
					return true;
				}
			}
			else
			{
				i = -i;
				if (i <= 0)
				{
					result = i;
					return true;
				}
			}
		}
		return false;
	}

	long long Decimal::ToInt64(Decimal d)
	{
		if ((d.flags & ScaleMask) != 0) FCall::FCallTruncate(&d);
		if (d.hi == 0)
		{
			long long l = d.lo & 0xFFFFFFFFL | (long long)d.mid << 32;
			if (d.flags >= 0)
			{
				if (l >= 0) return l;
			}
			else
			{
				l = -l;
				if (l <= 0) return l;
			}
		}
		throw System::OverflowException("Overflow_Int64");
	}

	bool Decimal::TryToInt64(Decimal d, long long& result)
	{
		if ((d.flags & ScaleMask) != 0) FCall::FCallTruncate(&d);
		if (d.hi == 0)
		{
			long long l = d.lo & 0xFFFFFFFFL | (long long)d.mid << 32;
			if (d.flags >= 0)
			{
				if (l >= 0)
				{
					result = l;
					return true;
				}
			}
			else
			{
				l = -l;
				if (l <= 0)
				{
					result = l;
					return true;
				}
			}
		}
		return false;
	}

	UInt16 Decimal::ToUInt16(Decimal value)
	{
		UInt16 temp;
		try
		{
			temp = ToUInt32(value);
		}
		catch (System::OverflowException e)
		{
			throw System::OverflowException("Overflow_UInt16");
		}
		if (temp < 0 || temp > USHRT_MAX)
			throw System::OverflowException("Overflow_UInt16");
		return (UInt16)temp;
	}

	bool Decimal::TryToUInt16(Decimal value, UInt16& result)
	{
		UInt32 temp;
		if (!TryToUInt32(value, temp))
			return false;
		if (temp < 0 || temp > USHRT_MAX)
			return false;
		result = (UInt16)temp;
		return true;
	}

	UInt32 Decimal::ToUInt32(Decimal d)
	{
		if ((d.flags & ScaleMask) != 0) FCall::FCallTruncate(&d);
		if (d.hi == 0 && d.mid == 0)
		{
			const UInt32 i = (UInt32)d.lo;
			if (d.flags >= 0 || i == 0)
				return i;
		}
		throw System::OverflowException("Overflow_UInt32");
	}

	bool Decimal::TryToUInt32(Decimal d, UInt32& result)
	{
		if ((d.flags & ScaleMask) != 0) FCall::FCallTruncate(&d);
		if (d.hi == 0 && d.mid == 0)
		{
			const UInt32 i = (UInt32)d.lo;
			if (d.flags >= 0 || i == 0)
			{
				result = i;
				return true;
			}
		}
		return false;
	}

	unsigned long long Decimal::ToUInt64(Decimal d)
	{
		if ((d.flags & ScaleMask) != 0) FCall::FCallTruncate(&d);
		if (d.hi == 0)
		{
			const unsigned long long l = (unsigned long long)(UInt32)d.lo | (unsigned long long)(UInt32)d.mid << 32;
			if (d.flags >= 0 || l == 0)
				return l;
		}
		throw System::OverflowException("Overflow_UInt64");
	}

	bool Decimal::TryToUInt64(Decimal d, unsigned long long& result)
	{
		if ((d.flags & ScaleMask) != 0) FCall::FCallTruncate(&d);
		if (d.hi == 0)
		{
			const unsigned long long l = (unsigned long long)(UInt32)d.lo | (unsigned long long)(UInt32)d.mid << 32;
			if (d.flags >= 0 || l == 0)
			{
				result = l;
				return true;
			}
		}
		return false;
	}

	double Decimal::ToDouble(Decimal d)
	{
		return FCall::FCallToDouble(d);
	}

	float Decimal::ToSingle(Decimal d)
	{
		return FCall::ToSingle(d);
	}

	int Decimal::GetScale(Decimal cy)
	{
		//return cy.ptr_decimal.u.u.scale;
		return cy.flags >> 16; //bdki
	}

	bool Decimal::IsZero(Decimal cy)
	{
		return cy == Zero;
	}

	Decimal Decimal::Truncate(Decimal d)
	{
		FCall::FCallTruncate(&d);
		return d;
	}

	Decimal Decimal::operator+() const
	{
		return *this;
	}

	Decimal Decimal::operator-() const
	{
		return Negate(*this);
	}

	Decimal& Decimal::operator--()
	{
		*this = Subtract(*this, One);
		return *this;
	}

	Decimal& Decimal::operator++()
	{
		*this = Add(*this, One);
		return *this;
	}

	Decimal Decimal::operator--(int)
	{
		*this = Subtract(*this, One);
		return *this;
	}

	Decimal& Decimal::operator++(int)
	{
		*this = Add(*this, One);
		return *this;
	}

	Decimal& Decimal::operator+=(const Decimal& d2)
	{
		*this = Add(*this, d2);
		return *this;
	}

	Decimal& Decimal::operator*=(const Decimal& decimal)
	{
		Decimal clone = decimal;
		FCall::FCallMultiply(this, &clone);
		return *this;
	}

	Decimal& Decimal::operator/=(const Decimal& decimal)
	{
		Decimal clone = decimal;
		FCall::FCallDivide(this, &clone);
		return *this;
	}

	Decimal& Decimal::operator%=(const Decimal& decimal)
	{
		const Decimal clone = decimal;
		*this = Remainder(*this, clone);
		return *this;
	}

	Decimal& Decimal::operator-=(const Decimal& d2)
	{
		*this = Subtract(*this, d2);
		return *this;
	}

	Decimal operator+(Decimal d1, Decimal d2)
	{
		FCall::FCallAddSub(&d1, &d2, DECIMAL_ADD);
		return d1;
	}

	Decimal operator-(Decimal d1, Decimal d2)
	{
		FCall::FCallAddSub(&d1, &d2, DECIMAL_NEG);
		return d1;
	}

	Decimal operator*(Decimal d1, Decimal d2)
	{
		FCall::FCallMultiply(&d1, &d2);
		return d1;
	}

	Decimal operator/(Decimal d1, Decimal d2)
	{
		FCall::FCallDivide(&d1, &d2);
		return d1;
	}

	Decimal operator%(Decimal d1, Decimal d2)
	{
		return Decimal::Remainder(d1, d2);
	}

	bool operator==(Decimal d1, Decimal d2)
	{
		return FCall::FCallCompare(&d1, &d2) == 0;
	}

	bool operator!=(Decimal d1, Decimal d2)
	{
		return FCall::FCallCompare(&d1, &d2) != 0;
	}

	bool operator<(Decimal d1, Decimal d2)
	{
		return FCall::FCallCompare(&d1, &d2) < 0;
	}

	bool operator<=(Decimal d1, Decimal d2)
	{
		return FCall::FCallCompare(&d1, &d2) <= 0;
	}

	bool operator>(Decimal d1, Decimal d2)
	{
		return FCall::FCallCompare(&d1, &d2) > 0;
	}

	bool operator>=(Decimal d1, Decimal d2)
	{
		return FCall::FCallCompare(&d1, &d2) >= 0;
	}


	void Decimal::InternalAddUInt32RawUnchecked(Decimal& value, UInt32 i)
	{
		UInt32 v;
		UInt32 sum;
		v = (UInt32)value.lo;
		sum = v + i;
		value.lo = (Int32)sum;
		if (sum < v || sum < i)
		{
			v = (UInt32)value.mid;
			sum = v + 1;
			value.mid = (Int32)sum;
			if (sum < v || sum < 1)
			{
				value.hi = (Int32)((UInt32)value.hi + 1);
			}
		}
	}

	UInt32 Decimal::InternalDivRemUInt32(Decimal& value, UInt32 divisor)
	{
		UInt32 remainder = 0;
		UInt64 n;
		if (value.hi != 0)
		{
			n = (UInt32)value.hi;
			value.hi = (Int32)(UInt32)(n / divisor);
			remainder = (UInt32)(n % divisor);
		}
		if (value.mid != 0 || remainder != 0)
		{
			n = (UInt64)remainder << 32 | (UInt32)value.mid;
			value.mid = (Int32)(UInt32)(n / divisor);
			remainder = (UInt32)(n % divisor);
		}
		if (value.lo != 0 || remainder != 0)
		{
			n = (UInt64)remainder << 32 | (UInt32)value.lo;
			value.lo = (Int32)(UInt32)(n / divisor);
			remainder = (UInt32)(n % divisor);
		}
		return remainder;
	}

	void Decimal::InternalRoundFromZero(Decimal& d, int decimalCount)
	{
		const Int32 scale = (d.flags & ScaleMask) >> ScaleShift;
		Int32 scaleDifference = scale - decimalCount;
		if (scaleDifference <= 0)
		{
			return;
		}
		// Divide the value by 10^scaleDifference
		UInt32 lastRemainder;
		UInt32 lastDivisor;
		do
		{
			const Int32 diffChunk = scaleDifference > MaxInt32Scale ? MaxInt32Scale : scaleDifference;
			lastDivisor = Powers10[diffChunk];
			lastRemainder = InternalDivRemUInt32(d, lastDivisor);
			scaleDifference -= diffChunk;
		}
		while (scaleDifference > 0);

		// Round away from zero at the mid point
		if (lastRemainder >= lastDivisor >> 1)
		{
			InternalAddUInt32RawUnchecked(d, 1);
		}

		// the scale becomes the desired decimal count
		d.flags = decimalCount << ScaleShift & ScaleMask | d.flags & SignMask;
	}

	DECIMAL Decimal::ToDECIMAL(Decimal* d)
	{
		DECIMAL ds;
		//ds.Hi32 = d->ptr_decimal.Hi32;
		//ds.wReserved = d->ptr_decimal.reserved;
		//ds.signscale = d->ptr_decimal.u.signscale;
		//ds.Lo64 = d->ptr_decimal.v.Lo64;
		//ds.Lo32 = d->ptr_decimal.v.v.Lo32;
		//ds.Mid32 = d->ptr_decimal.v.v.Mid32;
		//ds.scale = d->ptr_decimal.u.u.scale;
		//ds.sign = d->ptr_decimal.u.u.sign;

		ds.wReserved = 0;
		ds.Hi32 = d->hi;
		ds.Lo32 = d->lo;
		ds.Mid32 = d->mid;
		ds.signscale = d->flags >> 16;
		return ds;
	}

	Decimal Decimal::ToDecimal(DECIMAL* ds)
	{
		Decimal decimal;
		//decimal.ptr_decimal.Hi32 = ds->Hi32;
		//decimal.ptr_decimal.reserved = ds->wReserved;
		//decimal.ptr_decimal.u.signscale = ds->signscale;
		//decimal.ptr_decimal.v.Lo64 = ds->Lo64;
		//decimal.ptr_decimal.v.v.Lo32 = ds->Lo32;
		//decimal.ptr_decimal.v.v.Mid32 = ds->Mid32;
		//decimal.ptr_decimal.u.u.scale = ds->scale;
		//decimal.ptr_decimal.u.u.sign = ds->sign;

		decimal.flags = ds->signscale << 16;
		decimal.hi = ds->Hi32;
		decimal.lo = ds->Lo32;
		decimal.mid = ds->Mid32;
		return decimal;
	}
}
