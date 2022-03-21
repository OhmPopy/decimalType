#pragma once
#include "include/Decimal.h"

using namespace System;


class DecimalTestDotNet
{
	struct testcase_expected
	{
		System::Decimal d1;
		System::Decimal d2;
		int expected;

		testcase_expected(): expected(0)
		{
		}

		testcase_expected(Decimal d1, Decimal d2, int expected)
		{
			this->d1 = d1;
			this->d2 = d2;
			this->expected = expected;
		}
	};

public:
	static void MaxValue_Get_ReturnsExpected();

	static void MinusOne_Get_ReturnsExpected();

	static void MinValue_GetReturnsExpected();

	static void Zero_Get_ReturnsExpected();

	static void Ctor_ULong();

	static void Ctor_UInt();

	static void Ctor_Float_TestData();

	static void Ctor_InvalidFloat_ThrowsOverlowException();

	static void Ctor_Long();

	static void Ctor_IntArray();

	static void Ctor_Int();

	static void Ctor_Double();

	static void Ctor_LargeDouble_ThrowsOverlowException();

	static void Ctor_Int_Int_Int_Bool_Byte();

	static void Scale();

	static void Add();

	static void Add_Overflows_ThrowsOverflowException();

	static void Ceiling();

	static void CompareTo_Other_ReturnsExpected();

	static void Divide();

	static void Divide_ZeroDenominator_ThrowsDivideByZeroException();

	static void Divide_Overflows_ThrowsOverflowException();

	static void EqualsTest();

	static void FromOACurrency();

	static void Floor();

	static void GetBits();

	static void Multiply();

	static void Multiply_Invalid();

	static void Negate();

	static void Parse();


	static void Parse_Invalid();

	static void Remainder();

	static void RemainderV2();

	static void Remainder_ZeroDenominator_ThrowsDivideByZeroException();

	static void Round();

	static void Round_Digits_ReturnsExpected();

	static void Round_DigitsMode_ReturnsExpected();

	static void Round_MidpointRounding_ReturnsExpected();

	static void Subtract();

	static void Subtract_Invalid();

	static void ToOACurrency_Value_ReturnsExpected();

	static void ToOACurrency_InvalidAsLong_ThrowsOverflowException();

	static void ToByte();

	static void ToByte_Invalid();


	static void ToDouble();

	static void ToInt16();

	static void ToInt16_Invalid();

	static void ToInt32();

	static void ToInt32_Invalid();

	static void ToInt64();

	static void ToInt64_Invalid();

	static void ToSByte();

	static void ToSByte_Invalid();

	static void ToSingle();

	static void ToUInt16();

	static void ToUInt16_Invalid();

	static void ToUInt32();

	static void ToUInt32_Invalid();

	static void ToUInt64();

	static void ToUInt64_Invalid();

	static void ToString_InvalidFormat_ThrowsFormatException();

	static void TestRoundTripDecimalToString();

	static void Truncate();

	static void IncrementOperator();

	static void DecrementOperator();
};
