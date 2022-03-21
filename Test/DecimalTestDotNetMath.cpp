#include "DecimalTestDotNetMath.h"
#include "CppUnitTestAssert.h"
#include "random.h"
#include "include/DecimalMath.h"

Decimal DecimalTestDotNetMath::epsilon = 0.000000000001;
int DecimalTestDotNetMath::testCount = 1000;
Random random;


void DecimalTestDotNetMath::TestMethodExp()
{
	random.Init(123);

	Assert::WriteLineSpace();
	Assert::WriteLine(L"");
	Assert::WriteLine(L"TestMethodExp");
	Assert::WriteLine(L"");

	for (int i = 0; i < testCount; i++)
	{
		double d = random.NextDouble();
		Decimal d1 = d;
		d = exp(d);
		d1 = DecimalMath::Exp(d1);
		std::wstring text_1 = L"d=" + std::to_wstring(d);
		std::wstring text_2 = L"d1=" + d1.ToString();
		Assert::WriteLine(text_1.c_str());
		Assert::IsTrue(DecimalMath::Abs(d - d1) < epsilon);
	}

	{
		double d = 0.56956715116722845;
		Decimal d1 = d;
		d1 = DecimalMath::Exp(d1);
		std::wstring text_2 = L"d1=" + d1.ToString();
	}
	Assert::WriteLine(L"TEST TestMethodExp(): OK\n");
}

void DecimalTestDotNetMath::TestMethodAsin()
{
	random.Init(123);
	Assert::WriteLineSpace();
	Assert::WriteLine(L"");
	Assert::WriteLine(L"TestMethodAsin");
	Assert::WriteLine(L"");

	for (int i = 0; i < testCount; i++)
	{
		double d = random.NextDouble();
		Decimal d1 = d;
		d = asin(d);
		d1 = DecimalMath::Asin(d1);
		Assert::IsTrue(DecimalMath::Abs(d - d1) < epsilon);
	}

	Assert::WriteLine(L"TEST TestMethodAsin(): OK\n");
}

void DecimalTestDotNetMath::TestMethodAcos()
{
	Assert::WriteLineSpace();
	Assert::WriteLine(L"");
	Assert::WriteLine(L"TestMethodAcos");
	Assert::WriteLine(L"");

	for (int i = 0; i < testCount; i++)
	{
		double d = random.NextDouble();
		Decimal d1 = d;
		d = acos(d);
		d1 = DecimalMath::Acos(d1);
		Assert::IsTrue(DecimalMath::Abs(d - d1) < epsilon);
	}

	Assert::WriteLine(L"TEST TestMethodAcos(): OK\n");
}

void DecimalTestDotNetMath::TestMethodAtan()
{
	Assert::WriteLineSpace();
	Assert::WriteLine(L"");
	Assert::WriteLine(L"TestMethodAtan");
	Assert::WriteLine(L"");

	for (int i = 0; i < testCount; i++)
	{
		double d = random.NextDouble();
		Decimal d1 = d;
		d = atan(d);
		d1 = DecimalMath::Atan(d1);
		Assert::IsTrue(DecimalMath::Abs(d - d1) < epsilon);
	}

	Assert::WriteLine(L"TEST TestMethodAtan(): OK\n");
}

void DecimalTestDotNetMath::TestMethodSin()
{
	Assert::WriteLineSpace();
	Assert::WriteLine(L"");
	Assert::WriteLine(L"TestMethodSin");
	Assert::WriteLine(L"");

	for (int i = 0; i < testCount; i++)
	{
		double d = random.NextDouble();
		Decimal d1 = d;
		d = sin(d);
		d1 = DecimalMath::Sin(d1);
		Assert::IsTrue(DecimalMath::Abs(d - d1) < epsilon);
	}

	Assert::WriteLine(L"TEST TestMethodSin(): OK\n");
}

void DecimalTestDotNetMath::TestMethodCos()
{
	Assert::WriteLineSpace();
	Assert::WriteLine(L"");
	Assert::WriteLine(L"TestMethodCos");
	Assert::WriteLine(L"");

	for (int i = 0; i < testCount; i++)
	{
		double d = random.NextDouble();
		Decimal d1 = d;
		d = cos(d);
		d1 = DecimalMath::Cos(d1);
		Assert::IsTrue(DecimalMath::Abs(d - d1) < epsilon);
	}

	Assert::WriteLine(L"TEST TestMethodCos(): OK\n");
}

void DecimalTestDotNetMath::TestMethodAtan2()
{
	Assert::WriteLineSpace();
	Assert::WriteLine(L"");
	Assert::WriteLine(L"TestMethodAtan2");
	Assert::WriteLine(L"");

	for (int i = 0; i < testCount; i++)
	{
		double x = random.NextDouble();
		double y = random.NextDouble();
		Decimal dx = x;
		Decimal dy = y;
		double d = atan2(y, x);
		Decimal z = DecimalMath::Atan2(dy, dx);
		Assert::IsTrue(DecimalMath::Abs(d - z) < epsilon);
	}

	Assert::WriteLine(L"TEST TestMethodAtan2(): OK\n");
}

void DecimalTestDotNetMath::TestMethodPow001()
{
	const double x = 10;
	const double y = -5;
	const double result = pow(x, y);

	if (result == 1E-05)
	{
	}
	else
	{
		Assert::WriteLine(L"Error\n");
	}

	const Decimal dx = 10;
	const Decimal dy = -5;
	const Decimal dResult = DecimalMath::Power(dx, dy);

	if (dResult == 0.00001)
	{
	}
	else
	{
		Assert::WriteLine(L"Error\n");
	}
}

void DecimalTestDotNetMath::TestMethodPow002()
{
	const double x = 10;
	const double y = 5;
	const double result = pow(x, y);

	if (result == 100000)
	{
	}
	else
	{
		Assert::WriteLine(L"Error\n");
	}

	const Decimal dx = 10;
	const Decimal dy = 5;
	const Decimal dResult = DecimalMath::Power(dx, dy);
	if (dResult == 100000)
	{
	}
	else
	{
		Assert::WriteLine(L"Error\n");
	}
}
