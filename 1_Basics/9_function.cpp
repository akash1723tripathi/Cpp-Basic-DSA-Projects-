#include<iostream>
using namespace std;

void calculate(int a, int b){
      int sum = a+b;
      int sub = a-b;
      int multiply = a*b;
      int divide = a/b;
      cout<<"sum : "<<sum<<endl<<"subtarct : "<<sub<<endl<<"multiply : "<<multiply<<endl<<"Divide : "<<divide<<endl;
}

char ConvertToUpperCase(char ch){
      char ans=ch-'a'+'A';
      return ans;
      
}

int main(){\
      int a,b;
      cout<<"Enter the value of a & b :"<<endl;
      cin>>a;
      cin>>b;
      calculate(a,b);

      char ch='c';
      char res= ConvertToUpperCase(ch);
      cout<<res;
      

}


// return_type   function_name(parameters){
//  body }

// declaration 
// main
// definition