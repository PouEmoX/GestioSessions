#include "pch.h"
#include "conversorString.h"

using namespace System;

std::string conversorString::convertirString(System::String^ str) {
	if (str == nullptr) {
		return "";
	}

	IntPtr p = System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(str);
	std::string os = static_cast<const char*>(p.ToPointer());
	System::Runtime::InteropServices::Marshal::FreeHGlobal(p);
	return os;
}

System::String^ conversorString::convertirString(const std::string& str) {
	return gcnew System::String(str.c_str());
}
