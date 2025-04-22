#include<iostream>
using namespace std;

//sum of elements
int ArraySum(int arr[]){
      int sum=0;
      for(int i=0; i<10;i++){
            sum+=arr[i];
      }
      return sum;
}


void ReverseArray(int arr[], int size){
      int start = 0, end = size - 1;
      while (start < end) {
        // Swap the elements at start and end
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        // Move the pointers
        start++;
        end--;
      }
}

int ReturnCharArrayLength(char ch[]){
      int count=0;
      for(i<0 ; i<ch.len() , i++){
            count+=1;
      }
      return count;
}

int main(){
      // declaration    0--(n-1)
      int arr[10];
      // initialization
      // int brr[]={12,34,21,34,45};
      // int arr[5]={0} // all element is zero, if we push one value to newly declared array then all other elements will be zero if not so then they would have garbage value

      // input 
      for(int i=0; i<10;i++){
            cin>>arr[i];
      }

      // output
      for(int i=0; i<10;i++){
            cout<<arr[i]<<" ";
      }
      
      int sum = ArraySum(arr);
      cout<<endl<<sum;

      //Memset() is a C++ function that copies a single character for a specified number of times to the given bytes of memory. It is useful for filling a number of bytes with a given value starting from a specific memory location. It is defined in <cstring> header file.
      memset(a, 0, sizeof(a));
      for (int i = 0; i < 5; i++)
            cout << a[i] << " ";
      
      //character array 
      char ch[] ="newarray";
      cout<<arr<<endl; // behaviourals changes in cout will ne observed, when used it with integer arrays the output will be the address of the first element and for char it will be the whole char array.
      int length = ReturnCharArrayLength(ch[]);
} 