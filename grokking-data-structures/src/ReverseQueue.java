import java.util.Queue;
import java.util.Stack;

public class ReverseQueue {

    public Queue<Integer> reverseQueue(Queue<Integer> q){

        Stack<Integer> stk = new Stack<>();
        while (!q.isEmpty())
            stk.push(q.remove());

        while (!stk.empty())
            q.add(stk.pop());

        return q;
    }
}
