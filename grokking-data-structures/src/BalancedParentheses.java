import java.util.Stack;

class BalancedParentheses{
    public static void main(String[] args){
        BalancedParentheses sol = new BalancedParentheses();

        sol.testCases();
    }

    boolean isValid(String input){
        Stack<Character> stack = new Stack<>();

        for(Character c : input.toCharArray()){
            if(c == '(' || c == '[' || c == '{'){
                stack.push(c);
            } else {
                if(stack.isEmpty())
                    return false;
                else if(c == ')' && stack.peek() != '(')
                    return false;
                else if(c == ']' && stack.peek() != '[')
                    return false;
                else if(c == '}' && stack.peek() != '{')
                    return false;
                else
                    stack.pop();
            }
        }

        return stack.isEmpty();
    }

    void testCases(){
        System.out.println(isValid("{[()]}"));
        System.out.println(isValid("{[}]"));
        System.out.println(isValid("(]"));
    }
}


