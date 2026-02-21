#include<iostream>
#include<iomanip>
#include<vector>

using namespace std;

int main(){
    // Created a vector to store the elements
    vector<pair<string,double>>cont;
    // Inserting the data into the vector
    cont.push_back({"Appple",1.5000});
    cont.push_back({"Banana",0.9898});

    // using the setw to set the width, setprecision to set the decimal point value
    cout<<left<<setw(12)<<"Item"<<right<<setw(8)<<"Price"<<endl;
    for(auto item: cont){
        cout<<left<<setw(12)<<item.first<<right<<setw(8)<<fixed<<setprecision(2)<<item.second<<endl;
    }
}