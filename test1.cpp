#include <iostream>
#include <tuple>
#include "visitor.h"
#include "weatherdata.h"
#include "duck.h"
#include "gumballmachine.h"

std::tuple<int,double,std::string> foo()
{
    return std::make_tuple(1,1.5,u8"houzhijie");
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

#include <cstring>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <limits>
#include <thread>
#include "numseq.h"
#include "myal.h"

using namespace std;

class A
{
public:
    A() {}
};

A * create_a()
{
    static A a;
    cout<<&a<<endl;
    return &a;
}

template <typename IteratorType, typename elemType>
IteratorType my_find(IteratorType first, IteratorType last, const elemType &value)
{
    for(; first != last; ++first)
        if(value == *first)
            return first;
    return last;
}

int main()
{
    vector<int> ac{1,5,3,4};
    cout << "start" <<endl;
    insert_sort(ac);
    cout << "end" <<endl;
    system("pause");

    const int asize = 4;
    int ia1[asize] = { 1,2,3,4};
    int *pia = my_find<int*,int>(ia1,ia1+asize,3);
    if(pia != ia1+asize)
        cout<<*pia<<endl;

    thread t1(create_a);
    thread t2(create_a);
    thread t3(create_a);
    thread t4(create_a);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    cout << seq_func[1](2);
    cout << seq_func[2](0) << endl;

    vector<int(*)(int)> funs;
    funs.push_back(f1);
    funs.push_back(f2);
    funs.push_back(f3);
    int (*funcs[])(int) = {f1,f2,f3};
    cout << funs[0](5)<<endl;
    system("pause");
    bool more = true;
    char chs;
    while(more)
    {
        cout << "please input:\n";
        cin >> chs;
        cout << chs << endl;
        if(chs != 'Y' && chs != 'y')
            more = false;
    }
    return 0;

    ifstream isteam("F:\\test.txt");
    if(!isteam)
        return 0;
    vector<string> datas;
    string data;
    while(isteam >> data)
    {
        datas.push_back(data);
    }

    for(int i = 0; i < datas.size(); ++i)
    {
        cout<<i<<" "<<datas[i]<<" ";
    }
    cout<<endl;

    sort(datas.begin(),datas.end());

    for(int i = 0; i < datas.size(); ++i)
    {
        cout<<i<<" "<<datas[i]<<" ";
    }
    cout<<endl;
    return 0;

    const int array_size = 128;
    int ia[array_size];
    int ival,icnt=0,sum=0;
    while (cin >> ival && icnt < 128) {
        ia[icnt++] = ival;
    }
    for (int var = 0; var < icnt; ++var) {
        sum += ia[var];
    }
    int average = icnt > 0 ? sum/icnt : 0;
    cout<<"Sum of "<< icnt
         <<" elements: "<<sum
         <<". Average: "<<average<<endl;
    return 0;
    char name[128];
    const char * demo = "    hzj";
    cin>>setw(3)>>name;
    cout<<strlen(name)<<" "<<name<<endl;
    cout<<strlen(demo)<<endl;
    return 0;

    string user_name,second_name;
    cout<<"Please enter your first name: ";
    cin >> user_name;
    cout<<"Please enter your second name: ";
    cin >> second_name;
    cout<<"\n"
        <<"Hello, "
        <<user_name
        <<" "
        <<second_name
        <<" ... and goodbye!\n";
    return 0;
    state_demo();
    return 0;
    strategy_demo();
    return 0;
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

    return 0;
}
