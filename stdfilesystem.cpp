#include <filesystem>

int main()
{
	bool exists = std::filesystem::exists("D:\\existingFolder");
	return 0;
}