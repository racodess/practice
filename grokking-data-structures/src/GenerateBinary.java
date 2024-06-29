import java.util.Queue;
import java.util.Stack;
import java.util.LinkedList;

public class GenerateBinary {

    public static String[] generateBinaryNumbers(int n) {
        String[] res = new String[n];

        Queue<String> q = new LinkedList<>();
        Stack<Integer> stk = new Stack<>();
        StringBuilder str;
        for (int i = 1; i <= n; i++){

            int num = i;
            while (num >= 1){
                stk.push(num % 2);
                num /= 2;
            }

            str = new StringBuilder();
            while (!stk.empty()) {
                str.append(stk.pop());
            }

            q.add(str.toString());
        }

        for (int i = 0; !q.isEmpty(); i++){
            res[i] = q.remove();
        }

        return res;
    }
}
