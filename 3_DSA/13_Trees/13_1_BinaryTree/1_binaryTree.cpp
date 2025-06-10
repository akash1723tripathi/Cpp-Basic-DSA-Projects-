#include<iostream>
using namespace std;

class node{
      public:
            int data;
            node* left;
            node* right;

      //construtor
      node(int d){
            this -> data = d;
            this -> left = NULL;
            this -> right = NULL;
      };     
};

node* buildTree(node* root){
      int data;
      cout<<"Enter the data: "<<endl;
      cin>>data;
      root = new node(data);

      if(data == -1){
            return NULL;
      }

      cout<< "Enter the data to be inserted at the left "<<data<<endl;
      root->left=buildTree(root->left);
      cout<< "Enter the data to be inserted at the right "<<data<<endl;
      root->right=buildTree(root->right);
      return root;

}

//using level order traversal
void buildLevelOrderTree(node* &root){
      queue<node*> q;
      int data;
      cout<<"Enter the for root node " <<endl;
      cin>>data;
      root = new node(data);
      q.push(root);

      while(!q.empty){
            node* temp= q.front();
            q.pop();

            cout<<"Enter left node of : "<<temp->data<<endl; 
            int leftdata;
            cin>>leftdata;

            if(leftdata == -1){
                  temp->left new node(leftdata);
                  q.push(leftdata);
            }  

            cout<<"Enter right node of : "<<temp->data<<endl; 
            int rightdata;
            cin>>rightdata;

            if(rightdata == -1){
                  temp->right new node(rightdata);
                  q.push(rightdata);
            }            
      }
}

int main(){
      node* root = NULL;
      root=buildTree(root);
}