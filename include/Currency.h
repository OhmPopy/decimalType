#pragma once

namespace System
{
	class Decimal;

	struct Currency
	{
		long long m_value;

		// Constructs a Currency from a Decimal value.
		//
		Currency();
		Currency(Decimal value);

		// Constructs a Currency from a long value without scaling. The
		// ignored parameter exists only to distinguish this constructor
		// from the constructor that takes a long.  Used only in the System 
		// package, especially in Variant.
		Currency(long long value, int ignored);

		// Creates a Currency from an OLE Automation Currency.  This method
		// applies no scaling to the Currency value, essentially doing a bitwise
		// copy.
		// 
		static Currency FromOACurrency(long long cy);

		//Creates an OLE Automation Currency from a Currency instance.  This 
		// method applies no scaling to the Currency value, essentially doing 
		// a bitwise copy.
		// 
		long long ToOACurrency() const;

		// Converts a Currency to a Decimal.
		//
		static Decimal ToDecimal(Currency c);
	};
}
