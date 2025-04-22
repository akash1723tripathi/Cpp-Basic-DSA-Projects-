#include<iostream>
using namespace std;

int main(){
      int a=5;
      //refernecce variable 
      int &temp=a;
      cout<<temp<<endl;
      temp*=10;
      temp--;
      cout<<a<<endl;
}