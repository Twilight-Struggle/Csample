#include <iostream>
#include <string>

using std::cout, std::endl, std::cin, std::string;

int main()
{
    string s;
    cin >> s;
    int sum = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
            sum++;
    }
    cout << sum << endl;

    return 0;
}