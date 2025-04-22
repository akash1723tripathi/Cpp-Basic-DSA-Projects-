#include <iostream> 
using namespace std;

int main(){
      int a;
      cout<<"enter the value of a :"<<endl;
      cin>>a;
      for(int i=1 ; i<=a ; i++){
            if(i==5){
                  // break;
                  continue;
            }

            cout<<i<<endl;
      }

      char ch;
      for(ch='A';ch<='Z';ch++){
            cout<<ch<<endl;
      }
      int n=0;
      do{
            cout<<"iterator "<<n<<endl;
            n++;
      }while(n<10);


      // for(;;){   //infinte loop
      //       cout<<"chal raha hai";
      // }
      // do{
      // logic
      // updation 
      // }while (condition)


}




// for(initialization ; condition ; updation) { logic }ICU
//  declaration         while(condition ){  logic            updation }