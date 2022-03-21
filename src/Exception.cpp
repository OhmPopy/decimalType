#include "include/Exception.h"

namespace System
{
	Exception::Exception()
	{
	}

	Exception::~Exception()
	{
	}

	Exception::Exception(const std::string& errorMsg)
	{
	}

	Exception::Exception(const std::string& errorMsg, const std::string& mess)
	{
	}

	Exception::Exception(const std::string& errorMsg, Exception* inner_exception)
	{
	}

	Exception::Exception(const std::string& errorMsg, char* f, int l)
	{
	}

	Exception::Exception(const std::string& tag, const std::string& errorMsg, char* f, int l)
	{
	}

	OverflowException::OverflowException()
	{
	}

	OverflowException::OverflowException(const std::string& arg)
	{
	}

	OverflowException::OverflowException(const std::string& arg, const std::string& mess)
	{
	}

	OverflowException::OverflowException(const std::string& info, char* f, int l)
	{
	}

	OverflowException::OverflowException(const std::string& oper, const std::string& info, char* f, int l)
	{
	}

	ArgumentOutOfRangeException::ArgumentOutOfRangeException()
	{
	}

	ArgumentOutOfRangeException::ArgumentOutOfRangeException(const std::string& arg)
	{
	}

	ArgumentOutOfRangeException::ArgumentOutOfRangeException(const std::string& arg, const std::string& mess)
	{
	}

	ArgumentOutOfRangeException::ArgumentOutOfRangeException(const std::string& info, char* f, int l)
	{
	}

	ArgumentOutOfRangeException::ArgumentOutOfRangeException(const std::string& oper, const std::string& info, char* f, int l)
	{
	}

	ArgumentException::ArgumentException()
	{
	}

	ArgumentException::ArgumentException(const std::string& arg)
	{
	}

	ArgumentException::ArgumentException(const std::string& arg, const std::string& mess)
	{
	}

	ArgumentException::ArgumentException(const std::string& info, char* f, int l)
	{
	}

	ArgumentException::ArgumentException(const std::string& oper, const std::string& info, char* f, int l)
	{
	}

	DivideByZeroException::DivideByZeroException()
	{
	}

	DivideByZeroException::DivideByZeroException(const std::string& arg)
	{
	}

	DivideByZeroException::DivideByZeroException(const std::string& arg, const std::string& mess)
	{
	}

	DivideByZeroException::DivideByZeroException(const std::string& info, char* f, int l)
	{
	}

	DivideByZeroException::DivideByZeroException(const std::string& oper, const std::string& info, char* f, int l)
	{
	}

	ArgumentNullException::ArgumentNullException()
	{
	}

	ArgumentNullException::ArgumentNullException(const std::string& arg)
	{
	}

	ArgumentNullException::ArgumentNullException(const std::string& arg, const std::string& mess)
	{
	}

	ArgumentNullException::ArgumentNullException(const std::string& info, char* f, int l)
	{
	}

	ArgumentNullException::ArgumentNullException(const std::string& oper, const std::string& info, char* f, int l)
	{
	}

	FormatException::FormatException()
	{
	}

	FormatException::FormatException(const std::string& arg)
	{
	}

	FormatException::FormatException(const std::string& arg, const std::string& mess)
	{
	}

	FormatException::FormatException(const std::string& info, char* f, int l)
	{
	}

	FormatException::FormatException(const std::string& oper, const std::string& info, char* f, int l)
	{
	}
}
