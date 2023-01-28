#include <iostream>
#include <vector>
#include <cmath>

using std::cout, std::endl, std::cin, std::string;

typedef unsigned long long ulonlon;
constexpr ulonlon MOD = 1000000007;

void no1();
void no2();

int main()
{
    no2();
    return 0;
}

constexpr int BMAX = 30;
struct Smatrix
{
    int size;
    ulonlon ele[BMAX][BMAX];
};

Smatrix matmul(Smatrix A, Smatrix B)
{
    Smatrix ret;
    auto size = A.size;
    ret.size = size;
    for (auto &&row : ret.ele)
        for (auto &&e : row)
            e = 0LL;
    for (size_t i = 0; i < size; i++)
        for (size_t j = 0; j < size; j++)
            for (size_t k = 0; k < size; k++)
            {
                ret.ele[i][j] += A.ele[i][k] * B.ele[k][j];
                ret.ele[i][j] %= MOD;
            }
    return ret;
}

Smatrix matpow(Smatrix A, ulonlon p)
{
    ulonlon limit = 0, tmp = 1;
    while (true)
    {
        if (tmp > p)
            break;
        limit++;
        tmp *= 2;
    }

    Smatrix Apows[limit], ret;
    Apows[0] = A;
    for (size_t i = 1; i < limit; i++)
    {
        Apows[i] = matmul(Apows[i - 1], Apows[i - 1]);
    }

    ret.size = A.size;
    for (size_t i = 0; i < ret.size; i++)
    {
        for (size_t j = 0; j < ret.size; j++)
        {
            if (i == j)
                ret.ele[i][j] = 1;
            else
                ret.ele[i][j] = 0;
        }
    }

    for (int i = limit - 1; i >= 0; i--)
    {
        if (((1LL << i) & p) != 0LL)
            ret = matmul(ret, Apows[i]);
    }
    return ret;
}

void no2()
{
    ulonlon N, B, K;
    cin >> N >> B >> K;
    ulonlon c[K];
    for (auto &&e : c)
    {
        cin >> e;
    }
    Smatrix A;
    A.size = B;
    for (auto &&row : A.ele)
        for (auto &&e : row)
            e = 0LL;

    for (size_t j = 0; j < B; j++)
    {
        for (size_t k = 0; k < K; k++)
        {
            auto next = (10 * j + c[k]) % B;
            A.ele[j][next] += 1;
        }
    }

    Smatrix ret = matpow(A, N);

    cout << ret.ele[0][0] << endl;
}

void no1()
{
    ulonlon N, B, K;
    cin >> N >> B >> K;
    ulonlon c[K];
    for (auto &&e : c)
    {
        cin >> e;
    }
    std::vector<std::vector<ulonlon>> dp(N, std::vector<ulonlon>(B, 0LL));

    for (size_t k = 0; k < K; k++)
    {
        dp[0][c[k] % B] += 1;
    }
    for (size_t i = 0; i < N - 1; i++)
    {
        for (size_t j = 0; j < B; j++)
        {
            for (size_t k = 0; k < K; k++)
            {
                auto next = (10 * j + c[k]) % B;
                dp[i + 1][next] += dp[i][j];
                dp[i + 1][next] %= MOD;
            }
        }
    }

    cout << dp[N - 1][0] << endl;
}