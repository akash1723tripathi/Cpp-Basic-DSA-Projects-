class Solution {
private:
      Node* merge(Node* list1, Node* list2) {
            Node* dummyNode = new Node(-1);
            Node* res = dummyNode;

            while (list1 != NULL && list2 != NULL) {
                  if (list1->data < list2->data) {
                  res->bottom = list1;
                  res = list1;
                  list1 = list1->bottom;
                  } else {
                  res->bottom = list2;
                  res = list2;
                  list2 = list2->bottom;
                  }
                  res->next = nullptr;
            }

            if (list1) {
                  res->bottom = list1;
            } else {
                  res->bottom = list2;
            }

            Node* finalHead = dummyNode->bottom;
            delete dummyNode;
            return finalHead;
      }

public:
      Node *flatten(Node *root) {
            if (root == NULL || root->next == NULL) {
                  return root;
            }

            Node* mergedList = flatten(root->next);
            root = merge(root, mergedList);
            
            return root;
      }
};