import java.util.Arrays;

class RowWithMaximumOnes{
    public static void main(String[] args){
        RowWithMaximumOnes sol = new RowWithMaximumOnes();

        sol.testCases();
    }

    int[] findMaxOnesRow(int[][] binaryMatrix){
        int numOnes, maxOnesRow[];

        maxOnesRow = new int[2];
        for(int i=0; i<binaryMatrix.length; i++){
            numOnes = 0;

            for(int j=0; j<binaryMatrix[i].length; j++){
                numOnes += binaryMatrix[i][j];
            }

            if(numOnes >= maxOnesRow[1]) {
                if(numOnes == maxOnesRow[1])
                    ;
                else {
                    maxOnesRow[0] = i;
                    maxOnesRow[1] = numOnes;
                }
            }
        }

        return maxOnesRow;
    }

    void testCases(){
        System.out.println(Arrays.toString(findMaxOnesRow(new int[][] {{1,0},{1,1},{0,1}})));
        System.out.println(Arrays.toString(findMaxOnesRow(new int[][] {{0,1,1},{0,1,1},{1,1,1}})));
        System.out.println(Arrays.toString(findMaxOnesRow(new int[][] {{1,0,1},{0,0,1},{1,1,0}})));
    }
}