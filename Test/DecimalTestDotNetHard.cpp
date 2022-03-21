#include "DecimalTestDotNetHard.h"

#include "CppUnitTestAssert.h"

bool operator==(const std::wstring& lhs, char* str)
{
	std::string rebuild = str;
	std::string casttext = std::string(lhs.begin(), lhs.end());
	return rebuild == casttext;
}

bool operator==(const std::wstring& lhs, const char* ret)
{
	std::string rebuild = ret;
	std::string casttext = std::string(lhs.begin(), lhs.end());
	return rebuild == casttext;
}

bool operator==(const std::wstring& lhs, const std::string& rhs)
{
	std::string rebuild = rhs;
	std::string casttext = std::string(lhs.begin(), lhs.end());
	return rebuild == casttext;
}

void DecimalTestDotNetHard::TestMethod_ToString()
{
	Assert::WriteLineSpace();
	Assert::WriteLine(L"");
	Assert::WriteLine(L"Test Decimal String");
	Assert::WriteLine(L"");


	auto text3 = Decimal("12345679812313214.09743").ToString();
	Assert::IsTrue(text3 == L"12345679812313214.09743", L"12345679812313214.09743 => 12345679812313214.09743");
	auto text4 = Decimal("-12345679812313214.09743").ToString();
	Assert::IsTrue(text4 == "-12345679812313214.09743", L"-12345679812313214.09743 => -12345679812313214.09743");
	auto text5 = Decimal("-.0974000000").ToString();
	Assert::IsTrue(text5 == "-0.0974000000", L"-.0974000000 => -0.0974000000");
	auto text6 = Decimal("-.0974000000").ToString();
	Assert::IsTrue(text6 == "-0.0974000000", L"-.0974000000 => -0.0974000000");
	auto text7 = Decimal(".09743756565").ToString();
	Assert::IsTrue(text7 == "0.09743756565", L".09743756565 => 0.09743756565");
	auto text8 = Decimal("09743756565").ToString();
	Assert::IsTrue(text8 == "9743756565", L"09743756565 => 9743756565");
	auto text9_1 = Decimal("0").ToString();
	Assert::IsTrue(text9_1 == "0", L"0 => 0");
	auto text9_2 = Decimal("0").ToString();
	Assert::IsTrue(text9_2 == "0", L"0 => 0");
	auto text9_3 = Decimal("0.1").ToString();
	Assert::IsTrue(text9_3 == "0.1", L"0.1 => 0.1");
	auto text9_4 = Decimal("0.100").ToString();
	Assert::IsTrue(text9_4 == "0.100", L"0.100 => 0.100");
	auto text9_5 = Decimal("0.100").ToString();
	Assert::IsTrue(text9_5 == "0.100", L"0.100 => 0.100");
	auto text9_6 = Decimal("0.1001").ToString();
	Assert::IsTrue(text9_6 == "0.1001", L"0.1001 => 0.1001");
	auto text9_7 = Decimal("0.1001").ToString();
	Assert::IsTrue(text9_7 == "0.1001", L"0.1001 => 0.1001");
	auto text9_8 = Decimal("0.1001").ToString();
	Assert::IsTrue(text9_8 == "0.1001", L"0.1001 => 0.1001");
	auto text9_9 = Decimal("0.1001").ToString();
	Assert::IsTrue(text9_9 == "0.1001", L"0.1001 => 0.1001");

	auto text10 = Decimal("-09743756565").ToString();
	Assert::IsTrue(text10 == "-9743756565", L"-09743756565 => -9743756565");

	auto text11 = Decimal("-09743756565").ToString();
	Assert::IsTrue(text11 == "-9743756565", L"-09743756565 => -9743756565");
	auto text12 = Decimal("-09743756565").ToString();
	Assert::IsTrue(text12 == "-9743756565", L"-09743756565 => -9743756565");

	auto text13 = Decimal("-09743756565").ToString();
	Assert::IsTrue(text13 == "-9743756565", L"-09743756565 => -9743756565");
	auto text14 = Decimal("-09743756565").ToString();
	Assert::IsTrue(text14 == "-9743756565", L"-09743756565 => -9743756565");

	auto text15 = Decimal("-09743756565").ToString();
	Assert::IsTrue(text15 == "-9743756565", L"-09743756565 => -9743756565");
	auto text16 = Decimal("-09743756565").ToString();
	Assert::IsTrue(text16 == "-9743756565", L"-09743756565 => -9743756565");

	auto text17 = Decimal("-09743756565").ToString();
	Assert::IsTrue(text17 == "-9743756565", L"-09743756565 => -9743756565");
	auto text18 = Decimal("-09743756565").ToString();
	Assert::IsTrue(text18 == "-9743756565", L"-09743756565 => -9743756565");
	auto text19 = Decimal("12345679812313214.09743").ToString();
	Assert::IsTrue(text19 == "12345679812313214.09743", L"12345679812313214.09743 => 12345679812313214.09743");

	//auto text2_0 = Decimal("-0,88,666").ToString();
	//Assert::IsTrue(text2_0 == "0", L"-0,88,666 => 0");

	auto text2_1 = Decimal("1234").ToString();
	auto text2_1_TEST = text2_1 == "1234";
	Assert::IsTrue(text2_1_TEST, L"1234 => 1234");
	auto text2_2 = Decimal("1234").ToString();
	auto text2_2_TEST = text2_2 == "1234";
	Assert::IsTrue(text2_2_TEST, L"1234 => 1234");
	auto text2_3 = Decimal("0.1234").ToString();
	auto text2_3_TEST = text2_3 == "0.1234";
	Assert::IsTrue(text2_3_TEST, L"0.1234 => 0.1234");
	auto text2_4 = Decimal("0.1234").ToString();
	auto text2_4_TEST = text2_4 == "0.1234";
	Assert::IsTrue(text2_4_TEST, L"0.1234 => 0.1234");
	auto text2_5 = Decimal("-0.1234").ToString();
	auto text2_5_TEST = text2_5 == "-0.1234";
	Assert::IsTrue(text2_5_TEST, L"-0.1234 => -0.1234");
	auto text2_6 = Decimal("-0.1234").ToString();
	auto text2_6_TEST = text2_6 == "-0.1234";
	Assert::IsTrue(text2_6_TEST, L"-0.1234 => -0.1234");
	auto text2_7 = Decimal("0").ToString();
	auto text2_7_TEST = text2_7 == "0";
	Assert::IsTrue(text2_7_TEST, L"0 => 0");
	auto text2_8 = Decimal("0").ToString();
	auto text2_8_TEST = text2_8 == "0";
	Assert::IsTrue(text2_8_TEST, L"0 => 0");
	auto text2_9 = Decimal("123450").ToString();
	auto text2_9_TEST = text2_9 == "123450";
	Assert::IsTrue(text2_9_TEST, L"0 => 123450");


	auto text3_1 = Decimal("999").ToString();
	Assert::IsTrue(text3_1 == "999", L"999 => 999");
	auto text3_2 = Decimal("-999").ToString();
	Assert::IsTrue(text3_2 == "-999", L"-999 => -999");
	auto text3_3 = Decimal("1000").ToString();
	Assert::IsTrue(text3_3 == "1000", L"1000 => 1000");
	auto text3_4 = Decimal("-1000").ToString();
	Assert::IsTrue(text3_4 == "-1000", L"-1000 => -1000");
	auto text3_5 = Decimal("999999").ToString();
	Assert::IsTrue(text3_5 == "999999", L"999999 => 999999");
	auto text3_6 = Decimal("-999999").ToString();
	Assert::IsTrue(text3_6 == "-999999", L"-999999 => -999999");
	auto text3_7 = Decimal("1000000").ToString();
	Assert::IsTrue(text3_7 == "1000000", L"1000000 => 1000000");
	auto text3_8 = Decimal("-1000000").ToString();
	Assert::IsTrue(text3_8 == "-1000000", L"-1000000 => -1000000");

	auto text4_1 = Decimal("999").ToString();
	Assert::IsTrue(text4_1 == "999", L"999 => 999");
	auto text4_2 = Decimal("-999").ToString();
	Assert::IsTrue(text4_2 == "-999", L"-999 => -999");
	auto text4_3 = Decimal("1000").ToString();
	Assert::IsTrue(text4_3 == "1000", L"1000 => 1000");
	auto text4_4 = Decimal("-1000").ToString();
	Assert::IsTrue(text4_4 == "-1000", L"-1000 => -1000");
	auto text4_5 = Decimal("999999").ToString();
	Assert::IsTrue(text4_5 == "999999", L"999999 => 999999");
	auto text4_6 = Decimal("-999999").ToString();
	Assert::IsTrue(text4_6 == "-999999", L"-999999 => -999999");
	auto text4_7 = Decimal("1000000").ToString();
	Assert::IsTrue(text4_7 == "1000000", L"1000000 => 1000000");
	auto text4_8 = Decimal("-1000000").ToString();
	Assert::IsTrue(text4_8 == "-1000000", L"-1000000 => -1000000");

	auto text4_9 = Decimal("-0.957968").ToString();
	Assert::IsTrue(text4_9 == "-0.957968", L"-0.957968");
}

void DecimalTestDotNetHard::TestMethod_Convert_Int()
{
	Assert::WriteLineSpace();
	Assert::WriteLine(L"");
	Assert::WriteLine(L"TestMethod_int test convert");
	Assert::WriteLine(L"");
	decimal_convert_int_test();
}


void DecimalTestDotNetHard::int_convert_test(int value, const char* ret)
{
	Decimal value1 = Decimal(value);

	Assert::IsTrue(value1.ToString() == std::to_string(value), (std::to_wstring(value) + L" == " + value1.ToString()).c_str());

	Assert::IsTrue(value1.ToInt32(value1) == value, (std::to_wstring(value) + L" == " + value1.ToString()).c_str());

	Assert::IsTrue(value1.ToString() == ret, (std::to_wstring(value) + L" == " + value1.ToString()).c_str());
}

void DecimalTestDotNetHard::int_convert(const char* ret, int value)
{
	int value3 = Decimal::ToInt32(Decimal(ret));
	Assert::IsTrue(value == value3);
}

void DecimalTestDotNetHard::int_convert_overflow(const char* ret)
{
	int value3;
	bool v = Decimal::TryToInt32(Decimal(ret), value3);
	std::wstring text = L"Overflow ToInt32 " + Decimal(ret).ToString();
	Assert::IsTrue(v == false, text.c_str());
}

void DecimalTestDotNetHard::decimal_convert_int_test()
{
	int_convert_test(1000, "1000");
	int_convert_test(-1000, "-1000");
	int_convert_test(-999999999, "-999999999");
	int_convert_test(0, "0");
	int_convert_test(-2147483647, "-2147483647");
	int_convert_test(-2147483647 - 1, "-2147483648");
	int_convert_test(2147483647, "2147483647");

	int_convert("123456", 123456);
	int_convert("99999999", 99999999);
	int_convert("-123456", -123456);
	int_convert("-99999999", -99999999);
	int_convert("-123456.123456", -123456);
	int_convert("-99999999.123456", -99999999);
	int_convert("123456.123456", 123456);
	int_convert("99999999.123456", 99999999);

	int_convert_overflow("123456789123");
	int_convert_overflow("-123456789123");
	int_convert_overflow("2147483648");
	int_convert_overflow("-2147483649");

	Assert::WriteLine(L"TEST mg_decimal convert int methods: OK\n");
}

void DecimalTestDotNetHard::convert_test(const char* text)
{
	Decimal value(text);
	Assert::IsTrue(value.ToString() == text);
}

void DecimalTestDotNetHard::convert_test2(const char* text1, const char* text2)
{
	Decimal value(text1);
	Assert::IsTrue(value.ToString() == text2);
}

void DecimalTestDotNetHard::convert_test_OVERFLOW(const char* text1, bool cs)
{
	Decimal value;
	bool isfalse = Decimal::TryParse(text1, &value);
	if (cs == isfalse)
	{
		Assert::IsTrue(true);
		Assert::WriteLine(L"PASS OVERFLOE");
	}
	else
	{
		Assert::IsTrue(false);
		auto text = value.ToString();
		Assert::WriteLine(L"FAIL OVERFLOE");
	}
}

void DecimalTestDotNetHard::decimal_convert_string_test()
{
	convert_test("-1");
	convert_test("0");
	convert_test("1");
	convert_test("123456789");
	convert_test("123456789123456789");
	convert_test("12345678912345678912345678912");
	convert_test("1234567.1001");
	convert_test("1234567.1234567894656");
	convert_test("1234561234567.1234567");
	convert_test("1234561234567894567.1234567");
	convert_test("12345612345678123194567.123456");
	convert_test("12345612345678123194567.123456");
	convert_test("12345612345678123194567.123456");
	convert_test("78978.111111111111111111111111");
	convert_test("7.1111111111111111111111111111");
	convert_test("-6666");
	convert_test("-6666666666666666666666666");
	convert_test("-6666.6666");
	convert_test("-6666666666666666.666666666");
	convert_test("808465479.056146514");
	convert_test("8089.46547056146514");
	convert_test("808946547056146.514");
	convert_test("8089465470561489451411111114");
	convert_test("1000000.000000000000555");
	convert_test("1000000000000000");
	convert_test("100000000000000000000");
	convert_test("0.1111111111111111111111111111");
	convert_test("0.1111111189768415431454645444");
	convert_test("0.1311111189768415431454645444");


	convert_test2("00000111111111111", "111111111111");
	convert_test2("-00000111111111111", "-111111111111");
	convert_test2("+00000111111111111", "111111111111");
	convert_test2("+000001111111.11111", "1111111.11111");
	convert_test2("1.10", "1.10");
	convert_test2("1.10000", "1.10000");
	convert_test2("1.100000000000", "1.100000000000");
	convert_test2("1.1000000000000000000000000", "1.1000000000000000000000000");
	convert_test2("1.01234564857894156327864986148541864564165411231321", "1.0123456485789415632786498615");
	convert_test2("0.11234564857894156327864986148541864564165411231321", "0.1123456485789415632786498615");


	convert_test_OVERFLOW("999999999999999999999999999999999999", false);
	convert_test_OVERFLOW("988841684.165164131651648416544", true);
	//convert_test_OVERFLOW("9888416841651641316.5164841654");//bdki ??
	convert_test_OVERFLOW("98884168416516413165164841654", false);
	convert_test_OVERFLOW("1234567891234156498715634865156465151654152165453132416854114", false);


	Assert::WriteLine(L"TEST mg_decimal convert string methods: OK\n");
}

void DecimalTestDotNetHard::uint_convert_test(unsigned value, const char* ret)
{
	Decimal value1(value);
	Assert::IsTrue(value == value1.ToUInt32(value1));
	Assert::IsTrue(value1.ToString() == ret);
}

void DecimalTestDotNetHard::uint_convert_overflow(const char* value)
{
	unsigned int value3;
	Decimal value1(value);
	bool tryparse = value1.TryToUInt32(value1, value3);
	if (!tryparse)
	{
		Assert::IsTrue(true);
	}
	else
	{
		Assert::IsTrue(false);
	}
}

void DecimalTestDotNetHard::decimal_convert_uint_test()
{
	uint_convert_test(1000, "1000");
	uint_convert_test(999999999, "999999999");
	uint_convert_test(0, "0");
	uint_convert_test(2147483647, "2147483647");
	uint_convert_test(4294967295, "4294967295");
	uint_convert_test(12345, "12345");

	uint_convert_overflow("12345679812313214");
	uint_convert_overflow("-12345679812313214");
	uint_convert_overflow("-1");
	uint_convert_overflow("4294967296");

	Assert::WriteLine(L"TEST mg_decimal convert uint methods: OK\n");
}

void DecimalTestDotNetHard::TestMethod_Convert_Uint()
{
	Assert::WriteLineSpace();
	Assert::WriteLine(L"");
	Assert::WriteLine(L"TestMethod_uint test convert");
	Assert::WriteLine(L"");
	decimal_convert_uint_test();
}

void DecimalTestDotNetHard::_long_longconvert_test(long long value, const char* ret)
{
	Decimal value1(value);
	Assert::IsTrue(value1.ToInt64(value1) == value);
	Assert::IsTrue(value1.ToString() == ret);
}

void DecimalTestDotNetHard::long_long_convert_overflow(const char* value)
{
	long long value3;
	Decimal value1(value);
	bool tryparse = value1.TryToInt64(value1, value3);
	if (!tryparse)
	{
		Assert::IsTrue(true);
	}
	else
	{
		Assert::IsTrue(false);
	}
}

void DecimalTestDotNetHard::decimal_convert_long_long_test()
{
	_long_longconvert_test(1000, "1000");
	_long_longconvert_test(-1000, "-1000");
	_long_longconvert_test(-9999999999999, "-9999999999999");
	_long_longconvert_test(-999999999999999999, "-999999999999999999");
	_long_longconvert_test(-425415311, "-425415311");
	_long_longconvert_test(9223372036854775807, "9223372036854775807");
	_long_longconvert_test(-9223372036854775807LL - 1LL, "-9223372036854775808");
	_long_longconvert_test(0, "0");

	long_long_convert_overflow("12345678912345678912345961");
	long_long_convert_overflow("-12345678912345678912345961");
	long_long_convert_overflow("9223372036854775808");
	long_long_convert_overflow("-9223372036854775809");

	Assert::WriteLine(L"TEST mg_decimal convert long long methods: OK\n");
}

void DecimalTestDotNetHard::TestMethod_Convert_long_long()
{
	Assert::WriteLineSpace();
	Assert::WriteLine(L"");
	Assert::WriteLine(L"TestMethod_Convert_long_long test convert");
	Assert::WriteLine(L"");
	decimal_convert_long_long_test();
}

void DecimalTestDotNetHard::ulong_long_convert_test(long long value, const char* ret)
{
	Decimal value1(value);
	Assert::IsTrue(Decimal::ToUInt64(value1) == value);
	Assert::IsTrue(value1.ToString() == ret);
}

void DecimalTestDotNetHard::ulong_long_convert_overflow(const char* value)
{
	unsigned long long value3;
	Decimal value1(value);
	bool tryparse = value1.TryToUInt64(value1, value3);
	if (!tryparse)
	{
		Assert::IsTrue(true);
	}
	else
	{
		Assert::IsTrue(false);
	}
}

void DecimalTestDotNetHard::decimal_convert_ulong_long_test()
{
	ulong_long_convert_test(1000ULL, "1000");
	ulong_long_convert_test(9999999999999ULL, "9999999999999");
	ulong_long_convert_test(999999999999999999ULL, "999999999999999999");
	ulong_long_convert_test(425415311ULL, "425415311");
	ulong_long_convert_test(9223372036854775807ULL, "9223372036854775807");
	ulong_long_convert_test(0ULL, "0");

	ulong_long_convert_overflow("123456789123456789123456789");
	ulong_long_convert_overflow("-123456789123456789123456789");
	ulong_long_convert_overflow("-1");
	ulong_long_convert_overflow("18446744073709551616");

	Assert::WriteLine(L"TEST mg_decimal convert ulong long methods: OK\n");
}

void DecimalTestDotNetHard::TestMethod_Convert_ulong_long()
{
	Assert::WriteLineSpace();
	Assert::WriteLine(L"");
	Assert::WriteLine(L"TestMethod_Convert_ulong_long test convert");
	Assert::WriteLine(L"");
	decimal_convert_ulong_long_test();
}

void DecimalTestDotNetHard::float_convert_test(float value, const char* ret, int precision)
{
	Decimal value1(value);
	float value2 = value1.ToSingle(value1);

	Assert::IsTrue(value1.ToSingle(value1) == value);
	Assert::IsTrue(value1.ToString() == ret);
	Assert::IsTrue(fabs(value - value2) < 0.000001);
}

void DecimalTestDotNetHard::decimal_convert_float_test()
{
	float_convert_test(0.0f, "0", 10);
	float_convert_test(1.0f, "1", 10);
	float_convert_test(1.5f, "1.5", 10);
	float_convert_test(1.25f, "1.25", 10);
	float_convert_test(9999999.0f, "9999999", 10);
	float_convert_test(0.5f, "0.5", 6);
	float_convert_test(0.25f, "0.25", 6);
	float_convert_test(0.125f, "0.125", 6);
	float_convert_test(0.625f, "0.625", 6);
	float_convert_test(1.0125f, "1.0125", 6);
	float_convert_test(0.0125f, "0.0125", 6);
	float_convert_test(0.1f, "0.1", 6);
	float_convert_test(9999.99f, "9999.99", 3);
	float_convert_test(-9999.99f, "-9999.99", 3);
	float_convert_test(-0.25, "-0.25", 6);
	float_convert_test(-0.125, "-0.125", 6);
	float_convert_test(-0.625, "-0.625", 6);
	float_convert_test(9999, "9999", 6);
	float_convert_test(456, "456", 6);
	float_convert_test(456.5, "456.5", 6);
	float_convert_test(2, "2", 6);
	float_convert_test(4, "4", 6);
	float_convert_test(8, "8", 6);
	float_convert_test(16, "16", 6);
	float_convert_test(32, "32", 6);
	float_convert_test(64, "64", 6);
	float_convert_test(128, "128", 6);
	float_convert_test(256, "256", 6);
	float_convert_test(512, "512", 6);
	float_convert_test(1024, "1024", 6);
	float_convert_test(2048, "2048", 6);
	float_convert_test(4096, "4096", 6);
	float_convert_test(8192, "8192", 6);
	float_convert_test(16384, "16384", 6);
	float_convert_test(16994, "16994", 6);
	Assert::WriteLine(L"TEST mg_decimal convert float methods: OK\n");
}

void DecimalTestDotNetHard::TestMethod_Convert_float()
{
	Assert::WriteLineSpace();
	Assert::WriteLine(L"");
	Assert::WriteLine(L"TestMethod_Convert_float test convert");
	Assert::WriteLine(L"");
	decimal_convert_float_test();
}

void DecimalTestDotNetHard::double_convert_test(double value, const char* ret, int precision)
{
	Decimal value1(value);
	double value2 = value1.ToDouble(value1);

	Assert::IsTrue(value1.ToDouble(value1) == value);
	Assert::IsTrue(value1.ToString() == ret);
	Assert::IsTrue(fabs(value - value2) < 0.000001);
}

void DecimalTestDotNetHard::double_convert_print(const double value)
{
	Decimal value1(value);
	double value2 = value1.ToDouble(value1);
	Assert::WriteLine(value1.ToString().c_str());
}

void DecimalTestDotNetHard::decimal_convert_double_test()
{
	double_convert_test(0, "0", 10);
	double_convert_test(1.0, "1", 10);
	double_convert_test(1.5, "1.5", 10);
	double_convert_test(1.25, "1.25", 10);
	double_convert_test(99999999999.0, "99999999999", 10);
	double_convert_test(0.5, "0.5", 10);
	double_convert_test(0.25, "0.25", 10);
	double_convert_test(0.125, "0.125", 10);
	double_convert_test(0.625, "0.625", 10);
	double_convert_test(1.0125, "1.0125", 10);
	double_convert_test(0.0125, "0.0125", 10);
	double_convert_test(0.1, "0.1", 10);
	double_convert_test(99999999999.99, "99999999999.99", 2);
	double_convert_test(-99999999999.99, "-99999999999.99", 2);
	double_convert_test(-0.25, "-0.25", 10);
	double_convert_test(-0.125, "-0.125", 10);
	double_convert_test(-0.625, "-0.625", 10);
	double_convert_test(-965433.00163, "-965433.00163", 10);
	double_convert_test(5555555555555555, "5555555555555555", 10);
	double_convert_test(-99999999999999, "-99999999999999", 10);
	double_convert_test(-0.00000365242341, "-0.0000036524234", 13);
	double_convert_test(9999, "9999", 10);
	double_convert_test(456, "456", 10);
	double_convert_test(456.5, "456.5", 10);
	double_convert_test(2, "2", 10);
	double_convert_test(4, "4", 10);
	double_convert_test(8, "8", 10);
	double_convert_test(16, "16", 10);
	double_convert_test(32, "32", 10);
	double_convert_test(64, "64", 10);
	double_convert_test(128, "128", 10);
	double_convert_test(256, "256", 10);
	double_convert_test(512, "512", 10);
	double_convert_test(1024, "1024", 10);
	double_convert_test(2048, "2048", 10);
	double_convert_test(4096, "4096", 10);
	double_convert_test(8192, "8192", 10);
	double_convert_test(16384, "16384", 10);
	double_convert_test(16994, "16994", 10);
	double_convert_test(2251799813685248.0, "2251799813685248.0", 10);
	double_convert_test(4503599627370496.0, "4503599627370496.0", 10);
	double_convert_test(9007199254740992.0, "9007199254740992.0", 10);
	double_convert_test(18014398509481984.0, "18014398509481984.0", 10);
	double_convert_test(36028797018963968.0, "36028797018963968.0", 10);
	double_convert_test(4589599627370496.0, "4589599627370496.0", 10);
	double_convert_test(36695797018963968.0, "36695797018963968.0", 10);

	double_convert_print(-9999999999999999999.0);
	double_convert_print(9999999999999.9999);
	double_convert_print(99999999999999999999999999999999999.0);
	double_convert_print(999999999999000000000000000000000000.0);
	double_convert_print(100000000000000000000000000000000000.0);
	double_convert_print(555555555555555555550000000000000000.0);
	double_convert_print(0.00000000000000000000000000001);
	double_convert_print(0.00000000000000000000000000000000001);
	double_convert_print(0.00000000000000000000005555555);
	double_convert_print(1.0e+35);
	double_convert_print(0.00000000000000000000000000000000009);
	double_convert_print(0.00000000000000000000000000000000010);
	double_convert_print(0.00000000000000000000000000000000001);
	double_convert_print(0.000000000000000000000000000000000001);
	double_convert_print(0.00000000000000000000000000000000000009);
	double_convert_print(1.00000000000000000000000000000000009);
	double_convert_print(1.0000000000000000000000009);
	double_convert_print(1.00000000000000009);
	double_convert_print(1.000000009);
	double_convert_print(1.0009);

	Assert::WriteLine(L"TEST mg_decimal convert double methods: OK\n");
}

void DecimalTestDotNetHard::TestMethod_Convert_double()
{
	Assert::WriteLineSpace();
	Assert::WriteLine(L"");
	Assert::WriteLine(L"TestMethod_Convert_double test convert");
	Assert::WriteLine(L"");
	decimal_convert_double_test();
}

void DecimalTestDotNetHard::zero_test()
{
	Decimal value1 = Decimal::Zero;
	Assert::IsTrue(value1.ToString() == "0");
}

void DecimalTestDotNetHard::decimal_zero_test()
{
	zero_test();
	Assert::WriteLine(L"TEST mg_decimal_zero(): OK\n");
}

void DecimalTestDotNetHard::TestMethod_zero_test()
{
	Assert::WriteLineSpace();
	Assert::WriteLine(L"");
	Assert::WriteLine(L"TestMethod_Convert_zero_test test");
	Assert::WriteLine(L"");
	decimal_zero_test();
}

void DecimalTestDotNetHard::compare_test(const char* text1, const char* text2, int ret)
{
	Decimal value1(text1);
	Decimal value2(text2);


	if (ret < 0)
	{
		Assert::IsTrue(Decimal::Compare(value1, value2) < 0);
	}
	else if (ret > 0)
	{
		Assert::IsTrue(Decimal::Compare(value1, value2) > 0);
	}
	else
	{
		Assert::IsTrue(Decimal::Compare(value1, value2) == 0);
	}
}

void DecimalTestDotNetHard::decimal_compare_test()
{
	compare_test("0", "10000", -1);
	compare_test("10000", "0", 1);
	compare_test("-1", "0", -1);
	compare_test("0", "-1", 1);
	compare_test("0", "0", 0);
	compare_test("1000", "1000", 0);
	compare_test("100000000", "100000000", 0);
	compare_test("10000000000000000000000000", "1000", 1);
	compare_test("1000", "10000000000000000000000000", -1);
	compare_test("10000000000000000000000000", "10000000000000000000000000", 0);
	compare_test("10000000000000000000000000", "1000", 1);
	compare_test("1000", "10000000000000000000000000", -1);
	compare_test("1", "1.000", 0);
	compare_test("1", "1.001", -1);
	compare_test("2", "1.00000000000000000000000001", 1);
	compare_test("1", "1.00000000000000000000000001", -1);
	compare_test("2", "1.00000000000000000000000001", 1);
	compare_test("-1000", "-999", -1);
	compare_test("-1000.05", "-999", -1);
	compare_test("-1000", "-999.05", -1);
	compare_test("-1000", "-9900000000000009.05", 1);

	compare_test("-2", "-1.00000000000000000000000001", -1);
	compare_test("-1", "-1.00000000000000000000000001", 1);
	compare_test("-2", "-1.00000000000000000000000001", -1);

	compare_test("0.0010000", "0.0000009999999", 1);
	compare_test("-0.0010000", "-0.0000009999999", -1);

	compare_test("0.0000009999999", "0.0000009999999", 0);
	compare_test("-0.0000009999999", "-0.0000009999999", 0);

	compare_test("0.0000009999998", "0.0000009999999", -1);
	compare_test("-0.0000009999998", "-0.0000009999999", 1);

	compare_test("0.00000099999989999", "0.00000099999999", -1);
	compare_test("-0.00000099999989999", "-0.00000099999999", 1);

	compare_test("0.00000099999989999", "0.00000099899999", 1);
	compare_test("-0.00000099999989999", "-0.00000099899999", -1);

	Assert::WriteLine(L"TEST mg_decimal_compare(): OK\n");
}

void DecimalTestDotNetHard::TestMethod_compare_test()
{
	Assert::WriteLineSpace();
	Assert::WriteLine(L"");
	Assert::WriteLine(L"TestMethod_compare_test test");
	Assert::WriteLine(L"");
	decimal_compare_test();
}

void DecimalTestDotNetHard::add_test(const char* text1, const char* text2, const char* ret)
{
	Decimal value1, value2;
	bool p1 = Decimal::TryParse(text1, &value1);
	bool p2 = Decimal::TryParse(text2, &value2);

	if (p1 && p2)
	{
		Decimal value3 = value1 + value2;

		Assert::IsTrue(value3.ToString() == ret);
	}
	else
	{
		Assert::WriteLine(L"Parse overflow");
	}
}

void DecimalTestDotNetHard::decimal_add_test()
{
	add_test("1", "1", "2");
	add_test("1", "-1", "0");
	add_test("1", "0", "1");
	add_test("0", "1", "1");
	add_test("100000000000000000000", "10000000000000000", "100010000000000000000");
	add_test("100000000000000000000", "-10000000000000000", "99990000000000000000");
	add_test("-100000000000000000000", "10000000000000000", "-99990000000000000000");
	add_test("-100000000000000000000", "-10000000000000000", "-100010000000000000000");
	add_test("-1000000.000001", "-99.99", "-1000099.990001");
	add_test("-1000000.000001", "-99.000001", "-1000099.000002");
	add_test("1000000000.00000000000000001", "999999999.9999999999999999", "1999999999.99999999999999991");
	add_test("1000000000.00000000000000001", "-999999999.9999999999999999", "0.00000000000000011");
	add_test("-1000000000.00000000000000001", "999999999.9999999999999999", "-0.00000000000000011");
	add_test("-1000000000.00000000000000001", "-999999999.9999999999999999", "-1999999999.99999999999999991");
	add_test("79228162514264337593543950334", "1", "79228162514264337593543950335");
	add_test("3295", "8", "3303");
	add_test("9996666", "3334", "10000000");
	add_test("99999999999999999999", "1", "100000000000000000000");
	// The decimal is round down on overflow
	add_test("123456789123456789123456789", "0.12345678912345678912345678901234", "123456789123456789123456789.123456789");
	add_test("1678165131.16", "9654.6466879411111111", "1678174785.8066879411111111");
	add_test("8974165.41564", "-8974165564", "-8965191398.58436");
	add_test("11111111111165.41564", "-897411111111.65564", "10213700000053.76");
	add_test("11111", "100000000000000000000", "100000000000000011111");
	add_test("987654321009876543210", "987654321009876543210", "1975308642019753086420");
	add_test("98.7654321009876543210", "987654321009.876543210", "987654321108.641975310987654321");
	add_test("0.1", "0.1", "0.2");
	add_test("0.3", "0.0333333333333333333", "0.3333333333333333333");
	add_test("1000", "912345756978465", "912345756979465");
	add_test("999999999.9999", "999999999.9999", "1999999999.9998");
	add_test("980.8", "3.1415926535", "983.9415926535");
	add_test("1", "10", "11");
	add_test("1", "1000000000000", "1000000000001");
	add_test("89718", "8971899798271890987", "8971899798271980705");
	add_test("777", "223", "1000");
	add_test("123456", "1.05", "123457.05");
	add_test("123456", "1.08", "123457.08");
	add_test("123456", "1.10", "123457.1");
	add_test("-10000000000000000000000000000", "-0.000000000000000000000000000000001", "-10000000000000000000000000000");
	add_test("100", "-110", "-10");
	add_test("100", "-999", "-899");
	add_test("10000000000000000000000", "-11000000000000000000000", "-1000000000000000000000");
	add_test("1000000.00", "1000000.00", "2000000");
	add_test("1000000.00", "-1000000.00", "0");
	add_test("-1000000.00", "1000000.00", "0");
	add_test("1000000.99", "-1000000.00", "0.99");
	add_test("-1000000.00", "1000000.99", "0.99");
	add_test("-1000000.00", "-1000000.99", "-2000000.99");
	add_test("100000000000000000000000000.00", "100000000000000000000000000.00", "200000000000000000000000000");
	add_test("100000000000000000000000000.00", "-100000000000000000000000000.00", "0");
	add_test("-100000000000000000000000000.00", "100000000000000000000000000.00", "0");
	add_test("100000000000000000000000000.99", "-100000000000000000000000000.00", "0.99");
	add_test("-100000000000000000000000000.00", "100000000000000000000000000.99", "0.99");
	add_test("-100000000000000000000000000.00", "-100000000000000000000000000.99", "-200000000000000000000000000.99");
	add_test("100000000000.55", "10000000000000.000000000999", "10100000000000.550000000999");
	add_test("100000000000.55", "-10000000000000.000000000999", "-9899999999999.450000000999");
	add_test("-100000000000.55", "10000000000000.000000000999", "9899999999999.450000000999");
	add_test("10000000000000.000000000999", "-100000000000.55", "9899999999999.450000000999");
	add_test("-10000000000000.000000000999", "100000000000.55", "-9899999999999.450000000999");
	add_test("-10000000000000.000000000999", "-100000000000.55", "-10100000000000.550000000999");
	add_test("0", "10000000000000.000000000999", "10000000000000.000000000999");
	add_test("10000000000000.000000000999", "0", "10000000000000.000000000999");
	add_test("0", "-10000000000000.000000000999", "-10000000000000.000000000999");
	add_test("-10000000000000.000000000999", "0", "-10000000000000.000000000999");
	add_test("1000.0005", "1000.0005", "2000.001");
	add_test("1000.0005", "100.0005", "1100.001");
	add_test("1000.0005", "10.0005", "1010.001");
	add_test("1000.0005", "1.0005", "1001.001");
	add_test("999999999999999999999999999999.0", "0.000000000000000000001", "999999999999999999999999999999");
	add_test("999999999999999999999999999999.0", "0.0000000000000000009999999999", "999999999999999999999999999999");
	add_test("999999999999999999999999999999.0", "-0.0000000000000000009999999999", "999999999999999999999999999998.999999");

	Assert::WriteLine(L"TEST mg_decimal_add(): OK\n");
}

void DecimalTestDotNetHard::TestMethod_add_test()
{
	Assert::WriteLineSpace();
	Assert::WriteLine(L"");
	Assert::WriteLine(L"TestMethod_Convert_compare_test test");
	Assert::WriteLine(L"");
	decimal_add_test();
}

void DecimalTestDotNetHard::subtract_test(const char* text1, const char* text2, const char* ret)
{
	Decimal value1, value2;
	bool p1 = Decimal::TryParse(text1, &value1);
	bool p2 = Decimal::TryParse(text2, &value2);

	if (p1 && p2)
	{
		Decimal value3 = value1 - value2;

		Assert::IsTrue(value3.ToString() == ret);
	}
	else
	{
		Assert::WriteLine(L"Parse overflow");
	}
}

void DecimalTestDotNetHard::decimal_subtract_test()
{
	subtract_test("1", "1", "0");
	subtract_test("1", "-1", "2");
	subtract_test("1", "0", "1");
	subtract_test("0", "1", "-1");
	subtract_test("100000000000000000000", "10000000000000000", "99990000000000000000");
	subtract_test("100000000000000000000", "-10000000000000000", "100010000000000000000");
	subtract_test("-1000000.000001", "99.99", "-1000099.990001");
	subtract_test("1000000000.00000000000000001", "999999999.9999999999999999", "0.00000000000000011");
	subtract_test("1000000000.00000000000000001", "-999999999.9999999999999999", "1999999999.99999999999999991");
	subtract_test("9999999999999999999999999999999998", "9999999999999999999999999999999999", "-1");
	subtract_test("123456789123456789123456789", "-0.123456789123456789123456789", "123456789123456789123456789.123456789");
	subtract_test("99999999999999999999999", "9999999999999999999999999", "-9900000000000000000000000");

	Assert::WriteLine(L"TEST mg_decimal_subtract(): OK\n");
}

void DecimalTestDotNetHard::TestMethod_subtract_test()
{
	Assert::WriteLineSpace();
	Assert::WriteLine(L"");
	Assert::WriteLine(L"TestMethod_subtract_test test");
	Assert::WriteLine(L"");
	decimal_subtract_test();
}

void DecimalTestDotNetHard::negative_test(const char* text, const char* ret)
{
	Decimal value(text);
	value = -value;
	Assert::IsTrue(value.ToString() == ret);
}

void DecimalTestDotNetHard::decimal_negative_test()
{
	negative_test("1", "-1");
	negative_test("0", "0");
	negative_test("-1", "1");
	negative_test("-100000000000000000000", "100000000000000000000");
	negative_test("100000000000000000000", "-100000000000000000000");
	negative_test("-312654515641615641", "312654515641615641");
	negative_test("312654515641615641", "-312654515641615641");
	negative_test("-3126545156416156412134111101544963", "3126545156416156412134111101544963");
	negative_test("3126545156416156412134111101544963", "-3126545156416156412134111101544963");
	negative_test("-18446744073709551616", "18446744073709551616");
	negative_test("18446744073709551616", "-18446744073709551616");
	negative_test("-31265", "31265");
	negative_test("31265", "-31265");

	Assert::WriteLine(L"TEST mg_decimal_negate(): OK\n");
}

void DecimalTestDotNetHard::TestMethod_negative_test()
{
	Assert::WriteLineSpace();
	Assert::WriteLine(L"");
	Assert::WriteLine(L"TestMethod_negative_test test");
	Assert::WriteLine(L"");
	decimal_negative_test();
}

void DecimalTestDotNetHard::multiply_test(const char* text1, const char* text2, const char* ret)
{
	Decimal value1, value2;
	bool p1 = Decimal::TryParse(text1, &value1);
	bool p2 = Decimal::TryParse(text2, &value2);

	if (p1 && p2)
	{
		Decimal value3 = value1 * value2;

		Assert::IsTrue(value3.ToString() == ret);
	}
	else
	{
		Assert::WriteLine(L"Parse overflow");
	}
}

void DecimalTestDotNetHard::overflow_test(const char* text1, const char* text2)
{
	Decimal value1(text1), value2(text2);
	Decimal value3 = value1 * value2;

	//Assert::IsTrue(decimal::mg_decimal_multiply(&value1, &value2, /*out*/&value3) == mgE_OVERFLOW);
}

void DecimalTestDotNetHard::decimal_multiply_test()
{
	multiply_test("1000000", "1000000", "1000000000000");
	multiply_test("1000000000000", "1000000000000", "1000000000000000000000000");
	multiply_test("-1000000", "1000000", "-1000000000000");
	multiply_test("1000000000000", "-1000000000000", "-1000000000000000000000000");
	multiply_test("1000000000000", "1000000", "1000000000000000000");
	multiply_test("1000000", "0.000001", "1");
	multiply_test("1000000000000", "0.000000000001", "1");
	multiply_test("1000000", "10.5", "10500000");
	multiply_test("1000000.555", "1000", "1000000555");
	multiply_test("1000000.000000000000555", "1000000000000000", "1000000000000000000555");
	multiply_test("1000000.000000000000555", "-1000000000000000", "-1000000000000000000555");
	multiply_test("0.00000000000000000000000000001", "100000000000000000000000000000", "1");
	multiply_test("1678165131.16", "9654.6466879411111111", "16202091425372.154318115264831876");
	multiply_test("8974165.41564", "-8974165564", "-80535646238676235.02096");
	multiply_test("11111111111165.41564", "-897411111111.65564", "-9971234567956018376497461.6691502096");
	multiply_test("11111", "100000000000000000000", "1111100000000000000000000");
	multiply_test("98765432100", "9876543210", "975461057789971041000");
	multiply_test("98.7654321009876", "987654321009.8765", "97546105780947.9682975650040314");
	multiply_test("0.1", "0.1", "0.01");
	multiply_test("0.3", "0.0333333333333333333", "0.00999999999999999999");
	multiply_test("1000", "912345756978465", "912345756978465000");
	multiply_test("999999999.9999", "999999999.9999", "999999999999800000.00000001");
	multiply_test("980.8", "3.1415926535", "3081.2740745528");
	multiply_test("1", "10", "10");
	multiply_test("1", "1000000000000", "1000000000000");
	multiply_test("89718", "8971899798271890987", "804940906101357515571666");
	multiply_test("777", "223", "173271");
	multiply_test("123456", "1.05", "129628.8");
	multiply_test("123456", "1.08", "133332.48");
	multiply_test("123456", "1.10", "135801.6");
	multiply_test("1", "0.1", "0.1");
	multiply_test("1123456", "0.000001", "1.123456");
	multiply_test("10000000000000000000000", "0.0000000000000000000001", "1");
	multiply_test("0.0001", "0.0001", "0.00000001");
	multiply_test("10000", "0.0001", "1");
	multiply_test("0.0000000001", "0.0000000001", "0.00000000000000000001");
	multiply_test("0.0000000008", "0.0000000008", "0.00000000000000000064");
	multiply_test("-0.0000000008", "0.0000000008", "-0.00000000000000000064");
	multiply_test("0.0000000008", "-0.0000000008", "-0.00000000000000000064");
	multiply_test("-0.0000000008", "-0.0000000008", "0.00000000000000000064");
	multiply_test("-10", "-10", "100");
	multiply_test("-100", "-100", "10000");
	multiply_test("-100000", "-100000", "10000000000");
	multiply_test("-100000000", "-100000000", "10000000000000000");
	multiply_test("-100000000000", "-100000000000", "10000000000000000000000");
	multiply_test("-100000000000000", "-100000000000000", "10000000000000000000000000000");
	multiply_test("1234567", "1234567", "1524155677489");
	multiply_test("123456789", "123456789", "15241578750190521");
	multiply_test("1234567891234", "1234567891234", "1524157878065965654042756");
	multiply_test("123456789123456", "123456789123456", "15241578780673483700809383936");
	multiply_test("12345678912345600", "12345678912345600", "152415787806734837008093839360000");
	multiply_test("239541530454123456978132", "3333", "798391921003593482108113956");
	multiply_test("12331", "239541530454123456978132", "2953786612029796347997345692");
	multiply_test("20498", "0.78", "15988.44");
	multiply_test("9979", "0.87", "8681.73");

	multiply_test("0.00000000123412", "89145604156", "110.01637300100272");
	multiply_test("89145604156", "0.00000000123412", "110.01637300100272");
	multiply_test("0.00000000123412", "0.0000012312", "0.000000000000001519448544");
	multiply_test("0.0000012312", "0.00000000123412", "0.000000000000001519448544");
	multiply_test("-0.00000000123412", "0.0000012312", "-0.000000000000001519448544");
	multiply_test("0.0000012312", "-0.00000000123412", "-0.000000000000001519448544");
	multiply_test("-0.00000000123412", "89145604156", "-110.01637300100272");
	multiply_test("89145604156", "-0.00000000123412", "-110.01637300100272");
	multiply_test("0.00000000123412", "-0.0000012312", "-0.000000000000001519448544");
	multiply_test("-0.0000012312", "0.00000000123412", "-0.000000000000001519448544");
	multiply_test("0.00000000123412", "-89145604156", "-110.01637300100272");
	multiply_test("-89145604156", "0.00000000123412", "-110.01637300100272");

	overflow_test("99999999999999999999999999.0", "99999999999999999999999999.0");
	overflow_test("199999999999999999999999999.0", "199999999999999999999999999.0");

	Assert::WriteLine(L"TEST mg_decimal_multiply(): OK\n");
}

void DecimalTestDotNetHard::TestMethod_multiply_test()
{
	Assert::WriteLineSpace();
	Assert::WriteLine(L"");
	Assert::WriteLine(L"TestMethod_multiply_test test");
	Assert::WriteLine(L"");
	decimal_multiply_test();
}

void DecimalTestDotNetHard::divide_test(const char* text1, const char* text2, const char* ret)
{
	Decimal value1(text1), value2(text2);
	Decimal value3 = value1 / value2;

	Assert::IsTrue(value3.ToString() == ret);

	Decimal value4 = value1 / value2;
	Decimal value5 = value1 % value2;
	//Assert::IsTrue(decimal::mg_decimal_round(/*inout*/&value3, 0, mgDECIMAL_ROUND_DOWN) == 0);
	//Assert::IsTrue(decimal::mg_decimal_compare(&value3, &value4) == 0);
}

void DecimalTestDotNetHard::decimal_divide_test()
{
	divide_test("11111111", "10", "1111111.1");
	divide_test("11111111", "1000", "11111.111");
	divide_test("-111111111111111111111", "1000", "-111111111111111111.111");
	divide_test("-111111111111111111111", "-1000", "111111111111111111.111");
	divide_test("111111111111111111111", "-1000", "-111111111111111111.111");
	divide_test("1959", "2", "979.5");
	divide_test("1000000000000000000000", "2", "500000000000000000000");
	divide_test("1000000", "3", "333333.333333333333333333333333333333");
	divide_test("9999999999999999999999999999999999", "9999999999999999999999999999999999", "1");
	divide_test("9999999999999999999999999999999999", "1", "9999999999999999999999999999999999");
	divide_test("1", "9999999999999999999999999999999999", "0.0000000000000000000000000000000001");
	divide_test("1", "999999999999999999999999999999999", "0.000000000000000000000000000000001");
	divide_test("1678165131.16", "9654.6466879411111111", "173819.424511522428564578144929998874");
	divide_test("8974165.41564", "-8974165564", "-0.000999999983468100856624668352285371");
	divide_test("11111111111165.41564", "-897411111111.65564", "-12.3812943405633566936926641727499868");
	divide_test("11111", "100000000000000000000", "0.00000000000000011111");
	divide_test("987654321009876543210", "987654321009876543210", "1");
	divide_test("98.7654321009876543210", "987654321009.876543210", "0.0000000001");
	divide_test("0.1", "0.1", "1");
	divide_test("0.3", "0.0333333333333333333", "9.000000000000000009");
	divide_test("1", "99999999999999999999999", "0.00000000000000000000001");
	divide_test("1000", "912345756978465", "0.000000000001096075684411391403954103");
	divide_test("999999999.9999", "999999999.9999", "1");
	divide_test("980.8", "3.1415926535", "312.198336377985167070292170200352806");
	divide_test("1", "10", "0.1");
	divide_test("1", "100000000000", "0.00000000001");
	divide_test("89718", "8971899798271890987", "0.00000000000000999988876573063131011");
	divide_test("777", "223", "3.48430493273542600896860986547085201");
	divide_test("123456", "1.05", "117577.142857142857142857142857142857");
	divide_test("123456", "1.08", "114311.111111111111111111111111111111");
	divide_test("123456", "1.10", "112232.727272727272727272727272727272");
	divide_test("123456", "0.00000000000000000000000001", "12345600000000000000000000000000");
	divide_test("123456", "0.0001", "1234560000");
	divide_test("0.0000000000000000000001", "0.0000000000000000000001", "1");
	divide_test("0.000001", "2", "0.0000005");
	divide_test("0.000001", "4", "0.00000025");
	divide_test("0.000001", "8", "0.000000125");
	divide_test("0.000000000000000000001", "2", "0.0000000000000000000005");
	divide_test("0.000000000000000000001", "4", "0.00000000000000000000025");
	divide_test("0.000000000000000000001", "8", "0.000000000000000000000125");
	divide_test("-123456", "1.08", "-114311.111111111111111111111111111111");
	divide_test("-123456", "-1.08", "114311.111111111111111111111111111111");
	divide_test("123456", "-1.08", "-114311.111111111111111111111111111111");
	divide_test("1", "9999", "0.000100010001000100010001000100010001");
	divide_test("1", "999999", "0.000001000001000001000001000001000001");
	divide_test("1", "99999999999999999", "0.0000000000000000100000000000000001");
	divide_test("1", "9999999999999999999", "0.0000000000000000001");
	divide_test("100", "9", "11.1111111111111111111111111111111111");
	divide_test("0.00000000000000000000000000000000001", "4", "0.000000000000000000000000000000000002");
	divide_test("0.0000000000000000000000000000000001", "4", "0.000000000000000000000000000000000025");
	divide_test("0.0000000000000000000000000000000010", "4", "0.00000000000000000000000000000000025");
	divide_test("0.0000000000000000000000000000000100", "4", "0.0000000000000000000000000000000025");
	divide_test("12350", "333", "37.087087087087087087087087087087087");
	divide_test("123456789123456789", "333", "370741108478849.216216216216216216216");
	divide_test("123456789123456789123456789", "333", "370741108478849216586957.324324324324");
	divide_test("3212313211512654132123441131515", "3212313211512654132123441131515", "1");
	divide_test("3212313211512654132123441131515", "321231321151265413212344", "10000000.0000000000000000035224304901");
	divide_test("3212313211512654132123441131515", "3212313211512654132", "1000000000000.00000003842748928485479");
	divide_test("3212313211512654132123441131515", "321231321151", "10000000000008262370.2879630271218714");
	divide_test("3212313211512654132123441131515", "321231", "10000009997517842711704166.5702095999");
	divide_test("3212313211512654132123441131515", "2", "1606156605756327066061720565757.5");
	divide_test("3212313211512654132123441131515", "1", "3212313211512654132123441131515");
	divide_test("3212313211512654132123441131515", "321231321151265413212344", "10000000.0000000000000000035224304901");
	divide_test("3212313211512654132.123441131515", "3212313211512654132", "1.00000000000000000003842748928485479");
	divide_test("321231321151265413212.3441131515", "321231321151", "1000000000.00082623702879630271218714");
	divide_test("3212313211512654132123441131515", "321231", "10000009997517842711704166.5702095999");
	divide_test("3212313211512654132123.441131515", "2", "1606156605756327066061.7205657575");
	divide_test("321231321151265.4132123441131515", "1", "321231321151265.4132123441131515");
	divide_test("123456789.0", "101111", "1221.00255165115566061061605562203914");
	divide_test("3212313211512654132123441131516", "3212313211512654132123441131516", "1");
	divide_test("3212313211512654132123441131516", "3212313211512654132123441", "1000000.00000000000000000004094121318");
	divide_test("3212313211512654132123441131516", "32123132115126541321", "100000000000.000000000729727457210243");
	divide_test("3212313211512654132123441131516", "32123132115126", "100000000000001685.14462559651891458");
	divide_test("3212313211512654132123441131516", "32123132", "100000000358391396334686.204680041784");
	divide_test("3212313211512654132123441131516", "3212", "1000097512924238521831706454.39476961");
	divide_test("3212313211512654132123441131516", "99", "32447608197097516486095364964.8080808");
	divide_test("3212313211512654132123441131516", "16", "200769575719540883257715070719.75");
	divide_test("3212313211512654132123441131516", "8", "401539151439081766515430141439.5");
	divide_test("3212313211512654132123441131516", "7", "458901887358950590303348733073.714285");
	divide_test("3212313211512654132123441131516", "4", "803078302878163533030860282879");
	divide_test("3212313211512654132123441131516", "2", "1606156605756327066061720565758");
	divide_test("3212313211512654132123441131516", "1", "3212313211512654132123441131516");
	divide_test("999999999999999999999999999999999999", "999999999999999999999999999999999999", "1");
	divide_test("9999999999999999999999999999999999", "9999999999999999999999999999999999", "1");
	divide_test("9999999999999999999999999999999999", "9999999999999999999999999999999", "1000.0000000000000000000000000000999");
	divide_test("9999999999999999999999999999999999", "9999999999999999999999999999", "1000000.0000000000000000000000999999");
	divide_test("9999999999999999999999999999999999", "9999999999999999999999999", "1000000000.0000000000000000999999999");
	divide_test("9999999999999999999999999999999999", "9999999999999999999999", "1000000000000.0000000000999999999999");
	divide_test("9999999999999999999999999999999999", "9999999999999999999", "1000000000000000.0000999999999999999");
	divide_test("9999999999999999999999999999999999", "9999999999999999", "1000000000000000100.0000000000000099");
	divide_test("9999999999999999999999999999999999", "9999999999999", "1000000000000100000000.0000099999999");
	divide_test("9999999999999999999999999999999999", "9999999999", "1000000000100000000010000.0000009999");
	divide_test("9999999999999999999999999999999999", "9999999", "1000000100000010000001000000.0999999");
	divide_test("9999999999999999999999999999999999", "9999", "1000100010001000100010001000100.0099");
	divide_test("9999999999999999999999999999999999", "9", "1111111111111111111111111111111111");
	divide_test("81", "9", "9");
	divide_test("1000.0005", "1000.0005", "1");
	divide_test("1000.0005", "100.0005", "9.99995500022499887500562497187514062");
	divide_test("1000.0005", "10.0005", "99.9950502474876256187190640467976601");
	divide_test("1000.0005", "1.0005", "999.500749625187406296851574212893553");
	divide_test("-1959", "2", "-979.5");
	divide_test("1959", "-2", "-979.5");
	divide_test("-1959", "-2", "979.5");
	divide_test("100000000000000000000000000000000", "10000000000000000000000000000000", "10");
	divide_test("100000000000000000000000000000000", "10000000000000000000000000000", "10000");
	divide_test("100000000000000000000000000000000", "100000000000000000000000", "1000000000");
	divide_test("100000000000000000000000000000000", "1000000000000000000", "100000000000000");
	divide_test("100000000000000000000000000000000", "1000000000000", "100000000000000000000");
	divide_test("100000000000000000000000000000000", "1000000", "100000000000000000000000000");
	divide_test("100000000000000000000000000000000", "10", "10000000000000000000000000000000");
	divide_test("10000000000000000000000000000", "100000000000000000000000000000000", "0.0001");
	divide_test("100000000000000000000000", "100000000000000000000000000000000", "0.000000001");
	divide_test("1000000000000000000", "100000000000000000000000000000000", "0.00000000000001");
	divide_test("1000000000000", "100000000000000000000000000000000", "0.00000000000000000001");
	divide_test("1000000", "100000000000000000000000000000000", "0.00000000000000000000000001");
	divide_test("100000000000000000000000000", "100000000000000000000000000", "1");
	divide_test("100000000000000000000000000", "10000000000000000000000", "10000");
	divide_test("100000000000000000000000000", "100000000000000000", "1000000000");
	divide_test("100000000000000000000000000", "100000000000000", "1000000000000");
	divide_test("100000000000000000000000000", "1000000000000", "100000000000000");
	divide_test("100000000000000000000000000", "1000000", "100000000000000000000");
	divide_test("100000000000000000000000000", "10", "10000000000000000000000000");
	divide_test("100000000000000000000000000", "100000000000000000000000000", "1");
	divide_test("10000000000000000000000", "100000000000000000000000000", "0.0001");
	divide_test("100000000000000000", "100000000000000000000000000", "0.000000001");
	divide_test("100000000000000", "100000000000000000000000000", "0.000000000001");
	divide_test("1000000000000", "100000000000000000000000000", "0.00000000000001");
	divide_test("1000000", "100000000000000000000000000", "0.00000000000000000001");
	divide_test("10", "100000000000000000000000000", "0.0000000000000000000000001");
	divide_test("10000000000000000000000", "10000000000000000000000", "1");
	divide_test("10000000000000000000000", "100000000000000000", "100000");
	divide_test("10000000000000000000000", "100000000000000", "100000000");
	divide_test("10000000000000000000000", "1000000000000", "10000000000");
	divide_test("10000000000000000000000", "1000000", "10000000000000000");
	divide_test("10000000000000000000000", "10", "1000000000000000000000");
	divide_test("10000000000000000000000", "10000000000000000000000", "1");
	divide_test("100000000000000000", "10000000000000000000000", "0.00001");
	divide_test("100000000000000", "10000000000000000000000", "0.00000001");
	divide_test("1000000000000", "10000000000000000000000", "0.0000000001");
	divide_test("1000000", "10000000000000000000000", "0.0000000000000001");
	divide_test("10", "10000000000000000000000", "0.000000000000000000001");
	divide_test("100000000000000000", "100000000000000000", "1");
	divide_test("100000000000000000", "100000000000000", "1000");
	divide_test("100000000000000000", "1000000000000", "100000");
	divide_test("100000000000000000", "1000000", "100000000000");
	divide_test("100000000000000000", "10", "10000000000000000");
	divide_test("100000000000000000", "100000000000000000", "1");
	divide_test("1000000000000", "100000000000000000", "0.00001");
	divide_test("1000000", "100000000000000000", "0.00000000001");
	divide_test("10", "100000000000000000", "0.0000000000000001");
	divide_test("10000000000000", "10000000000000", "1");
	divide_test("10000000000000", "1000000", "10000000");
	divide_test("10000000000000", "10", "1000000000000");
	divide_test("10000000000000", "10000000000000", "1");
	divide_test("1000000", "10000000000000", "0.0000001");
	divide_test("10", "10000000000000", "0.000000000001");
	divide_test("10000000", "10000000", "1");
	divide_test("10000000", "10000", "1000");
	divide_test("10000000", "10", "1000000");
	divide_test("10000000", "10000000", "1");
	divide_test("10000", "10000000", "0.001");
	divide_test("10", "10000000", "0.000001");
	divide_test("10000000", "10000000", "1");
	divide_test("10000000", "10000", "1000");
	divide_test("10000000", "10", "1000000");
	divide_test("10000000", "10000000", "1");
	divide_test("10000", "10000000", "0.001");
	divide_test("10", "10000000", "0.000001");
	divide_test("10000000", "-10000000", "-1");
	divide_test("10000000", "-10000", "-1000");
	divide_test("10000000", "-10", "-1000000");
	divide_test("10000000", "-10000000", "-1");

	Assert::WriteLine(L"TEST mg_decimal_divide(): OK\n");
}

void DecimalTestDotNetHard::TestMethod_divide_test()
{
	Assert::WriteLineSpace();
	Assert::WriteLine(L"");
	Assert::WriteLine(L"TestMethod_divide_test test");
	Assert::WriteLine(L"");
	decimal_divide_test();
}

void DecimalTestDotNetHard::divide_and_modulus_test(const char* text1, const char* text2, const char* ret, const char* reminder)
{
	Decimal value1(text1), value2(text2);
	Decimal value3 = value1 / value2;
	Decimal value4 = value1 % value2;

	Assert::IsTrue(value3.ToString() == ret);
	Assert::IsTrue(value4.ToString() == reminder);
}

void DecimalTestDotNetHard::divide_and_modulus_test2(const char* text1, const char* text2)
{
	Decimal value1(text1), value2(text2);

	Decimal q = value1 / value2;
	Decimal r = value1 % value2;
	Decimal tmp = q * value2;
	tmp = r + tmp;

	Assert::IsTrue(tmp.CompareTo(value1) == 0);
}

void DecimalTestDotNetHard::decimal_divide_and_modulus_test()
{
	divide_and_modulus_test("9999999999999999999999999999999999", "9999999999999999999999999999999999", "1", "0");
	divide_and_modulus_test("-111111111111111111111", "-1000", "111111111111111111", "-111");
	divide_and_modulus_test("-111111111111111111111", "-1000", "111111111111111111", "-111");
	divide_and_modulus_test("1000000000000000000000000000", "3", "333333333333333333333333333", "1");
	divide_and_modulus_test("1959", "2", "979", "1");
	divide_and_modulus_test("100", "0.01", "10000", "0");
	divide_and_modulus_test("100.01", "0.01", "10001", "0");
	divide_and_modulus_test("100.005000000", "0.06", "1666", "0.045");
	divide_and_modulus_test("100.005", "0.06", "1666", "0.045");
	divide_and_modulus_test("100.11111", "0.1", "1001", "0.01111");
	divide_and_modulus_test("19999.999", "32", "624", "31.999");
	divide_and_modulus_test("1", "0.000000001", "1000000000", "0");
	divide_and_modulus_test("984615112", "15641", "62950", "14162");
	divide_and_modulus_test("3212313211512654132123441131515", "3212313211512654132123441131515", "1", "0");
	divide_and_modulus_test("3212313211512654132123441131515", "321231321151265413212344", "10000000", "1131515");
	divide_and_modulus_test("3212313211512654132123441131515", "3212313211512654132", "1000000000000", "123441131515");
	divide_and_modulus_test("3212313211512654132123441131515", "321231321151", "10000000000008262370", "92502743645");
	divide_and_modulus_test("3212313211512654132123441131515", "321231", "10000009997517842711704166", "183169");
	divide_and_modulus_test("3212313211512654132123441131515", "2", "1606156605756327066061720565757", "1");
	divide_and_modulus_test("3212313211512654132123441131515", "1", "3212313211512654132123441131515", "0");
	divide_and_modulus_test("32123132115126541321234.41131515", "3212313211512654132123441131515", "0", "32123132115126541321234.41131515");
	divide_and_modulus_test("32123132115126541321234.41131515", "321231321151265413212344", "0", "32123132115126541321234.41131515");
	divide_and_modulus_test("321231321151265413212344.1131515", "3212313211512654132", "100000", "12344.1131515");
	divide_and_modulus_test("321231321151265413212.3441131515", "321231321151", "1000000000", "265413212.3441131515");
	divide_and_modulus_test("321231321151265413.2123441131515", "321231", "1000000999751", "251932.2123441131515");
	divide_and_modulus_test("3212313211512654132123441.131515", "2", "1606156605756327066061720", "1.131515");
	divide_and_modulus_test("321231321151265413.2123441131515", "1", "321231321151265413", "0.2123441131515");
	divide_and_modulus_test("18446744073709551616", "18446744073709551616", "1", "0");
	divide_and_modulus_test("18446744073709551616", "500000000", "36893488147", "209551616");
	divide_and_modulus_test("18446744073709551616", "35.300", "522570653646162935", "10.5");
	divide_and_modulus_test("18446744073709551616", "3500000.300000", "5270497855017", "695110.9");
	divide_and_modulus_test("-18446744073709551616", "18446744073709551616", "-1", "0");
	divide_and_modulus_test("18446744073709551616", "-500000000", "-36893488147", "209551616");
	divide_and_modulus_test("-18446744073709551616", "-35.300", "522570653646162935", "-10.5");

	// divide/modulusåüéZ
	divide_and_modulus_test2("546456040", "4654156");
	divide_and_modulus_test2("1", "3");
	divide_and_modulus_test2("1", "-3");
	divide_and_modulus_test2("-1", "-3");
	divide_and_modulus_test2("999999956465465.141", "33.3");
	divide_and_modulus_test2("987456", "62.5");
	divide_and_modulus_test2("333333333333", "3");
	divide_and_modulus_test2("987654321", "11111111111111111111");
	divide_and_modulus_test2("11111111111111111111", "9871987");
	divide_and_modulus_test2("1111111111111.1111111", "987.1987");
	divide_and_modulus_test2("-99999995.141", "-33.64654653");
	divide_and_modulus_test2("33.33333", "33.3");
	divide_and_modulus_test2("33300000000000000000000", "33.3");
	divide_and_modulus_test2("33300000000000000000001", "33.3");
	divide_and_modulus_test2("391887191456", "35215331.156234");
	divide_and_modulus_test2("9875424163165", "3");
	divide_and_modulus_test2("21121", "22332323");
	divide_and_modulus_test2("15000.0004", "15000.0004");
	divide_and_modulus_test2("15000.0004", "15000.0004");
	divide_and_modulus_test2("-15000.0004", "15000.0004");
	divide_and_modulus_test2("798798798111789784561211144", "7987987987987987.98798");
	divide_and_modulus_test2("798798798111789784561211144", "-7987987987987987.98798");
	//divide_and_modulus_test2("798798798111789784561211112944", "79.8798798798798798798"); //@J åvéZåÎç∑Ç≈ïsàÍív
	divide_and_modulus_test2("79879879811178978456121111294489", "1000000000000000000000");
	divide_and_modulus_test2("798798798111789784561211112944891", "1000000000000000000000");
	divide_and_modulus_test2("150.4", "1500");
	divide_and_modulus_test2("8888888888888888", "2");
	divide_and_modulus_test2("8888888888888888", "4");
	divide_and_modulus_test2("8888888888888888", "8");
	divide_and_modulus_test2("8888888888888888", "3");
	divide_and_modulus_test2("8888888888888888", "-2");
	divide_and_modulus_test2("8888888888888888", "-4");
	divide_and_modulus_test2("8888888888888888", "-8");
	divide_and_modulus_test2("8888888888888888", "-3");
	divide_and_modulus_test2("-8888888888888888", "-2");
	divide_and_modulus_test2("-8888888888888888", "-4");
	divide_and_modulus_test2("-8888888888888888", "-8");
	divide_and_modulus_test2("-8888888888888888", "-3");
	divide_and_modulus_test2("-8888888888888888", "2");
	divide_and_modulus_test2("-8888888888888888", "4");
	divide_and_modulus_test2("-8888888888888888", "8");
	divide_and_modulus_test2("-8888888888888888", "3");
	divide_and_modulus_test2("123456", "0.00000000000000000000000001");
	divide_and_modulus_test2("-48941513131", "0.000000000461651");
	divide_and_modulus_test2("-4894151", "0.000000461651");
	divide_and_modulus_test2("-897798788465145641454134", "0.0000000003");
	divide_and_modulus_test2("-897798", "0.000000000000000084615533");
	divide_and_modulus_test2("897798", "-0.000000000000000084615533");
	divide_and_modulus_test2("-897798", "-0.000000000000000084615533");
	divide_and_modulus_test2("-897798999999999999", "-0.003");
	divide_and_modulus_test2("-89779899999999999131539", "-0.099");
	divide_and_modulus_test2("-0.0000000000008", "254");
	divide_and_modulus_test2("-0.0000000000008", "0.00000000000000254");
	divide_and_modulus_test2("-0.0000000000008", "0.0000000000000254");
	divide_and_modulus_test2("-0.0000000000008", "0.000000000000254");
	divide_and_modulus_test2("-0.0000000000008", "0.00000000000254");
	divide_and_modulus_test2("-0.0000000000008", "0.0000000000254");
	divide_and_modulus_test2("-897798999999999991315", "-0.099");
	divide_and_modulus_test2("-8977989999999999913", "-0.099");
	divide_and_modulus_test2("-8977989999999999", "-0.099");
	divide_and_modulus_test2("-89779899999999", "-0.099");
	divide_and_modulus_test2("-897798999999", "-0.099");
	divide_and_modulus_test2("-8977989999", "-0.099");
	divide_and_modulus_test2("-89779899", "-0.099");
	divide_and_modulus_test2("-897798", "-0.099");
	divide_and_modulus_test2("-8977", "-0.099");
	divide_and_modulus_test2("-89", "-0.099");

	Assert::WriteLine(L"TEST mg_decimal_divide_and_modulus(): OK\n");
}

void DecimalTestDotNetHard::TestMethod_divide_and_modulus_test()
{
	Assert::WriteLineSpace();
	Assert::WriteLine(L"");
	Assert::WriteLine(L"TestMethod_divide_and_modulus_test test");
	Assert::WriteLine(L"");
	decimal_divide_and_modulus_test();
}

void DecimalTestDotNetHard::modulus_test(const char* text1, const char* text2, const char* ret)
{
	Decimal value1(text1), value2(text2);
	Decimal value3 = value1 % value2;
	Assert::IsTrue(value3.ToString() == ret);
}

void DecimalTestDotNetHard::decimal_modulus_test()
{
	modulus_test("100000000000", "3", "1");
	modulus_test("8", "3", "2");

	Assert::WriteLine(L"TEST mg_decimal_modulus(): OK\n");
}

void DecimalTestDotNetHard::TestMethod_modulus_test()
{
	Assert::WriteLineSpace();
	Assert::WriteLine(L"");
	Assert::WriteLine(L"TestMethod_modulus_test test");
	Assert::WriteLine(L"");
	decimal_modulus_test();
}

void DecimalTestDotNetHard::error_test()
{
	//decimal v1, v2, v3, v4;

	//Assert::IsTrue(decimal::mg_decimal_parse_string("519229685853482762853049632922009699", &v1) == 0);
	//Assert::IsTrue(decimal::mg_decimal_parse_string("519229685853482762853049632922009699", &v2) == 0);
	//Assert::IsTrue(decimal::mg_decimal_add(&v1, &v2, /*out*/&v3) == mgE_OVERFLOW);

	//Assert::IsTrue(decimal::mg_decimal_parse_string("999999999999999999999999999999999999", &v1) == 0);
	//Assert::IsTrue(decimal::mg_decimal_parse_string("1", &v2) == 0);
	//Assert::IsTrue(decimal::mg_decimal_add(&v1, &v2, /*out*/&v3) == mgE_OVERFLOW);

	//Assert::IsTrue(decimal::mg_decimal_parse_string("999999999999999999999999999999999999", &v1) == 0);
	//Assert::IsTrue(decimal::mg_decimal_parse_string("1", &v2) == 0);
	//Assert::IsTrue(decimal::mg_decimal_add(&v2, &v1, /*out*/&v3) == mgE_OVERFLOW);

	//Assert::IsTrue(decimal::mg_decimal_parse_string("999999999999999999999999999999999999", &v1) == 0);
	//Assert::IsTrue(decimal::mg_decimal_parse_string("-1", &v2) == 0);
	//Assert::IsTrue(decimal::mg_decimal_subtract(&v1, &v2, /*out*/&v3) == mgE_OVERFLOW);

	//Assert::IsTrue(decimal::mg_decimal_parse_string("519229685853482762853049632922009699", &v1) == 0);
	//Assert::IsTrue(decimal::mg_decimal_parse_string("-519229685853482762853049632922009699", &v2) == 0);
	//Assert::IsTrue(decimal::mg_decimal_subtract(&v1, &v2, /*out*/&v3) == mgE_OVERFLOW);

	//Assert::IsTrue(decimal::mg_decimal_parse_string("999999999999999999999999999999999999", &v1) == 0);
	//Assert::IsTrue(decimal::mg_decimal_parse_string("2", &v2) == 0);
	//Assert::IsTrue(decimal::mg_decimal_multiply(&v1, &v2, /*out*/&v3) == mgE_OVERFLOW);

	//Assert::IsTrue(decimal::mg_decimal_parse_string("5192296858534827628530496329220096", &v1) == 0);
	//Assert::IsTrue(decimal::mg_decimal_parse_string("5192296858534827628530496329220096", &v2) == 0);
	//Assert::IsTrue(decimal::mg_decimal_multiply(&v1, &v2, /*out*/&v3) == mgE_OVERFLOW);

	//Assert::IsTrue(decimal::mg_decimal_parse_string("1000000000000000000", &v1) == 0);
	//Assert::IsTrue(decimal::mg_decimal_parse_string("1000000000000000000", &v2) == 0);
	//Assert::IsTrue(decimal::mg_decimal_multiply(&v1, &v2, /*out*/&v3) == mgE_OVERFLOW);

	//Assert::IsTrue(decimal::mg_decimal_parse_string("9999999999999999999999999999999999", &v1) == 0);
	//Assert::IsTrue(decimal::mg_decimal_parse_string("0", &v2) == 0);
	//Assert::IsTrue(decimal::mg_decimal_divide(&v1, &v2, /*out*/&v3) == mgE_ZERODIVIDE);

	//Assert::IsTrue(decimal::mg_decimal_parse_string("9999999999999999999999999999999999", &v1) == 0);
	//Assert::IsTrue(decimal::mg_decimal_parse_string("0", &v2) == 0);
	//Assert::IsTrue(decimal::mg_decimal_divide_and_modulus(&v1, &v2, /*out*/&v3, /*out*/&v4) == mgE_ZERODIVIDE);

	//Assert::IsTrue(decimal::mg_decimal_parse_string("999999999999999999999999999999999999", &v1) == 0);
	//Assert::IsTrue(decimal::mg_decimal_parse_string("0.1", &v2) == 0);
	//Assert::IsTrue(decimal::mg_decimal_divide_and_modulus(&v1, &v2, /*out*/&v3, /*out*/&v4) == mgE_OVERFLOW);
}

void DecimalTestDotNetHard::decimal_error_test()
{
	error_test();

	Assert::WriteLine(L"TEST mg_decimal error pattern: OK\n");
}

void DecimalTestDotNetHard::TestMethod_error_test()
{
	Assert::WriteLineSpace();
	Assert::WriteLine(L"");
	Assert::WriteLine(L"TestMethod_error_test test");
	Assert::WriteLine(L"");
	decimal_error_test();
}

void DecimalTestDotNetHard::round_test(const char* text, int precision, int type, const char* ret)
{
	Decimal value1(text);
	value1 = Decimal::Round(value1, precision, (MidpointRoundings)type);
	Assert::IsTrue(value1.ToString() == ret);
}

void DecimalTestDotNetHard::Truncate_test(const char* text, const char* ret)
{
	Decimal value1(text);
	value1 = Decimal::Truncate(value1);
	Assert::IsTrue(value1.ToString() == ret);
}

void DecimalTestDotNetHard::decimal_round_test()
{
	//round_test("10.0015", 3, mgDECIMAL_ROUND_UP, "10.002");
	//round_test("10.0015", 3, mgDECIMAL_ROUND_DOWN, "10.001");
	//round_test("10.0015", 3, mgDECIMAL_ROUND_OFF, "10.002");
	//round_test("10.0014", 3, mgDECIMAL_ROUND_OFF, "10.001");
	//round_test("10.0014", 3, mgDECIMAL_ROUND_UP, "10.002");
	//round_test("10.0014", 3, mgDECIMAL_ROUND_DOWN, "10.001");
	//round_test("10.000000000000000000000015", 23, mgDECIMAL_ROUND_UP, "10.00000000000000000000002");
	//round_test("10.000000000000000000000015", 23, mgDECIMAL_ROUND_DOWN, "10.00000000000000000000001");
	//round_test("10.000000000000000000000015", 23, mgDECIMAL_ROUND_OFF, "10.00000000000000000000002");
	//round_test("10.000000000000000000000014", 23, mgDECIMAL_ROUND_OFF, "10.00000000000000000000001");
	//round_test("10.000000000000000000000014", 23, mgDECIMAL_ROUND_UP, "10.00000000000000000000002");
	//round_test("10.000000000000000000000014", 23, mgDECIMAL_ROUND_DOWN, "10.00000000000000000000001");

	//round_test("10.001412345679", 3, mgDECIMAL_ROUND_DOWN, "10.001");
	//round_test("10.001512345679", 3, mgDECIMAL_ROUND_DOWN, "10.001");
	//round_test("10.00141", 3, mgDECIMAL_ROUND_DOWN, "10.001");
	//round_test("10.00159", 3, mgDECIMAL_ROUND_DOWN, "10.001");
	//round_test("10.00141211", 3, mgDECIMAL_ROUND_DOWN, "10.001");
	//round_test("10.00151111", 3, mgDECIMAL_ROUND_DOWN, "10.001");

	//round_test("10.001412345679", 3, mgDECIMAL_ROUND_UP, "10.002");
	//round_test("10.001512345679", 3, mgDECIMAL_ROUND_UP, "10.002");
	//round_test("10.00141", 3, mgDECIMAL_ROUND_UP, "10.002");
	//round_test("10.00159", 3, mgDECIMAL_ROUND_UP, "10.002");
	//round_test("10.00141211", 3, mgDECIMAL_ROUND_UP, "10.002");
	//round_test("10.00151111", 3, mgDECIMAL_ROUND_UP, "10.002");

	//round_test("10.001412345679", 3, mgDECIMAL_ROUND_OFF, "10.001");
	//round_test("10.001512345679", 3, mgDECIMAL_ROUND_OFF, "10.002");
	//round_test("10.00141", 3, mgDECIMAL_ROUND_OFF, "10.001");
	//round_test("10.00159", 3, mgDECIMAL_ROUND_OFF, "10.002");
	//round_test("10.00141211", 3, mgDECIMAL_ROUND_OFF, "10.001");
	//round_test("10.00151111", 3, mgDECIMAL_ROUND_OFF, "10.002");

	Truncate_test("10.001412345679", "10");
	Truncate_test("10.001512345679", "10");
	Truncate_test("10.00141", "10");
	Truncate_test("10.00159", "10");
	Truncate_test("10.00141211", "10");
	Truncate_test("10.00151111", "10");
	Truncate_test("0.00151111", "0");
	Truncate_test("-0.00151111", "0");
	Truncate_test("-10.001412345679", "-10");
	Truncate_test("-10.001512345679", "-10");
	Truncate_test("-10.00141", "-10");
	Truncate_test("-10.00159", "-10");
	Truncate_test("-10.00141211", "-10");
	Truncate_test("-10.00151111", "-10");
	Truncate_test("-10.9", "-10");
	Truncate_test("10.9", "10");
	Truncate_test("10.000000000000000000000000000000000000000000000000000039", "10");
	Truncate_test("-10.000000000000000000000000000000000000000000000000000039", "-10");
	Truncate_test("-10.9000000000000000000000000000000000000000000000000000039", "-10");

	Truncate_test("0", "0");
	Truncate_test("0.000000000000000000000000001", "0");
	Truncate_test("-0.000000000000000000000000001", "0");
	Truncate_test("0.99999999999999999999999999999999999", "0");
	Truncate_test("-0.99999999999999999999999999999999999", "0");
	Truncate_test("1.99999999999999999999999999999999999", "1");
	Truncate_test("-1.99999999999999999999999999999999999", "-1");
	Truncate_test("123.456", "123");
	Truncate_test("-123.456", "-123");
	Truncate_test("-123.0000000", "-123");
	Truncate_test("-9999999999.9999999999", "-9999999999");


	//round_test("-10.001412345679", 3, mgDECIMAL_ROUND_DOWN, "-10.001");
	//round_test("-10.001512345679", 3, mgDECIMAL_ROUND_DOWN, "-10.001");
	//round_test("-10.00141", 3, mgDECIMAL_ROUND_DOWN, "-10.001");
	//round_test("-10.00159", 3, mgDECIMAL_ROUND_DOWN, "-10.001");
	//round_test("-10.00141211", 3, mgDECIMAL_ROUND_DOWN, "-10.001");
	//round_test("-10.00151111", 3, mgDECIMAL_ROUND_DOWN, "-10.001");

	//round_test("-10.001412345679", 3, mgDECIMAL_ROUND_UP, "-10.002");
	//round_test("-10.001512345679", 3, mgDECIMAL_ROUND_UP, "-10.002");
	//round_test("-10.00141", 3, mgDECIMAL_ROUND_UP, "-10.002");
	//round_test("-10.00159", 3, mgDECIMAL_ROUND_UP, "-10.002");
	//round_test("-10.00141211", 3, mgDECIMAL_ROUND_UP, "-10.002");
	//round_test("-10.00151111", 3, mgDECIMAL_ROUND_UP, "-10.002");

	//round_test("-10.001412345679", 3, mgDECIMAL_ROUND_OFF, "-10.001");
	//round_test("-10.001512345679", 3, mgDECIMAL_ROUND_OFF, "-10.002");
	//round_test("-10.00141", 3, mgDECIMAL_ROUND_OFF, "-10.001");
	//round_test("-10.00159", 3, mgDECIMAL_ROUND_OFF, "-10.002");
	//round_test("-10.00141211", 3, mgDECIMAL_ROUND_OFF, "-10.001");
	//round_test("-10.00151111", 3, mgDECIMAL_ROUND_OFF, "-10.002");

	//round_test("10.001412345679", 3, mgDECIMAL_CEILING, "10.002");
	//round_test("10.001512345679", 3, mgDECIMAL_CEILING, "10.002");
	//round_test("-10.001412345679", 3, mgDECIMAL_CEILING, "-10.001");
	//round_test("-10.001512345679", 3, mgDECIMAL_CEILING, "-10.001");

	//round_test("0000.001412345679", 3, mgDECIMAL_CEILING, "0.002");
	//round_test("0000.001512345679", 3, mgDECIMAL_CEILING, "0.002");
	//round_test("-0000.001412345679", 3, mgDECIMAL_CEILING, "-0.001");
	//round_test("-0000.001512345679", 3, mgDECIMAL_CEILING, "-0.001");

	//round_test("10.001412345679", 3, mgDECIMAL_FLOOR, "10.001");
	//round_test("10.001512345679", 3, mgDECIMAL_FLOOR, "10.001");
	//round_test("-10.001412345679", 3, mgDECIMAL_FLOOR, "-10.002");
	//round_test("-10.001512345679", 3, mgDECIMAL_FLOOR, "-10.002");

	//round_test("0000.001412345679", 3, mgDECIMAL_FLOOR, "0.001");
	//round_test("0000.001512345679", 3, mgDECIMAL_FLOOR, "0.001");
	//round_test("-0000.001412345679", 3, mgDECIMAL_FLOOR, "-0.002");
	//round_test("-0000.001512345679", 3, mgDECIMAL_FLOOR, "-0.002");

	//round_test("1005", -1, mgDECIMAL_FLOOR, "1000");
	//round_test("1000.5", 0, mgDECIMAL_FLOOR, "1000");
	//round_test("1025", -2, mgDECIMAL_FLOOR, "1000");
	//round_test("-1005", -1, mgDECIMAL_FLOOR, "-1010");
	//round_test("-1000.5", 0, mgDECIMAL_FLOOR, "-1001");
	//round_test("-1025", -2, mgDECIMAL_FLOOR, "-1100");
	//round_test("9999999991025", -5, mgDECIMAL_FLOOR, "9999999900000");

	//round_test("1005", -1, mgDECIMAL_CEILING, "1010");
	//round_test("1000.5", 0, mgDECIMAL_CEILING, "1001");
	//round_test("1025", -2, mgDECIMAL_CEILING, "1100");
	//round_test("-1005", -1, mgDECIMAL_CEILING, "-1000");
	//round_test("-1000.5", 0, mgDECIMAL_CEILING, "-1000");
	//round_test("-1025", -2, mgDECIMAL_CEILING, "-1000");
	//round_test("9999999991025", -5, mgDECIMAL_CEILING, "10000000000000");

	//Assert::WriteLine(L"TEST mg_decimal_round(): OK\n");
}

void DecimalTestDotNetHard::TestMethod_round_test()
{
	Assert::WriteLineSpace();
	Assert::WriteLine(L"");
	Assert::WriteLine(L"TestMethod_round_test test");
	Assert::WriteLine(L"");
	decimal_round_test();
}

void DecimalTestDotNetHard::value_test(Decimal value, const char* text)
{
	Assert::IsTrue(value.ToString() == text);
}

void DecimalTestDotNetHard::decimal_value_test()
{
	Decimal value = Decimal::Zero;

	value_test(value, "0");
	value = Decimal::One;
	value_test(value, "1");
	value = Decimal::MinusOne;
	value_test(value, "-1");
	value = Decimal::MaxValue;
	value_test(value, "999999999999999999999999999999999999");
	value = Decimal::MinValue;
	value_test(value, "-999999999999999999999999999999999999");

	Assert::WriteLine(L"TEST mg_decimal values: OK\n");
}

void DecimalTestDotNetHard::TestMethod_value_test()
{
	Assert::WriteLineSpace();
	Assert::WriteLine(L"");
	Assert::WriteLine(L"TestMethod_value_test test");
	Assert::WriteLine(L"");
	decimal_value_test();
}

void DecimalTestDotNetHard::abs_test(const char* text, const char* ret)
{
	Decimal value1(text);
	Decimal value2 = Decimal::Abs(value1);
	Assert::IsTrue(value2.ToString() == ret);
}

void DecimalTestDotNetHard::decimal_abs_test()
{
	abs_test("1024", "1024");
	abs_test("-1024", "1024");
	abs_test("99999999999999999999.999999", "99999999999999999999.999999");
	abs_test("-99999999999999999999.999999", "99999999999999999999.999999");

	Assert::WriteLine(L"TEST mg_decimal_abs(): OK\n");
}

void DecimalTestDotNetHard::TestMethod_abs_test()
{
	Assert::WriteLineSpace();
	Assert::WriteLine(L"");
	Assert::WriteLine(L"TestMethod_abs_test test");
	Assert::WriteLine(L"");
	decimal_abs_test();
}

void DecimalTestDotNetHard::max_test(const char* text1, const char* text2, const char* ret)
{
	Decimal value1(text1);
	Decimal value2(text2);
	Decimal value3 = Decimal::Max(value1, value2);
	Assert::IsTrue(value3.ToString() == ret);
}

void DecimalTestDotNetHard::decimal_max_test()
{
	max_test("1", "-1", "1");
	max_test("-1", "1", "1");
	max_test("-1", "-1", "-1");
	max_test("1", "1", "1");
	max_test("9999999999.9999", "999999", "9999999999.9999");
	max_test("-9999999999.9999", "999999", "999999");

	Assert::WriteLine(L"TEST mg_decimal_max(): OK\n");
}

void DecimalTestDotNetHard::TestMethod_max_test()
{
	Assert::WriteLineSpace();
	Assert::WriteLine(L"");
	Assert::WriteLine(L"TestMethod_max_test test");
	Assert::WriteLine(L"");
	decimal_max_test();
}

void DecimalTestDotNetHard::min_test(const char* text1, const char* text2, const char* ret)
{
	Decimal value1(text1);
	Decimal value2(text2);
	Decimal value3 = Decimal::Min(value1, value2);
	Assert::IsTrue(value3.ToString() == ret);
}

void DecimalTestDotNetHard::decimal_min_test()
{
	min_test("1", "-1", "-1");
	min_test("-1", "1", "-1");
	min_test("-1", "-1", "-1");
	min_test("1", "1", "1");
	min_test("9999999999.9999", "999999", "999999");
	min_test("-9999999999.9999", "999999", "-9999999999.9999");

	Assert::WriteLine(L"TEST mg_decimal_min(): OK\n");
}

void DecimalTestDotNetHard::TestMethod_min_test()
{
	Assert::WriteLineSpace();
	Assert::WriteLine(L"");
	Assert::WriteLine(L"TestMethod_min_test test");
	Assert::WriteLine(L"");
	decimal_min_test();
}

void DecimalTestDotNetHard::get_binary_test(const char* text1)
{
	Decimal value1(text1);
	auto bits = value1.GetBits(value1);
	Decimal value2(bits);
	Assert::IsTrue(value1.ToString() == value2.ToString());
}

void DecimalTestDotNetHard::decimal_get_binary_test()
{
	get_binary_test("123456789123456789");
	get_binary_test("-123456789123456789");
	get_binary_test("9999999999999999999999999999999999");
	get_binary_test("-9999999999999999999999999999999999");
	get_binary_test("1");
	get_binary_test("-1");
	get_binary_test("100000.9999999999999");
	get_binary_test("-100000.9999999999999");
	get_binary_test("0.00000000000000123456789");
	get_binary_test("-0.00000000000000123456789");
	get_binary_test("0.012345678912345681352156123123123");
	get_binary_test("-0.012345678912345681352156123123123");
	get_binary_test("0.0123456789123456813521561231231234");
	get_binary_test("-0.0123456789123456813521561231231234");
	get_binary_test("0.01234567891234568135215612312312345");
	get_binary_test("-0.01234567891234568135215612312312345");
	get_binary_test("0.012345678912345681352156123123123456");
	get_binary_test("-0.012345678912345681352156123123123456");
	get_binary_test("0.00000000000000000000000000000000001");
	get_binary_test("-0.00000000000000000000000000000000001");

	Assert::WriteLine(L"TEST mg_decimal_get_binary(): OK\n");
}

void DecimalTestDotNetHard::TestMethod_get_binary_test()
{
	Assert::WriteLineSpace();
	Assert::WriteLine(L"");
	Assert::WriteLine(L"TestMethod_get_binary_test test");
	Assert::WriteLine(L"");
	decimal_get_binary_test();
}

void DecimalTestDotNetHard::is_zero_test(const char* text, bool zero)
{
	Decimal value1(text);
	Assert::IsTrue(Decimal::IsZero(value1) == zero);
}

void DecimalTestDotNetHard::decimal_is_zero_test()
{
	is_zero_test("1024", false);
	is_zero_test("-1024", false);
	is_zero_test("99999999999999999999.999999", false);
	is_zero_test("-99999999999999999999.999999", false);

	is_zero_test("0", true);
	is_zero_test("-0", true);
	is_zero_test("0000000000", true);
	is_zero_test("-0000000000", true);
	is_zero_test("00.00000000", true);
	is_zero_test("-00.00000000", true);

	Assert::WriteLine(L"TEST mg_decimal_is_zero(): OK\n");
}

void DecimalTestDotNetHard::TestMethod_is_zero_test()
{
	Assert::WriteLineSpace();
	Assert::WriteLine(L"");
	Assert::WriteLine(L"TestMethod_is_zero_test test");
	Assert::WriteLine(L"");
	decimal_is_zero_test();
}

void DecimalTestDotNetHard::TestMethod_Convert_String()
{
	Assert::WriteLineSpace();
	Assert::WriteLine(L"");
	Assert::WriteLine(L"TestMethod_string test convert");
	Assert::WriteLine(L"");
	decimal_convert_string_test();
}
