#include <iostream>
#include <future>
#include <thread>
#include <vector>
#include <string>

int getMax(std::vector<int> inputVec)
{
    std::cout<<"in getMax \n";

    return *(std::max_element(inputVec.begin(),inputVec.end()));
}
int main()
{
    std::vector<int> nums = {761,52,33,14,56,78,90};
    std::future<int> f = std::async(std::launch::deferred,getMax,nums);

    std::cout<< "getting the result in Main"<<std::endl;

    // std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout<< f.get()<<std::endl;


    std::future<std::string> f1 = std::async(std::launch::async,
                                             [](){ std::string s("Future of lambda is great \n"); return s;});
    std::cout<<f1.get();


    std::packaged_task<std::string()> task([](){std::string s("Syntax of packaged_task is complex"); return s;});
    std::future<std::string> f2 = task.get_future();
    task();
    std::cout<< f2.get()<<std::endl;

    std::promise<int> p;
    std::future<int> f3 = p.get_future();
    std::thread do_work([&p](){std::cout<<"working \n";p.set_value(5);});
    do_work.detach();
    std::cout<< f3.get()<<std::endl;

    return 0;
}
