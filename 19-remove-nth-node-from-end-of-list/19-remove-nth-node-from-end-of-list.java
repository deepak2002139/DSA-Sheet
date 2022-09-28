/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) 
    {
        ListNode curr= head;
        int count=1;
        while(curr.next!= null)
        {
            count++;
            curr=curr.next;
        }
        if(n==count)
            return head.next;
        int m =count-n;
        curr=head;
        int start=1;
        while(start<m)
        {
            curr=curr.next;
            start++;
        }
        curr.next=curr.next.next;
        return head;
        
    }
}