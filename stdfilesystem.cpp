#include <filesystem>
#include <iostream>
int main()
{
	bool exists = std::filesystem::exists("D:\\NotBackedUp");
	//returns size in bytes
	const auto fileSize{ std::filesystem::file_size("D:\\NotBackedUp\\MyFiles\\MyPhoto.pdf") };
	//returns empty space on D drive in bytes
	const auto availableSpace = std::filesystem::space("D:\\NotBackedUp\\MyFiles").available;
	
	std::filesystem::path tempFolder("D:\\NotBackedUp\\TempFoder");
	std::filesystem::create_directory(tempFolder);
	exists = std::filesystem::exists(tempFolder);
	if (exists)
		std::filesystem::remove(tempFolder);
	exists = std::filesystem::exists(tempFolder);
	if (exists == false)
		std::cout << "Created and removed a temparary folder";
	return 0;
}