/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
    ListNode *detectCycle(ListNode *head) 
    {
        ListNode *fast = head, *slow = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)//if there is a cycle, two pointers will definitely meet somewhere in the list
            {
                slow = head;//now put one of the pointers at the beginning
                while(1)
                {
                    if(slow == fast)//both pointers will meet at the start of the cycle
                        return slow;
                    slow = slow->next;//increment both one by one
                    fast = fast->next;
                }
            }
        }
        return NULL;
    }
};