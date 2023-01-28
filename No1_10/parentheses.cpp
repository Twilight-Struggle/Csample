#include <iostream>
#include <vector>
#include <cmath>

using std::cout, std::endl, std::cin, std::string;

int main()
{
    int N;
    cin >> N;
    std::vector<string> res;
    for (uint32_t i = 0; i < std::pow(2, N) - 1; i++)
    {
        uint32_t one = 1;
        int cond = 0;
        for (int j = N - 1; j >= 0; j--)
        {
            uint32_t mask = one << j;
            if ((i & mask) == 0)
                cond++;
            else
                cond--;
            if (cond < 0)
                break;
        }
        if (cond == 0)
        {
            string tmp = "";
            uint32_t one = 1;
            for (int j = N - 1; j >= 0; j--)
            {
                uint32_t mask = one << j;
                if ((i & mask) == 0)
                    tmp.push_back('(');
                else
                    tmp.push_back(')');
            }
            res.push_back(tmp);
        }
    }
    for (const auto &e : res)
        cout << e << endl;

    return 0;
}