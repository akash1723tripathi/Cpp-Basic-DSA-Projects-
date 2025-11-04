class Solution {
public:
    void deleteAllOccurOfX(Node** head_ref, int x) {
        Node* curr = *head_ref;

        // Traverse the list
        while (curr != nullptr) {
            if (curr->data == x) {
                Node* toDelete = curr;

                // If it's the head node
                if (curr == *head_ref) {
                    *head_ref = curr->next;
                    if (*head_ref != nullptr)
                        (*head_ref)->prev = nullptr;
                }
                // If it's not the head
                else {
                    curr->prev->next = curr->next;
                    if (curr->next != nullptr)
                        curr->next->prev = curr->prev;
                }

                // Move current forward
                curr = curr->next;

                // Delete the node
                delete toDelete;
            } else {
                curr = curr->next;
            }
        }
    }
};