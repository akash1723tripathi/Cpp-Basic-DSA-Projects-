//leetcode me last me same manga hai but gfg me revserse karke dena hai

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;

        while(curr != nullptr){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
        }
        return prev;
    }

    ListNode* getKthNode(ListNode* temp ,int k){
        k=k-1;
        while(temp!=nullptr && k>0){
            k--;
            temp=temp->next;
        }
        return temp;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = nullptr;

        while(temp!=nullptr){
            ListNode* kthNode = getKthNode(temp,k);
            //no k-group of nodes exist
            if(kthNode==nullptr){
            //for leetcode
                if(prev) prev->next=temp;
                break;

            // for gfg
            //     if(prev){
            //         Node* tail = findTail(temp);
            //         reverseList(temp);
            //         prev->next=tail;
            //     } 
            //     break;
            }

            //to preserve the LL
            ListNode* nextNode = kthNode->next;
            
            // to crave out k-node section
            kthNode->next=nullptr;

            reverseList(temp);

            //if the selected kth group is the first one
            if(temp==head){
                head=kthNode;
            }else{
                //for passes other than first
                prev->next = kthNode;
            }

            prev=temp;
            temp=nextNode;
        }
        return head;
    }
};