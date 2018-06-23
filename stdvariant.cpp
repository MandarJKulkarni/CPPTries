#include <variant>
#include <iostream>
#include <cassert>

int main()
{
	std::variant<int, float> var1;
	var1 = 12.33f;

	float f1 = std::get<float>(var1);	//f1=12.33
	float f2 = std::get<1>(var1);	// f2=12.33

	try {
		std::get<0>(var1);		//throws bad_variant_access
	}
	catch (const std::exception &ex)
	{
		std::cout << typeid(ex).name() << " " << ex.what();
	}

	try {
		int i = std::get<int>(var1);	//throws bad_variant_access
	}
	catch (const std::exception &ex)
	{
		std::cout << typeid(ex).name() << " " << ex.what();
	}

	int *i = std::get_if<int>(&var1);
	if(i) {
		std::cout << *i << std::endl;
	}
	float *f3 = std::get_if<float>(&var1);
	if (f3) {
		std::cout << *f3 << std::endl;
	}
	if (std::holds_alternative<float>(var1) == true) // succeeds
	{
		var1 = 100;
		if (std::holds_alternative<int>(var1) == true) //succeeds
		{
			var1 = 12.33f;
		}
	}

	if (var1.valueless_by_exception())
	{
		int x = 100;
	}

	std::visit([](auto const &e) {std::cout << e; }, var1);
}