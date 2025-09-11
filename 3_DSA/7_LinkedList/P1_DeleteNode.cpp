//statement takeaway --- We have to delete the given node's val and delete a node from a singly-linked list without knowing its head or previous node. Not actual given node. Given node is not tail node, so it will always have next node.

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next= node->next->next;
    }
};
