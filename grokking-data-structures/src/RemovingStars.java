import java.util.Deque;
import java.util.ArrayDeque;

public class RemovingStars {

    public String removeStars(String input) {

        Deque<Character> stk = new ArrayDeque<>();
        for (char c : input.toCharArray())
            stk.push(c);

        StringBuilder finalStr = new StringBuilder();
        int count = 0;
        while (!stk.isEmpty()){
            if (stk.peek() == '*'){
                stk.pop();
                count++;
            }
            else if (count > 0 && !stk.isEmpty() && stk.peek() != '*') {
                for (int i = 0; i < count && !stk.isEmpty(); i++)
                    stk.pop();
                count = 0;
            }
            else {
                finalStr.insert(0, stk.pop());
            }
        }

        return finalStr.toString();
    }
    public static void main(String[] args){

        RemovingStars test = new RemovingStars();
        System.out.println(test.removeStars("abc*de*f"));
        System.out.println(test.removeStars("a*b*c*d"));
        System.out.println(test.removeStars("abcd"));
    }
}
