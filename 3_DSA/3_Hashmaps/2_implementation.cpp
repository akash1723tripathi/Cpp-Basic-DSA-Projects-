#include<iostream>
#include<map> 
#include<unordered_map>
using namespace std;

int main(){
      // unordered_map < data_type1 , data_type_2 > map_name;
      unordered_map<string,int> m;

      // insertion : pair wise insertion hota hai
      // 1
      pair<string,int> p1 = make_pair("akash",1);
      m.insert(p1);

      //2 
      pair<string,int> p2("tripathi",2);
      m.insert(p2);

      //3
      m["love"]=3;


      //searching 
      cout<<m["akash"] << endl;
      cout<<m.at("tripathi") <<endl;

      //size
      cout<<m.size() << endl;

      //to check presence 
      cout<<m.count("bro")<<endl;

      // to erase value corresponding to a key 
      m.erase("love");
      cout<< m.size() <<endl;

      //access karne ke liye 
      for(auto i:m){
            cout<< i.first <<" "<< i.second << endl;
      }

      //iterator  
      cout<<"iterations "<<endl;
      unordered_map<string,int> :: iterator it = m.begin();
      while( it != m.end() ){
            cout<< it->first <<" " << it->second <<endl;
            it++;
      }
}