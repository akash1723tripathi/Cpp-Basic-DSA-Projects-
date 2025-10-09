class Solution {
  public:
      Node* removeDuplicates(Node* head) {
            if (!head) return nullptr;

            Node* curr = head;

            while (curr != nullptr && curr->next != nullptr) {
                  if (curr->data == curr->next->data) {
                  curr->next = curr->next->next;
                  } else {
                  curr = curr->next;  
                  }
            }

            return head;
      }
};