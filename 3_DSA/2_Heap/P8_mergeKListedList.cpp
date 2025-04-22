#include<queue>
class compare{
      public:
            bool operator()(ListNode* a, ListNode* b){
                  return a->data > b->data;
            }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;
      int k= lists.size();
      if(k==0){
            return NULL;
      }

      //step 1:

      for(i=0;i<k;i++){
            if(lists[i] != NULL){
                  minHeap.push(lists[i]);
            }
      }

      ListNode* head = NULL;
      ListNode* tail = NULL;

      while(minHeap.size()>0){
            ListNode* top = minHeap.top();
            minHeap.pop();

            if(top->next != NULL){
                  mihHeap.push(top->next);
            }

            if(head==NULL){
                  // ans LL is empty 
                  head = top;
                  tail = top;
            }
            else{
                  // insert at Linked List
                  tail->next = top;
                  tail= top;
            }
      }
      return head;        
    }
};