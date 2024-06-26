import java.util.Stack;

public class SortingStack {
    public static Stack<Integer> sortStack(Stack<Integer> input) {
        Stack<Integer> tmp1 = new Stack<>();
        Stack<Integer> tmp2 = new Stack<>();

        while(!input.empty() || !tmp2.empty()){
            if(input.empty() || tmp1.empty()){
                while(!tmp1.empty())
                    input.push(tmp1.pop());
                while(!tmp2.empty())
                    input.push(tmp2.pop());

                tmp1.push(input.pop());
                tmp2.push(input.pop());
            }
            else if(input.peek() < tmp1.peek() || input.peek() < tmp2.peek())
                tmp1.push(input.pop());
            else
                tmp2.push(input.pop());
        }

        return tmp1;
    }

    public static void main (String[] args){
        Stack<Integer> s = new Stack<>();

        s.push(5);
        s.push(4);
        s.push(3);
        s.push(2);
        s.push(1);

        sortStack(s);
    }
}
