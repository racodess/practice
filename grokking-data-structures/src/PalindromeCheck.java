import java.util.Deque;
import java.util.LinkedList;

public class PalindromeCheck {
    public static boolean checkPalindrome(String input) {
        Deque<Character> deq = new LinkedList<Character>();

        String str = "";
        for (String s : input.trim().toLowerCase().split(" "))
            str += s;

        for (char c : str.toCharArray())
            deq.add(c);

        while (!deq.isEmpty()) {
            if (deq.peekFirst() == deq.peekLast()) {
                deq.pollFirst();
                deq.pollLast();
            }
            else
                return false;
        }

        return true;
    }
    public static void main(String[] args) {
        PalindromeCheck test = new PalindromeCheck();

        System.out.println(test.checkPalindrome("madam"));
        System.out.println(test.checkPalindrome("A man a plan a canal Panama"));
    }
}
