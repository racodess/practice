import java.util.Deque;
import java.util.ArrayDeque;

public class AdjacentDuplicates {

    public String removeDuplicates(String str){

        char[] arr = str.toCharArray();
        Deque<Character> stk = new ArrayDeque<>();
        for (int i = arr.length - 1; i >= 0; i--) {
            if (!stk.isEmpty() && arr[i] == stk.peek())
                stk.pop();
            else
                stk.push(arr[i]);
        }

        StringBuilder finalStr = new StringBuilder();
        while (!stk.isEmpty())
            finalStr.append(stk.pop());

        return finalStr.toString();
    }

    public static void main(String[] args) {

        AdjacentDuplicates test = new AdjacentDuplicates();
        System.out.println(test.removeDuplicates("abbaca"));
        System.out.println(test.removeDuplicates("azxxzy"));
        System.out.println(test.removeDuplicates("abba"));
    }
}
