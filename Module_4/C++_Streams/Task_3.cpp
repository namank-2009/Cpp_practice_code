#include<iostream>
#include<fstream>
using namespace std;

int main(){
    string filename;
    string text;

    // Ask the user to enter the filename
    std::cout<<"Enter the filename\n";
    getline(cin,filename);

    cout << "Enter the text to save: ";
    getline(cin, text);

    // ofstream is used to write in the file
    ofstream fout(filename, ios::out);

    if(!fout.is_open()){
        cerr<<"Error: file not open!\n";
        return 1;
    }

    //Writing the data in the file
    fout<<text<<endl;

    // Closing the file
    fout.close();

    
    cout << "Data written successfully.\n";

    // Reading from the file
    ifstream fin(filename, ios::in);

    // Checking the file is open or not
    if(!fin.is_open()){
        cerr<<"Error: File not open\n";
        return 1;
    }

    string line;
    cout << "File Contents:\n";

    // Reading the file content
    while (getline(fin, line)) {
        cout << line << endl;
    }

    fin.close();
    return 0;
}