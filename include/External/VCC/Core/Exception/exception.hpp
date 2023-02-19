#pragma once
#include <string>

#include "base_exception.hpp"

#include "string_helper.hpp"
#include "class_macro.hpp"
#include "exception_type.hpp"

using namespace std;

namespace vcc
{
	// General Exception
	class Exception : public BaseException
	{
	private:
		Exception() {}
	public:
		Exception(ExceptionType type, wstring message) : BaseException(type, message) {}
		~Exception() {}
	};
}