class MatrixDiagonalSum{
    public static void main(String[] args){
        MatrixDiagonalSum sol = new MatrixDiagonalSum();

        sol.testCases();
    }

    int diagonalSum(int[][] matrix){
        int sum = 0, subArrLen = 0, mid = 0;

        for(int i=0; i<matrix.length; i++){
            subArrLen = matrix[i].length;
            mid = subArrLen / 2;

            sum += matrix[i][i];
            sum += matrix[i][subArrLen-1-i];
        }

        if(subArrLen % 2 != 0)
            sum -= matrix[mid][mid];

        return sum;
    }

    void testCases(){
        int[][] arr1 = {{1,2,3},{5,5,5},{8,8,8}};
        int[][] arr2 = {{0,1,0},{0,1,0},{0,1,0}};
        int[][] arr3 = {{1,1,1},{1,0,1},{1,0,1}};

        System.out.println(diagonalSum(arr1));
        System.out.println(diagonalSum(arr2));
        System.out.println(diagonalSum(arr3));
    }
}