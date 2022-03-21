#pragma once
#include <Windows.h>

typedef unsigned long DWORD;
typedef unsigned long ULONG_PTR;
typedef ULONG_PTR SIZE_T;

template <DWORD SIZE, DWORD INCREMENT>
class CQuickBytesBase
{
public:
	CQuickBytesBase() :
		pbBuff(0),
		iSize(0),
		cbTotal(SIZE)
	{
	}

	void Destroy()
	{
		if (pbBuff)
		{
			free(pbBuff);
			pbBuff = 0;
		}
	}

	void* Alloc(SIZE_T iItems)
	{
		iSize = iItems;
		if (iItems <= SIZE)
		{
			cbTotal = SIZE;
			return (&rgData[0]);
		}
		else
		{
			if (pbBuff) free(pbBuff);
			pbBuff = malloc(iItems);
			cbTotal = pbBuff ? iItems : 0;
			return (pbBuff);
		}
	}

	HRESULT ReSize(SIZE_T iItems)
	{
		void* pbBuffNew;
		if (iItems <= cbTotal)
		{
			iSize = iItems;
			return NOERROR;
		}

		pbBuffNew = malloc(iItems + INCREMENT);
		if (!pbBuffNew)
			return E_OUTOFMEMORY;
		if (pbBuff)
		{
			memcpy(pbBuffNew, pbBuff, cbTotal);
			free(pbBuff);
		}
		else
		{
			memcpy(pbBuffNew, rgData, cbTotal);
		}
		cbTotal = iItems + INCREMENT;
		iSize = iItems;
		pbBuff = pbBuffNew;
		return NOERROR;
	}

	operator PVOID()
	{
		return ((pbBuff) ? pbBuff : &rgData[0]);
	}

	void* Ptr()
	{
		return ((pbBuff) ? pbBuff : &rgData[0]);
	}

	SIZE_T Size()
	{
		return (iSize);
	}

	SIZE_T MaxSize()
	{
		return (cbTotal);
	}

	void Maximize()
	{
		HRESULT hr = ReSize(MaxSize());
		_ASSERTE(hr == NOERROR);
	}

	void* pbBuff;
	SIZE_T iSize; // number of bytes used
	SIZE_T cbTotal; // total bytes allocated in the buffer
	BYTE rgData[SIZE];
};

#define     CQUICKBYTES_INCREMENTAL_SIZE    128
#define     CQUICKBYTES_BASE_SIZE           512

template <DWORD CQUICKBYTES_BASE_SPECIFY_SIZE>
class CQuickBytesNoDtorSpecifySize : public CQuickBytesBase<CQUICKBYTES_BASE_SPECIFY_SIZE, CQUICKBYTES_INCREMENTAL_SIZE>
{
};

template <DWORD CQUICKBYTES_BASE_SPECIFY_SIZE>
class CQuickBytesSpecifySize : public CQuickBytesNoDtorSpecifySize<CQUICKBYTES_BASE_SPECIFY_SIZE>
{
public:
	CQuickBytesSpecifySize()
	{
	}

	~CQuickBytesSpecifySize()
	{
		Destroy();
	}
};

class CQuickBytesNoDtor : public CQuickBytesBase<CQUICKBYTES_BASE_SIZE, CQUICKBYTES_INCREMENTAL_SIZE>
{
};

class CQuickBytes : public CQuickBytesNoDtor
{
public:
	CQuickBytes()
	{
	}

	~CQuickBytes()
	{
		Destroy();
	}
};
