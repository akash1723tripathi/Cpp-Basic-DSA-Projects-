#include<iostream>
using namespace std;

int main(){
      // implicit
      // 1. int->float
      int num1=10;
      float num2=5.5;
      float result= num1+num2;
      cout<< result<<endl;

      // 2. char->int
      char ch ='A';
      int a= ch+1;
      cout<<a<<endl;

      // 3.int->char
      int b=97;
      char cs=b;
      cout<<cs<<endl;
      

      // explicit conversion
      float f1=65.5;
      char pr = (char)f1;
      cout<<pr<<endl;
}
