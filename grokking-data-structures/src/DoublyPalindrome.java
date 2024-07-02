// class DLNode {
//     int val;
//     DLNode next, prev;
//     DLNode(int val) { this.val = val; }
// }

public class DoublyPalindrome {

    public boolean isPalindrome(DLNode head) {
        DLNode dummy = new DLNode(-1);
        dummy.next = head;

        while (dummy.next != null) {
            dummy.prev = dummy.next;
            dummy.next = dummy.next.next;
        }

        while (head != null) {
            if (head.val != dummy.prev.val)
                return false;
            head = head.next;
            dummy.prev = dummy.prev.prev;
        }

        return true;
    }
}
