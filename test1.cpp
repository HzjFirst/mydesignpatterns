#include <iostream>
#include <tuple>
#include "visitor/visitor.h"
#include "obs/weatherdata.h"

std::tuple<int,double,std::string> foo()
{
    return std::make_tuple(1,1.5,u8"houzhijie");
}

int demo = 10;

decltype(auto) ff_foo()
{
    return foo();
}

decltype(auto) ff()
{
    return &demo;
}

template<typename T0>
void magic(T0 value)
{
    std::cout << value << std::endl;
}
template<typename T,typename... Ts>
void magic(T value, Ts... args)
{
    std::cout << value << std::endl;
    if constexpr (sizeof...(args) > 0)
        magic(args...);
}

template<typename T, typename... Ts>
auto printf3(T value, Ts... args) {
    std::cout << value << std::endl;
    (void) std::initializer_list<T>{([&args] {
        std::cout << args << std::endl;
    }(), value)...};
}

template<typename T0>
void printf1(T0 value) {
    std::cout << value << std::endl;
}
template<typename T, typename... Ts>
void printf1(T value, Ts... args) {
    std::cout<<sizeof...(args)<<std::endl;
    std::cout << value << std::endl;
    printf1(args...);
}
#include <QFile>
#include <QTextStream>
#include <QDebug>

int main()
{
    observer_demo();
    return 0;
    QFile file(u8"F:/hou.csv");
    if(!file.open(QIODevice::WriteOnly))
        return 0;
    QTextStream steam(&file);
    steam<<"x,y,z,v";
    int v = 0;
    for(int i = 0; i < 50; ++i)
    {
        if(i % 10 == 0)
            ++v;
        for(int j = 0; j < 50; ++j)
        {
            for(int k = 0; k < j+1; ++k)
            {
                steam<<"\n"<<k<<","<<j<<","<<i<<","<<v;
            }
        }
    }
    visitor_demo();
    return 0;
    printf3("h","h","h","h");
    std::cout<<"houzhijie"<<std::endl;
    return 0;
    auto [x,y,z] = foo();
    std::cout<<x<<","<<y<<","<<z<<std::endl;
    std::cout<<"wanchengle"<<std::endl;
    auto test = ff();

    if(std::is_same<decltype(test), int*>::value)
    {
        std::cout<<"demo is double";
    }
    std::cout << "demo &: " << &demo << "  test &: "<<test;
    return 0;
}
