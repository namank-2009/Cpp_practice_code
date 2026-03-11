#include<iostream>
#include<memory>
class Widget{
    public:
    Widget(){
        std::cout<<"Construction of widget called at "<<this<<std::endl;
    }
    ~Widget(){
        std::cout<<"Destructor of widget called at "<<this<<std::endl;
    }
    void greet() const {
        std::cout << "Hello from Widget at " << this << std::endl;
    }
};

std::unique_ptr<Widget> makeWidget() {
    auto ptr = std::make_unique<Widget>();
    ptr->greet();
    return ptr; // Ownership moves to caller!
};
//std::unique_ptr cannot be copied, so it is moved to the caller.
int main() {
    std::cout << "== Smart pointer (unique_ptr) example ==\n";
    {
        auto widgetPtr = makeWidget();
        widgetPtr->greet();
    } // unique_ptr goes out of scope, deletes object here

    std::cout << "== Manual new/delete (anti-pattern) ==\n";
    {
        Widget* w = new Widget();
        w->greet();
        delete w; // forget this line and you have a leak!
    }

    std::cout << "Program end." << std::endl;
    return 0;
}
