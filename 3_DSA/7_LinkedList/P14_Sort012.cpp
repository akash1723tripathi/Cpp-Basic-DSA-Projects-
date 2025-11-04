class Solution {
  public:
      Node* segregate(Node* head) {
            if(head==nullptr || head->next == nullptr) return head;
            
            Node* zeroHead = new Node(-1);
            Node* zero = zeroHead;
            
            Node* oneHead = new Node(-1);
            Node* one = oneHead;
            
            Node* twoHead = new Node(-1);
            Node* two = twoHead;
            
            Node* curr = head;
            
            while(curr != nullptr){
                  if(curr->data == 0){
                  zero->next=curr;
                  zero=zero->next;
                  }
                  else if(curr->data == 1){
                  one->next=curr;
                  one=one->next;
                  }else{
                  two->next=curr;
                  two=two->next;
                  }
                  curr=curr->next;
            }
            
            zero->next = (oneHead->next)? oneHead->next : twoHead->next;
            one->next = twoHead->next;
            two->next=nullptr;
      
            head=zeroHead->next;
            
            delete zeroHead,oneHead,twoHead;
            return head;
            
      }
};