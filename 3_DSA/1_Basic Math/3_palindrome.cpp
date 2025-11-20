class Solution {
      public:
          bool isPalindrome(int x) {
              long r,y=0;
              long num=x;
              while(num!=0){
                  r=num%10;
                  // if((y>INT_MAX /10) || (y<INT_MIN/10)){
                  //     return false;
                  // }
                  y=y*10+r;
                  num=num/10;
              }
              if(x==y && x>=0 ){
                  return true;
              }else{
                
                  return false;
              }
          }
      };