import java.util.LinkedList;
import java.util.ArrayList;
import java.util.List;
import java.util.Deque;
import java.util.Arrays;

public class MaxOfSubarrays {

    public List<Integer> printMax(int[] arr, int k) {
        Deque<Integer> deq = new LinkedList<Integer>();
        List<Integer> result = new ArrayList<Integer>();

        int totalSubArr = arr.length - (k - 1);
        for (int i = 0; i < totalSubArr; i++) {

            for (int j : Arrays.copyOfRange(arr, i, i + k))
                deq.add(j);

            int val = deq.pollFirst();
            while (!deq.isEmpty()) {
                int tmp = (deq.peekLast() > deq.peekFirst()) ? deq.pollLast() : deq.pollFirst();

                val = (tmp > val) ? tmp : val;
            }

            result.add(val);
        }

        return result;
    }

    public static void main(String[] args) {
        System.out.println(new MaxOfSubarrays().printMax(new int[] {6, 7, 8, 9, 10}, 2));
    }
}
