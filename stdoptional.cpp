#include <optional>
int main()
{
	std::optional<int> opt1 = std::nullopt;
	std::optional<std::string> optStr = std::make_optional<std::string>("str");
	std::optional<int> opt = 2;
	if (opt.has_value())
	{
		int val = *opt;
		int val2 = opt.value();
	}

	return opt.value_or(3);
}
