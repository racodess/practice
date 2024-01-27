import java.util.Arrays;

class LeftRightSumDifferences{
    public static void main(String[] args){
        LeftRightSumDifferences diff = new LeftRightSumDifferences();
        diff.testCases();
    }

    String LeftRightSumDifferences(int[] nums){

        int leftSum = 0;
        int rightSum;
        for(int i = 0; i < nums.length; ++i){
            rightSum = 0;
            leftSum += nums[i];

            if(i != nums.length - 1) {
                for (int j = i + 1; j < nums.length; ++j) {
                    rightSum += nums[j];
                }
            }

            nums[i] = Math.abs((leftSum - nums[i]) - rightSum);
        }

        return Arrays.toString(nums);
    }

    void testCases(){
        int[][] arr = {
                {2,5,1,6},
                {1,2,3,4},
                {5,4,3,2,1},
                {5, 5, 5, 5, 5}
        };
        System.out.println("Input:");
        System.out.println(Arrays.deepToString(arr) + "\n");
        System.out.println("Output:");
        for(int[] x : arr){
            System.out.println(LeftRightSumDifferences(x)
            );
        }

    }
}