//using length method
class Solution {
public:
      ListNode* removeNthFromEnd(ListNode* head, int n) {
            if (!head) return nullptr;

            int count = 0;
            ListNode* temp = head;
            while (temp) {
                  count++;
                  temp = temp->next;
            }

            int res = count - n;

            if (res == 0) {
                  ListNode* newHead = head->next;
                  delete head;
                  return newHead;
            }

            temp = head;
            while (res > 1) {
                  temp = temp->next;
                  res--;
            }

            ListNode* delNode = temp->next;
            temp->next = temp->next->next;
            delete delNode;

            return head;
      }
};


//using slow-fast pointer method
class Solution {
public:
      ListNode* removeNthFromEnd(ListNode* head, int n) {
            if (!head) return nullptr;

            ListNode* fast = head;
            ListNode* slow = head;

            for(int i=0;i<n;i++){
                  fast=fast->next;
            }

            if (fast==nullptr) {
                  ListNode* newHead = head->next;
                  delete head;
                  return newHead;
            }

            while (fast->next != nullptr) {
                  fast = fast->next;
                  slow = slow->next;
            }

            ListNode* delNode = slow->next;
            slow->next = slow->next->next;
            delete delNode;

            return head;
      }
};
