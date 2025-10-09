class Solution {
  public:
      int lengthOfLoop(Node *head) {
            Node* slow = head;
            Node* fast = head;
            int count=0;
            
            while(fast!=nullptr && fast->next!=nullptr){
                  fast=fast->next->next;
                  slow=slow->next;
                  
                  if(slow==fast){
                  slow=fast->next;
                  count++;
                  while(slow!=fast){
                        slow=slow->next;
                        count++;
                  }
                  return count;
                  }
            }
            return count;
      }
};