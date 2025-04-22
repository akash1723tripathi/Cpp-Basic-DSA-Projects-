//OOPS :- Obejct Oriented Programming Systems 

#include<iostream>
using namespace std;

// class - defines blueprint -- empty class 1 bit ka size leti hai 
// class creation 
class student{
      public:
            //properties --- data members 
            string name;
            int age;
            int height;
            int weight;

            //behaviour -- member functions 
            void running(){
                  cout<<"i`m fast as fuck boiiii.."<<name<<endl;
            }     
};

int main(){
// object creation

// static method 
student s1;
s1.name="akash";
s1.running();

//dynamic method
student* s2 = new student();   // class_ponter obj_name = new class_name
s2->name="KASH";
(*s2).height=123; 
s2->running();
}