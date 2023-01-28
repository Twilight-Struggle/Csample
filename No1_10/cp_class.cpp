#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using std::cout, std::endl, std::cin, std::string;

int main()
{
    int N, Q;
    cin >> N;
    std::vector<int> A(N);
    for (auto &&a : A)
        cin >> a;
    cin >> Q;
    std::vector<int> B(Q);
    for (auto &&b : B)
        cin >> b;

    std::sort(A.begin(), A.end());
    for (const auto &b : B)
    {
        auto pos = std::lower_bound(A.begin(), A.end(), b);
        if (pos == A.begin())
            cout << std::abs(b - *pos) << endl;
        else if (pos == A.end())
        {
            pos--;
            cout << std::abs(b - *pos) << endl;
        }
        else
        {
            auto x = std::abs(b - *pos);
            pos--;
            auto y = std::abs(b - *pos);
            cout << std::min(x, y) << endl;
        }
    }

    return 0;
}