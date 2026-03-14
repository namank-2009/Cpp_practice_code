#include<iostream>
#include<memory>
#include<string>
#include<fstream>
#include<cstdio>
using namespace std;


int main(){
    FILE* file = fopen("log.txt","w");
    if(!file){
        cerr<<"File not opened"<<endl;
        return 0;
    }

    auto fileDeleter  = [](FILE* f){
        if(f) {
        cout << "Closing file using lambda function\n";
        fclose(f);
    }
    };
    unique_ptr<FILE,decltype(fileDeleter)>ptr(file,fileDeleter);
    fprintf(ptr.get(), "Log started\n");
    cout<<"Writing done\n";
    return 0;
}