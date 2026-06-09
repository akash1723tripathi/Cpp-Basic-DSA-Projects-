class Solution {
public:
      bool isValid(string s) {
            stack<char> st;
            for(char c : s){

                  if(st.empty()){
                  st.push(c);
                  continue;
                  }

                  char t = st.top();
                  if( (t=='(' && c==')') || (t=='[' && c==']') || (t=='{' && c=='}')  ){
                  st.pop();
                  }
                  else{
                  st.push(c);
                  }
                  
            }
            
      return st.empty(); 
      }
};