// using brute force approach with hashing
class Solution {
  public:
      Node* cloneLinkedList(Node* head) {
            Node* temp = head;
            map<Node*,Node*> mp;
            
            while(temp!=NULL){
                  Node* newNode = new Node(temp->data);
                  mp[temp] = newNode;
                  temp=temp->next;
            }
            
            temp = head;
            
            
            while(temp!=NULL){
                  Node* copyNode = mp[temp];
                  copyNode->next = mp[temp->next];
                  copyNode->random = mp[temp->random];
                  temp = temp->next;
            }
            
      return mp[head];
      }
};


//Space optimized approach

class Solution {
private:
      void insertCopy(Node* head){
            Node* temp = head;
            while(temp!=NULL){
                  Node* newNode = new Node(temp->val);
                  newNode->next=temp->next;
                  temp->next=newNode;
                  temp=temp->next->next;
            }
      }

      void connectRandom(Node* head){
            Node* temp = head;
            while(temp!=NULL){
                  if(temp->random){
                  temp->next->random = temp->random->next;
                  }else{
                  temp->next->random = nullptr;
                  }
                  temp=temp->next->next;
            }
      }

      Node* getDeepCopy(Node* head){
            Node* temp = head;
            Node* dNode = new Node(-1);
            Node* res = dNode;

            while(temp!=NULL){
                  res->next = temp->next;
                  temp->next = temp->next->next;

                  res=res->next;
                  temp=temp->next;
            }
            return dNode->next;
      }

public:
      Node* copyRandomList(Node* head) {
            insertCopy(head);
            connectRandom(head);
            return getDeepCopy(head);
      }
};