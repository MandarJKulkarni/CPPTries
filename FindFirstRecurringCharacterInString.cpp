#include <string>
#include <unordered_map>
#include <chrono>
#include <iostream>

char FindTheFirstRecurringCharacterInStringUsingString(const char* str)
{
	std::string lst = "";
	std::string dest = new char[strlen(str)];
	dest[0] = str[0];
	for (int i = 1; i < strlen(str); ++i)
	{
		if (std::string::npos != dest.find(str[i]))
			return str[i];
		dest[i] = str[i];
	}
	return '\0';
}

char FindTheFirstRecurringCharacterInStrinUsingHash(const char* str)
{
	std::string lst = "";
	std::string dest = new char[strlen(str)];
	std::unordered_map<char, int> charToCount;

	charToCount[str[0]] = 1;
	for (int i = 1; i < strlen(str); ++i)
	{
		if (charToCount.end() != charToCount.find(str[i]))
			return str[i];
		charToCount[str[i]] = 1;
	}
	return '\0';
}

int main()
{
	auto start = std::chrono::steady_clock::now();
	char r = FindTheFirstRecurringCharacterInStringUsingString("abcdefghijklmnopqrstuvwxyzabc");	//92992 ns
	auto end = std::chrono::steady_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << std::endl;

	start = std::chrono::steady_clock::now();
	char n = FindTheFirstRecurringCharacterInStringUsingString("abc");				//10211 ns
	end = std::chrono::steady_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << std::endl;

	start = std::chrono::steady_clock::now();
	r = FindTheFirstRecurringCharacterInStringUsingString("aabbccdd");				//9846 ns
	end = std::chrono::steady_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << std::endl;

	start = std::chrono::steady_clock::now();
	r = FindTheFirstRecurringCharacterInStrinUsingHash("abcdefghijklmnopqrstuvwxyzabc");			//415727 ns
	end = std::chrono::steady_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << std::endl;

	start = std::chrono::steady_clock::now();
	n = FindTheFirstRecurringCharacterInStrinUsingHash("abc");						//54701 ns
	end = std::chrono::steady_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << std::endl;

	start = std::chrono::steady_clock::now();
	r = FindTheFirstRecurringCharacterInStrinUsingHash("aabbccdd");						//35738 ns
	end = std::chrono::steady_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << std::endl;
	
	//ToDo: Check for large size string like 100 or 1000
	
	return 0;
}
