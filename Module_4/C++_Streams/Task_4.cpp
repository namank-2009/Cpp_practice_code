#include<iostream>
#include<fstream>

using namespace std;

int main(){
    string input_file;
    string output_file;

    // Input file name
    cout<<"Enter the input filename\n";
    getline(cin,input_file);

    // getting the ouput file name
    cout<<"Enter the output filename\n";
    getline(cin,output_file);

    //ifstream to read data from the file
    ifstream fin(input_file,ios::in);

    // Check for file open or not
    if(!fin.is_open()){
        cerr<<"Error: file not open!!\n";
        return 1;
    }

    //ofstream used to write in the file
    ofstream fout(output_file,ios::out);

    // Checking for output file is open or not
    if(!fout.is_open()){
        cerr<<"Error: file not open!!\n";
        return 1;
    }

    // reaqding data from input file and copying to the output file
    string line;
    while (getline(fin, line)) {
        fout << line << endl;
    }

    //Close files
    fin.close();
    fout.close();

    cout << "File copied successfully!\n";
    return 0;
}