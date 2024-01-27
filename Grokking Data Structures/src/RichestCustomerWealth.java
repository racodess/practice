class RichestCustomerWealth {
    public static void main(String[] args) {
        RichestCustomerWealth max = new RichestCustomerWealth();

        max.testCases();
    }

    int maxWealth(int[][] accounts){
       int maxWealth = 0;
       int accSum;

       for(int i=0; i<accounts.length; i++){
           accSum = 0;

           for(int j=0; j<accounts[i].length; j++){
               accSum += accounts[i][j];

               if(maxWealth < accSum)
                   maxWealth = accSum;
           }
       }

       return maxWealth;
    }

    void testCases(){
       int[][] testInput = {
               {1,2,3,4,5},
               {5,5,5,5,5},
               {6,6,7,7,8},
       };

       System.out.println(maxWealth(testInput));
    }

}
