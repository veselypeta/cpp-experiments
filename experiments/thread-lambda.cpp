#include <gtest/gtest.h>
#include <thread>
#include <iostream>


TEST(ThreadTest, LambdaThread){
    std::string to_be_written = "intro ";
    std::thread myT([&to_be_written](){
        to_be_written += "{{ my text }}";
    });

    myT.join();
    std::cout << to_be_written << '\n';
}
