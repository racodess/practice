import java.util.LinkedList;
import java.util.Queue;
import java.util.List;
import java.util.Arrays;

public class ZigZagIterator {
    Queue<Integer> q = new LinkedList<Integer>();

    public ZigZagIterator(List<Integer> v1, List<Integer> v2) {

        int size = (v1.size() >= v2.size()) ? v1.size() : v2.size();
        for (int i = 0; i < size; i++) {
            if (i < v1.size())
                q.add(v1.get(i));
            if (i < v2.size())
                q.add(v2.get(i));
        }
    }

    public int next() {
        return q.poll();
    }

    public boolean hasNext() {
        return !q.isEmpty();
    }

    public static void main(String[] args) {
        ZigZagIterator i;
        List<Integer> v1 = Arrays.asList(1, 2);
        List<Integer> v2 = Arrays.asList(3, 4, 5, 6);

        i = new ZigZagIterator(v1, v2);

        while (i.hasNext()) {
            System.out.println(i.next());
        }

        System.out.println(i.hasNext());
    }
}
