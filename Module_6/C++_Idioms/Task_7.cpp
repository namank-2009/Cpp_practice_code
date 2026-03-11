#include"widget7.h"
#include<iostream>
#include<cstring>

struct Widget::Impl{
    std::string name;
    char* buffer;

    Impl():buffer(new char[100]){
        std::cout<<"[Impl] Allocated buffer at "<<static_cast<void*>(buffer)<<std::endl;
    }
    ~Impl(){
        std::cout<<"[Impl] Deallocated buffer at "<<static_cast<void*>(buffer)<<std::endl;
        delete[] buffer;
    }
};

Widget::Widget() : pImpl(std::make_unique<Impl>()){}

Widget::~Widget() = default;

void Widget::setName(const std::string& name) {
    pImpl->name = name;
    std::strncpy(pImpl->buffer, name.c_str(), 99);
    pImpl->buffer[99] = '\0'; // Ensure null termination
}

void Widget::printData() const {
    std::cout << "Widget name: " << pImpl->name << ", buffer: " << pImpl->buffer << std::endl;
}

int main() {
    {
        Widget w;
        w.setName("PIMPL+RAII Example");
        w.printData();
    } // Widget and its Impl are destroyed here; resource cleanup printed
    return 0;
}
