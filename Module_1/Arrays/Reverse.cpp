#include<iostream>
using namespace std;

//Taking input
void inputArray(int arr[], int size){
      for(int i=0; i<size; i++){
          cout<<"Enter the value for "<<i<<"index"<<endl;
          cin>>arr[i];
     }
}

//Reversed Array
void reverseArray(int arr[], int reversedArr[], int size){
           for(int i=0; i<size; i++){
               reversedArr[i] = arr[size-i-1];
          }
}

//Printing both the array
void printArray(int arr[], int reversedArr[], int size){
      cout<<"Original Array";
     for(int i=0; i<size; i++){
          cout<<arr[i]<<" ";
     }

     cout<<"\n Reversed Array";
     for(int i=0; i<size; i++){
          cout<<reversedArr[i]<<" ";
     }
}

int main(){
    int size;
cout<<"Enter the number of integers"<<endl;
cin>>size;

if(size<=0){
cout<<"Invalid size of array"<<endl;
return 0;
}

int arr[size];
int reversedArr[size];
inputArray(arr,size);
reverseArray(arr,reversedArr,size);
printArray(arr,reversedArr,size);

return 0;
}

