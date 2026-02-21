#include<iostream>
#include<fstream>
#include<limits>

using namespace std;

int main(){
    string filename;
    cout<<"Enter the filename: ";
    getline(cin,filename);
    ifstream in(filename);
    
    if(!in.is_open()){
        cerr<<"Error: File is not open"<<endl;
        return 1;
    }
    int value;
    while(true){

        in>>value;
        if(in.eof()){
            cout<<"\nEnd of file reached."<<endl;
            break;
        }
        if(in.bad()){
            cerr<<"Fatal error!"<<endl;
            break;
        }

        if(in.fail()){
            cout<<"Invalid token encountered. Skipping..."<<endl;

            in.clear();
            in.ignore(numeric_limits<streamsize>::max(),' ');
            continue;
        }
        cout<<"Read integer: "<<value<<endl;
    }
    in.close();
    return 0;
}