#pragma once
#include<string>


ref class conversorString
{
public:

	std::string convertirString(System::String^ str);

	System::String^ convertirString(const std::string& str);
};

