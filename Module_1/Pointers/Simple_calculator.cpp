#include<stdio.h>

int add(int num1, int num2){
       return num1+num2;
}

int subtract(int num1, int num2){
       return num1-num2;
}

int multiply(int num1,int num2){
       return num1*num2;
}

int main(){
int num1;
int num2;
printf("Enter two numbers");
scanf("%d",&num1);
scanf("%d",&num2);

int (*operation)(int,int);

//To do addition
operation = add;
printf("Addition of %d + %d = %d", num1,num2,operation(num1,num2));

//To do subtraction
operation = subtract;
printf("Subtraction of %d - %d = %d", num1,num2,operation(num1,num2));

//To do multiplication
operation = multiply;
printf("Multiplication of %d * %d = %d", num1,num2,operation(num1,num2));

return 0;
}