public class ReverseLinkedList {

    public ListNode reverseList(ListNode head) {

        ListNode ptr1 = head;
        ListNode ptr2 = ptr1.next;
        ListNode tmp = head;
        for (int i = 0; ptr2 != null && ptr2.next != null; i++) {
            tmp = ptr2.next;
            ptr2.next = ptr1;
            ptr1 = ptr2;
            ptr2 = tmp;
        }

        if (ptr2 == null)
            return head;

        ptr2.next = ptr1;
        head.next = null;

        return ptr2;
    }
}
