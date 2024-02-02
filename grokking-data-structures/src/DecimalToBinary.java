import java.util.Stack;

class DecimalToBinary{
    public static void main(String[] args){
        DecimalToBinary sol = new DecimalToBinary();

        sol.testCases();
    }

    String decimalToBinary(int num){
        Stack<Integer> stack = new Stack<>();

        String binary = "";
        if(num == 0) {
            binary += 0;
            return binary;
        }

        int n = num;
        while(n > 0){
            int bit = n % 2;
            stack.push(bit);
            n /= 2;
        }

        while(!stack.isEmpty()){
            binary += stack.pop();
        }

        return binary;
    }

    void testCases(){
        System.out.println(decimalToBinary(0));
        System.out.println(decimalToBinary(32768));
        System.out.println(decimalToBinary(111));
    }
}