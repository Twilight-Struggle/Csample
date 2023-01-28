#include <iostream>
#include <string>
#include <vector>
#include <tuple>

using std::cout, std::endl, std::cin, std::string;
using Zahyo = std::tuple<int, int, int>;

bool between(const Zahyo &a, const Zahyo &b)
{
    auto time_d = std::get<0>(b) - std::get<0>(a);
    auto x_d = std::abs(std::get<1>(b) - std::get<1>(a));
    auto y_d = std::abs(std::get<2>(b) - std::get<2>(a));
    auto xy_d = x_d + y_d;
    bool bigger = xy_d <= time_d;
    bool mods = (time_d % 2) == (xy_d % 2);
    return bigger && mods;
}

int main()
{
    std::vector<Zahyo> zahyos;
    int N;
    cin >> N;

    zahyos.reserve(N + 1);
    zahyos.emplace_back(0, 0, 0);
    for (size_t i = 0; i < N; i++)
    {
        int t, x, y;
        cin >> t >> x >> y;
        zahyos.emplace_back(t, x, y);
    }

    bool flag = true;
    for (size_t i = 0; i < N; i++)
    {
        flag = flag && between(zahyos[i], zahyos[i + 1]);
    }

    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}