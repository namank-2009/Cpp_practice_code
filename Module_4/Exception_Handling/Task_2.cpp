#include<iostream>
using namespace std;

class SystemError{
    public:
    const char* message;
    SystemError(const char* msg): message(msg) {}
};

class NetworkError{
    public:
    const char* message;
    NetworkError(const char* msg): message(msg) {}
};

void complexOperation(){
    static int counter = 0;
    counter++;

    if(counter == 1){
        throw SystemError("Disk failure Detected.");
    }
    else if(counter == 2){
        throw NetworkError("Unable to connect to server.");
    }
    else if(counter == 3){
        throw -1;
    }
    else if(counter == 4){
        throw "Very unexpected error!";
    }
    else{
        cout<<"Operation completed successfully!";
    }
}

int main(){
    
    for (int i = 0; i < 5; i++) {
    try{
        complexOperation();
    }
    catch(const NetworkError& error){
        cout<<"Network Error occured "<<error.message<<endl;
    }

    catch(const SystemError & error){
        cout<<"System Error occured "<<error.message<<endl;
    }

    catch(int& errorCode){
        cout<<"Generic integer error caught: "<<errorCode<<endl;
    }
    catch(...){
        cout<<"Unknown exception caught!"<<endl;
    }
    cout << "--- End of processing ---" << endl;
    }
}