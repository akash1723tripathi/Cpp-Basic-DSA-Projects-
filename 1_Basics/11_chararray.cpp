#include<iostream>
using namespace std;

int ReturnCharArrayLength(char arr[]){
    int count = 0;
    int index = 0;
    while(arr[index] != '\0'){
        index++;
        count++;
    }
    return count;
}

void concat(char arr1[],char arr2[]){
      int aIndex= ReturnCharArrayLength(arr1);
      int bIndex= 0;
      while(arr2[bIndex] != '\0'){
            arr1[aIndex]=arr2[bIndex];
            aIndex++;
            bIndex++;
      }
      arr1[aIndex]='\0';
}

bool CompareArray(char arr1[],char arr2[]){
      int aIndex=0;
      int bIndex=0;
      int arr1Length = ReturnCharArrayLength(arr1);
      while(aIndex <= arr1Length){
            if(arr1[aIndex] != arr2[bIndex]){
                  return false;
            }
            else{
                  aIndex++;
                  bIndex++;
            }
      }
      return true;
}

int main(){
    char charr1[]="Akash";  
    char charr2[]="Tripathi";
    char charr3[]="Akash";
    cout << charr1 << endl;
    int length = ReturnCharArrayLength(charr1);
    cout << length << endl;
    concat(charr1,charr2);
    cout<<charr1<<endl;
    cout<< CompareArray(charr1,charr3) <<endl;
}


// strlen(char_array) 
// strcpy(destination,source)
// strcmp(arr1,arr2)  : true ke case me 0 output deta hai
// strcat(arr1,arr2)
