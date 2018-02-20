#include <iostream>
#include <future>
#include <thread>

int main()
{
	std::promise<int> p;
	std::future<int> f3 = p.get_future();
	std::thread do_work([&p]() {std::cout << "working \n"; p.set_value(5); });
	do_work.detach();
	std::cout << f3.get() << std::endl;
}
