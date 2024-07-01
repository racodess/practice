public class MergeTwoSortedLists {

    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {

        if (l1 == null) return l2;
        if (l2 == null) return l1;

        ListNode current = (l1.val < l2.val) ? l1 : l2;
        ListNode head = current;
        ListNode prev = current;
        ListNode other = (l1.val < l2.val) ? l2 : l1;
        while (current.next != null) {
            if (current.next.val > other.val) {
                current = other;
                other = prev.next;
                prev = prev.next = current;
            }
            else
                prev = current = current.next;
        }
        current.next = other;

        return head;
    }
}
