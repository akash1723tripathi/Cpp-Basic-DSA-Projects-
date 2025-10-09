//using hashmap
class Solution {
public:
      bool hasCycle(ListNode *head) {
            
            if(head == nullptr){
                  return false;
            }

            unordered_map<ListNode*,bool> visited;
            ListNode* temp = head;

            while(temp != nullptr){
                  if(visited[temp]==true){
                  return true;
                  }
                  visited[temp]=true;
                  temp=temp->next;
            }

            return false;
      }
};



//using slow and fast pointer

class Solution {
public:
      bool hasCycle(ListNode *head) {
            if(head==nullptr) return false;

            ListNode* slow = head;
            ListNode* fast = head;

            while(fast != nullptr && fast->next != nullptr){
                  fast=fast->next->next;
                  slow=slow->next;
                  if(slow==fast){
                  return true;
                  }
            }

            return false;
      }
};