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
    // ListNode reverse(ListNode head)
    // {
//         ArrayDeque <Integer> ad=new ArrayDeque<Integer>();
//         ListNode curr=head;
//         int len=0;
//         while(curr!=null)
//         {
//             len++;
//             curr=curr.next;
//         }
//         int a=len;
//         ListNode ptr=head;
//         while(len-->0)
//         {
//             ad.push(ptr.val);
//             ptr=ptr.next;
//         }
//         ptr=head;
//         while(a-->0)
//         {
//             ptr.val=ad.pop();
//             ptr=ptr.next;
//         }
//         return head;
//         // code here
//     }
    
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) 
    {
        // l1=reverse(l1);
        // l2=reverse(l2);
        
//         ListNode sum =null;
//         int carry=0;
//         while(l1!=null||l2!=null||carry>0)
//         {
//             int newv= carry;
//             if(l1!=null)
//                 newv+=l1.val;
//             if(l2!=null)
//                 newv+=l2.val;
//             carry=newv/10;
//             newv=newv%10;
//             ListNode newNode=new ListNode(newv);
//             newNode.next=sum;
//             sum=newNode;
//             if(l1!=null)
//                 l1=l1.next;
//             if(l2!=null)
//                 l2=l2.next;
            
//         }
//         return sum;
        ListNode list = new ListNode();;
    ListNode head = list;
    int carry=0;
    
    while(l1!=null || l2!=null || carry!=0) {
        ListNode temp = new ListNode();
        int sum = (l1==null?0:l1.val)+(l2==null?0:l2.val)+carry;
        temp.val=sum%10;
        carry=sum/10;
        
        list.next=temp;
        list=list.next;
        l1=(l1==null?l1:l1.next);
        l2=(l2==null?l2:l2.next);
    } 
    return head.next;
    }
}