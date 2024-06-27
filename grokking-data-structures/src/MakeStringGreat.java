import java.util.Deque;
import java.util.ArrayDeque;

public class MakeStringGreat {

    public String makeGreat(String input){

        Deque<Character> stk = new ArrayDeque<>();

        return "";
    }

    public static void main(String[] args){

        MakeStringGreat test = new MakeStringGreat();
        System.out.println(test.makeGreat("AaBbCcDdEeff"));
        System.out.println(test.makeGreat("abBA"));
        System.out.println(test.makeGreat("s"));
        System.out.println(test.makeGreat("aacCBB"));
    }
}
