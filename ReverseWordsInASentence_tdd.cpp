#include <string>
#include <iostream>
#include <sstream>

void ReverseAString(std::string &str)
{
	for (int i = 0; i < (str.size()/2); ++i)
	{
		char temp = str[str.size() - i - 1];
		str[str.size() - i - 1] = str[i];
		str[i] = temp;
		if (i == (str.size() / 2) - 1)
			break;
	}
}

std::string ReverseWordsInASentence(const std::string &sent)
{
	std::string newSentence;
	std::istringstream sentence(sent);
	std::string word;
	std::getline(sentence, word, char(' '));
	ReverseAString(word);
	newSentence += word;
	while (std::getline(sentence, word, char(' ')))
	{
		newSentence +=' ';
		ReverseAString(word);
		newSentence += word;
	}
	return newSentence;
}

int main()
{
	std::string test1Input = std::string("dcba");
	if (ReverseWordsInASentence(test1Input) == "abcd")
	{
		std::cout << "Test1 passed";
	}
	std::string test2Input = std::string("aaaa");
	if (ReverseWordsInASentence(test2Input) == "aaaa")
	{
		std::cout << "Test2 passed";
	}
	
	std::string test3Input = std::string("My Name is Mandar");
	if (ReverseWordsInASentence(test3Input) == "yM emaN si radnaM")
	{
		std::cout << "Test3 passed";
	}

	std::string test4Input = std::string("My Name is not Mandar");
	if (ReverseWordsInASentence(test4Input) == "yM emaN si ton radnaM")
	{
		std::cout << "Test4 passed";
	}

	return 0;
}
