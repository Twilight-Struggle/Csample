#include <iostream>
#include <string>
#include <algorithm>

using std::cout, std::endl, std::cin, std::string;

int main()
{
    string S;
    cin >> S;
    string ds[] = {"dream", "dreamer", "erase", "eraser"};

    std::reverse(S.begin(), S.end());
    for (auto &&e : ds)
    {
        std::reverse(e.begin(), e.end());
    }

    string loopS = S;
    bool found;
    do
    {
        found = false;
        for (const auto &e : ds)
        {
            if (loopS.find(e) == 0)
            {
                loopS = loopS.substr(e.size());
                found = true;
                break;
            }
        }
    } while (found);

    if (loopS.size() != 0)
        cout
            << "NO" << endl;
    else
        cout << "YES" << endl;

    return 0;
}