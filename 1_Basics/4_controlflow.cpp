#include<iostream>
using namespace std;

int main(){
    int paisa;
    cout << " kitna paisa hai tumahre pass : "<<endl;
    cin>>paisa;

    if(paisa>20000){
        cout<<"bandi bana sakte ho"<<endl;
    }else if (paisa>10000){
        cout<<"bandi kya tum toh khana bi nhi kha sakte"<<endl;
    }else{
        cout<<"raeent";
    }

    // will churn out same input to output
    if(cin>>i){    
            cout<<i;
    }

    (paisa > 20000) ? cout<<"bandi in process ": cout<<"no bandi";

    return 0;
}

// conditional , if/if-else/nested if

// TERNARY OPERATOR
// variable =(exp)? true : false ;