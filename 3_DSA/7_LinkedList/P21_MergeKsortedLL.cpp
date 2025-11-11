// using min-heap (priority queue) to merge k sorted linked lists
ListNode* mergeKLists(vector<ListNode*>& lists){
      priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> minHeap;
      for(auto listHead : lists){
          if(listHead) {
              minHeap.push({listHead->val, listHead});
          }
      }
      ListNode* dummy = new ListNode(0);
      ListNode* curr = dummy;
      while(!minHeap.empty()) {
          auto [val, node] = minHeap.top();
          minHeap.pop();
          curr->next = new ListNode(val);
          curr = curr->next;
          if(node->next) {
              minHeap.push({node->next->val, node->next});
          }
      }
      return dummy->next;
}


//by love babbar 
#include<queue>
class compare{
      public:
            bool operator()(Node* a, Node* b){
                  return a->data > b->data;
            }
};
class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
            priority_queue<Node*, vector<Node*>, compare> minHeap;
            int k= arr.size();
            if(k==0){
                  return NULL;
            }

            //step 1:

            for(int i=0;i<k;i++){
                  if(arr[i] != NULL){
                        minHeap.push(arr[i]);
                  }
            }

            Node* head = NULL;
            Node* tail = NULL;

            while(minHeap.size()>0){
                  Node* top = minHeap.top();
                  minHeap.pop();

                  if(top->next != NULL){
                        minHeap.push(top->next);
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