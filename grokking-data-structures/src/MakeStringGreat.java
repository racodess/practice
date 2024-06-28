import java.util.Deque;
import java.util.ArrayDeque;
import java.util.Set;

public class MakeStringGreat {

    public String makeGreat(String input){
        Set<Integer> diff = Set.of(-32, 32);

        Deque<Character> stk = new ArrayDeque<>();
        for (char c : input.toCharArray()){
            if (stk.isEmpty() || !diff.contains(c - stk.peek()))
                stk.push(c);
            else
                stk.pop();
        }

        StringBuilder finalStr = new StringBuilder();
        while (!stk.isEmpty())
            finalStr.insert(0, stk.pop());

        return finalStr.toString();
    }

    public static void main(String[] args){

        MakeStringGreat test = new MakeStringGreat();
        System.out.println(test.makeGreat("AaBbCcDdEeff"));
        System.out.println(test.makeGreat("abBA"));
        System.out.println(test.makeGreat("s"));
        System.out.println(test.makeGreat("aacCBB"));
    }
}
