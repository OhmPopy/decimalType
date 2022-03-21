#pragma once
#include <string>

#include "include/BaseType.h"

using namespace System;

class DecimalTestDotNetFormat
{
public:
	static void TestMethod_DecimalToString();
	static void TestMethod_DoubleToString();
	static void TestMethod_Int32ToString();
	static void TestMethod_UInt32ToString();
	static void TestMethod_Int64ToString();
	static void TestMethod_UInt64ToString();
	static void TestMethod_SingleToString();

	static void TestMethod_DecimalCheckLeak();


	static std::wstring ToStringDouble(double value, std::wstring format);
	static std::wstring ToStringInt32(int value, std::wstring format);
	static std::wstring ToStringUInt32(System::UInt32 value, std::wstring format);
	static std::wstring ToStringInt64(System::Int64 value, std::wstring format);
	static std::wstring ToStringUInt64(System::UInt64 value, std::wstring format);
	static std::wstring ToStringSingle(float value, std::wstring format);
};
