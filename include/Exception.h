#pragma once

#include <string>

namespace System
{
	class Exception
	{
	public:
		Exception();
		virtual ~Exception();
		explicit Exception(const std::string& errorMsg);
		Exception(const std::string& errorMsg, const std::string& mess);
		Exception(const std::string& errorMsg, Exception* inner_exception);
		Exception(const std::string& errorMsg, char* f, int l);
		Exception(const std::string& tag, const std::string& errorMsg, char* f, int l);
	};

	class OverflowException : public Exception
	{
	public:
		OverflowException();
		explicit OverflowException(const std::string& arg);
		OverflowException(const std::string& arg, const std::string& mess);
		OverflowException(const std::string& info, char* f, int l);
		OverflowException(const std::string& oper, const std::string& info, char* f, int l);
	};

	class ArgumentOutOfRangeException : public Exception
	{
	public:
		ArgumentOutOfRangeException();
		explicit ArgumentOutOfRangeException(const std::string& arg);
		ArgumentOutOfRangeException(const std::string& arg, const std::string& mess);
		ArgumentOutOfRangeException(const std::string& info, char* f, int l);
		ArgumentOutOfRangeException(const std::string& oper, const std::string& info, char* f, int l);
	};

	class ArgumentException : public Exception
	{
	public:
		ArgumentException();
		explicit ArgumentException(const std::string& arg);
		ArgumentException(const std::string& arg, const std::string& mess);
		ArgumentException(const std::string& info, char* f, int l);
		ArgumentException(const std::string& oper, const std::string& info, char* f, int l);
	};

	class DivideByZeroException : public Exception
	{
	public:
		DivideByZeroException();
		explicit DivideByZeroException(const std::string& arg);
		DivideByZeroException(const std::string& arg, const std::string& mess);
		DivideByZeroException(const std::string& info, char* f, int l);
		DivideByZeroException(const std::string& oper, const std::string& info, char* f, int l);
	};

	class ArgumentNullException : public Exception
	{
	public:
		ArgumentNullException();
		explicit ArgumentNullException(const std::string& arg);
		ArgumentNullException(const std::string& arg, const std::string& mess);
		ArgumentNullException(const std::string& info, char* f, int l);
		ArgumentNullException(const std::string& oper, const std::string& info, char* f, int l);
	};

	class FormatException : public Exception
	{
	public:
		FormatException();
		explicit FormatException(const std::string& arg);
		FormatException(const std::string& arg, const std::string& mess);
		FormatException(const std::string& info, char* f, int l);
		FormatException(const std::string& oper, const std::string& info, char* f, int l);
	};
}
