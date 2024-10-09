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
 //Using three poinetr
 //using inplace-without making an extra data structure
class Solution {
    public ListNode reverseList(ListNode head) {
       ListNode current=head;
       ListNode prev=null;
       while(current!=null)
       {
        ListNode fast=current.next;
        current.next=prev;
        prev=current;
        current=fast;
       } 
       return prev;
    }
}