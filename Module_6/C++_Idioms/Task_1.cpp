#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class FileWrapper{
    ofstream file;
    public:
    FileWrapper(const std::string& filename) {
        file.open(filename);
        if (!file) throw std::runtime_error("Failed to open file");
        std::cout << "File opened: " << filename << "\n";
    }
    ~FileWrapper(){
        if(file.is_open()){
            file.close();
            cout<<"File closed automatically"<<"\n";
        }
    }
    std::ofstream& get() { return file; }
};

int main(){
    try{
    FileWrapper f("text.cpp");
    // This file will cause exception cannot be open
    //FileWrapper f("/invalid_folder/text.txt");
    f.get()<<"First line "<<"\n";
    f.get()<<"Second line"<<"\n";
    // Uncomment the following to test exception safety:
    throw std::runtime_error("Simulated crash!");
    f.get()<<"Third line "<<"\n";
    }

    catch(const exception& e){
        cerr<<"Exception: "<<e.what()<<endl;
    }
    cout<<"Back in main, after FileWrapper goes outof scope"<<endl;
    return 0;
}