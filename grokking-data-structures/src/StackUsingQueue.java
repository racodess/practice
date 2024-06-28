import java.util.Queue;
import java.util.LinkedList;

public class StackUsingQueue {
    Queue<Integer> q = new LinkedList<>();
    Queue<Integer> stkq = new LinkedList<>();

    public void push(int x){
        q.add(x);
    }

    public int pop(){
        if (!q.isEmpty()){
            while (!q.isEmpty()){
                for (int j = 0; j < q.size() - 1; j++) {
                    q.add(q.remove());
                }

                stkq.add(q.remove());
            }

            int initialSize = stkq.size();
            for (int i = 0; i < initialSize; i++)
                stkq.add(stkq.remove());
        }

        return stkq.poll();
    }
}
