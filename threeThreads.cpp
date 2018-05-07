#include <thread>
#include <iostream>
#include <mutex>

int currentCount = 0;
std::mutex m1;
std::condition_variable cv;
void print(int i)
{
	
	std::unique_lock<std::mutex> lk(m1);
	cv.wait(lk, [i] {return i - currentCount == 1 || currentCount - i == 2; });
	{
		std::cout << i << "	";
		currentCount = i;
	}
	//This is not needed as we are using one function for 3 threads
	/*lk.unlock();
	cv.notify_one();*/
}
void main()
{
	while (true)
	{
		std::thread t1(print, 1);
		//_sleep(1);
		std::thread t2(print, 2);
		//_sleep(1);
		std::thread t3(print, 3);

		t1.join();

		t2.join();

		t3.join();
		std::cout << std::endl;
	}
	
}
//The other way to do this would be:
// 3 threads, 3 functions and 3 conditional variables
