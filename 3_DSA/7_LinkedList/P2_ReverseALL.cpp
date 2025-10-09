//for Singly Linked List
class Solution {
public:
      ListNode* reverseList(ListNode* head) {
            ListNode* prev = nullptr;
            ListNode* curr = head;
            ListNode* next = nullptr;

            while(curr != nullptr){
                  next = curr->next;
                  curr->next = prev;
                  prev = curr;
                  curr = next;
            }

      return prev;
      }
};




//For Doubly Linked List
class Solution {
  public:
      Node *reverse(Node *head) {
            Node* curr = head;
            Node* temp = nullptr;
            
            while(curr != nullptr){
                  temp = curr->prev;
                  curr->prev = curr->next;
                  curr->next = temp;
                  curr = curr->prev;
            }
            
            if(temp != nullptr){
                  head = temp->prev;
            }
      return head;
      }
};