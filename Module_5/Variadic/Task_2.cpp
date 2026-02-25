// #include<iostream>
// #include<string>

// using namespace std;

// template<typename... Types>
// class MyTuple;

// template<>
// class MyTuple<>{
// };

// template<typename T, typename... Rest>
// class MyTuple<T,Rest...>{
//     public:
//     T first;
//     MyTuple<Rest...>rest;

//     MyTuple(T f, Rest... r):first(f),rest(r...){}
// };

// void printTuple(MyTuple<>){
// }

// template<typename T, typename... Rest>
// void printTuple(MyTuple<T,Rest...>t){
//     cout<<t.first<<" ";
//     printTuple(t.rest);
// }

// int main(){
//     MyTuple<int, double, std::string> t(1, 2.5, "hello");
//     printTuple(t);
//     return 0;
// }


#include<iostream>
#include<tuple>
using namespace std;

template<typename... Args>
class MyTuple{
    tuple<Args...>data;
public:
    MyTuple(Args... arg):data(arg...){}

    void print() const{
        printHelper<0>();
        cout<<endl;
    }

private:
    template<size_t index>
    void printHelper() const{
        if constexpr (index< sizeof...(Args)){
            cout<< get<index>(data)<<" ";
            printHelper<index+1>();
        }
    }
};

int main(){
    MyTuple<int,double,string>t(2,12.5,"hello");
    t.print();
}