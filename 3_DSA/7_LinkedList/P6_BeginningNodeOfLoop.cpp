//Modular code -- using external helper functions
class Solution {
private:
      ListNode* FSloop(ListNode* head){
            ListNode* slow = head;
            ListNode* fast = head;

            while(fast != nullptr && fast->next != nullptr){
                  fast=fast->next->next;
                  slow=slow->next;

                  if(slow==fast){
                  return slow;
                  }
            }
            return nullptr;
      }
public:
      ListNode *detectCycle(ListNode *head) {
            if(head==nullptr){
                  return nullptr;
            }

            ListNode* interSec = FSloop(head);
            ListNode* slow = head;

            if(interSec == nullptr){
                  return nullptr;
            }
            
            while(slow != interSec){
                  slow=slow->next;
                  interSec = interSec->next;
            }

            return slow;
      }
};

//Single function code
class Solution {
public:
      ListNode *detectCycle(ListNode *head) {
            ListNode* slow=head;
            ListNode* fast=head;
            while(fast!=NULL && fast->next!=NULL){
                  slow=slow->next;
                  fast=fast->next->next;
                  if(slow==fast){
                  slow=head;
                  while(slow!=fast){
                        slow=slow->next;
                        fast=fast->next;
                  }
                  return slow;
                  }
            }
            return NULL;
      }
};