#include <iostream>
#include <string>

using std::cout, std::endl, std::cin, std::string;

int main()
{
    int a, b, c;
    string s;
    cin >> a;
    cin >> b >> c;
    cin >> s;
    int sum = a + b + c;
    cout << sum << " " << s << endl;

    return 0;
}