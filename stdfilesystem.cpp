#include <filesystem>

int main()
{
	//returns true for existing folder
	bool exists = std::filesystem::exists("D:\\existingFolder");
	return 0;
}
