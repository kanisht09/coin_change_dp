#include<iostream>
using namespace std;

int minCoins(int coins[], int m, int val)
{
    if (val == 0)
    {
        return 0;
    }

    int res = INT_MAX;

    for (int i = 0; i < m; i++)
    {
        if (coins[i] <= val)
        {
            int curr = minCoins(coins, m, val - coins[i]);

            if (curr != INT_MAX && curr + 1 < res)
                res = curr + 1;
        }
    }
    return res;
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
