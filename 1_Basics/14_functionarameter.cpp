#include<iostream>
using namespace std;

//pass by value
void toUpperCase(char ch){  
      ch++;
      cout<<"in function "<<ch<<endl;
}


// pass by value
void toUpperCase2(char &ch){
      ch++;
      cout<<"in function "<<ch<<endl;`
}

int main(){
      char chr = 'a';
      cout<<"inside main "<<chr<<endl;
      toUpperCase(chr);
      cout<<"inside main "<<chr<<endl;
      toUpperCase2(chr);
      cout<<"inside main "<<chr<<endl;

}
// array hamesha pass by refernce hota hai