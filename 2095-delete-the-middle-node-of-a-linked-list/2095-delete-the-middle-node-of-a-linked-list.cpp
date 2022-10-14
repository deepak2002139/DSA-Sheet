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
public:
    ListNode* deleteMiddle(ListNode* head) {
       if(head->next==NULL) return NULL;
        //make the pointers 
       ListNode* slow=head;
       ListNode* fast=head; 
        //made condition for 2 length node
       if(slow->next->next==NULL){
           slow->next=NULL;
           return head;
       }
        //run the loop
       while(fast !=NULL&&fast->next !=NULL  ){
           fast=fast->next->next; //by 2 places
           slow=slow->next; //by one
       }
      //now slow is at mid
       slow->val=slow->next->val; //remove the mid value by it's next
       slow->next=slow->next->next; //pointing ->next->next to remove the node

            return head;
    }
};