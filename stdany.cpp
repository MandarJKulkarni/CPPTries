// stdanyvariantoptional.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <any>
#include <optional>
#include <variant>
#include <iostream>
int main()
{
	auto i = std::make_any<int>(20);
	if(i.has_value())
		std::cout << std::any_cast<int> (i) << std::endl;
	try
	{
		std::string str = std::any_cast<std::string> (i);
	}
	catch (const std::bad_any_cast &ex)
	{
		std::cout << "Caught bad_any_cast exception " << ex.what() << "\n";
	}
	std::cout << i.type().name() << "\n";

	//For an empty any object, returned type info is typeid(void)
	std::any emptyObj;
	std::cout << emptyObj.type().name() << "\n";

	
	return 0;
}

