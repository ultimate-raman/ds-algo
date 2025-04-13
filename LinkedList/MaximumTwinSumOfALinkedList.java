package LinkedList;

public class MaximumTwinSumOfALinkedList {
    public ListNode reverseList(ListNode head) {
        ListNode curr = head;
        ListNode next = null;
        ListNode prev = null;

        while(curr != null) {
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    public ListNode findMiddleOfLinkedList(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;

        while(fast != null && fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        return slow;
    }


    public int pairSum(ListNode head) {
        ListNode middleNode = findMiddleOfLinkedList(head);
        ListNode secondHead = reverseList(middleNode.next);
        middleNode.next = secondHead;

        int maxSum = 0;
        ListNode p1 = head;
        ListNode p2 = secondHead;
        

        while (p2 != null) {
            maxSum = Math.max(maxSum, p1.val + p2.val);
            p1 = p1.next;
            p2 = p2.next;
        }

        return maxSum;
    }
}

class ListNode {
    int val;
    ListNode next;
    
    public ListNode() {}

    public ListNode(int val) {
        this.val = val;
    }

    public ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}
