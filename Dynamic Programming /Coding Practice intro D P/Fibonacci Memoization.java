import java.util.*;

class solution{
    
    static int fibonacci(int n, int[] dp){
        if (n == 0){
            return 0;
        }
        if (n == 1){
            return 1;
        }
        if (dp[n]!= -1){
            return dp[n];
        }
        dp[n] = fibonacci(n-1,dp)+fibonacci(n-2,dp);
        return dp[n];
    }

    public static void main(String arg[]){
        Scanner scanner = new Scanner(System.in);
        int n =scanner.nextInt();
        int[] dp = new int[n+1];
        for (int i=0;i<=n;i++){
            dp[i]=-1;
        }
        System.out.println(fibonacci(n,dp));

    }
}