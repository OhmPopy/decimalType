#include "include/Currency.h"

#include "include/CQuickBytesBase.h"
#include "include/Decimal.h"
#include "include/FCallExtension.h"


namespace System
{
	Currency::Currency()
	{
		m_value = 0;
	}

	System::Currency::Currency(Decimal value)
	{
		m_value = Decimal::ToCurrency(value).m_value;
	}

	Currency::Currency(long long value, int ignored)
	{
		m_value = value;
	}

	Currency Currency::FromOACurrency(long long cy)
	{
		return Currency(cy, 0);
	}

	long long Currency::ToOACurrency() const
	{
		return m_value;
	}

	Decimal Currency::ToDecimal(Currency c)
	{
		CY cy;
		cy.int64 = c.m_value;
		DECIMAL d;
		FCallExtension::FCallToDecimal(&d, cy);
		const Decimal result = Decimal::ToDecimal(&d);
		return result;
	}
}
