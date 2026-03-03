#include<iostream>
#include<cstring>
using namespace std;

class MyString{
    char* str;
    public:
        //Constructor
        MyString(const char* val){
            str = new char[strlen(val)+1];
            strcpy(str,val);
        }

        // Copy Constructor
        MyString(const MyString& obj1){
            str = new char[strlen(obj1.str)+1];
            strcpy(str,obj1.str);
        }

        // Copy Assignment
        MyString& operator=(const MyString& obj1){
            if(this != &obj1){
                delete[]str;
                str = new char[strlen(obj1.str)+1];
                strcpy(str,obj1.str);
            }
            return *this;
        }

        // Move constructor
        MyString(MyString&& obj){
            str = obj.str;
            obj.str = nullptr;
        }

        //Move Assignment
        MyString& operator=(MyString&& obj){
            if(this != &obj){
                delete[] str;      // purani memory delete
                str = obj.str;     // pointer steal
                obj.str = nullptr; // source nullify
            }   
            return *this;
        }

        // Destructor
        ~MyString() {
        delete[] str;
        }

        //Displaying the str
        void display(const string label){
        cout<<"Calling by object "<<label<<" str: ";
        if(str)
            cout<<str;
        else
            cout<<"nullptr";
        cout<<endl;
    }
};

int main(){
   MyString obj1("Naman");
    MyString obj2("Ram");

    obj2 = move(obj1);   // MOVE ASSIGNMENT

    obj1.display("obj1");
    obj2.display("obj2");
}