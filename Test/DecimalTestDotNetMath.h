#pragma once
#include "include/Decimal.h"

using namespace System;

class DecimalTestDotNetMath
{
	static Decimal epsilon;
	static int testCount;
public:
	static void TestMethodExp();
	static void TestMethodAsin();
	static void TestMethodAcos();
	static void TestMethodAtan();
	static void TestMethodSin();
	static void TestMethodCos();
	static void TestMethodAtan2();
	static void TestMethodPow001();
	static void TestMethodPow002();
};
