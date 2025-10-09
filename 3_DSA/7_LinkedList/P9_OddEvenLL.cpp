// Odd Even Rearrange Linked List via indices--leetcode

class Solution {
public:
      ListNode* oddEvenList(ListNode* head) {
            if (!head || !head->next) return head;

            ListNode* odd = head;
            ListNode* even = head->next;
            ListNode* evenHead = even;  // store start of even list

            // Rearrange
            while (even && even->next) {
                  odd->next = even->next;   // link odd → next odd
                  odd = odd->next;          // move odd pointer
                  even->next = odd->next;   // link even → next even
                  even = even->next;        // move even pointer
            }

            // connect end of odd list to start of even list
            odd->next = evenHead;
            return head;
      }
};



// odd even rearrange linked list via values--gfg

class Solution {
  public:
      Node* divide(Node* head) {
            if (!head || !head->next) return head;

            Node* evenStart = nullptr;
            Node* evenEnd = nullptr;
            Node* oddStart = nullptr;
            Node* oddEnd = nullptr;

            Node* curr = head;

            while (curr != nullptr) {
                  if (curr->data % 2 == 0) {  // even node
                        if (evenStart == nullptr) {
                              evenStart = curr;
                              evenEnd = curr;
                        } else {
                              evenEnd->next = curr;
                              evenEnd = evenEnd->next;
                        }
                  } else {  // odd node
                        if (oddStart == nullptr) {
                              oddStart = curr;
                              oddEnd = curr;
                        } else {
                              oddEnd->next = curr;
                              oddEnd = oddEnd->next;
                        }
                  }
                  curr = curr->next;
            }

            // If no even nodes exist, return odd list as is
            if (evenStart == nullptr) return oddStart;

            // If no odd nodes exist, return even list as is
            if (oddStart == nullptr) return evenStart;

            // Connect even list to odd list
            evenEnd->next = oddStart;
            oddEnd->next = nullptr;  // terminate final list

            return evenStart;
      }
};