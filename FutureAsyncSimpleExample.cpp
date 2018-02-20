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
    std::future<int> f = std::async(std::launch::async,getMax,nums);

    std::cout<< "getting the result in Main"<<std::endl;

    // std::this_thread::sleep_for(std::chrono::seconds(2));
    //Do some other IMPORTANT work
    std::cout<< f.get();
}
