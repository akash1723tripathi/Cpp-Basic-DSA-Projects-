//Approach 1 : using set

//Approach 2 : using two pointers
vector<int> sortedAraayUnion(vector<int> &a, vector<int> &b){
      vector<int> unionArr;
      int n1 = a.size();
      int n2 = b.size();
      int i = 0;
      int j = 0;

      while(i<n1 && j<n2){
            if(a[i]<b[j]){
                  if(unionArr.size()==0 || unionArr.back()!=a[i]){
                        unionArr.push_back(a[i]);
                  }
                  i++;
            }
            else{
                  if(unionArr.size()==0 || unionArr.back()!=b[j]){
                        unionArr.push_back(b[j]);
                  }
                  j++;
            }
      } 

      while(j<n2){
            if(unionArr.back != b[j]){
                  unionaArr.push_back(b[j]);
            }
            j++;
      }
      while(i<n1){
            if(unionArr.back != a[i]){
                  unionaArr.push_back(a[i]);
            }
            i++;
      }

      return unionArr;

}
