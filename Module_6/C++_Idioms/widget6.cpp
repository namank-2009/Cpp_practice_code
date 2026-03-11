#include "widget.h"
#include<iostream>
using namespace std;

// Actual implementation hidden from header
struct Widget::Impl{
    string name;
};

Widget::Widget(): pImpl(make_unique<Impl>()) {}

Widget::~Widget() = default;

// Move semantics
Widget::Widget(Widget&&) noexcept = default;
Widget& Widget::operator=(Widget&&) noexcept = default;

void Widget::setName(const string& name){
    pImpl->name = name;
}

void Widget::printname() const{
    std::cout << "Widget name: " << pImpl->name << std::endl;
}

int main(){
    Widget w;
    w.setName("Pimpl example");
    w.printname();
    return 0;
}