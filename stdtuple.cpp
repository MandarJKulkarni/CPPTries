#include <tuple>
#include <iostream>
#include <string>

std::tuple<int, char> functionReturningTuple()
{
	//return std::make_tuple(1,'A');	//Before C++17
	return {1,'A'};	//list-initialization since C++17
}


void main()
{
	std::tuple<int, float, std::string> myTuple = {1,2.2,"3.3"};

	auto tuple2 = std::make_tuple("Creating", "tuple", 2);
	int num = std::get<2>(tuple2);
	const int i = 1;
	std::string message = std::get<i>(tuple2);

	auto combinedTuple = std::tuple_cat(myTuple, tuple2);

	int index;
	char letter;
	//prior to C++17
	std::tie(index, letter) = functionReturningTuple();	//index=1, letter='A'
	//Structured bindings with C++17
	auto[index1, letter1] = functionReturningTuple();	//index1=1, letter1='A'
}