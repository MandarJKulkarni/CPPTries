#include <string>
#include <iostream>
#include <chrono>
#include <map>

char FindTheFirstNonRecurringCharacterInStringUsingString(const char* str)
{
	std::string dest(str);
	
	for (int i = 0; i < strlen(str); ++i)
	{
		if(1 == std::count(dest.begin(), dest.end(), str[i]))
			return str[i];
	}
	return '\0';
}

char FindTheFirstNonRecurringCharacterInStringUsingMap(const char* str)
{
	std::string dest(str);
	std::map<char, int> charToCount;
	for (int i = 0; i < strlen(str); ++i)
	{		
		if (charToCount.end() != charToCount.find(str[i]))
			charToCount[str[i]] = charToCount[str[i]] + 1;
		else
		{
			charToCount[str[i]] = 1;
		}
	}
	//Need to traverse the string again because map doesn't store the letters in insertion order
	for (int i = 0; i < strlen(str); ++i)
	{
		if (charToCount[str[i]] == 1)
			return str[i];
	}

	return '\0';
}

int main()
{
	auto start = std::chrono::steady_clock::now();
	char r = FindTheFirstNonRecurringCharacterInStringUsingString("bcdefghijklmnopqrstuvwxyz01234567890123456789bcdefghijklmnopqrstsuvwxyzbcdefghijklmnopqrstuvwxyz01234567890123456789bcdefghijklmnopqrstsuvwxyzbcdefghijklmnopqrstuvwxyz01234567890123456789bcdefghijklmnopqrstsuvwxyzbcdefghijklmnopqrstuvwxyz01234567890123456789bcdefghijklmnopqrstsuvwxyzbcdefghijklmnopqrstuvwxyz01234567890123456789bcdefghijklmnopqrstsuvwxyzbcdefghijklmnopqrstuvwxyz01234567890123456789bcdefghijklmnopqrstsuvwxyzbcdefghijklmnopqrstuvwxyz01234567890123456789bcdefghijklmnopqrstsuvwxyzbcdefghijklmnopqrstuvwxyz01234567890123456789bcdefghijklmnopqrstsuvwxyzbcdefghijklmnopqrstuvwxyz01234567890123456789bcdefghijklmnopqrstsuvwxyza");
	auto end = std::chrono::steady_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << " ns" << std::endl;

	start = std::chrono::steady_clock::now();
	r = FindTheFirstNonRecurringCharacterInStringUsingString("abcdefghijklmnopqrstuvwxyz0123456789");
	 end = std::chrono::steady_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << " ns" << std::endl;

	start = std::chrono::steady_clock::now();
	r = FindTheFirstNonRecurringCharacterInStringUsingString("aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyyzz0");
	 end = std::chrono::steady_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << " ns" << std::endl;
	
	start = std::chrono::steady_clock::now();
	r = FindTheFirstNonRecurringCharacterInStringUsingMap("bcdefghijklmnopqrstuvwxyz01234567890123456789bcdefghijklmnopqrstsuvwxyzbcdefghijklmnopqrstuvwxyz01234567890123456789bcdefghijklmnopqrstsuvwxyzbcdefghijklmnopqrstuvwxyz01234567890123456789bcdefghijklmnopqrstsuvwxyzbcdefghijklmnopqrstuvwxyz01234567890123456789bcdefghijklmnopqrstsuvwxyzbcdefghijklmnopqrstuvwxyz01234567890123456789bcdefghijklmnopqrstsuvwxyzbcdefghijklmnopqrstuvwxyz01234567890123456789bcdefghijklmnopqrstsuvwxyzbcdefghijklmnopqrstuvwxyz01234567890123456789bcdefghijklmnopqrstsuvwxyzbcdefghijklmnopqrstuvwxyz01234567890123456789bcdefghijklmnopqrstsuvwxyzbcdefghijklmnopqrstuvwxyz01234567890123456789bcdefghijklmnopqrstsuvwxyza");
	end = std::chrono::steady_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << " ns" << std::endl;

	start = std::chrono::steady_clock::now();
	r = FindTheFirstNonRecurringCharacterInStringUsingMap("abcdefghijklmnopqrstuvwxyz0123456789");
	end = std::chrono::steady_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << " ns" << std::endl;

	start = std::chrono::steady_clock::now();
	r = FindTheFirstNonRecurringCharacterInStringUsingMap("aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyyzz0");
	end = std::chrono::steady_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << " ns" << std::endl;

	return 0;
}
