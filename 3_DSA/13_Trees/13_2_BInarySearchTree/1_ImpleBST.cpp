#include<iostream>
#include<queue>
using namespace std;

class Node {
public:
      int data;
      Node* left;
      Node* right;

      Node(int d){
            this->data = d;
            this->left = NULL;
            this->right = NULL;
      }
};

Node* InserIntoBST(Node* &root, int d ){
      if(root == NULL){
            root = new Node(d);
            return root;
      }

      if(d > root->data){
            root->right = InserIntoBST(root->right,d);
      }else{
            root->left = InserIntoBST(root->left,d);
      }
      return root;

}

void takeInput(Node* &root){
      int data;
      cin >> data;

      while(data != -1){
            root = InserIntoBST(root,data);
            cin >> data;
      }
}

void LevelOrderTraversal(Node* root){
      queue<Node*> q;
      q.push(root);
      q.push(NULL); //sepeartor

      while(!q.empty()){
            Node* temp=q.front();
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

int main(){
      Node* root = NULL;
      cout<<"Enter the Value for Node: "<<endl;
      takeInput(root);
      cout<<"The levelOrder for tree is as follow :"<<endl;
      LevelOrderTraversal(root);

}