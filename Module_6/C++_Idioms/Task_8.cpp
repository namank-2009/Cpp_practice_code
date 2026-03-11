#include"widget8.h"
#include<iostream>
#include<cstring>

struct Widget::Impl{
    std::string name;
    char* buffer;
    
    Impl():buffer(new char[100]){
        std::cout<<"[Impl] allocated buffer at "<<static_cast<void*>(buffer)<<std::endl;
    }

    Impl(const Impl& other): name(other.name),buffer(new char[100]){
        std::cout << "[Impl] Copy ctor, buffer at " << static_cast<void*>(buffer) << std::endl;
        std::strcpy(buffer, other.buffer);
    }

    Impl& operator=(const Impl& other){
        if(this!=&other){
            name = other.name;
            std::strncpy(buffer,other.buffer,99);
             buffer[99] = '\0';
        }
        return *this;
    }

    ~Impl() {
        std::cout << "[Impl] Deleting buffer at " << static_cast<void*>(buffer) << std::endl;
        delete[] buffer;
    }
    
};
// Widget implementations
Widget::Widget() : pImpl(std::make_unique<Impl>()) {}

Widget::~Widget() = default;

// Copy constructor (deep copy)
Widget::Widget(const Widget& other)
    : pImpl(std::make_unique<Impl>(*other.pImpl)) {}

// Copy assignment (deep copy)
Widget& Widget::operator=(const Widget& other) {
    if (this != &other) {
        *pImpl = *other.pImpl;
    }
    return *this;
}

// Move constructor
Widget::Widget(Widget&& other) noexcept
    : pImpl(std::move(other.pImpl)) {}

// Move assignment
Widget& Widget::operator=(Widget&& other) noexcept {
    if (this != &other) {
        pImpl = std::move(other.pImpl);
    }
    return *this;
}

void Widget::setName(const std::string& name) {
    pImpl->name = name;
    std::strncpy(pImpl->buffer, name.c_str(), 99);
    pImpl->buffer[99] = '\0';
}

void Widget::printData() const {
    std::cout << "Widget name: " << pImpl->name << ", buffer: " << pImpl->buffer << std::endl;
}


int main() {
    Widget w1;
    w1.setName("PIMPL RuleOf5 Widget");
    w1.printData();

    std::cout << "--- copy constructor ---\n";
    Widget w2(w1);
    w2.printData();

    std::cout << "--- copy assignment ---\n";
    Widget w3;
    w3 = w1;
    w3.printData();

    std::cout << "--- move constructor ---\n";
    Widget w4(std::move(w1));
    w4.printData();

    std::cout << "--- move assignment ---\n";
    Widget w5;
    w5 = std::move(w2);
    w5.printData();
    return 0;
}
