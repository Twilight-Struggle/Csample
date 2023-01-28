#include <iostream>
#include <vector>

using std::cout, std::endl, std::cin, std::string;

int main()
{
    int N, L, K;
    cin >> N >> L;
    cin >> K;

    std::vector<int> yokans;
    int A0, A1;
    A0 = 0;
    for (size_t i = 0; i < N; i++)
    {
        cin >> A1;
        yokans.push_back(A1 - A0);
        A0 = A1;
    }
    yokans.push_back(L - A1);

    int minimum = 0;
    int maximum = L;
    while (minimum < maximum)
    {
        int median = (minimum + maximum + 1) / 2;
        int cutted = 0;
        int sum = 0;
        for (const auto &part : yokans)
        {
            sum += part;
            if (cutted < K)
            {
                if (sum >= median)
                {
                    cutted++;
                    sum = 0;
                }
            }
        }

        if (sum >= median && cutted == K)
            minimum = median;
        else
            maximum = median - 1;
    }

    cout << minimum << endl;

    return 0;
}