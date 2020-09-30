#include<iostream>
using namespace std;

int minCoins(int coins[], int m, int V)
{
    int dp[V + 1];

    dp[0] = 0;

    for (int i = 1; i <= V; i++)
    {
        dp[i] = INT_MAX;
    }

    for (int i = 1; i <= V; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (coins[j] <= i)
            {
                int curr = dp[i - coins[j]];

                if (curr != INT_MAX && curr + 1 < dp[i])
                {
                    dp[i] = curr + 1;
                }
            }
        }
    }
    return dp[V];
}

int main()
{
    int n;
    cin >> n;

    int change;
    cin >> change;

    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "MINIMUM COINS NEEDED : " << minCoins(a, n, change);
}
