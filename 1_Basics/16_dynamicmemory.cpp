#include<iostream>
using namespace std;

// system allocate program two kinda of memory : (static)stack(small in size)  v/s (dynamic)Heap(larger is size, as much large as vitual memory) 

// heap memory keywords like  NEW/DELETE is used
// heap memory returns address of new alloacted block which is saved in a pointer

int main(){

      int* ptr = new int;
      cout<< ptr<<endl; //heap address
      cout<< *ptr<<endl; //garbage value
      *ptr = 508209987;
      cout<<*ptr<<endl;

      delete ptr;

      int* ptr1 = new int[5];
      ptr[0]=40;
      *(ptr+2)=1230;

      for(int i=0; i<5;i++){
            cout<<*(ptr+i)<<" ";
      }

      delete []ptr1;

      // allocating dynamic array 
      int size;
      cin>>size;
      int* ptr2 = new int[size];
 

      
}



//Given , you must answer  queries. Each query is in the format i j, where  denotes an index in array  and  denotes an index in the array located at . For each query, find and print the value of element  in the array at location  on a new line.
int n,q;
    cin>>n>>q;
    int **a = new int*[n](); 
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        int* sub_arr = new int[k]();
        for(int j=0;j<k;j++){
            cin >> sub_arr[j];
        }
        a[i] = sub_arr;
    } 
    
    for(int query=0;query<q;query++){
        int i,j;
        cin>>i>>j;
        cout<<a[i][j]<<endl;
    }
    delete[] a;