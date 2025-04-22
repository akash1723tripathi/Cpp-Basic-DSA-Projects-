#include<iostream>
#include<queue>
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

void LevelOrderTraversal(node* root){
      queue<node*> q;
      q.push(root);
      q.push(NULL); //sepeartor

      while(!q.empty()){
            node* temp=q.front();
            q.pop();

            if(temp==NULL){
                  cout<<endl;
                  if(!q.empty()){
                        q.push(NULL);
                  }
            }else{
                  cout<<temp->data<<" ";
                  if(temp->left){
                        q.push(temp->left);
                  }
                  if(temp->right){
                        q.push(temp->right);
                  }
            }
      }
}

void InorderTraversal(node* root){
      if(root==NULL){
            return;
      }
      InorderTraversal(root->left);
      cout<<root->data<<" ";
      InorderTraversal(root->right);
}

void PreorderTraversal(node* root){
      if(root==NULL){
            return;
      }
      cout<<root->data<<" ";
      PreorderTraversal(root->left);
      PreorderTraversal(root->right);
}

void PostorderTraversal(node* root){
      if(root==NULL){
            return;
      }
      PostorderTraversal(root->left);
      PostorderTraversal(root->right);
      cout<<root->data<<" ";
}

int main(){
      
      node* root = NULL;
      root=buildTree(root);

      LevelOrderTraversal(root);
       
      cout<<"Inorder tarversal"<<endl;
      InorderTraversal(root);
      cout<<endl<<"Preorder tarversal"<<endl;
      PreorderTraversal(root);
      cout<<endl<<"Postorder tarversal"<<endl;
      PostorderTraversal(root);
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 