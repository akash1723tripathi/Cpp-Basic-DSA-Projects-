class Solution {
  private:
    int lengthOfList(Node* head) {
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }
        return len;
    }
    
    
  public:
    Node* rotate(Node* head, int k) {
        if (!head || !head->next || k == 0)
            return head;

        int len = lengthOfList(head);
        k = k % len;  // handle cases where k >= len

        if (k == 0)
            return head;

        // Find the tail node
        Node* tail = head;
        while (tail->next) tail = tail->next;

        // Make it circular
        tail->next = head;

        // Find new tail 
        //for left 
      //   Node* newTail = head;
      //   for (int i = 1; i <k; i++) {
      //       newTail = newTail->next;
      //   }

        //for right rotation
        int stepsToNewTail = len - k;
        ListNode* newTail = head;
        for (int i = 1; i < stepsToNewTail; i++) {
            newTail = newTail->next;
        }

        // New head is next of newTail
        Node* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
        
    }
};