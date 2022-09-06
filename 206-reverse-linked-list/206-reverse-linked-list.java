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
class Solution 
{
    public ListNode reverseList(ListNode head) 
    {
        ArrayDeque <Integer> ad=new ArrayDeque<Integer>();
        ListNode curr=head;
        int len=0;
        while(curr!=null)
        {
            len++;
            curr=curr.next;
        }
        int a=len;
        ListNode ptr=head;
        while(len-->0)
        {
            ad.push(ptr.val);
            ptr=ptr.next;
        }
        ptr=head;
        while(a-->0)
        {
            ptr.val=ad.pop();
            ptr=ptr.next;
        }
        return head;
        // code here
    }
    
    }
