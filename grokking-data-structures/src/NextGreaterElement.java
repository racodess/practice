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
        List<Integer> res = new ArrayList<>();
        Stack<Integer> stack = new Stack<>();

        for(int i = 0; i < arr.size(); i++){
            for(int j = arr.size() - 1; j >= 0 ; j--) {
                stack.push(arr.get(j));
            }

            while(!stack.empty()){
                int val = stack.pop();

                if(arr.get(i) < val) {
                    res.add(val);
                    break;
                }
            }

            if(stack.empty())
                res.add(-1);
        }

        return res;
    }

    void testCase(){
        List<Integer> arr = new ArrayList<>();

        for(int i = 1; i <= 5; i++){
            arr.add(i);
        }

        System.out.println(nextLargerElement(arr));
    }
}
