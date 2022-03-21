// ==++==
// 
//   Copyright (c) Microsoft Corporation.  All rights reserved.
// 
// ==--==
#ifndef _COMNUMBER_H_
#define _COMNUMBER_H_

#include <windows.h>

#include "BaseType.h"
#include "NumberFormatInfo.h"

#pragma pack(push)
#pragma pack(1)


static void COMPlusThrowOM();
static void COMPlusThrowArgumentNull(const wchar_t*);
using namespace System;

class COMNumber
{
public:
	static STRINGREF __stdcall FormatDecimal(NUMFMTREF numfmt, STRINGREF format, DECIMAL* value);
	static STRINGREF __stdcall FormatDouble(NUMFMTREF numfmt, STRINGREF format, double value);
	static STRINGREF __stdcall FormatInt32(NUMFMTREF numfmt, STRINGREF format, Int32 value);
	static STRINGREF __stdcall FormatUInt32(NUMFMTREF numfmt, STRINGREF format, UInt32 value);
	static STRINGREF __stdcall FormatInt64(NUMFMTREF numfmt, STRINGREF format, Int64 value);
	static STRINGREF __stdcall FormatUInt64(NUMFMTREF numfmt, STRINGREF format, ::UInt64 value);
	static STRINGREF __stdcall FormatSingle(NUMFMTREF numfmt, STRINGREF format, float value);

	static double __stdcall ParseDouble(NUMFMTREF numfmt, I4 options, STRINGREF value);
	static bool __stdcall TryParseDecimal(NUMFMTREF numfmt, I4 options, STRINGREF value, DECIMAL* result);
	static bool __stdcall TryParseDouble(NUMFMTREF numfmt, I4 options, STRINGREF value, double* result);
	static void __stdcall ParseDecimal(NUMFMTREF numfmt, I4 options, STRINGREF value, DECIMAL* result);
	static int __stdcall ParseInt32(NUMFMTREF numfmt, I4 options, STRINGREF value);
	static unsigned int __stdcall ParseUInt32(NUMFMTREF numfmt, I4 options, STRINGREF value);
	static __int64 __stdcall ParseInt64(NUMFMTREF numfmt, I4 options, STRINGREF value);
	static unsigned __int64 __stdcall ParseUInt64(NUMFMTREF numfmt, I4 options, STRINGREF value);
	static float __stdcall ParseSingle(NUMFMTREF numfmt, I4 options, STRINGREF value);
};

#pragma pack(pop)

#endif _COMNUMBER_H_
