//when number are in reverse order
class Solution {
private:
      ListNode* InsertInLL(ListNode* ansHead, int val){
            ListNode* newNode = new ListNode(val);

            if(ansHead==nullptr){
                  ansHead=newNode;
                  return ansHead;
            }

            ListNode* temp = ansHead;
            while(temp->next != nullptr){
                  temp=temp->next;
            }
            temp->next = newNode;

      return ansHead;
      }    
public:
      ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            int carry = 0;
            ListNode* temp1 = l1;
            ListNode* temp2 = l2;
            ListNode* ansHead = nullptr;

            while( temp1 != NULL || temp2 != NULL || carry != 0 ){
                  int v1=0, v2=0;

                  if(temp1 != NULL) v1= temp1->val;
                  if(temp2 != NULL) v2= temp2->val;

                  int sum = carry + v1 + v2;
                  int digit = sum%10;
                  ansHead = InsertInLL(ansHead, digit);
                  carry = sum/10;

                  if(temp1 != NULL) temp1= temp1->next;
                  if(temp2 != NULL) temp2= temp2->next;
            }

            return ansHead;
      }
};



//when number are in correct order
//approach 1: reverse both linked list and then add them using above approach and again reverse the result
//approach 2: using stacks
//approach 3: using recursion and length alignment


class Solution {
  private:
      int getLength(Node* head) {
            int len = 0;
            while (head) {
                  len++;
                  head = head->next;
            }
            return len;
      }
    
      Node* padWithZeros(Node* head, int diff) {
            while (diff--) {
                  Node* newNode = new Node(0);
                  newNode->next = head;
                  head = newNode;
            }
            return head;
      }
    
      Node* addHelper(Node* l1, Node* l2, int &carry) {
            if (l1 == nullptr && l2 == nullptr) return nullptr;
            
            Node* nextNode = addHelper(l1->next, l2->next, carry);
            
            int sum = l1->data + l2->data + carry;
            int digit = sum % 10;
            carry = sum / 10;
            
            Node* newNode = new Node(digit);
            newNode->next = nextNode;
            
            return newNode;
      }
    
      Node* removeLeadingZeros(Node* head) {
            while (head && head->data == 0) {
                  head = head->next;
            }
            if (!head) return new Node(0); // all zeros case
            return head;
      }
    
  public:
      Node* addTwoLists(Node* head1, Node* head2) {
            int n1 = getLength(head1);
            int n2 = getLength(head2);
            
            if (n1 < n2) head1 = padWithZeros(head1, n2-n1);
            else if (n2 < n1) head2 = padWithZeros(head2, n1-n2);
            
            int carry = 0;
            Node* result = addHelper(head1, head2, carry);
            
            if (carry) {
                  Node* newNode = new Node(carry);
                  newNode->next = result;
                  result = newNode;
            }
            
            // remove leading zeroes
            result = removeLeadingZeros(result);
            
            return result;
      }
};
