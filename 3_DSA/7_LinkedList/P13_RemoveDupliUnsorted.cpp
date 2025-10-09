//using two loops --o(n^2)
class Solution {
  public:
      Node* removeDuplicates(Node* head) {
            Node* curr = head;

            while (curr != nullptr) {
                  Node* runner = curr;
                  while (runner->next != nullptr) {
                        if (runner->next->data == curr->data) {
                              Node* dup = runner->next;
                              runner->next = runner->next->next;
                              delete dup; // optional cleanup
                        } else {
                              runner = runner->next;
                        }
                  }
                  curr = curr->next;
            }
            return head;
      }
};



//using hashing --o(n) and o(n) space
class Solution {
  public:
      Node *removeDuplicates(Node *head) {
            if (!head) return nullptr;

            unordered_set<int> seen;
            Node* curr = head;
            Node* prev = nullptr;

            while (curr != nullptr) {
                  if (seen.find(curr->data) != seen.end()) {
                        prev->next = curr->next;
                        delete curr;
                  } else {
                        seen.insert(curr->data);
                        prev = curr;
                  }
                  curr = prev->next;
            }
            return head;
      }
};


