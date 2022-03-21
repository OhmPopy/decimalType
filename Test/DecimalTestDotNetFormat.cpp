#include "DecimalTestDotNetFormat.h"

#include "CppUnitTestAssert.h"
#include "include/ComNumberRaw.h"
#include "include/Decimal.h"

void DecimalTestDotNetFormat::TestMethod_DecimalToString()
{
	System::Decimal decimal(L"-16325.62");

	Assert::WriteLine(decimal.ToString(L"C").c_str());
	Assert::WriteLine(decimal.ToString(L"C0").c_str());
	Assert::WriteLine(decimal.ToString(L"E").c_str());
	Assert::WriteLine(decimal.ToString(L"E2").c_str());
	Assert::WriteLine(decimal.ToString(L"e2").c_str());
	Assert::WriteLine(decimal.ToString(L"F").c_str());
	Assert::WriteLine(decimal.ToString(L"F1").c_str());
	Assert::WriteLine(decimal.ToString(L"G").c_str());
	Assert::WriteLine(decimal.ToString(L"g2").c_str());
	Assert::WriteLine(decimal.ToString(L"N").c_str());
	Assert::WriteLine(decimal.ToString(L"N1").c_str());
	Assert::WriteLine(decimal.ToString(L"P").c_str());
	Assert::WriteLine(decimal.ToString(L"P1").c_str());
	//Assert::WriteLine(decimal.ToString(L"0000").c_str());
	//Assert::WriteLine(decimal.ToString(L"####").c_str());
	//Assert::WriteLine(decimal.ToString(L"##.###").c_str());
	//Assert::WriteLine(decimal.ToString(L"00.000").c_str());
	//Assert::WriteLine(decimal.ToString(L"##,###").c_str());
	//Assert::WriteLine(decimal.ToString(L"##'item'").c_str());
}

void DecimalTestDotNetFormat::TestMethod_DoubleToString()
{
	double value = 16325.62901;
	Assert::WriteLine(ToStringDouble(value, L"C0").c_str());
	Assert::WriteLine(ToStringDouble(value, L"C").c_str());
	Assert::WriteLine(ToStringDouble(value, L"E").c_str());
	Assert::WriteLine(ToStringDouble(value, L"E2").c_str());
	Assert::WriteLine(ToStringDouble(value, L"e2").c_str());
	Assert::WriteLine(ToStringDouble(value, L"F").c_str());
	Assert::WriteLine(ToStringDouble(value, L"F1").c_str());
	Assert::WriteLine(ToStringDouble(value, L"G").c_str());
	Assert::WriteLine(ToStringDouble(value, L"g2").c_str());
	Assert::WriteLine(ToStringDouble(value, L"N").c_str());
	Assert::WriteLine(ToStringDouble(value, L"N1").c_str());
	Assert::WriteLine(ToStringDouble(value, L"P").c_str());
	Assert::WriteLine(ToStringDouble(value, L"P1").c_str());
	Assert::WriteLine(ToStringDouble(value, L"R").c_str());
	Assert::WriteLine(ToStringDouble(value, L"0000").c_str());
	Assert::WriteLine(ToStringDouble(value, L"####").c_str());
	Assert::WriteLine(ToStringDouble(value, L"##.###").c_str());
	Assert::WriteLine(ToStringDouble(value, L"##.000").c_str());
	Assert::WriteLine(ToStringDouble(value, L"##,###").c_str());
	Assert::WriteLine(ToStringDouble(value, L"## 'items'").c_str());
}

void DecimalTestDotNetFormat::TestMethod_Int32ToString()
{
	//                 
	Int32 value = 16325.62901;
	Assert::WriteLine(ToStringInt32(value, L"C0").c_str());
	Assert::WriteLine(ToStringInt32(value, L"C").c_str());
	Assert::WriteLine(ToStringInt32(value, L"D").c_str());
	Assert::WriteLine(ToStringInt32(value, L"D5").c_str());
	Assert::WriteLine(ToStringInt32(value, L"E").c_str());
	Assert::WriteLine(ToStringInt32(value, L"E2").c_str());
	Assert::WriteLine(ToStringInt32(value, L"e2").c_str());
	Assert::WriteLine(ToStringInt32(value, L"F").c_str());
	Assert::WriteLine(ToStringInt32(value, L"F1").c_str());
	Assert::WriteLine(ToStringInt32(value, L"G").c_str());
	Assert::WriteLine(ToStringInt32(value, L"g2").c_str());
	Assert::WriteLine(ToStringInt32(value, L"N").c_str());
	Assert::WriteLine(ToStringInt32(value, L"N1").c_str());
	Assert::WriteLine(ToStringInt32(value, L"P").c_str());
	Assert::WriteLine(ToStringInt32(value, L"P1").c_str());
	Assert::WriteLine(ToStringInt32(value, L"X").c_str());
	Assert::WriteLine(ToStringInt32(value, L"x8").c_str());
	Assert::WriteLine(ToStringInt32(value, L"0000").c_str());
}

void DecimalTestDotNetFormat::TestMethod_UInt32ToString()
{
	UInt32 value = 16325.62901;
	Assert::WriteLine(ToStringUInt32(value, L"C0").c_str());
	Assert::WriteLine(ToStringUInt32(value, L"C").c_str());
	Assert::WriteLine(ToStringUInt32(value, L"D").c_str());
	Assert::WriteLine(ToStringUInt32(value, L"D5").c_str());
	Assert::WriteLine(ToStringUInt32(value, L"E").c_str());
	Assert::WriteLine(ToStringUInt32(value, L"E2").c_str());
	Assert::WriteLine(ToStringUInt32(value, L"e2").c_str());
	Assert::WriteLine(ToStringUInt32(value, L"F").c_str());
	Assert::WriteLine(ToStringUInt32(value, L"F1").c_str());
	Assert::WriteLine(ToStringUInt32(value, L"G").c_str());
	Assert::WriteLine(ToStringUInt32(value, L"g2").c_str());
	Assert::WriteLine(ToStringUInt32(value, L"N").c_str());
	Assert::WriteLine(ToStringUInt32(value, L"N1").c_str());
	Assert::WriteLine(ToStringUInt32(value, L"P").c_str());
	Assert::WriteLine(ToStringUInt32(value, L"P1").c_str());
	Assert::WriteLine(ToStringUInt32(value, L"X").c_str());
	Assert::WriteLine(ToStringUInt32(value, L"x8").c_str());
	Assert::WriteLine(ToStringUInt32(value, L"0000").c_str());
}

void DecimalTestDotNetFormat::TestMethod_Int64ToString()
{
	Int64 value = 16325.62901;
	Assert::WriteLine(ToStringInt64(value, L"C0").c_str());
	Assert::WriteLine(ToStringInt64(value, L"C").c_str());
	Assert::WriteLine(ToStringInt64(value, L"D").c_str());
	Assert::WriteLine(ToStringInt64(value, L"D5").c_str());
	Assert::WriteLine(ToStringInt64(value, L"E").c_str());
	Assert::WriteLine(ToStringInt64(value, L"E2").c_str());
	Assert::WriteLine(ToStringInt64(value, L"e2").c_str());
	Assert::WriteLine(ToStringInt64(value, L"F").c_str());
	Assert::WriteLine(ToStringInt64(value, L"F1").c_str());
	Assert::WriteLine(ToStringInt64(value, L"G").c_str());
	Assert::WriteLine(ToStringInt64(value, L"g2").c_str());
	Assert::WriteLine(ToStringInt64(value, L"N").c_str());
	Assert::WriteLine(ToStringInt64(value, L"N1").c_str());
	Assert::WriteLine(ToStringInt64(value, L"P").c_str());
	Assert::WriteLine(ToStringInt64(value, L"P1").c_str());
	Assert::WriteLine(ToStringInt64(value, L"X").c_str());
	Assert::WriteLine(ToStringInt64(value, L"x8").c_str());
	Assert::WriteLine(ToStringInt64(value, L"0000").c_str());
}

void DecimalTestDotNetFormat::TestMethod_UInt64ToString()
{
	UInt64 value = 16325.62901;
	Assert::WriteLine(ToStringUInt64(value, L"C0").c_str());
	Assert::WriteLine(ToStringUInt64(value, L"C").c_str());
	Assert::WriteLine(ToStringUInt64(value, L"D").c_str());
	Assert::WriteLine(ToStringUInt64(value, L"D5").c_str());
	Assert::WriteLine(ToStringUInt64(value, L"E").c_str());
	Assert::WriteLine(ToStringUInt64(value, L"E2").c_str());
	Assert::WriteLine(ToStringUInt64(value, L"e2").c_str());
	Assert::WriteLine(ToStringUInt64(value, L"F").c_str());
	Assert::WriteLine(ToStringUInt64(value, L"F1").c_str());
	Assert::WriteLine(ToStringUInt64(value, L"G").c_str());
	Assert::WriteLine(ToStringUInt64(value, L"g2").c_str());
	Assert::WriteLine(ToStringUInt64(value, L"N").c_str());
	Assert::WriteLine(ToStringUInt64(value, L"N1").c_str());
	Assert::WriteLine(ToStringUInt64(value, L"P").c_str());
	Assert::WriteLine(ToStringUInt64(value, L"P1").c_str());
	Assert::WriteLine(ToStringUInt64(value, L"X").c_str());
	Assert::WriteLine(ToStringUInt64(value, L"x8").c_str());
	Assert::WriteLine(ToStringUInt64(value, L"0000").c_str());
}

void DecimalTestDotNetFormat::TestMethod_SingleToString()
{
	float value = 16325.62901;
	Assert::WriteLine(ToStringSingle(value, L"C0").c_str());
	Assert::WriteLine(ToStringSingle(value, L"C").c_str());
	Assert::WriteLine(ToStringSingle(value, L"E").c_str());
	Assert::WriteLine(ToStringSingle(value, L"E2").c_str());
	Assert::WriteLine(ToStringSingle(value, L"e2").c_str());
	Assert::WriteLine(ToStringSingle(value, L"F").c_str());
	Assert::WriteLine(ToStringSingle(value, L"F1").c_str());
	Assert::WriteLine(ToStringSingle(value, L"G").c_str());
	Assert::WriteLine(ToStringSingle(value, L"g2").c_str());
	Assert::WriteLine(ToStringSingle(value, L"N").c_str());
	Assert::WriteLine(ToStringSingle(value, L"N1").c_str());
	Assert::WriteLine(ToStringSingle(value, L"P").c_str());
	Assert::WriteLine(ToStringSingle(value, L"P1").c_str());
	Assert::WriteLine(ToStringSingle(value, L"R").c_str());
	Assert::WriteLine(ToStringSingle(value, L"0000").c_str());
}

void DecimalTestDotNetFormat::TestMethod_DecimalCheckLeak()
{
	//DateTime now_1 = DateTime::GetNow();
	for (int i = 0; i < 1000000; ++i)
	{
		//System::Decimal decimal1(L"-16325.62");
		System::Decimal decimal1 = 200;
		System::Decimal decimal2 = 100;
		System::Decimal decimal3 = 100;

		decimal3 = decimal1 + decimal2;
		decimal3 += decimal1 + decimal2;
		decimal3 = decimal3 - decimal2;
		decimal3 = decimal3 / decimal2;
		decimal3 = decimal3 * decimal2;
		decimal3 = decimal3 % decimal2;
		decimal3 = decimal3 - decimal2;
		decimal3 += 1;
		decimal3 -= 1;
		decimal3 *= 1;
		decimal3 /= 1;
		decimal3 %= 1;
		decimal3--;
		decimal3++;
		++decimal3;
		--decimal3;

		bool b_1 = decimal3 < 1;
		bool b_2 = decimal3 <= 1;
		bool b_3 = decimal3 > 1;
		bool b_4 = decimal3 >= 1;

		auto text_1 = decimal1.ToString();
		auto text_2 = decimal1.ToString(L"F");
		auto text_3 = decimal1.ToString(L"G");
		//auto text_3 = decimal1.ToString(L"F", L"es-ES");
	}
	//DateTime now_2 = DateTime::GetNow();

	//Assert::WriteLine((now_2 - now_1).ToStringStand(TimeSpan::FormatToString::HourMinSecondMiniSecond).c_str());
}

std::wstring DecimalTestDotNetFormat::ToStringDouble(double value, std::wstring format)
{
	StringObject format_ptr(format.c_str());
	//return COMNumber::FormatDouble(ComCultureInfo::CreateSpecificCulture(L"es-ES")->NumberFormat(), &format_ptr, value)->ToString();
	//return COMNumber::FormatDouble(ComCultureInfo::CreateSpecificCulture(L"en-GB")->NumberFormat(), &format_ptr, value)->ToString();
	//return COMNumber::FormatDouble(ComCultureInfo::CreateSpecificCulture(L"fr-FR")->NumberFormat(), &format_ptr, value)->ToString();
	//return COMNumber::FormatDouble(ComCultureInfo::InvariantCulture()->NumberFormat(), &format_ptr, value)->ToString();
	return COMNumber::FormatDouble(NumberFormatInfo::InvariantNumberFormat(), &format_ptr, value)->ToString();
}

std::wstring DecimalTestDotNetFormat::ToStringInt32(int value, std::wstring format)
{
	StringObject format_ptr(format.c_str());
	return COMNumber::FormatInt32(NumberFormatInfo::InvariantNumberFormat(), &format_ptr, value)->ToString();
}

std::wstring DecimalTestDotNetFormat::ToStringUInt32(UInt32 value, std::wstring format)
{
	StringObject format_ptr(format.c_str());
	return COMNumber::FormatUInt32(NumberFormatInfo::InvariantNumberFormat(), &format_ptr, value)->ToString();
}

std::wstring DecimalTestDotNetFormat::ToStringInt64(Int64 value, std::wstring format)
{
	StringObject format_ptr(format.c_str());
	return COMNumber::FormatInt64(NumberFormatInfo::InvariantNumberFormat(), &format_ptr, value)->ToString();
}

std::wstring DecimalTestDotNetFormat::ToStringUInt64(UInt64 value, std::wstring format)
{
	StringObject format_ptr(format.c_str());
	return COMNumber::FormatUInt64(NumberFormatInfo::InvariantNumberFormat(), &format_ptr, value)->ToString();
}

std::wstring DecimalTestDotNetFormat::ToStringSingle(float value, std::wstring format)
{
	StringObject format_ptr(format.c_str());
	return COMNumber::FormatSingle(NumberFormatInfo::InvariantNumberFormat(), &format_ptr, value)->ToString();
}
