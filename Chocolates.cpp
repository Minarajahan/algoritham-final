// Algoritham Final Exam
#include <bits/stdc++.h>
using namespace std;

bool chocolates(int total_choco, vector<int>& choco, int n)
{
    if (total_choco % 2 == 0)
    {
        int half = total_choco / 2;
        vector<vector<bool>> dp(n + 1, vector<bool>(half + 1, false));
        for (int i = 0; i <= n; ++i)
            dp[i][0] = true;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= half; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j >= choco[i - 1])
                {
                    dp[i][j] = dp[i][j] || dp[i - 1][j - choco[i - 1]];
                }
            }
        }
        return dp[n][half];
    }
    else
    {
        return false;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> choco(n);
        int total_choco = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> choco[i];
            total_choco += choco[i];
        }
        if (chocolates(total_choco, choco, n))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

