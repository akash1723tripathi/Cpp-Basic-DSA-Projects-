//STACK/VECTOR based approach
class Solution {
public:
      bool isPalindrome(ListNode* head) {
            stack<int> st;
            ListNode* temp = head;

            while(temp!=nullptr){
                  st.push(temp->val);
                  temp=temp->next;
            }

            temp = head;

            while(temp != nullptr ){
                  if(st.top()==temp->val) {
                  st.pop();
                  temp=temp->next;
                  }
                  else {
                  return false;
                  }
            }
            return true;
      }
};



//OPTIMAL APPROACH

class Solution {
      ListNode* reverse(ListNode* head){

            ListNode* curr=head;
            ListNode* prev=nullptr;

            while(curr!=nullptr){
                  ListNode* temp=curr->next;

                  curr->next=prev;
                  prev=curr;
                  curr=temp;
            }

            return prev;
      }

public:
      bool isPalindrome(ListNode* head) {
            ListNode* temp=head;

            ListNode* slow=temp;
            ListNode* fast=temp;

            while(fast->next!=nullptr && fast->next->next!=nullptr){
                  slow=slow->next;
                  fast=fast->next->next;
            }

            ListNode* newHead=reverse(slow->next);

            ListNode* first=head;
            ListNode* second=newHead;

            while(second!=nullptr){
                  if(first->val!=second->val){
                  reverse(newHead);
                  return false;
                  }
                  first=first->next;
                  second=second->next;


            }

            reverse(newHead);

            return true;
      }
};