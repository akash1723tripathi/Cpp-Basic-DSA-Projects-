//Brute Force Approach
class Solution {
public:
      ListNode* sortList(ListNode* head) {
            vector<int> store;
            ListNode* temp = head;

            while(temp!=NULL){
                  store.push_back(temp->val);
                  temp=temp->next;
            }

            sort(store.begin(),store.end());
            int i=0;
            temp=head;

            while(temp!=NULL){
                  temp->val=store[i];
                  temp=temp->next;
                  i++;
            }

            return head;
      }
};


//Space Optimized Approach

class Solution {
private:
      ListNode* findMiddle(ListNode* head){
            ListNode* slow = head;
            ListNode* fast = head->next;
            while(fast!=NULL && fast->next!=NULL){
                  slow=slow->next;
                  fast=fast->next->next;
            }
            return slow;
      }

      ListNode* sortedMerge(ListNode* head1, ListNode* head2) {
                  ListNode* temp1 = head1;
                  ListNode* temp2 = head2;

                  ListNode* dNode = new ListNode(-1);
                  ListNode* temp = dNode;

                  while(temp1!=nullptr && temp2!=nullptr){
                  if(temp1->val < temp2->val){
                        temp->next=temp1;
                        temp = temp1;
                        temp1=temp1->next;
                  }else{
                        temp->next=temp2;
                        temp=temp2;
                        temp2 = temp2->next;
                  }
                  }

                  if(temp1) temp->next = temp1;
                  else temp->next = temp2;

                  return dNode->next;    
      }


public:
      ListNode* sortList(ListNode* head) {
            if(head==NULL || head->next==NULL){
                  return head;
            }

            ListNode* middle = findMiddle(head);
            ListNode* lefthead = head;
            ListNode* righthead = middle->next;

            middle->next = nullptr;
            
            lefthead = sortList(lefthead);
            righthead = sortList(righthead); 

            return sortedMerge(lefthead,righthead);
      }
};