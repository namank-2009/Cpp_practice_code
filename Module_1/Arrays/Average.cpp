#include<iostream>
using namespace std;

//Taking input
void inputArray(int arr[], int size){
      for(int i=0; i<size; i++){
          cout<<"Enter the value for "<<i<<"index"<<endl;
          cin>>arr[i];
     }
}

// Function to sum the marks of an array
int sumArray(int arr[], int size){
    int sum =0;
    for(int i=0; i<size; i++){
        sum+=arr[i];
    }
return sum;
}

// Function to calculate the average
float calculateAverage(int sum, int size){
      return static_cast<float>(sum)/size;
}

// Main function
int main(){
int size;
cout<<"Enter the number of integers"<<endl;
cin>>size;

if(size<=0){
cout<<"Invalid size of array"<<endl;
return 0;
}

int marks[size];
inputArray(marks,size);
int sum = sumArray(marks,size);

cout<<"The average marks is = "<<calculateAverage(sum,size);
return 0;
}