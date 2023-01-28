#include <iostream>
#include <vector>

using std::cout, std::endl, std::cin, std::string;
constexpr long long MOD = 1000000007;

int main()
{
    int N;
    string S;
    cin >> N;
    cin >> S;
    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(8, 0));

    dp[0][0] = 1;
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j <= 7; j++)
        {
            dp[i + 1][j] += dp[i][j];
            if (S[i] == 'a' && j == 0)
                dp[i + 1][j + 1] += dp[i][j];
            else if (S[i] == 't' && j == 1)
                dp[i + 1][j + 1] += dp[i][j];
            else if (S[i] == 'c' && j == 2)
                dp[i + 1][j + 1] += dp[i][j];
            else if (S[i] == 'o' && j == 3)
                dp[i + 1][j + 1] += dp[i][j];
            else if (S[i] == 'd' && j == 4)
                dp[i + 1][j + 1] += dp[i][j];
            else if (S[i] == 'e' && j == 5)
                dp[i + 1][j + 1] += dp[i][j];
            else if (S[i] == 'r' && j == 6)
                dp[i + 1][j + 1] += dp[i][j];
        }
        for (size_t j = 0; j <= 7; j++)
            dp[i + 1][j] %= MOD;
    }

    cout << dp[N][7] << endl;

    return 0;
}