public class RemoveDuplicatesSortedList {

    public ListNode deleteDuplicates(ListNode head) {

        ListNode current = head;
        ListNode next = current.next;
        while (next != null) {
            if (next.val == current.val) {
                next = current.next = next.next;
            }
            else {
                current = next;
                next = current.next;
            }
        }

        return head;
    }
}
