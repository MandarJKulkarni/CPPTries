#include <iostream>
#include <future>
#include <thread>
#include <vector>
#include <string>

int main()
{
    std::promise<void> p2;
    std::shared_future<void> sf = p2.get_future();
    std::mutex m;

    std::future<void> f1 = std::async(std::launch::async, [&sf, &m]()
                                      {   sf.wait();
                                          m.lock();
                                          std::cout<<"received signal from promise in thread1 \n";
                                          m.unlock();}
    );

    std::future<void> f2 = std::async(std::launch::async,[&sf, &m]()
                                      {   sf.wait();
                                          m.lock();
                                          std::cout<<"received signal from promise in thread2 \n";
                                          m.unlock();}
    );

    p2.set_value();

    f1.wait();
    f2.wait();
}
