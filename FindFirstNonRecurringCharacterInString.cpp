#include <string>
#include <iostream>

char FindTheFirstNonRecurringCharacterInStringUsingString(const char* str)
{
	std::string lst = "";
	std::string dest(str);
	
	for (int i = 0; i < strlen(str); ++i)
	{
		if(1 == std::count(dest.begin(), dest.end(), str[i]))
			return str[i];
	}
	return '\0';
}


int main()
{
	char r = FindTheFirstNonRecurringCharacterInStringUsingString("abcdefghijklmnopqrstuvwxyzabc");
	char n = FindTheFirstNonRecurringCharacterInStringUsingString("abc");
	r = FindTheFirstNonRecurringCharacterInStringUsingString("aabbccdd");

	return 0;
}
