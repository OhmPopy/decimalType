#include "DecimalTestDotNet.h"
#include "CppUnitTestAssert.h"
#include "vector"
#include "include/ComNumberRaw.h"
#include "include/NumberFormatInfo.h"

void DecimalTestDotNet::MaxValue_Get_ReturnsExpected()
{
	Assert::IsTrue(Decimal::Parse("79228162514264337593543950335") == System::Decimal::MaxValue);
}

void DecimalTestDotNet::MinusOne_Get_ReturnsExpected()
{
	Assert::IsTrue(-1 == Decimal::MinusOne);
}

void DecimalTestDotNet::MinValue_GetReturnsExpected()
{
	Assert::IsTrue(Decimal::Parse("-79228162514264337593543950335") == System::Decimal::MinValue);
}

void DecimalTestDotNet::Zero_Get_ReturnsExpected()
{
	Assert::IsTrue(0 == Decimal::Zero);
}

void DecimalTestDotNet::Ctor_ULong()
{
	Assert::IsTrue(0 == Decimal::ToUInt64(Decimal(0)));
	Assert::IsTrue(ULLONG_MAX == Decimal::ToUInt64(Decimal(ULLONG_MAX)));
}

void DecimalTestDotNet::Ctor_UInt()
{
	Assert::IsTrue(0 == Decimal::ToUInt32(Decimal(0)));
	Assert::IsTrue(UINT_MAX == Decimal::ToUInt32(Decimal(UINT_MAX)));
}

void DecimalTestDotNet::Ctor_Float_TestData()
{
	struct testcase_float
	{
		float value;
		int bits[4];

		testcase_float(float v, int i_0, int i_1, int i_2, int i_3)
		{
			value = v;
			bits[0] = i_0;
			bits[1] = i_1;
			bits[2] = i_2;
			bits[3] = i_3;
		}
	};

	std::vector<testcase_float> cass;
	cass.push_back(testcase_float(123456789.123456f, 123456800, 0, 0, 0));
	cass.push_back(testcase_float(2.0123456789123456f, 2012346, 0, 0, 393216));
	cass.push_back(testcase_float(2E-28f, 2, 0, 0, 1835008));
	cass.push_back(testcase_float(2E-29f, 0, 0, 0, 0));
	cass.push_back(testcase_float(2E28f, 536870912, 2085225666, 1084202172, 0));
	cass.push_back(testcase_float(1.5f, 15, 0, 0, 65536));
	cass.push_back(testcase_float(0.0f, 0, 0, 0, 0));
	//cass.push_back(testcase_float( float.Parse("-0.0", CultureInfo.InvariantCulture), 0, 0, 0, 0 ));

	cass.push_back(testcase_float(1000000.1f, 1000000, 0, 0, 0));
	cass.push_back(testcase_float(100000.1f, 1000001, 0, 0, 65536));
	cass.push_back(testcase_float(10000.1f, 100001, 0, 0, 65536));
	cass.push_back(testcase_float(1000.1f, 10001, 0, 0, 65536));
	cass.push_back(testcase_float(100.1f, 1001, 0, 0, 65536));
	cass.push_back(testcase_float(10.1f, 101, 0, 0, 65536));
	cass.push_back(testcase_float(1.1f, 11, 0, 0, 65536));
	cass.push_back(testcase_float(1.0f, 1, 0, 0, 0));
	cass.push_back(testcase_float(0.1f, 1, 0, 0, 65536));
	cass.push_back(testcase_float(0.01f, 10, 0, 0, 196608));
	cass.push_back(testcase_float(0.001f, 1, 0, 0, 196608));
	cass.push_back(testcase_float(0.0001f, 10, 0, 0, 327680));
	cass.push_back(testcase_float(0.00001f, 10, 0, 0, 393216));
	cass.push_back(testcase_float(0.0000000000000000000000000001f, 1, 0, 0, 1835008));
	cass.push_back(testcase_float(0.00000000000000000000000000001f, 0, 0, 0, 0));


	for (size_t i = 0; i < cass.size(); ++i)
	{
		Decimal d(cass.at(i).value);
		Assert::IsTrue(cass.at(i).value == d);
		auto bit_value = Decimal::GetBits(d);
		auto bit_bits = cass.at(i).bits;
		Assert::IsTrue(cass.at(i).bits[0] == bit_value[0]);
		Assert::IsTrue(cass.at(i).bits[1] == bit_value[1]);
		Assert::IsTrue(cass.at(i).bits[2] == bit_value[2]);
		Assert::IsTrue(cass.at(i).bits[3] == bit_value[3]);
	}
}

void DecimalTestDotNet::Ctor_InvalidFloat_ThrowsOverlowException()
{
	//Decimal d(2E29);
	//Assert::Throws<OverflowException>(Decimal(2E29));
}

void DecimalTestDotNet::Ctor_Long()
{
	Decimal decimal_long_min = Decimal(LONG_MIN);
	auto text = decimal_long_min.ToString();
	Assert::IsTrue(LONG_MIN == Decimal::ToInt64(decimal_long_min));
	Assert::IsTrue(0 == Decimal::ToInt64(Decimal(0)));
	Assert::IsTrue(LONG_MAX == Decimal::ToInt64(Decimal(LONG_MAX)));
}

void DecimalTestDotNet::Ctor_IntArray()
{
	Decimal expected = 3;
	expected += UINT_MAX;
	expected += ULLONG_MAX;

	struct testcase_int
	{
		Decimal value;
		int bits[4];

		testcase_int(int i_0, int i_1, int i_2, int i_3, Decimal v)
		{
			value = v;
			bits[0] = i_0;
			bits[1] = i_1;
			bits[2] = i_2;
			bits[3] = i_3;
		}
	};
	std::vector<testcase_int> cass;
	cass.push_back(testcase_int(1, 1, 1, 0, expected));
	cass.push_back(testcase_int(1, 0, 0, 0, Decimal::One));
	cass.push_back(testcase_int(1000, 0, 0, 0x30000, Decimal::One));
	cass.push_back(testcase_int(1000, 0, 0, ((int)0x80030000), -Decimal::One));
	cass.push_back(testcase_int(0, 0, 0, 0x1C0000, Decimal::Zero));
	cass.push_back(testcase_int(1000, 0, 0, 0x1C0000, 0.0000000000000000000000001));
	cass.push_back(testcase_int(0, 0, 0, 0, Decimal::Zero));
	cass.push_back(testcase_int(0, 0, 0, ((int)0x80000000), Decimal::Zero));

	//int bits[4]{ 1,0,0,0 };
	//Decimal decimal(bits);

	for (size_t i = 0; i < cass.size(); ++i)
	{
		Decimal value(cass.at(i).value);
		Decimal bits(cass.at(i).bits);
		auto bit_value = Decimal::GetBits(value);
		auto bit_bits = Decimal::GetBits(bits);
		auto text_1 = value.ToString();
		auto text_2 = bits.ToString();
		Assert::IsTrue(value == bits);
	}
}

void DecimalTestDotNet::Ctor_Int()
{
	Assert::IsTrue(INT_MIN == Decimal::ToInt32(Decimal(INT_MIN)));
	Assert::IsTrue(0 == Decimal::ToInt32(Decimal(0)));
	Assert::IsTrue(INT_MAX == Decimal::ToInt32(Decimal(INT_MAX)));
}

void DecimalTestDotNet::Ctor_Double()
{
	struct testcase_double
	{
		double value;
		int bits[4];

		testcase_double(double v, int i_0, int i_1, int i_2, int i_3)
		{
			value = v;
			bits[0] = i_0;
			bits[1] = i_1;
			bits[2] = i_2;
			bits[3] = i_3;
		}
	};

	std::vector<testcase_double> cass;


	cass.push_back(testcase_double(123456789.123456, -2045800064, 28744, 0, 393216));
	cass.push_back(testcase_double(2.0123456789123456, -1829795549, 46853, 0, 917504));
	cass.push_back(testcase_double(2E-28, 2, 0, 0, 1835008));
	cass.push_back(testcase_double(2E-29, 0, 0, 0, 0));
	cass.push_back(testcase_double(2E28, 536870912, 2085225666, 1084202172, 0));
	cass.push_back(testcase_double(1.5, 15, 0, 0, 65536));
	cass.push_back(testcase_double(0, 0, 0, 0, 0));
	//cass.push_back(testcase_double( double.Parse("-0.0", CultureInfo.InvariantCulture), 0, 0, 0, 0));

	cass.push_back(testcase_double(100000000000000.1, 276447232, 23283, 0, 0));
	cass.push_back(testcase_double(10000000000000.1, 276447233, 23283, 0, 65536));
	cass.push_back(testcase_double(1000000000000.1, 1316134913, 2328, 0, 65536));
	cass.push_back(testcase_double(100000000000.1, -727379967, 232, 0, 65536));
	cass.push_back(testcase_double(10000000000.1, 1215752193, 23, 0, 65536));
	cass.push_back(testcase_double(1000000000.1, 1410065409, 2, 0, 65536));
	cass.push_back(testcase_double(100000000.1, 1000000001, 0, 0, 65536));
	cass.push_back(testcase_double(10000000.1, 100000001, 0, 0, 65536));
	cass.push_back(testcase_double(1000000.1, 10000001, 0, 0, 65536));
	cass.push_back(testcase_double(100000.1, 1000001, 0, 0, 65536));
	cass.push_back(testcase_double(10000.1, 100001, 0, 0, 65536));
	cass.push_back(testcase_double(1000.1, 10001, 0, 0, 65536));
	cass.push_back(testcase_double(100.1, 1001, 0, 0, 65536));
	cass.push_back(testcase_double(10.1, 101, 0, 0, 65536));
	cass.push_back(testcase_double(1.1, 11, 0, 0, 65536));
	cass.push_back(testcase_double(1, 1, 0, 0, 0));
	cass.push_back(testcase_double(0.1, 1, 0, 0, 65536));
	cass.push_back(testcase_double(0.01, 1, 0, 0, 131072));
	cass.push_back(testcase_double(0.001, 1, 0, 0, 196608));
	cass.push_back(testcase_double(0.0001, 1, 0, 0, 262144));
	cass.push_back(testcase_double(0.00001, 1, 0, 0, 327680));
	cass.push_back(testcase_double(0.0000000000000000000000000001, 1, 0, 0, 1835008));
	cass.push_back(testcase_double(0.00000000000000000000000000001, 0, 0, 0, 0));

	for (size_t i = 0; i < cass.size(); ++i)
	{
		Decimal d(cass.at(i).value);
		Assert::IsTrue(cass.at(i).value == d);
		auto bits = Decimal::GetBits(d);
		Assert::IsTrue(cass.at(i).bits[0] == bits[0]);
		Assert::IsTrue(cass.at(i).bits[1] == bits[1]);
		Assert::IsTrue(cass.at(i).bits[2] == bits[2]);
		Assert::IsTrue(cass.at(i).bits[3] == bits[3]);
	}
}

void DecimalTestDotNet::Ctor_LargeDouble_ThrowsOverlowException()
{
	//Assert::Throws<OverflowException>(() = > new decimal(double.NaN));
}

void DecimalTestDotNet::Ctor_Int_Int_Int_Bool_Byte()
{
	struct testcase_bit
	{
		Decimal value;
		int lo;
		int mid;
		int hi;
		bool isNegative;
		byte scale;

		testcase_bit(int lo, int mid, int hi, bool isNegative, byte scale, Decimal v)
		{
			value = v;
			this->lo = lo;
			this->mid = mid;
			this->hi = hi;
			this->isNegative = isNegative;
			this->scale = scale;
		}
	};
	Decimal expected = 3;
	expected += UINT_MAX;
	expected += ULLONG_MAX;

	std::vector<testcase_bit> cass;
	cass.push_back(testcase_bit(1, 1, 1, false, 0, expected));
	cass.push_back(testcase_bit(1, 0, 0, false, 0, Decimal::One));
	cass.push_back(testcase_bit(1000, 0, 0, false, 3, Decimal::One));
	cass.push_back(testcase_bit(1000, 0, 0, true, 3, -Decimal::One));
	cass.push_back(testcase_bit(0, 0, 0, false, 28, Decimal::Zero));
	cass.push_back(testcase_bit(1000, 0, 0, false, 28, 0.0000000000000000000000001));
	cass.push_back(testcase_bit(0, 0, 0, false, 0, Decimal::Zero));
	cass.push_back(testcase_bit(0, 0, 0, true, 0, Decimal::Zero));


	for (size_t i = 0; i < cass.size(); ++i)
	{
		Decimal d(cass.at(i).value);
		Decimal d2(cass.at(i).lo, cass.at(i).mid, cass.at(i).hi, cass.at(i).isNegative, cass.at(i).scale);

		auto text_1 = d.ToString();
		auto text_2 = d2.ToString();

		Assert::IsTrue(d == d2);
	}
}

void DecimalTestDotNet::Scale()
{
	struct testcase_scale
	{
		Decimal value;
		byte scale;

		testcase_scale(Decimal v, byte scale)
		{
			value = v;
			this->scale = scale;
		}
	};

	std::vector<testcase_scale> cass;
	cass.push_back(testcase_scale(10, 0));
	cass.push_back(testcase_scale(1, 0));
	cass.push_back(testcase_scale(-1, 0));
	cass.push_back(testcase_scale(Decimal::Parse("1.0"), 1));
	cass.push_back(testcase_scale(Decimal::Parse("-1.0"), 1));
	cass.push_back(testcase_scale(Decimal::Parse("1.1"), 1));
	cass.push_back(testcase_scale(Decimal::Parse("1.00"), 2));
	cass.push_back(testcase_scale(Decimal::Parse("1.01"), 2));
	cass.push_back(testcase_scale(Decimal::Parse("1.0000000000000000000000000000"), 28));

	for (size_t i = 0; i < cass.size(); ++i)
	{
		Decimal d(cass.at(i).value);
		//Assert::IsTrue(cass.at(i).scale == Decimal::GetScale(d));
	}
}

void DecimalTestDotNet::Add()
{
	struct testcase_add
	{
		Decimal d1;
		Decimal d2;
		Decimal expected;

		testcase_add(Decimal d1, Decimal d2, Decimal expected)
		{
			this->d1 = d1;
			this->d2 = d2;
			this->expected = expected;
		}
	};

	std::vector<testcase_add> cass;
	cass.push_back(testcase_add(1, 1, 2));
	cass.push_back(testcase_add(-1, 1, 0));
	cass.push_back(testcase_add(1, -1, 0));
	cass.push_back(testcase_add(1, 0, 1));
	cass.push_back(testcase_add(Decimal::Parse("79228162514264337593543950330"), 5, Decimal::MaxValue));
	cass.push_back(testcase_add(Decimal::Parse("79228162514264337593543950335"), -5, Decimal::Parse("79228162514264337593543950330")));
	cass.push_back(testcase_add(Decimal::Parse("-79228162514264337593543950330"), 5, Decimal::Parse("-79228162514264337593543950325")));
	cass.push_back(testcase_add(Decimal::Parse("-79228162514264337593543950330"), -5, Decimal::MinValue));
	cass.push_back(testcase_add(Decimal::Parse("1234.5678"), Decimal::Parse("0.00009"), Decimal::Parse("1234.56789")));
	cass.push_back(testcase_add(Decimal::Parse("-1234.5678"), Decimal::Parse("0.00009"), Decimal::Parse("-1234.56771")));
	cass.push_back(testcase_add(Decimal::Parse("0.1111111111111111111111111111"), Decimal::Parse("0.1111111111111111111111111111"), Decimal::Parse("0.2222222222222222222222222222")));
	cass.push_back(testcase_add(Decimal::Parse("0.5555555555555555555555555555"), Decimal::Parse("0.5555555555555555555555555555"), Decimal::Parse("1.1111111111111111111111111110")));
	cass.push_back(testcase_add(Decimal::MinValue, Decimal::Zero, Decimal::MinValue));
	cass.push_back(testcase_add(Decimal::MaxValue, Decimal::Zero, Decimal::MaxValue));
	cass.push_back(testcase_add(Decimal::MinValue, Decimal::Zero, Decimal::MinValue));

	for (size_t i = 0; i < cass.size(); ++i)
	{
		DECIMAL ds;
		StringObject* format_ptr = new StringObject("-79228162514264337593543950330");
		COMNumber::ParseDecimal(NumberFormatInfo::InvariantNumberFormat(), (int)NumberStyles::Number, format_ptr, &ds);


		Decimal d_1 = cass.at(i).d1;
		Decimal d_2 = cass.at(i).d2;
		auto text_1 = d_1.ToString();
		auto text_2 = d_2.ToString();
		auto bit_bits = d_1.GetBits(d_1);
		Decimal sum = d_1 + d_2;
		auto text_3 = sum.ToString();
		Assert::IsTrue(cass.at(i).expected == sum);
		Assert::IsTrue(cass.at(i).expected == Decimal::Add(cass.at(i).d1, cass.at(i).d2));

		Decimal d3 = cass.at(i).d1;
		d3 += cass.at(i).d2;
		Assert::IsTrue(cass.at(i).expected == d3);
	}
}

void DecimalTestDotNet::Add_Overflows_ThrowsOverflowException()
{
	struct testcase_Overflows
	{
		Decimal d1;
		Decimal d2;

		testcase_Overflows(Decimal d1, Decimal d2)
		{
			this->d1 = d1;
			this->d2 = d2;
		}
	};


	std::vector<testcase_Overflows> cass;
	cass.push_back(testcase_Overflows(Decimal::MaxValue, Decimal::MaxValue));
	cass.push_back(testcase_Overflows(Decimal::Parse("79228162514264337593543950330"), 6));
	cass.push_back(testcase_Overflows(Decimal::Parse("-79228162514264337593543950330"), -6));

	for (size_t i = 0; i < cass.size(); ++i)
	{
		//Assert.Throws<OverflowException>(() = > d1 + d2);
		//Assert.Throws<OverflowException>(() = > decimal.Add(d1, d2));

		//decimal d3 = d1;
		//Assert.Throws<OverflowException>(() = > d3 += d2);
	}
}

void DecimalTestDotNet::Ceiling()
{
	struct testcase_Ceiling
	{
		Decimal d1;
		Decimal expected;

		testcase_Ceiling(Decimal d1, Decimal expected)
		{
			this->d1 = d1;
			this->expected = expected;
		}
	};


	std::vector<testcase_Ceiling> cass;
	cass.push_back(testcase_Ceiling(123, 123));
	cass.push_back(testcase_Ceiling(123.123, 124));
	cass.push_back(testcase_Ceiling(123.456, 124));
	cass.push_back(testcase_Ceiling(-123.123, -123));
	cass.push_back(testcase_Ceiling(-123.456, -123));

	for (size_t i = 0; i < cass.size(); ++i)
	{
		Decimal expected = cass.at(i).expected;
		auto text_1 = expected.ToString();
		Decimal result = Decimal::Ceiling(cass.at(i).d1);
		auto text_2 = result.ToString();
		Assert::IsTrue(expected == result);
	}
}

void DecimalTestDotNet::CompareTo_Other_ReturnsExpected()
{
	//struct testcase_Compare
	//{
	//	Decimal d1;
	//	Decimal obj;
	//	int expected;

	//	testcase_Compare(Decimal d1, Decimal obj, int expected)
	//	{
	//		this->d1 = d1;
	//		this->obj = obj;
	//		this->expected = expected;
	//	}
	//};


	//std::vector<testcase_Compare> cass;
	//cass.push_back(testcase_Compare(5, 15, -1));
	//cass.push_back(testcase_Compare(15, 15, 0));
	//cass.push_back(testcase_Compare(15, 5, 1));


	//cass.push_back(testcase_Compare(Decimal::Zero, Decimal::Zero, 0));
	//cass.push_back(testcase_Compare(Decimal::Zero, Decimal::One, -1));
	//cass.push_back(testcase_Compare(Decimal::One, Decimal::Zero, 1));
	//cass.push_back(testcase_Compare(Decimal::MaxValue, Decimal::MaxValue, 0));
	//cass.push_back(testcase_Compare(Decimal::MinValue, Decimal::MinValue, 0));
	//cass.push_back(testcase_Compare(Decimal::MaxValue, Decimal::MinValue, 1));
	//cass.push_back(testcase_Compare(Decimal::MinValue, Decimal::MaxValue, -1));

	//for (size_t i = 0; i < cass.size(); ++i)
	//{
	//	Decimal expected = cass.at(i).expected;
	//	Decimal d1 = cass.at(i).d1;
	//	Decimal d2 = cass.at(i).obj;


	//	Assert::IsTrue(expected == Math::Sign(d1.CompareTo(d2)));
	//	if (expected >= 0)
	//	{
	//		Assert::IsTrue(d1 >= d2);
	//		Assert::IsFalse(d1 < d2);
	//	}

	//	if (expected > 0)
	//	{
	//		Assert::IsTrue(d1 > d2);
	//		Assert::IsFalse(d1 <= d2);
	//	}

	//	if (expected <= 0)
	//	{
	//		Assert::IsTrue(d1 <= d2);
	//		Assert::IsFalse(d1 > d2);
	//	}

	//	if (expected < 0)
	//	{
	//		Assert::IsTrue(d1 < d2);
	//		Assert::IsFalse(d1 >= d2);
	//	}

	//	Assert::IsTrue(expected == Math::Sign(Decimal::Compare(d1, d2)));

	//	Assert::IsTrue(expected == Math::Sign(d1.CompareTo(d2)));
	//}
}

void DecimalTestDotNet::Divide()
{
	struct testcase_Divide
	{
		Decimal d1;
		Decimal d2;
		Decimal expected;

		testcase_Divide(Decimal d1, Decimal d2, Decimal expected)
		{
			this->d1 = d1;
			this->d2 = d2;
			this->expected = expected;
		}
	};
	std::vector<testcase_Divide> cass;
	cass.push_back(testcase_Divide(Decimal::One, Decimal::One, Decimal::One));
	cass.push_back(testcase_Divide(Decimal::MinusOne, Decimal::MinusOne, Decimal::One));
	cass.push_back(testcase_Divide(15, 2, 7.5));
	cass.push_back(testcase_Divide(10, 2, 5));
	cass.push_back(testcase_Divide(-10, -2, 5));
	cass.push_back(testcase_Divide(10, -2, -5));
	cass.push_back(testcase_Divide(-10, 2, -5));
	cass.push_back(testcase_Divide(Decimal::Parse("0.9214206543486529434634231456"), Decimal::MaxValue, Decimal::Zero));
	cass.push_back(testcase_Divide(Decimal::Parse("38214206543486529434634231456"), Decimal::Parse("0.49214206543486529434634231456"), Decimal::Parse("77648730371625094566866001277")));
	cass.push_back(testcase_Divide(Decimal::Parse("-78228162514264337593543950335"), Decimal::MaxValue, Decimal::Parse("-0.987378225516463811113412343")));

	cass.push_back(testcase_Divide(Decimal::MaxValue, Decimal::MinusOne, Decimal::MinValue));
	cass.push_back(testcase_Divide(Decimal::MinValue, Decimal::MaxValue, Decimal::MinusOne));
	cass.push_back(testcase_Divide(Decimal::MaxValue, Decimal::MaxValue, Decimal::One));
	cass.push_back(testcase_Divide(Decimal::MinValue, Decimal::MinValue, Decimal::One));

	// Tests near MaxValue
	cass.push_back(testcase_Divide(Decimal::Parse("792281625142643375935439503.4"), 0.1, Decimal::Parse("7922816251426433759354395034")));
	cass.push_back(testcase_Divide(Decimal::Parse("79228162514264337593543950.34"), 0.1, Decimal::Parse("792281625142643375935439503.4")));
	cass.push_back(testcase_Divide(Decimal::Parse("7922816251426433759354395.034"), 0.1, Decimal::Parse("79228162514264337593543950.34")));
	cass.push_back(testcase_Divide(Decimal::Parse("792281625142643375935439.5034"), 0.1, Decimal::Parse("7922816251426433759354395.034")));
	cass.push_back(testcase_Divide(Decimal::Parse("79228162514264337593543950335"), 10, Decimal::Parse("7922816251426433759354395033.5")));
	cass.push_back(testcase_Divide(Decimal::Parse("79228162514264337567774146561"), 10, Decimal::Parse("7922816251426433756777414656.1")));
	cass.push_back(testcase_Divide(Decimal::Parse("79228162514264337567774146560"), 10, Decimal::Parse("7922816251426433756777414656")));
	cass.push_back(testcase_Divide(Decimal::Parse("79228162514264337567774146559"), 10, Decimal::Parse("7922816251426433756777414655.9")));
	cass.push_back(testcase_Divide(Decimal::Parse("79228162514264337593543950335"), 1.1, Decimal::Parse("72025602285694852357767227577")));
	cass.push_back(testcase_Divide(Decimal::Parse("79228162514264337593543950335"), 1.01, Decimal::Parse("78443725261647859003508861718")));
	cass.push_back(testcase_Divide(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("1.001"), Decimal::Parse("79149013500763574019524425909.091")));
	cass.push_back(testcase_Divide(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("1.0001"), Decimal::Parse("79220240490215316061937756559.344")));
	cass.push_back(testcase_Divide(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("1.00001"), Decimal::Parse("79227370240561931974224208092.919")));
	cass.push_back(testcase_Divide(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("1.000001"), Decimal::Parse("79228083286181051412492537842.462")));
	cass.push_back(testcase_Divide(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("1.0000001"), Decimal::Parse("79228154591448878448656105469.389")));
	cass.push_back(testcase_Divide(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("1.00000001"), Decimal::Parse("79228161721982720373716746597.833")));
	cass.push_back(testcase_Divide(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("1.000000001"), Decimal::Parse("79228162435036175158507775176.492")));
	cass.push_back(testcase_Divide(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("1.0000000001"), Decimal::Parse("79228162506341521342909798200.709")));
	cass.push_back(testcase_Divide(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("1.00000000001"), Decimal::Parse("79228162513472055968409229775.316")));
	cass.push_back(testcase_Divide(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("1.000000000001"), Decimal::Parse("79228162514185109431029765225.569")));
	cass.push_back(testcase_Divide(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("1.0000000000001"), Decimal::Parse("79228162514256414777292524693.522")));
	cass.push_back(testcase_Divide(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("1.00000000000001"), Decimal::Parse("79228162514263545311918807699.547")));
	cass.push_back(testcase_Divide(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("1.000000000000001"), Decimal::Parse("79228162514264258365381436070.742")));
	cass.push_back(testcase_Divide(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("1.0000000000000001"), Decimal::Parse("79228162514264329670727698908.567")));
	cass.push_back(testcase_Divide(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("1.00000000000000001"), Decimal::Parse("79228162514264336801262325192.357")));
	cass.push_back(testcase_Divide(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("1.000000000000000001"), Decimal::Parse("79228162514264337514315787820.736")));
	cass.push_back(testcase_Divide(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("1.0000000000000000001"), Decimal::Parse("79228162514264337585621134083.574")));
	cass.push_back(testcase_Divide(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("1.00000000000000000001"), Decimal::Parse("79228162514264337592751668709.857")));
	cass.push_back(testcase_Divide(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("1.000000000000000000001"), Decimal::Parse("79228162514264337593464722172.486")));
	cass.push_back(testcase_Divide(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("1.0000000000000000000001"), Decimal::Parse("79228162514264337593536027518.749")));
	cass.push_back(testcase_Divide(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("1.00000000000000000000001"), Decimal::Parse("79228162514264337593543158053.375")));
	cass.push_back(testcase_Divide(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("1.000000000000000000000001"), Decimal::Parse("79228162514264337593543871106.837")));
	cass.push_back(testcase_Divide(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("1.0000000000000000000000001"), Decimal::Parse("79228162514264337593543942412.184")));
	cass.push_back(testcase_Divide(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("1.00000000000000000000000001"), Decimal::Parse("79228162514264337593543949542.718")));
	cass.push_back(testcase_Divide(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("1.000000000000000000000000001"), Decimal::Parse("79228162514264337593543950255.772")));
	cass.push_back(testcase_Divide(Decimal::Parse("7922816251426433759354395033.5"), Decimal::Parse("0.9999999999999999999999999999"), Decimal::Parse("7922816251426433759354395034")));
	cass.push_back(testcase_Divide(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("10000000"), Decimal::Parse("7922816251426433759354.3950335")));
	cass.push_back(testcase_Divide(Decimal::Parse("7922816251426433759354395033.5"), Decimal::Parse("1.000001"), Decimal::Parse("7922808328618105141249253784.2")));
	cass.push_back(testcase_Divide(Decimal::Parse("7922816251426433759354395033.5"), Decimal::Parse("1.0000000000000000000000000001"), Decimal::Parse("7922816251426433759354395032.7")));
	cass.push_back(testcase_Divide(Decimal::Parse("7922816251426433759354395033.5"), Decimal::Parse("1.0000000000000000000000000002"), Decimal::Parse("7922816251426433759354395031.9")));
	cass.push_back(testcase_Divide(Decimal::Parse("7922816251426433759354395033.5"), Decimal::Parse("0.9999999999999999999999999999"), Decimal::Parse("7922816251426433759354395034")));
	cass.push_back(testcase_Divide(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("1.0000000000000000000000000001"), Decimal::Parse("79228162514264337593543950327")));

	Decimal boundary7 = Decimal((int)429u, (int)2133437386u, 0, false, 0);
	Decimal boundary71 = Decimal((int)429u, (int)2133437387u, 0, false, 0);
	Decimal maxValueBy7 = Decimal::MaxValue * 0.0000001;
	cass.push_back(testcase_Divide(maxValueBy7, 1, maxValueBy7));
	cass.push_back(testcase_Divide(maxValueBy7, 1, maxValueBy7));
	cass.push_back(testcase_Divide(maxValueBy7, 0.0000001, Decimal::MaxValue));
	cass.push_back(testcase_Divide(boundary7, 1, boundary7));
	cass.push_back(testcase_Divide(boundary7, Decimal::Parse("0.000000100000000000000000001"), Decimal::Parse("91630438009337286849083695.62")));
	cass.push_back(testcase_Divide(boundary71, Decimal::Parse("0.000000100000000000000000001"), Decimal::Parse("91630438052286959809083695.62")));
	cass.push_back(testcase_Divide(Decimal::Parse("7922816251426433759354.3950335"), 1, Decimal::Parse("7922816251426433759354.3950335")));
	cass.push_back(testcase_Divide(Decimal::Parse("7922816251426433759354.3950335"), Decimal::Parse("0.0000001"), Decimal::Parse("79228162514264337593543950335")));


	for (size_t i = 0; i < cass.size(); ++i)
	{
		Decimal expected = cass.at(i).expected;
		Decimal d1 = cass.at(i).d1;
		Decimal d2 = cass.at(i).d2;
		Assert::IsTrue(expected == d1 / d2);
		Assert::IsTrue(expected == Decimal::Divide(d1, d2));
	}
}

void DecimalTestDotNet::Divide_ZeroDenominator_ThrowsDivideByZeroException()
{
	struct testcase_Throws
	{
		Decimal d1;
		Decimal d2;

		testcase_Throws(Decimal d1, Decimal d2)
		{
			this->d1 = d1;
			this->d2 = d2;
		}
	};

	std::vector<testcase_Throws> cass;
	cass.push_back(testcase_Throws(Decimal::One, Decimal::Zero));
	cass.push_back(testcase_Throws(Decimal::Zero, Decimal::Zero));
	cass.push_back(testcase_Throws(0.0, 0.0));

	for (size_t i = 0; i < cass.size(); ++i)
	{
		Decimal d1 = cass.at(i).d1;
		Decimal d2 = cass.at(i).d2;
		//Assert.Throws<DivideByZeroException>(()= > d1 / d2);
		//Assert.Throws<DivideByZeroException>(()= > Decimal::Divide(d1, d2));
	}
}

void DecimalTestDotNet::Divide_Overflows_ThrowsOverflowException()
{
	struct testcase_Throws
	{
		Decimal d1;
		Decimal d2;

		testcase_Throws(Decimal d1, Decimal d2)
		{
			this->d1 = d1;
			this->d2 = d2;
		}
	};

	std::vector<testcase_Throws> cass;
	cass.push_back(testcase_Throws(Decimal::One, Decimal::Zero));
	cass.push_back(testcase_Throws(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("-0.9999999999999999999999999")));
	cass.push_back(testcase_Throws(Decimal::Parse("792281625142643.37593543950335"), Decimal::Parse(" -0.0000000000000079228162514264337593543950335")));
	cass.push_back(testcase_Throws(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("0.1")));
	cass.push_back(testcase_Throws(Decimal::Parse("7922816251426433759354395034"), Decimal::Parse("0.1")));
	cass.push_back(testcase_Throws(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("0.9")));
	cass.push_back(testcase_Throws(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("0.99")));
	cass.push_back(testcase_Throws(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("0.9999")));
	cass.push_back(testcase_Throws(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("0.99999")));
	cass.push_back(testcase_Throws(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("0.999999")));
	cass.push_back(testcase_Throws(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("0.9999999")));
	cass.push_back(testcase_Throws(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("0.99999999")));
	cass.push_back(testcase_Throws(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("0.999999999")));
	cass.push_back(testcase_Throws(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("0.9999999999")));
	cass.push_back(testcase_Throws(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("0.99999999999")));
	cass.push_back(testcase_Throws(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("0.999999999999")));
	cass.push_back(testcase_Throws(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("0.9999999999999")));
	cass.push_back(testcase_Throws(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("0.99999999999999")));
	cass.push_back(testcase_Throws(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("0.9999999999999999")));
	cass.push_back(testcase_Throws(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("0.99999999999999999")));
	cass.push_back(testcase_Throws(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("0.99999999999999999999")));
	cass.push_back(testcase_Throws(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("0.9999999999999999999999")));
	cass.push_back(testcase_Throws(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("0.99999999999999999999999")));
	cass.push_back(testcase_Throws(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("0.999999999999999999999999")));
	cass.push_back(testcase_Throws(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("0.9999999999999999999999999")));
	cass.push_back(testcase_Throws(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("0.999999999999999999999999999")));
	cass.push_back(testcase_Throws(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("0.9999999999999999999999999999")));
	cass.push_back(testcase_Throws(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("-0.1")));
	cass.push_back(testcase_Throws(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("-0.9999999999999999999999999")));
	cass.push_back(testcase_Throws(Decimal::MaxValue / 2, 0.5));

	for (size_t i = 0; i < cass.size(); ++i)
	{
		Decimal d1 = cass.at(i).d1;
		Decimal d2 = cass.at(i).d2;
		//Assert.Throws<OverflowException>(()= > d1 / d2);
		//Assert.Throws<OverflowException>(()= > decimal.Divide(d1, d2));
	}
}

void DecimalTestDotNet::EqualsTest()
{
	struct testcase_EqualsTest
	{
		Decimal d1;
		Decimal d2;
		bool expected;

		testcase_EqualsTest(Decimal d1, Decimal d2, bool expected)
		{
			this->d1 = d1;
			this->d2 = d2;
			this->expected = expected;
		}
	};
	std::vector<testcase_EqualsTest> cass;
	cass.push_back(testcase_EqualsTest(Decimal::Zero, Decimal::Zero, true));
	cass.push_back(testcase_EqualsTest(Decimal::Zero, Decimal::One, false));
	cass.push_back(testcase_EqualsTest(Decimal::MaxValue, Decimal::MaxValue, true));
	cass.push_back(testcase_EqualsTest(Decimal::MinValue, Decimal::MinValue, true));
	cass.push_back(testcase_EqualsTest(Decimal::MaxValue, Decimal::MinValue, false));


	for (size_t i = 0; i < cass.size(); ++i)
	{
		Decimal d1 = cass.at(i).d1;
		Decimal d2 = cass.at(i).d2;
		bool expected = cass.at(i).expected;
		bool e_1 = d1.Equals(d2);

		Assert::IsTrue(expected == e_1);
		Assert::IsTrue(expected == Decimal::Equals(d1, d2));
		Assert::IsTrue(expected == (d1 == d2));
		Assert::IsTrue(!expected == (d1 != d2));
		Assert::IsTrue(expected == (d1.GetHashCode() == d2.GetHashCode()));

		Assert::IsTrue(d1.Equals(d1));
		Assert::IsTrue(d1 == d1);
		Assert::IsFalse(d1 != d1);
		Assert::IsTrue(d1.GetHashCode() == d1.GetHashCode());

		//Assert::IsTrue(expected == Decimal::Equals(obj1, obj2));
	}
}

void DecimalTestDotNet::FromOACurrency()
{
	struct testcase_OACurrency
	{
		Int64 oac;
		Decimal expected;

		testcase_OACurrency(Int64 oac, Decimal expected)
		{
			this->oac = oac;
			this->expected = expected;
		}
	};

	std::vector<testcase_OACurrency> cass;
	cass.push_back(testcase_OACurrency(0L, Decimal::Parse("0")));
	cass.push_back(testcase_OACurrency(1L, Decimal::Parse("0.0001")));
	cass.push_back(testcase_OACurrency(100000L, Decimal::Parse("10")));
	cass.push_back(testcase_OACurrency(10000000000L, Decimal::Parse("1000000")));
	cass.push_back(testcase_OACurrency(1000000000000000000L, Decimal::Parse("100000000000000")));
	cass.push_back(testcase_OACurrency(9223372036854775807LL, Decimal::Parse("922337203685477.5807")));
	cass.push_back(testcase_OACurrency(-9223372036854775808LL, Decimal::Parse("-922337203685477.5808")));
	cass.push_back(testcase_OACurrency(123456789L, Decimal::Parse("12345.6789")));
	cass.push_back(testcase_OACurrency(1234567890000L, Decimal::Parse("123456789")));
	cass.push_back(testcase_OACurrency(1234567890987654321L, Decimal::Parse("123456789098765.4321")));
	cass.push_back(testcase_OACurrency(4294967295L, Decimal::Parse("429496.7295")));

	for (size_t i = 0; i < cass.size(); ++i)
	{
		Int64 oac = cass.at(i).oac;
		Decimal expected = cass.at(i).expected;
		Assert::IsTrue(expected == Decimal::FromOACurrency(oac));
	}
}

void DecimalTestDotNet::Floor()
{
	struct testcase_Floor
	{
		Decimal d;
		Decimal expected;

		testcase_Floor(Decimal d, Decimal expected)
		{
			this->d = d;
			this->expected = expected;
		}
	};

	std::vector<testcase_Floor> cass;
	cass.push_back(testcase_Floor(123, 123));
	cass.push_back(testcase_Floor(123.123, 123));
	cass.push_back(testcase_Floor(123.456, 123));
	cass.push_back(testcase_Floor(-123.123, -124));
	cass.push_back(testcase_Floor(-123.456, -124));

	for (size_t i = 0; i < cass.size(); ++i)
	{
		Decimal d = cass.at(i).d;
		Decimal expected = cass.at(i).expected;
		Assert::IsTrue(expected == Decimal::Floor(d));
	}
}

void DecimalTestDotNet::GetBits()
{
	struct testcase_Bits
	{
		Decimal value;
		int bits[4];

		testcase_Bits(Decimal v, int i_0, int i_1, int i_2, int i_3)
		{
			value = v;
			bits[0] = i_0;
			bits[1] = i_1;
			bits[2] = i_2;
			bits[3] = i_3;
		}
	};

	std::vector<testcase_Bits> cass;
	cass.push_back(testcase_Bits(Decimal::Parse("1"), 0x00000001, 0x00000000, 0x00000000, 0x00000000));
	cass.push_back(testcase_Bits(Decimal::Parse("100000000000000"), 0x107A4000, 0x00005AF3, 0x00000000, 0x00000000));
	cass.push_back(testcase_Bits(Decimal::Parse("100000000000000.00000000000000"), 0x10000000, 0x3E250261, 0x204FCE5E, 0x000E0000));
	cass.push_back(testcase_Bits(Decimal::Parse("1.0000000000000000000000000000"), 0x10000000, 0x3E250261, 0x204FCE5E, 0x001C0000));
	cass.push_back(testcase_Bits(Decimal::Parse("123456789"), 0x075BCD15, 0x00000000, 0x00000000, 0x00000000));
	cass.push_back(testcase_Bits(Decimal::Parse("0.123456789"), 0x075BCD15, 0x00000000, 0x00000000, 0x00090000));
	cass.push_back(testcase_Bits(Decimal::Parse("0.000000000123456789"), 0x075BCD15, 0x00000000, 0x00000000, 0x00120000));
	cass.push_back(testcase_Bits(Decimal::Parse("0.000000000000000000123456789"), 0x075BCD15, 0x00000000, 0x00000000, 0x001B0000));
	cass.push_back(testcase_Bits(Decimal::Parse("4294967295"), ((int)0xFFFFFFFF), 0x00000000, 0x00000000, 0x00000000));
	cass.push_back(testcase_Bits(Decimal::Parse("18446744073709551615"), ((int)0xFFFFFFFF), ((int)0xFFFFFFFF), 0x00000000, 0x00000000));
	cass.push_back(testcase_Bits(Decimal::MaxValue, ((int)0xFFFFFFFF), ((int)0xFFFFFFFF), ((int)0xFFFFFFFF), 0x00000000));
	cass.push_back(testcase_Bits(Decimal::MinValue, ((int)0xFFFFFFFF), ((int)0xFFFFFFFF), ((int)0xFFFFFFFF), ((int)0x80000000)));
	cass.push_back(testcase_Bits(Decimal::Parse("-7.9228162514264337593543950335"), ((int)0xFFFFFFFF), ((int)0xFFFFFFFF), ((int)0xFFFFFFFF), ((int)0x801C0000)));

	for (size_t i = 0; i < cass.size(); ++i)
	{
		Decimal input = cass.at(i).value;
		auto expected = cass.at(i).bits;
		auto bits = Decimal::GetBits(input);

		Assert::IsTrue(expected[0] == bits[0]);
		Assert::IsTrue(expected[1] == bits[1]);
		Assert::IsTrue(expected[2] == bits[2]);
		Assert::IsTrue(expected[3] == bits[3]);

		bool sign = (bits[3] & 0x80000000) != 0;
		byte scale = (byte)((bits[3] >> 16) & 0x7F);
		Decimal newValue = Decimal(bits[0], bits[1], bits[2], sign, scale);

		Assert::IsTrue(input == newValue);
	}
}

void DecimalTestDotNet::Multiply()
{
	struct testcase_Multiply
	{
		Decimal d1;
		Decimal d2;
		Decimal expected;

		testcase_Multiply(Decimal d1, Decimal d2, Decimal expected)
		{
			this->d1 = d1;
			this->d2 = d2;
			this->expected = expected;
		}
	};
	std::vector<testcase_Multiply> cass;
	cass.push_back(testcase_Multiply(Decimal::One, Decimal::One, Decimal::One));
	cass.push_back(testcase_Multiply(Decimal::Parse("7922816251426433759354395033.5"), Decimal(10), Decimal::MaxValue));
	cass.push_back(testcase_Multiply(Decimal::Parse("0.2352523523423422342354395033"), Decimal::Parse("56033525474612414574574757495"), Decimal::Parse("13182018677937129120135020796")));
	cass.push_back(testcase_Multiply(Decimal::Parse("46161363632634613634.093453337"), Decimal::Parse("461613636.32634613634083453337"), Decimal::Parse("21308714924243214928823669051")));
	cass.push_back(testcase_Multiply(Decimal::Parse("0.0000000000000345435353453563"), Decimal::Parse(".0000000000000023525235234234"), Decimal::Parse("0.0000000000000000000000000001")));

	// Near Decimal::MaxValue
	cass.push_back(testcase_Multiply(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("0.9"), Decimal::Parse("71305346262837903834189555302")));
	cass.push_back(testcase_Multiply(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("0.99"), Decimal::Parse("78435880889121694217608510832")));
	cass.push_back(testcase_Multiply(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("0.9999999999999999999999999999"), Decimal::Parse("79228162514264337593543950327")));
	cass.push_back(testcase_Multiply(Decimal::Parse("-79228162514264337593543950335"), Decimal::Parse("0.9"), Decimal::Parse("-71305346262837903834189555302")));
	cass.push_back(testcase_Multiply(Decimal::Parse("-79228162514264337593543950335"), Decimal::Parse("0.99"), Decimal::Parse("-78435880889121694217608510832")));
	cass.push_back(testcase_Multiply(Decimal::Parse("-79228162514264337593543950335"), Decimal::Parse("0.9999999999999999999999999999"), Decimal::Parse("-79228162514264337593543950327")));

	for (size_t i = 0; i < cass.size(); ++i)
	{
		Decimal expected = cass.at(i).expected;
		Decimal d1 = cass.at(i).d1;
		Decimal d2 = cass.at(i).d2;

		Assert::IsTrue(expected == d1 * d2);
		Assert::IsTrue(expected == Decimal::Multiply(d1, d2));
	}
}

void DecimalTestDotNet::Multiply_Invalid()
{
	struct testcase_Invalid
	{
		Decimal d1;
		Decimal d2;

		testcase_Invalid(Decimal d1, Decimal d2)
		{
			this->d1 = d1;
			this->d2 = d2;
		}
	};
	std::vector<testcase_Invalid> cass;
	cass.push_back(testcase_Invalid(Decimal::MaxValue, Decimal::MinValue));
	cass.push_back(testcase_Invalid(Decimal::MinValue, 1.1));
	cass.push_back(testcase_Invalid(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("1.1")));
	cass.push_back(testcase_Invalid(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("1.01")));
	cass.push_back(testcase_Invalid(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("1.001")));
	cass.push_back(testcase_Invalid(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("1.0001")));
	cass.push_back(testcase_Invalid(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("1.00001")));
	cass.push_back(testcase_Invalid(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("1.000001")));
	cass.push_back(testcase_Invalid(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("1.0000001")));
	cass.push_back(testcase_Invalid(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("1.00000001")));
	cass.push_back(testcase_Invalid(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("1.000000001")));
	cass.push_back(testcase_Invalid(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("1.0000000001")));
	cass.push_back(testcase_Invalid(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("1.00000000001")));
	cass.push_back(testcase_Invalid(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("1.000000000001")));
	cass.push_back(testcase_Invalid(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("1.0000000000001")));
	cass.push_back(testcase_Invalid(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("1.00000000000001")));
	cass.push_back(testcase_Invalid(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("1.000000000000001")));
	cass.push_back(testcase_Invalid(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("1.0000000000000001")));
	cass.push_back(testcase_Invalid(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("1.00000000000000001")));
	cass.push_back(testcase_Invalid(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("1.000000000000000001")));
	cass.push_back(testcase_Invalid(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("1.0000000000000000001")));
	cass.push_back(testcase_Invalid(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("1.00000000000000000001")));
	cass.push_back(testcase_Invalid(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("1.000000000000000000001")));
	cass.push_back(testcase_Invalid(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("1.0000000000000000000001")));
	cass.push_back(testcase_Invalid(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("1.00000000000000000000001")));
	cass.push_back(testcase_Invalid(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("1.000000000000000000000001")));
	cass.push_back(testcase_Invalid(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("1.0000000000000000000000001")));
	cass.push_back(testcase_Invalid(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("1.00000000000000000000000001")));
	cass.push_back(testcase_Invalid(Decimal::Parse("79228162514264337593543950335"), Decimal::Parse("1.000000000000000000000000001")));
	cass.push_back(testcase_Invalid(Decimal::MaxValue / 2, 2));

	for (size_t i = 0; i < cass.size(); ++i)
	{
		Decimal d1 = cass.at(i).d1;
		Decimal d2 = cass.at(i).d2;
		//Assert.Throws<OverflowException>(()= > d1 * d2);
		//Assert.Throws<OverflowException>(()= > Decimal::Multiply(d1, d2));
	}
}

void DecimalTestDotNet::Negate()
{
	struct testcase_Negate
	{
		Decimal d;
		Decimal expected;

		testcase_Negate(Decimal d, Decimal expected)
		{
			this->d = d;
			this->expected = expected;
		}
	};
	std::vector<testcase_Negate> cass;
	cass.push_back(testcase_Negate(Decimal::MaxValue, Decimal::MinValue));
	cass.push_back(testcase_Negate(1, -1));
	cass.push_back(testcase_Negate(0, 0));
	cass.push_back(testcase_Negate(-1, 1));
	cass.push_back(testcase_Negate(Decimal::MaxValue, Decimal::MinValue));
	cass.push_back(testcase_Negate(Decimal::MinValue, Decimal::MaxValue));

	for (size_t i = 0; i < cass.size(); ++i)
	{
		Decimal d = cass.at(i).d;
		Decimal expected = cass.at(i).expected;
		Assert::IsTrue(expected == Decimal::Negate(d));
	}
}

void DecimalTestDotNet::Parse()
{
	//struct testcase_Parse
	//{
	//	std::string value;
	//	NumberStyles style;
	//	NumberFormatInfo* provider;
	//	Decimal expected;

	//	testcase_Parse(std::string value, NumberStyles style, NumberFormatInfo* provider, Decimal expected)
	//	{
	//		this->value = value;
	//		this->style = style;
	//		this->provider = provider;
	//		this->expected = expected;
	//	}
	//};

	//NumberStyles defaultStyle = NumberStyles::Number;
	//NumberFormatInfo* invariantFormat = NumberFormatInfo::InvariantInfo;

	//NumberFormatInfo* emptyFormat = NumberFormatInfo::CurrentInfo;

	//NumberFormatInfo* customFormat1 = new NumberFormatInfo();
	//customFormat1->CurrencySymbol = "$";
	//customFormat1->CurrencyGroupSeparator = ",";

	//NumberFormatInfo* customFormat2 = new NumberFormatInfo();
	//customFormat2->NumberDecimalSeparator = ".";

	//NumberFormatInfo customFormat3 = NumberFormatInfo();
	//customFormat3.NumberGroupSeparator = ",";

	//NumberFormatInfo customFormat4 = NumberFormatInfo();
	//customFormat4.NumberDecimalSeparator = ".";

	//std::vector<testcase_Parse> cass;
	//cass.push_back(testcase_Parse("-123", defaultStyle, null, -123m));
	//cass.push_back(testcase_Parse("0", defaultStyle, null, 0m));
	//cass.push_back(testcase_Parse("123", defaultStyle, null, 123m));
	//cass.push_back(testcase_Parse("  123  ", defaultStyle, null, 123m));
	//cass.push_back(testcase_Parse((567.89m).ToString(), defaultStyle, null, 567.89m));
	//cass.push_back(testcase_Parse((-567.89m).ToString(), defaultStyle, null, -567.89m));
	//cass.push_back(testcase_Parse("0.6666666666666666666666666666500000000000000000000000000000000000000000000000000000000000000", defaultStyle, invariantFormat, 0.6666666666666666666666666666m));

	//cass.push_back(testcase_Parse(emptyFormat.NumberDecimalSeparator + "234", defaultStyle, null, 0.234m));
	//cass.push_back(testcase_Parse("234" + emptyFormat.NumberDecimalSeparator, defaultStyle, null, 234.0m));
	//cass.push_back(testcase_Parse("7" + new string('0', 28) + emptyFormat.NumberDecimalSeparator, defaultStyle, null, 7E28m));
	//cass.push_back(testcase_Parse("07" + new string('0', 28) + emptyFormat.NumberDecimalSeparator, defaultStyle, null, 7E28m));

	//cass.push_back(testcase_Parse("79228162514264337593543950335", defaultStyle, null, 79228162514264337593543950335m));
	//cass.push_back(testcase_Parse("-79228162514264337593543950335", defaultStyle, null, -79228162514264337593543950335m));
	//cass.push_back(testcase_Parse("79,228,162,514,264,337,593,543,950,335", NumberStyles::AllowThousands, customFormat3, 79228162514264337593543950335m));

	//cass.push_back(testcase_Parse((123.1m).ToString(), NumberStyles::AllowDecimalPoint, null, 123.1));
	//cass.push_back(testcase_Parse(1000.ToString("N0"), NumberStyles::AllowThousands, null, 1000));

	//cass.push_back(testcase_Parse("123", NumberStyles::Any, emptyFormat, 123));
	//cass.push_back(testcase_Parse(std::to_string((123.567)), NumberStyles::Any, emptyFormat, 123.567));
	//cass.push_back(testcase_Parse("123", NumberStyles::Float, emptyFormat, 123));
	//cass.push_back(testcase_Parse("$1000", NumberStyles::Currency, customFormat1, 1000));
	//cass.push_back(testcase_Parse("123.123", NumberStyles::Float, customFormat2, 123.123));
	//cass.push_back(testcase_Parse("(123)", NumberStyles::AllowParentheses, customFormat2, -123));

	//// Number buffer limit ran out (string too long)
	//cass.push_back(testcase_Parse("1234567890123456789012345.678456", defaultStyle, customFormat4, 1234567890123456789012345.6785m));

	//for (int i = 0; i < cass.size(); ++i)
	//{
	//	bool isDefaultProvider = provider == null || provider == NumberFormatInfo.CurrentInfo;
	//	decimal result;
	//	if ((style & ~NumberStyles::Number) == 0 && style != NumberStyles::None)
	//	{
	//		// Use Parse(string) or Parse(string, IFormatProvider)
	//		if (isDefaultProvider)
	//		{
	//			Assert::IsTrue(decimal.TryParse(value, out result));
	//			Assert::IsTrue(expected, result);

	//			Assert::IsTrue(expected, decimal.Parse(value));
	//		}

	//		Assert::IsTrue(expected, decimal.Parse(value, provider));
	//	}

	//	// Use Parse(string, NumberStyles, IFormatProvider)
	//	Assert::IsTrue(decimal.TryParse(value, style, provider, out result));
	//	Assert::IsTrue(expected, result);

	//	Assert::IsTrue(expected, decimal.Parse(value, style, provider));

	//	if (isDefaultProvider)
	//	{
	//		// Use Parse(string, NumberStyles) or Parse(string, NumberStyles, IFormatProvider)
	//		Assert::IsTrue(decimal.TryParse(value, style, NumberFormatInfo.CurrentInfo, out result));
	//		Assert::IsTrue(expected, result);

	//		Assert::IsTrue(expected, decimal.Parse(value, style));
	//		Assert::IsTrue(expected, decimal.Parse(value, style, NumberFormatInfo.CurrentInfo));
	//	}
	//}
}

void DecimalTestDotNet::Parse_Invalid()
{
	//struct testcase_Parse
	//{
	//	std::string value;
	//	NumberStyles style;
	//	NumberFormatInfo* provider;
	//	Decimal expected;

	//	testcase_Parse(std::string value, NumberStyles style, NumberFormatInfo* provider, Decimal expected)
	//	{
	//		this->value = value;
	//		this->style = style;
	//		this->provider = provider;
	//		this->expected = expected;
	//	}
	//};


	//NumberStyles defaultStyle = NumberStyles::Number;

	//NumberFormatInfo customFormat = NumberFormatInfo();
	//customFormat.CurrencySymbol = "$";
	//customFormat.NumberDecimalSeparator = ".";

	//std::vector<testcase_Parse> cass;
	//cass.push_back(testcase_Parse("-123", defaultStyle, null, -123m));
	//cass.push_back(testcase_Parse(null, defaultStyle, null, typeof(ArgumentNullException)));
	//cass.push_back(testcase_Parse("79228162514264337593543950336", defaultStyle, null, typeof(OverflowException)));
	//cass.push_back(testcase_Parse("", defaultStyle, null, typeof(FormatException)));
	//cass.push_back(testcase_Parse(" ", defaultStyle, null, typeof(FormatException)));
	//cass.push_back(testcase_Parse("Garbage", defaultStyle, null, typeof(FormatException)));

	//cass.push_back(testcase_Parse("ab", defaultStyle, null, typeof(FormatException))); // Hex value
	//cass.push_back(testcase_Parse("(123)", defaultStyle, null, typeof(FormatException))); // Parentheses
	//cass.push_back(testcase_Parse(100.ToString("C0"), defaultStyle, null, typeof(FormatException))); // Currency

	//cass.push_back(testcase_Parse((123.456m).ToString(), NumberStyles::Integer, null, typeof(FormatException))); // Decimal
	//cass.push_back(testcase_Parse("  " + (123.456m).ToString(), NumberStyles::None, null, typeof(FormatException))); // Leading space
	//cass.push_back(testcase_Parse((123.456m).ToString() + "   ", NumberStyles::None, null, typeof(FormatException))); // Leading space
	//cass.push_back(testcase_Parse("1E23", NumberStyles::None, null, typeof(FormatException))); // Exponent

	//cass.push_back(testcase_Parse("ab", NumberStyles::None, null, typeof(FormatException))); // Hex value
	//cass.push_back(testcase_Parse("  123  ", NumberStyles::None, null, typeof(FormatException))); // Trailing and leading whitespace


	//for (int i = 0; i < cass.size(); ++i)
	//{
	//	bool isDefaultProvider = provider == null || provider == NumberFormatInfo.CurrentInfo;
	//	decimal result;
	//	if ((style & ~NumberStyles::Number) == 0 && style != NumberStyles::None &&
	//		(style & NumberStyles::AllowLeadingWhite) == (style & NumberStyles::AllowTrailingWhite))
	//	{
	//		// Use Parse(string) or Parse(string, IFormatProvider)
	//		if (isDefaultProvider)
	//		{
	//			Assert::IsFalse(decimal.TryParse(value, out result));
	//			Assert::IsTrue(default(decimal), result);

	//			Assert.Throws(exceptionType, ()= > decimal.Parse(value));
	//		}

	//		Assert.Throws(exceptionType, ()= > decimal.Parse(value, provider));
	//	}

	//	// Use Parse(string, NumberStyles, IFormatProvider)
	//	Assert::IsFalse(decimal.TryParse(value, style, provider, out result));
	//	Assert::IsTrue(default(decimal), result);

	//	Assert.Throws(exceptionType, ()= > decimal.Parse(value, style, provider));

	//	if (isDefaultProvider)
	//	{
	//		// Use Parse(string, NumberStyles) or Parse(string, NumberStyles, IFormatProvider)
	//		Assert::IsFalse(decimal.TryParse(value, style, NumberFormatInfo.CurrentInfo, out result));
	//		Assert::IsTrue(default(decimal), result);

	//		Assert.Throws(exceptionType, ()= > decimal.Parse(value, style));
	//		Assert.Throws(exceptionType, ()= > decimal.Parse(value, style, NumberFormatInfo.CurrentInfo));
	//	}
	//}
}

void DecimalTestDotNet::Remainder()
{
	struct testcase_Remainder
	{
		Decimal d1;
		Decimal d2;
		Decimal expected;

		testcase_Remainder(Decimal d1, Decimal d2, Decimal expected)
		{
			this->d1 = d1;
			this->d2 = d2;
			this->expected = expected;
		}
	};

	std::vector<testcase_Remainder> cass;
	Decimal NegativeZero = Decimal(0, 0, 0, true, 0);
	cass.push_back(testcase_Remainder(5, 3, 2));
	cass.push_back(testcase_Remainder(5, -3, 2));
	cass.push_back(testcase_Remainder(-5, 3, -2));
	cass.push_back(testcase_Remainder(-5, -3, -2));
	cass.push_back(testcase_Remainder(3, 5, 3));
	cass.push_back(testcase_Remainder(3, -5, 3));
	cass.push_back(testcase_Remainder(-3, 5, -3));
	cass.push_back(testcase_Remainder(-3, -5, -3));
	cass.push_back(testcase_Remainder(10, -3, 1));
	cass.push_back(testcase_Remainder(-10, 3, -1));
	cass.push_back(testcase_Remainder(-2.0, 0.5, -0.0));
	cass.push_back(testcase_Remainder(2.3, 0.531, 0.176));
	cass.push_back(testcase_Remainder(0.00123, 3242, 0.00123));
	cass.push_back(testcase_Remainder(3242, 0.00123, 0.00044));
	cass.push_back(testcase_Remainder(17.3, 3, 2.3));
	cass.push_back(testcase_Remainder(8.55, 2.25, 1.80));
	cass.push_back(testcase_Remainder(0.00, 3, 0.00));
	cass.push_back(testcase_Remainder(NegativeZero, 2.2, NegativeZero));

	// Max/Min
	cass.push_back(testcase_Remainder(Decimal::MaxValue, Decimal::MaxValue, 0));
	cass.push_back(testcase_Remainder(Decimal::MaxValue, Decimal::MinValue, 0));
	cass.push_back(testcase_Remainder(Decimal::MaxValue, 1, 0));
	cass.push_back(testcase_Remainder(Decimal::MaxValue, 2394713, 1494647));
	cass.push_back(testcase_Remainder(Decimal::MaxValue, -32768, 32767));
	cass.push_back(testcase_Remainder(-0.00, Decimal::MaxValue, -0.00));
	cass.push_back(testcase_Remainder(1.23984, Decimal::MaxValue, 1.23984));
	cass.push_back(testcase_Remainder(2398412.12983, Decimal::MaxValue, 2398412.12983));
	cass.push_back(testcase_Remainder(-0.12938, Decimal::MaxValue, -0.12938));

	cass.push_back(testcase_Remainder(Decimal::MinValue, Decimal::MinValue, NegativeZero));
	cass.push_back(testcase_Remainder(Decimal::MinValue, Decimal::MaxValue, NegativeZero));
	cass.push_back(testcase_Remainder(Decimal::MinValue, 1, NegativeZero));
	cass.push_back(testcase_Remainder(Decimal::MinValue, 2394713, -1494647));
	cass.push_back(testcase_Remainder(Decimal::MinValue, -32768, -32767));
	cass.push_back(testcase_Remainder(0.0, Decimal::MinValue, 0.0));
	cass.push_back(testcase_Remainder(1.23984, Decimal::MinValue, 1.23984));
	cass.push_back(testcase_Remainder(2398412.12983, Decimal::MinValue, 2398412.12983));
	cass.push_back(testcase_Remainder(-0.12938, Decimal::MinValue, -0.12938));

	cass.push_back(testcase_Remainder(Decimal::Parse("57675350989891243676868034225"), 7, 5));
	cass.push_back(testcase_Remainder(Decimal::Parse("-57675350989891243676868034225"), 7, -5));
	cass.push_back(testcase_Remainder(Decimal::Parse("57675350989891243676868034225"), -7, 5));
	cass.push_back(testcase_Remainder(Decimal::Parse("-57675350989891243676868034225"), -7, -5));

	cass.push_back(testcase_Remainder(Decimal::Parse("792281625142643375935439503.4"), 0.1, 0.0));
	cass.push_back(testcase_Remainder(Decimal::Parse("79228162514264337593543950.34"), 0.1, 0.04));
	cass.push_back(testcase_Remainder(Decimal::Parse("7922816251426433759354395.034"), 0.1, 0.034));
	cass.push_back(testcase_Remainder(Decimal::Parse("792281625142643375935439.5034"), 0.1, 0.0034));
	cass.push_back(testcase_Remainder(Decimal::Parse("79228162514264337593543950335"), 10, 5));
	cass.push_back(testcase_Remainder(Decimal::Parse("79228162514264337567774146561"), 10, 1));
	cass.push_back(testcase_Remainder(Decimal::Parse("79228162514264337567774146560"), 10, 0));
	cass.push_back(testcase_Remainder(Decimal::Parse("79228162514264337567774146559"), 10, 9));

	for (size_t i = 0; i < cass.size(); ++i)
	{
		Decimal d1 = cass.at(i).d1;
		Decimal d2 = cass.at(i).d2;
		Decimal expected = cass.at(i).expected;
		auto text_1 = d1.ToString();
		auto text_2 = d2.ToString();
		auto text_3 = expected.ToString();
		Decimal result1 = d1 % d2;
		Decimal result2 = Decimal::Remainder(d1, d2);
		auto text_4 = result1.ToString();
		auto text_5 = result2.ToString();


		Assert::IsTrue(expected == result1);
		Assert::IsTrue(expected == result2);
	}
}

void DecimalTestDotNet::RemainderV2()
{
	struct testcase_Remainder
	{
		Decimal d1;
		Decimal d2;
		Decimal expected;

		testcase_Remainder(Decimal d1, Decimal d2, Decimal expected)
		{
			this->d1 = d1;
			this->d2 = d2;
			this->expected = expected;
		}
	};
	std::vector<testcase_Remainder> cass;

	cass.push_back(testcase_Remainder(Decimal::MaxValue, 0.1, 0.0));
	cass.push_back(testcase_Remainder(Decimal::MaxValue, Decimal::Parse("7.081881059"), Decimal::Parse("3.702941036")));
	cass.push_back(testcase_Remainder(Decimal::MaxValue, Decimal::Parse("2004094637636.6280382536104438"), Decimal::Parse("1980741879937.1051521151154118")));
	cass.push_back(testcase_Remainder(Decimal::MaxValue, Decimal(0, 0, 1, false, 28), Decimal::Parse("0.0000000013968756053316206592")));
	cass.push_back(testcase_Remainder(Decimal::MaxValue, Decimal(0, 1, 0, false, 28), Decimal::Parse("0.0000000000000000004026531840")));
	cass.push_back(testcase_Remainder(Decimal::MaxValue, Decimal(1, 0, 0, false, 28), Decimal::Parse("0.0000000000000000000000000000")));
	cass.push_back(testcase_Remainder(Decimal::Parse("5"), Decimal::Parse("0.0000000000000000000000000003"), Decimal::Parse("0.0000000000000000000000000002")));
	cass.push_back(testcase_Remainder(Decimal::Parse("5.94499443"), Decimal::Parse("0.0000000000000000000000000007"), Decimal::Parse("0.0000000000000000000000000005")));
	cass.push_back(testcase_Remainder(Decimal::Parse("1667"), Decimal::Parse("325.66574961026426932314500573"), Decimal::Parse("38.67125194867865338427497135")));
	cass.push_back(testcase_Remainder(Decimal::Parse("1667"), Decimal::Parse("0.00000000013630700224712809"), Decimal::Parse("0.00000000002527942770321278")));
	cass.push_back(testcase_Remainder(Decimal::Parse("60596869520933069.9"), Decimal::Parse("8063773.1275438997671"), Decimal::Parse("5700076.9722872002614")));

	for (size_t i = 0; i < cass.size(); ++i)
	{
		Decimal d1 = cass.at(i).d1;
		Decimal d2 = cass.at(i).d2;
		Decimal expected = cass.at(i).expected;
		auto text_1 = d1.ToString();
		auto text_2 = d2.ToString();
		auto text_3 = expected.ToString();
		Decimal result1 = d1 % d2;
		Decimal result2 = Decimal::Remainder(d1, d2);
		auto text_4 = result1.ToString();
		auto text_5 = result2.ToString();


		Assert::IsTrue(expected == result1);
		Assert::IsTrue(expected == result2);
	}
}

void DecimalTestDotNet::Remainder_ZeroDenominator_ThrowsDivideByZeroException()
{
	//Assert.Throws<DivideByZeroException>(()= > d1 % d2);
	//Assert.Throws<DivideByZeroException>(()= > decimal.Remainder(d1, d2));
}

void DecimalTestDotNet::Round()
{
	struct testcase_Round
	{
		Decimal d1;
		Decimal expected;

		testcase_Round(Decimal d1, Decimal expected)
		{
			this->d1 = d1;
			this->expected = expected;
		}
	};
	std::vector<testcase_Round> cass;
	cass.push_back(testcase_Round(0, 0));
	cass.push_back(testcase_Round(0.1, 0));
	cass.push_back(testcase_Round(0.5, 0));
	cass.push_back(testcase_Round(0.7, 1));
	cass.push_back(testcase_Round(1.3, 1));
	cass.push_back(testcase_Round(1.5, 2));
	cass.push_back(testcase_Round(-0.1, 0));
	cass.push_back(testcase_Round(-0.5, 0));
	cass.push_back(testcase_Round(-0.7, -1));
	cass.push_back(testcase_Round(-1.3, -1));
	cass.push_back(testcase_Round(-1.5, -2));

	for (size_t i = 0; i < cass.size(); ++i)
	{
		Decimal d1 = cass.at(i).d1;
		Decimal expected = cass.at(i).expected;
		Decimal round = Decimal::Round(d1);


		auto text_1 = d1.ToString();
		auto text_2 = expected.ToString();
		auto text_3 = round.ToString();

		Assert::IsTrue(expected == round);
	}
}

void DecimalTestDotNet::Round_Digits_ReturnsExpected()
{
	struct testcase_Digits
	{
		Decimal d1;
		int digits;
		Decimal expected;

		testcase_Digits(Decimal d1, int digits, Decimal expected)
		{
			this->d1 = d1;
			this->digits = digits;
			this->expected = expected;
		}
	};
	std::vector<testcase_Digits> cass;
	cass.push_back(testcase_Digits(1.45, 1, 1.4));
	cass.push_back(testcase_Digits(1.55, 1, 1.6));
	cass.push_back(testcase_Digits(123.456789, 4, 123.4568));
	cass.push_back(testcase_Digits(123.456789, 6, 123.456789));
	cass.push_back(testcase_Digits(123.456789, 8, 123.456789));
	cass.push_back(testcase_Digits(-123.456, 0, -123));
	cass.push_back(testcase_Digits(-123.0000000, 3, -123.000));
	cass.push_back(testcase_Digits(-123.0000000, 11, -123.0000000));
	cass.push_back(testcase_Digits(-9999999999.9999999999, 9, -10000000000.000000000));
	cass.push_back(testcase_Digits(-9999999999.9999999999, 10, -9999999999.9999999999));

	for (size_t i = 0; i < cass.size(); ++i)
	{
		Decimal d = cass.at(i).d1;
		int digits = cass.at(i).digits;
		Decimal expected = cass.at(i).expected;
		Assert::IsTrue(expected == Decimal::Round(d, digits));
	}
}

void DecimalTestDotNet::Round_DigitsMode_ReturnsExpected()
{
	struct testcase_ReturnsExpected
	{
		Decimal d;
		int digits;
		MidpointRoundings mode;
		Decimal expected;

		testcase_ReturnsExpected(Decimal d, int digits, MidpointRoundings mode, Decimal expected)
		{
			this->d = d;
			this->digits = digits;
			this->mode = mode;
			this->expected = expected;
		}
	};
	std::vector<testcase_ReturnsExpected> cass;
	cass.push_back(testcase_ReturnsExpected(1.45, 1, MidpointRoundings::ToEven, 1.4));
	cass.push_back(testcase_ReturnsExpected(1.45, 1, MidpointRoundings::AwayFromZero, 1.5));
	cass.push_back(testcase_ReturnsExpected(1.55, 1, MidpointRoundings::ToEven, 1.6));
	cass.push_back(testcase_ReturnsExpected(1.55, 1, MidpointRoundings::AwayFromZero, 1.6));
	cass.push_back(testcase_ReturnsExpected(-1.45, 1, MidpointRoundings::ToEven, -1.4));
	cass.push_back(testcase_ReturnsExpected(-1.45, 1, MidpointRoundings::AwayFromZero, -1.5));
	cass.push_back(testcase_ReturnsExpected(123.456789, 4, MidpointRoundings::ToEven, 123.4568));
	cass.push_back(testcase_ReturnsExpected(123.456789, 4, MidpointRoundings::AwayFromZero, 123.4568));
	cass.push_back(testcase_ReturnsExpected(123.456789, 6, MidpointRoundings::ToEven, 123.456789));
	cass.push_back(testcase_ReturnsExpected(123.456789, 6, MidpointRoundings::AwayFromZero, 123.456789));
	cass.push_back(testcase_ReturnsExpected(123.456789, 8, MidpointRoundings::ToEven, 123.456789));
	cass.push_back(testcase_ReturnsExpected(123.456789, 8, MidpointRoundings::AwayFromZero, 123.456789));
	cass.push_back(testcase_ReturnsExpected(-123.456, 0, MidpointRoundings::ToEven, -123));
	cass.push_back(testcase_ReturnsExpected(-123.456, 0, MidpointRoundings::AwayFromZero, -123));
	cass.push_back(testcase_ReturnsExpected(-123.0000000, 3, MidpointRoundings::ToEven, -123.000));
	cass.push_back(testcase_ReturnsExpected(-123.0000000, 3, MidpointRoundings::AwayFromZero, -123.000));
	cass.push_back(testcase_ReturnsExpected(-123.0000000, 11, MidpointRoundings::ToEven, -123.0000000));
	cass.push_back(testcase_ReturnsExpected(-123.0000000, 11, MidpointRoundings::AwayFromZero, -123.0000000));
	cass.push_back(testcase_ReturnsExpected(-9999999999.9999999999, 9, MidpointRoundings::ToEven, -10000000000.000000000));
	cass.push_back(testcase_ReturnsExpected(-9999999999.9999999999, 9, MidpointRoundings::AwayFromZero, -10000000000.000000000));
	cass.push_back(testcase_ReturnsExpected(-9999999999.9999999999, 10, MidpointRoundings::ToEven, -9999999999.9999999999));
	cass.push_back(testcase_ReturnsExpected(-9999999999.9999999999, 10, MidpointRoundings::AwayFromZero, -9999999999.9999999999));

	for (size_t i = 0; i < cass.size(); ++i)
	{
		Decimal d = cass.at(i).d;
		int digits = cass.at(i).digits;
		MidpointRoundings mode = cass.at(i).mode;
		Decimal expected = cass.at(i).expected;

		Assert::IsTrue(expected == Decimal::Round(d, digits, (MidpointRoundings)mode));
	}
}

void DecimalTestDotNet::Round_MidpointRounding_ReturnsExpected()
{
	struct testcase_ReturnsExpected
	{
		Decimal d;
		MidpointRoundings mode;
		Decimal expected;

		testcase_ReturnsExpected(Decimal d, MidpointRoundings mode, Decimal expected)
		{
			this->d = d;
			this->mode = mode;
			this->expected = expected;
		}
	};
	std::vector<testcase_ReturnsExpected> cass;
	cass.push_back(testcase_ReturnsExpected(0, MidpointRoundings::ToEven, 0));
	cass.push_back(testcase_ReturnsExpected(0, MidpointRoundings::AwayFromZero, 0));
	cass.push_back(testcase_ReturnsExpected(0.1, MidpointRoundings::ToEven, 0));
	cass.push_back(testcase_ReturnsExpected(0.1, MidpointRoundings::AwayFromZero, 0));
	cass.push_back(testcase_ReturnsExpected(0.5, MidpointRoundings::ToEven, 0));
	cass.push_back(testcase_ReturnsExpected(0.5, MidpointRoundings::AwayFromZero, 1));
	cass.push_back(testcase_ReturnsExpected(0.7, MidpointRoundings::ToEven, 1));
	cass.push_back(testcase_ReturnsExpected(0.7, MidpointRoundings::AwayFromZero, 1));
	cass.push_back(testcase_ReturnsExpected(1.3, MidpointRoundings::ToEven, 1));
	cass.push_back(testcase_ReturnsExpected(1.3, MidpointRoundings::AwayFromZero, 1));
	cass.push_back(testcase_ReturnsExpected(1.5, MidpointRoundings::ToEven, 2));
	cass.push_back(testcase_ReturnsExpected(1.5, MidpointRoundings::AwayFromZero, 2));
	cass.push_back(testcase_ReturnsExpected(-0.1, MidpointRoundings::ToEven, 0));
	cass.push_back(testcase_ReturnsExpected(-0.1, MidpointRoundings::AwayFromZero, 0));
	cass.push_back(testcase_ReturnsExpected(-0.5, MidpointRoundings::ToEven, 0));
	cass.push_back(testcase_ReturnsExpected(-0.5, MidpointRoundings::AwayFromZero, -1));
	cass.push_back(testcase_ReturnsExpected(-0.7, MidpointRoundings::ToEven, -1));
	cass.push_back(testcase_ReturnsExpected(-0.7, MidpointRoundings::AwayFromZero, -1));
	cass.push_back(testcase_ReturnsExpected(-1.3, MidpointRoundings::ToEven, -1));
	cass.push_back(testcase_ReturnsExpected(-1.3, MidpointRoundings::AwayFromZero, -1));
	cass.push_back(testcase_ReturnsExpected(-1.5, MidpointRoundings::ToEven, -2));
	cass.push_back(testcase_ReturnsExpected(-1.5, MidpointRoundings::AwayFromZero, -2));

	for (size_t i = 0; i < cass.size(); ++i)
	{
		Decimal d = cass.at(i).d;
		MidpointRoundings mode = cass.at(i).mode;
		Decimal expected = cass.at(i).expected;
		Assert::IsTrue(expected == Decimal::Round(d, (MidpointRoundings)mode));
	}
}

void DecimalTestDotNet::Subtract()
{
	struct testcase_Subtract
	{
		Decimal d1;
		Decimal d2;
		Decimal expected;

		testcase_Subtract(Decimal d1, Decimal d2, Decimal expected)
		{
			this->d1 = d1;
			this->d2 = d2;
			this->expected = expected;
		}
	};
	std::vector<testcase_Subtract> cass;
	cass.push_back(testcase_Subtract(1, 1, 0));
	cass.push_back(testcase_Subtract(1, 0, 1));
	cass.push_back(testcase_Subtract(0, 1, -1));
	cass.push_back(testcase_Subtract(1, 1, 0));
	cass.push_back(testcase_Subtract(-1, 1, -2));
	cass.push_back(testcase_Subtract(1, -1, 2));
	cass.push_back(testcase_Subtract(Decimal::MaxValue, Decimal::Zero, Decimal::MaxValue));
	cass.push_back(testcase_Subtract(Decimal::MinValue, Decimal::Zero, Decimal::MinValue));
	cass.push_back(testcase_Subtract(Decimal::Parse("79228162514264337593543950330"), -5, Decimal::MaxValue));
	cass.push_back(testcase_Subtract(Decimal::Parse("79228162514264337593543950330"), 5, Decimal::Parse("79228162514264337593543950325")));
	cass.push_back(testcase_Subtract(Decimal::Parse("-79228162514264337593543950330"), 5, Decimal::MinValue));
	cass.push_back(testcase_Subtract(Decimal::Parse("-79228162514264337593543950330"), -5, Decimal::Parse("-79228162514264337593543950325")));
	cass.push_back(testcase_Subtract(Decimal::Parse("1234.5678"), Decimal::Parse("0.00009"), Decimal::Parse("1234.56771")));
	cass.push_back(testcase_Subtract(Decimal::Parse("-1234.5678"), Decimal::Parse("0.00009"), Decimal::Parse("-1234.56789")));
	cass.push_back(testcase_Subtract(Decimal::Parse("0.1111111111111111111111111111"), Decimal::Parse("0.1111111111111111111111111111"), Decimal::Parse("0")));
	cass.push_back(testcase_Subtract(Decimal::Parse("0.2222222222222222222222222222"), Decimal::Parse("0.1111111111111111111111111111"), Decimal::Parse("0.1111111111111111111111111111")));
	cass.push_back(testcase_Subtract(Decimal::Parse("1.1111111111111111111111111110"), Decimal::Parse("0.5555555555555555555555555555"), Decimal::Parse("0.5555555555555555555555555555")));

	for (size_t i = 0; i < cass.size(); ++i)
	{
		Decimal d1 = cass.at(i).d1;
		Decimal d2 = cass.at(i).d2;
		Decimal expected = cass.at(i).expected;

		Assert::IsTrue(expected == d1 - d2);
		Assert::IsTrue(expected == Decimal::Subtract(d1, d2));

		Decimal d3 = d1;
		d3 -= d2;
		Assert::IsTrue(expected == d3);
	}
}

void DecimalTestDotNet::Subtract_Invalid()
{
	struct testcase_Invalid
	{
		Decimal d1;
		Decimal d2;

		testcase_Invalid(Decimal d1, Decimal d2)
		{
			this->d1 = d1;
			this->d2 = d2;
		}
	};
	std::vector<testcase_Invalid> cass;
	cass.push_back(testcase_Invalid(Decimal::Parse("79228162514264337593543950330"), -6));
	cass.push_back(testcase_Invalid(Decimal::Parse("-79228162514264337593543950330"), 6));
	for (size_t i = 0; i < cass.size(); ++i)
	{
		//Assert.Throws<OverflowException>(()= > decimal.Subtract(d1, d2));
		//Assert.Throws<OverflowException>(()= > d1 - d2);

		//decimal d3 = d1;
		//Assert.Throws<OverflowException>(()= > d3 -= d2);
	}
}

void DecimalTestDotNet::ToOACurrency_Value_ReturnsExpected()
{
	struct testcase_Value
	{
		Decimal value;
		Decimal expected;

		testcase_Value(Decimal value, Decimal expected)
		{
			this->value = value;
			this->expected = expected;
		}
	};
	std::vector<testcase_Value> cass;
	cass.push_back(testcase_Value(0, 0L));
	cass.push_back(testcase_Value(1, 10000L));
	cass.push_back(testcase_Value(Decimal::Parse("1.000000000000000"), 10000L));
	cass.push_back(testcase_Value(Decimal::Parse("10000000000"), 100000000000000L));
	cass.push_back(testcase_Value(Decimal::Parse("10000000000.00000000000000000"), 100000000000000L));
	cass.push_back(testcase_Value(Decimal::Parse("0.000000000123456789"), 0L));
	cass.push_back(testcase_Value(Decimal::Parse("0.123456789"), 1235L));
	cass.push_back(testcase_Value(Decimal::Parse("123456789"), 1234567890000L));
	cass.push_back(testcase_Value(Decimal::Parse("4294967295"), 42949672950000LL));
	cass.push_back(testcase_Value(Decimal::Parse("-79.228162514264337593543950335"), -792282L));
	cass.push_back(testcase_Value(Decimal::Parse("-79228162514264.337593543950335"), -792281625142643376LL));


	for (size_t i = 0; i < cass.size(); ++i)
	{
		Decimal value = cass.at(i).value;
		Decimal expected = cass.at(i).expected;
		Assert::IsTrue(expected == Decimal::ToOACurrency(value));
	}
}

void DecimalTestDotNet::ToOACurrency_InvalidAsLong_ThrowsOverflowException()
{
	//Assert.Throws<OverflowException>(()= > Decimal::ToOACurrency(new decimal(LLONG_MAX) + 1));
	//Assert.Throws<OverflowException>(()= > Decimal::ToOACurrency(new decimal(LLONG_MIN) - 1));
}

void DecimalTestDotNet::ToByte()
{
	//Assert::IsTrue(byte.MinValue== Decimal::ToByte(byte.MinValue));
	//Assert::IsTrue(123== Decimal::ToByte(123));
	//Assert::IsTrue(123== Decimal::ToByte(123.123));
	//Assert::IsTrue(byte.MaxValue== Decimal::ToByte(byte.MaxValue));
}

void DecimalTestDotNet::ToByte_Invalid()
{
	//Assert.Throws<OverflowException>(()= > Decimal::ToByte(byte.MinValue - 1)); // Decimal < byte.MinValue
	//Assert.Throws<OverflowException>(()= > Decimal::ToByte(byte.MaxValue + 1)); // Decimal > byte.MaxValue
}

void DecimalTestDotNet::ToDouble()
{
	double d = Decimal::ToDouble(Decimal(0, 0, 1, false, 0));

	double dbl = 123456789.123456;
	Assert::IsTrue(dbl == Decimal::ToDouble(dbl));
	Assert::IsTrue(-dbl == Decimal::ToDouble(-dbl));

	dbl = 1e20;
	Assert::IsTrue(dbl == Decimal::ToDouble(dbl));
	Assert::IsTrue(-dbl == Decimal::ToDouble(-dbl));

	dbl = 1e27;
	Assert::IsTrue(dbl == Decimal::ToDouble(dbl));
	Assert::IsTrue(-dbl == Decimal::ToDouble(-dbl));

	dbl = LLONG_MAX;
	// Need to pass in the Int64.MaxValue to ToDouble and not dbl because the conversion to double is a little lossy and we want precision
	Assert::IsTrue(dbl == Decimal::ToDouble(LLONG_MAX));
	Assert::IsTrue(-dbl == Decimal::ToDouble(-LLONG_MAX));
}

void DecimalTestDotNet::ToInt16()
{
	Assert::IsTrue(INT16_MIN == Decimal::ToInt16(INT16_MIN));
	Assert::IsTrue(-123 == Decimal::ToInt16(-123));
	Assert::IsTrue(0 == Decimal::ToInt16(0));
	Assert::IsTrue(123 == Decimal::ToInt16(123));
	Assert::IsTrue(123 == Decimal::ToInt16(123.123));
	Assert::IsTrue(INT16_MAX == Decimal::ToInt16(INT16_MAX));
}

void DecimalTestDotNet::ToInt16_Invalid()
{
	//Assert.Throws<OverflowException>(()= > Decimal::ToInt16(INT16_MIN- 1)); // Decimal < INT16_MIN
	//Assert.Throws<OverflowException>(()= > Decimal::ToInt16(INT16_MAX+ 1)); // Decimal > INT16_MAX

	//Assert.Throws<OverflowException>(()= > Decimal::ToInt16((long)INT_MIN- 1)); // Decimal < INT16_MIN
	//Assert.Throws<OverflowException>(()= > Decimal::ToInt16((long)INT_MAX+ 1)); // Decimal > INT16_MAX
}

void DecimalTestDotNet::ToInt32()
{
	Assert::IsTrue(INT_MIN == Decimal::ToInt32(INT_MIN));
	Assert::IsTrue(-123 == Decimal::ToInt32(-123));
	Assert::IsTrue(0 == Decimal::ToInt32(0));
	Assert::IsTrue(123 == Decimal::ToInt32(123));
	Assert::IsTrue(123 == Decimal::ToInt32(123.123));
	Assert::IsTrue(INT_MAX == Decimal::ToInt32(INT_MAX));
}

void DecimalTestDotNet::ToInt32_Invalid()
{
	//Assert.Throws<OverflowException>(()= > Decimal::ToInt32((long)INT_MIN- 1)); // Decimal < INT_MIN
	//Assert.Throws<OverflowException>(()= > Decimal::ToInt32((long)INT_MAX+ 1)); // Decimal > INT_MAX
}

void DecimalTestDotNet::ToInt64()
{
	Assert::IsTrue(LLONG_MIN == Decimal::ToInt64(LLONG_MIN));
	Assert::IsTrue(-123 == Decimal::ToInt64(-123));
	Assert::IsTrue(0 == Decimal::ToInt64(0));
	Assert::IsTrue(123 == Decimal::ToInt64(123));
	Assert::IsTrue(123 == Decimal::ToInt64(123.123));
	Assert::IsTrue(LLONG_MAX == Decimal::ToInt64(LLONG_MAX));
}

void DecimalTestDotNet::ToInt64_Invalid()
{
	//Assert.Throws<OverflowException>(()= > Decimal::ToUInt64(Decimal::MinValue)); // Decimal < LLONG_MIN
	//Assert.Throws<OverflowException>(()= > Decimal::ToUInt64(Decimal::MaxValue)); // Decimal > LLONG_MAX
}

void DecimalTestDotNet::ToSByte()
{
	Assert::IsTrue(SCHAR_MIN == Decimal::ToSByte(SCHAR_MIN));
	Assert::IsTrue(-123 == Decimal::ToSByte(-123));
	Assert::IsTrue(0 == Decimal::ToSByte(0));
	Assert::IsTrue(123 == Decimal::ToSByte(123));
	Assert::IsTrue(123 == Decimal::ToSByte(123.123));
	Assert::IsTrue(SCHAR_MAX == Decimal::ToSByte(SCHAR_MAX));
}

void DecimalTestDotNet::ToSByte_Invalid()
{
	//Assert.Throws<OverflowException>(()= > Decimal::ToSByte(SCHAR_MIN - 1)); // Decimal < SCHAR_MIN
	//Assert.Throws<OverflowException>(()= > Decimal::ToSByte(SCHAR_MAX + 1)); // Decimal > SCHAR_MAX

	//Assert.Throws<OverflowException>(()= > Decimal::ToSByte((long)INT_MIN- 1)); // Decimal < SCHAR_MIN
	//Assert.Throws<OverflowException>(()= > Decimal::ToSByte((long)INT_MAX+ 1)); // Decimal > SCHAR_MAX
}

void DecimalTestDotNet::ToSingle()
{
	float f = 12345.12f;
	Assert::IsTrue(f == Decimal::ToSingle(f));
	Assert::IsTrue(-f == Decimal::ToSingle(-f));

	f = 1e20f;
	Assert::IsTrue(f == Decimal::ToSingle(f));
	Assert::IsTrue(-f == Decimal::ToSingle(-f));

	f = 1e27f;
	Assert::IsTrue(f == Decimal::ToSingle(f));
	Assert::IsTrue(-f == Decimal::ToSingle(-f));
}

void DecimalTestDotNet::ToUInt16()
{
	Assert::IsTrue(0 == Decimal::ToUInt16(0));
	Assert::IsTrue(123 == Decimal::ToByte(123));
	Assert::IsTrue(123 == Decimal::ToByte(123.123));
	Assert::IsTrue(USHRT_MAX == Decimal::ToUInt16(USHRT_MAX));
}

void DecimalTestDotNet::ToUInt16_Invalid()
{
	//Assert.Throws<OverflowException>(()= > Decimal::ToUInt16(0 - 1)); // Decimal < ushort.MinValue
	//Assert.Throws<OverflowException>(()= > Decimal::ToUInt16(USHRT_MAX + 1)); // Decimal > USHRT_MAX
}

void DecimalTestDotNet::ToUInt32()
{
	Assert::IsTrue(0 == Decimal::ToUInt32(0));
	Assert::IsTrue(123 == Decimal::ToUInt32(123));
	Assert::IsTrue(123 == Decimal::ToUInt32(123.123));
	Assert::IsTrue(UINT_MAX == Decimal::ToUInt32(UINT_MAX));
}

void DecimalTestDotNet::ToUInt32_Invalid()
{
	//Assert.Throws<OverflowException>(()= >Decimal::ToUInt32((long)0 - 1)); // Decimal < uint.MinValue
	//Assert.Throws<OverflowException>(()= >Decimal::ToUInt32((long)UINT_MAX + 1)); // Decimal > UINT_MAX
}

void DecimalTestDotNet::ToUInt64()
{
	Assert::IsTrue(0 == Decimal::ToUInt64(0));
	Assert::IsTrue(123 == Decimal::ToUInt64(123));
	Assert::IsTrue(123 == Decimal::ToUInt64(123.123));
	Assert::IsTrue(ULLONG_MAX == Decimal::ToUInt64(ULLONG_MAX));
}

void DecimalTestDotNet::ToUInt64_Invalid()
{
	//Assert.Throws<OverflowException>(()= >Decimal::ToUInt64((long)0 - 1)); // Decimal < uint.MinValue
}

void DecimalTestDotNet::ToString_InvalidFormat_ThrowsFormatException()
{
	//	decimal f = 123;
	//	Assert.Throws<FormatException>(()= > f.ToString("Y"));
	//	Assert.Throws<FormatException>(()= > f.ToString("Y", null));
	//	long intMaxPlus1 = (long)
	//int
	//	.
	//	MaxValue + 1;
	//	string intMaxPlus1String = intMaxPlus1.ToString();
	//	Assert.Throws<FormatException>(()= > f.ToString("E" + intMaxPlus1String));
}

void DecimalTestDotNet::TestRoundTripDecimalToString()
{
	//string input = "3.00";
	//decimal d = Decimal.Parse(input, NumberStyles::Number, NumberFormatInfo.InvariantInfo);
	//string dString = d.ToString(CultureInfo.InvariantCulture);
	//Assert::IsTrue(input, dString);
}

void DecimalTestDotNet::Truncate()
{
	struct testcase_Truncate
	{
		Decimal d;
		Decimal expected;

		testcase_Truncate(Decimal d, Decimal expected)
		{
			this->d = d;
			this->expected = expected;
		}
	};
	std::vector<testcase_Truncate> cass;
	cass.push_back(testcase_Truncate(123, 123));
	cass.push_back(testcase_Truncate(123.123, 123));
	cass.push_back(testcase_Truncate(123.456, 123));
	cass.push_back(testcase_Truncate(-123.123, -123));
	cass.push_back(testcase_Truncate(-123.456, -123));

	for (size_t i = 0; i < cass.size(); ++i)
	{
		Assert::IsTrue(cass.at(i).expected == Decimal::Truncate(cass.at(i).d));
	}
}

void DecimalTestDotNet::IncrementOperator()
{
	struct testcase_IncrementOperator
	{
		Decimal d;
		Decimal expected;

		testcase_IncrementOperator(Decimal d, Decimal expected)
		{
			this->d = d;
			this->expected = expected;
		}
	};
	std::vector<testcase_IncrementOperator> cass;
	cass.push_back(testcase_IncrementOperator(1, 2));
	cass.push_back(testcase_IncrementOperator(0, 1));
	cass.push_back(testcase_IncrementOperator(-1, -0));
	cass.push_back(testcase_IncrementOperator(12345, 12346));
	cass.push_back(testcase_IncrementOperator(12345.678, 12346.678));
	cass.push_back(testcase_IncrementOperator(-12345.678, -12344.678));

	for (size_t i = 0; i < cass.size(); ++i)
	{
		Assert::IsTrue(cass.at(i).expected == ++cass.at(i).d);
	}
}

void DecimalTestDotNet::DecrementOperator()
{
	struct testcase_DecrementOperator
	{
		Decimal d;
		Decimal expected;

		testcase_DecrementOperator(Decimal d, Decimal expected)
		{
			this->d = d;
			this->expected = expected;
		}
	};
	std::vector<testcase_DecrementOperator> cass;
	cass.push_back(testcase_DecrementOperator(1, 0));
	cass.push_back(testcase_DecrementOperator(0, -1));
	cass.push_back(testcase_DecrementOperator(-1, -2));
	cass.push_back(testcase_DecrementOperator(12345, 12344));
	cass.push_back(testcase_DecrementOperator(12345.678, 12344.678));
	cass.push_back(testcase_DecrementOperator(-12345.678, -12346.678));
	for (size_t i = 0; i < cass.size(); ++i)
	{
		Assert::IsTrue(cass.at(i).expected == --cass.at(i).d);
	}
}
