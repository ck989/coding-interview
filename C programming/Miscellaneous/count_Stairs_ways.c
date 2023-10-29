#include <stdio.h>

int countWays(int n)
{
    int dp[n + 1];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    return dp[n];
}

int main()
{
    int stairs = 10;
    int ways = countWays(stairs);

    printf("Number of ways to climb %d stairs: %d\n", stairs, ways);

    return 0;
}
