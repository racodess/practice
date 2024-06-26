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

                do tmp1.push(input.pop());
                while(!input.empty() && input.peek() < tmp1.peek());

                if(input.empty() && tmp2.empty()){
                    while(!tmp1.empty())
                        tmp2.push(tmp1.pop());

                    return tmp2;
                }

                do tmp2.push(input.pop());
                while(!input.empty() && input.peek() > tmp2.peek());
            }
            else if(!input.empty() && input.peek() < tmp1.peek() || !input.empty() && input.peek() < tmp2.peek())
                tmp1.push(input.pop());
            else if(!input.empty())
                tmp2.push(input.pop());
        }

        return tmp1;
    }

    public static void main (String[] args){
        Stack<Integer> s1 = new Stack<>();
        Stack<Integer> s2 = new Stack<>();
        Stack<Integer> s3 = new Stack<>();
        Stack<Integer> s4 = new Stack<>();
        Stack<Integer> s5 = new Stack<>();

        s1.push(5);
        s1.push(4);
        s1.push(3);
        s1.push(2);
        s1.push(1);

        System.out.println(sortStack(s1));

        s2.push(34);
        s2.push(3);
        s2.push(31);
        s2.push(98);
        s2.push(92);
        s2.push(23);

        System.out.println(sortStack(s2));

        s3.push(4);
        s3.push(3);
        s3.push(2);
        s3.push(10);
        s3.push(12);
        s3.push(1);
        s3.push(5);
        s3.push(6);

        System.out.println(sortStack(s3));

        s4.push(20);
        s4.push(10);
        s4.push(-5);
        s4.push(-1);

        System.out.println(sortStack(s4));

        s5.push(1);
        s5.push(2);
        s5.push(3);
        s5.push(4);
        s5.push(5);

        System.out.println(sortStack(s5));
    }
}
