#include<iostream>
using namespace std;

int main(){
    double weight;
    cout<<"Enter the order weight in kg: "<<endl;
    cin>>weight;

    if(weight<=0 ){ 
    cout<<"Error: Order weight must be positive"<<endl;
    return 0;
    }
    else if(weight>100 ){   
    cout<<"Error: Order weight must be less than or equal to 100"<<endl;
    return 0;
    }

    char zone;
    cout<<"Enter shipping zone (A, B, or C): ";
    cin>>zone;

    if(zone != 'A' && zone !='B' && zone != 'C'){
    cout<<"Error: Invalid shipping zone. Please enter A, B, or C.";
    return 0;
    }

    double cost;    
    if(zone == 'A'){  // Region A: Local
        if(weight<=2){
            cost = 100;
        }
        else if(weight<=10){
            cost = 200;
        }
        else{
            cost = 200 + (weight-10)*50;
        }
    }
    else if(zone == 'B'){  // Region B: Intra state
        if(weight<=5){
            cost = 300;
        }
        else{
            cost = 300 + (weight-5)*50;
        }
    }
    else if (zone == 'C') {   // Region C: Inter state
        if (weight <= 5) {
            cost = 500;
        } 
        else{
            cost = 500 + (weight - 5) * 100;
        }
    }
    cout << "Total shipping cost: Rs. " << cost << endl;
    return 0;
}

