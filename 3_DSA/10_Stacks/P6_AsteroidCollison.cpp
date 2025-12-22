// brute-- mannually resolving the collisons -- TLE

class Solution {
public:
      vector<int> asteroidCollision(vector<int>& asteroids) {
            bool collison = true;

            while(collison){

                  collison = false;

                  for(int i=0;i<asteroids.size()-1;i++){

                  if(asteroids[i]>0 && asteroids[i+1]){  // detecting collison

                        if(abs(asteroids[i]) > abs(asteroids[i+1])){
                              asteroids.erase(asteroids.begin()+i+1);
                        }
                        else if(abs(asteroids[i]) < abs(asteroids[i+1])){
                              asteroids.erase(asteroids.begin()+i);
                        }
                        else{
                              asteroids.erase(asteroids.begin()+i,asteroids.begin()+i+2);
                        }
                  }
                  collison = true;
                  break;
                  }
            }
            return asteroids;
      }
};


//optimal 
vector<int> asteroidCollision(vector<int>& arr) {
      stack<int> st;

      for (int i = 0; i < arr.size(); i++) {

            // Case 1: Positive asteroid → always safe to push
            if (arr[i] > 0) {
                  st.push(arr[i]);
            }
            else {  // arr[i] < 0
                  // Resolve collisions
                  while (!st.empty() && st.top() > 0 && st.top() < abs(arr[i])) {
                  st.pop();   // smaller positive asteroid destroyed
                  }

                  // Case: same size collision
                  if (!st.empty() && st.top() == abs(arr[i])) {
                  st.pop();   // both destroyed
                  }
                  // Case: stack empty OR top is negative → safe to push
                  else if (st.empty() || st.top() < 0) {
                  st.push(arr[i]);
                  }
                  // Else: top is positive and bigger → current asteroid destroyed
            }
      }

      // Convert stack to vector
      vector<int> ans(st.size());
      for(int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
      }

      return ans;
}
