/*
Given an array, print the Next Greater Element (NGE) for every element.

The Next Greater Element for an element x is the first greater element on the right side of x in the array.

Elements for which no greater element exist, consider the next greater element as -1.
 */

import java.util.Stack;
import java.util.List;
import java.util.ArrayList;

public class NextGreaterElement {
    public static void main(String[] args){
        NextGreaterElement solution = new NextGreaterElement();

        solution.testCase();
    }


    public List<Integer> nextLargerElement(List<Integer> arr) {
        List<Integer> result = new ArrayList<>();
        Stack<Integer> stack = new Stack<>();

        for (int i = 0; i < arr.size(); i++){
            for (int j = arr.size() - 1; j >= i + 1; j--) {
                stack.push(arr.get(j));
            }

            if (stack.empty()) {
                result.add(-1);
            }
            else {
                while (!stack.empty()) {
                    int val = stack.pop();

                    if (arr.get(i) < val) {
                        result.add(val);
                        break;
                    }
                    else if (stack.empty()) {
                        result.add(-1);
                    }
                }
            }
        }

        return result;
    }

    void testCase(){
        List<Integer> arr;

        arr = new ArrayList<>(){{add(1); add(2); add(3); add(4); add(5);}};
        System.out.println("\nYour input: " + arr);
        System.out.println("Output: " + nextLargerElement(arr));

        arr.clear();
        arr = new ArrayList<>(){{add(5); add(4); add(3); add(2); add(1);}};
        System.out.println("\nYour input: " + arr);
        System.out.println("Output: " + nextLargerElement(arr));

        arr.clear();
        arr = new ArrayList<>(){{add(1); add(3); add(5); add(2); add(4);}};
        System.out.println("\nYour input: " + arr);
        System.out.println("Output: " + nextLargerElement(arr));
    }
}
