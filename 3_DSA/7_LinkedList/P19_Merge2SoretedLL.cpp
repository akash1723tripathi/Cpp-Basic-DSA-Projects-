class Solution {
  public:
      Node* sortedMerge(Node* head1, Node* head2) {
            Node* temp1 = list1;
            Node* temp2 = list2;

            Node* dNode = new Node(-1);
            Node* temp = dNode;

            while(temp1!=nullptr && temp2!=nullptr){
                  if(temp1->val < temp2->val){
                  temp->next=temp1;
                  temp = temp1;
                  temp1=temp1->next;
                  }else{
                  temp->next=temp2;
                  temp=temp2;
                  temp2 = temp2->next;
                  }
            }

            if(temp1) temp->next = temp1;
            else temp->next = temp2;

            return dNode->next;    
      }
};