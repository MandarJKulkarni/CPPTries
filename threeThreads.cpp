#include <thread>
#include <iostream>
#include <mutex>

int currentCount = 0;
void print(int i)
{
	std::mutex m1;
	m1.lock();
	if (i - currentCount == 1 || currentCount - i ==2)
	{
		std::cout << i << std::endl;
		std::condition_variable cv;
		currentCount = i;
	}
	m1.unlock();
}
void main()
{
	std::thread t1(print,1);
	_sleep(1);
	std::thread t2(print, 2);
	_sleep(1);
	std::thread t3(print, 3);

	t1.join();
	
	t2.join();
	
	t3.join();
}