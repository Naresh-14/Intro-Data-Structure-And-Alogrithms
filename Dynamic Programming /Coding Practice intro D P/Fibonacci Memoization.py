def fibonacci(n,dp):
    if n==0:
        return 0
    if n == 1:
        return 1
    if dp[n]!= -1:
        return dp[n]
    dp[n] = fibonacci(n-1,dp)+fibonacci(n-2,dp)
    return dp[n]

def main():
    n = int(input())
    dp = [-1] * (n+1)
    print(fibonacci(n,dp))

if __name__ == "__main__":
    main()