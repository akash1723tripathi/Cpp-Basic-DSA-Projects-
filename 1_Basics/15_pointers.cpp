#include<iostream>
using namespace std;

int main(){
      int* p ; // bad declartion 
      int* n = NULL; //good for practice null pointer exception : segmentation fault

      int num=15;
      int* ptr= &num; //&num gives the address of the variable, and int* significies the pointer space which stores integer
      cout<<num<<endl;
      cout<<&num<<endl; // address of num memory location 
      cout<<ptr<<endl;  // addres stored will be shown 
      cout<<*ptr<<endl; // derefference operator , will show the value where the pointer is pointing  
      cout<<&ptr<<endl; // address of ptr memory space
      cout<< ++(*ptr )<<endl;


      //void pointer: point to any value of any data type
      int A =56;
      void* ptr3= &A;
      cout<<*ptr3<<endl;

      int a=10;
      int *atr= &a;
      int **btr =&atr;

      cout<<a<<endl;
      cout<<&a<<endl;
      cout<<atr<<endl;
      cout<<&atr<<endl;
      cout<<*atr<<endl;
      cout<<btr<<endl;
      cout<<&btr<<endl;
      cout<<*btr<<endl;
      cout<<**btr<<endl;
      

}