//Approach 1 : lenghth method
class Solution {
      public:
      int getMiddle(Node* head) {
            int count = 0;
            Node* temp = head;
            
            while(temp != nullptr){
                  count++;
                  temp = temp->next;
            }
            
            int midIndex = count/2; 
            temp = head;
            while(midIndex--){
                  temp = temp->next;
            }
            return temp->data;
      }
};

//Approach 2 : slow and fast pointer method