#ifndef _CORE_BASETYPE_H_
#define _CORE_BASETYPE_H_

#pragma once

namespace System
{
	typedef unsigned char Byte;
	typedef unsigned char UInt8;
	typedef unsigned short UInt16;
	typedef unsigned int UInt32;
	typedef unsigned __int64 UInt64;

	typedef wchar_t Char;
	typedef __int64 Time_t;

	typedef char Int8;
	typedef short Int16;
	typedef int Int32;
	typedef __int64 Int64;

	typedef float Float;

#ifdef _WIN64
typedef __int64 HUIWND;
typedef __int64 DHDC;
typedef __int64 Handle;
#else
	typedef unsigned long HUIWND;
	typedef unsigned long DHDC;
	typedef unsigned long Handle;
#endif


	typedef unsigned long long FastId;
};

#endif
