import java.util.Stack;

class ReverseString{
    public static void main(String[] args){
        ReverseString sol = new ReverseString();

        sol.testCases();
    }

    String reverse(String input){
       Stack<Character> stack = new Stack<>();

       for(Character c : input.toCharArray()){
            stack.push(c);
       }

       String revString = "";
       while(!stack.isEmpty()){
            revString += stack.pop();
       }

       return revString;
    }

    void testCases(){
        String test1 = "Hello, World!";
        String test2 = "OpenAI";
        String test3 = "Stacks are fun!";

        System.out.println(reverse(test1));
        System.out.println(reverse(test2));
        System.out.println(reverse(test3));
    }
}