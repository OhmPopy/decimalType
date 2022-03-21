#pragma once
#include "include/Decimal.h"


using namespace System;

class DecimalTestDotNetHard
{
public:
	static void TestMethod_ToString();
	static void TestMethod_Convert_Int();
	static void TestMethod_Convert_String();
	static void TestMethod_Convert_Uint();
	static void TestMethod_Convert_long_long();
	static void TestMethod_Convert_ulong_long();
	static void TestMethod_Convert_float();
	static void TestMethod_Convert_double();
	static void TestMethod_zero_test();
	static void TestMethod_compare_test();
	static void TestMethod_add_test();
	static void TestMethod_subtract_test();
	static void TestMethod_negative_test();
	static void TestMethod_multiply_test();
	static void TestMethod_divide_test();
	static void TestMethod_divide_and_modulus_test();
	static void TestMethod_modulus_test();
	static void TestMethod_error_test();
	static void TestMethod_round_test();
	static void TestMethod_value_test();
	static void TestMethod_abs_test();
	static void TestMethod_max_test();
	static void TestMethod_min_test();
	static void TestMethod_get_binary_test();
	static void TestMethod_is_zero_test();


private:
	static void Truncate_test(const char* text, const char* ret);

	static void int_convert_test(int value, const char* ret);

	static void int_convert(const char* ret, int value);

	static void int_convert_overflow(const char* ret);

	static void decimal_convert_int_test();

	static void convert_test(const char* text);

	static void convert_test2(const char* text1, const char* text2);

	static void convert_test_OVERFLOW(const char* text1, bool cs);

	static void decimal_convert_string_test();

	static void uint_convert_test(unsigned int value, const char* ret);

	static void uint_convert_overflow(const char* value);

	static void decimal_convert_uint_test();

	static void _long_longconvert_test(long long value, const char* ret);

	static void long_long_convert_overflow(const char* value);

	static void decimal_convert_long_long_test();

	static void ulong_long_convert_test(long long value, const char* ret);

	static void ulong_long_convert_overflow(const char* value);

	static void decimal_convert_ulong_long_test();

	static void float_convert_test(float value, const char* ret, int precision);

	static void decimal_convert_float_test();

	static void double_convert_test(double value, const char* ret, int precision);

	static void double_convert_print(const double value);

	static void decimal_convert_double_test();

	static void zero_test();

	static void decimal_zero_test();

	static void compare_test(const char* text1, const char* text2, int ret);

	static void decimal_compare_test();

	static void add_test(const char* text1, const char* text2, const char* ret);

	static void decimal_add_test();

	static void subtract_test(const char* text1, const char* text2, const char* ret);

	static void decimal_subtract_test();

	static void negative_test(const char* text, const char* ret);

	static void decimal_negative_test();

	static void multiply_test(const char* text1, const char* text2, const char* ret);

	static void overflow_test(const char* text1, const char* text2);

	static void decimal_multiply_test();

	static void divide_test(const char* text1, const char* text2, const char* ret);

	static void decimal_divide_test();

	static void divide_and_modulus_test(const char* text1, const char* text2, const char* ret, const char* reminder);

	static void divide_and_modulus_test2(const char* text1, const char* text2);

	static void decimal_divide_and_modulus_test();

	static void modulus_test(const char* text1, const char* text2, const char* ret);

	static void decimal_modulus_test();

	static void error_test();

	static void decimal_error_test();

	static void round_test(const char* text, int precision, int type, const char* ret);

	static void decimal_round_test();

	static void value_test(Decimal value, const char* text);

	static void decimal_value_test();

	static void abs_test(const char* text, const char* ret);

	static void decimal_abs_test();

	static void max_test(const char* text1, const char* text2, const char* ret);

	static void decimal_max_test();

	static void min_test(const char* text1, const char* text2, const char* ret);

	static void decimal_min_test();

	static void get_binary_test(const char* text1);

	static void decimal_get_binary_test();

	static void is_zero_test(const char* text, bool zero);

	static void decimal_is_zero_test();
};
