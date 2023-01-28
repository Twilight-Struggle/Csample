#include <iostream>

using std::cout, std::endl, std::cin, std::string;

int main()
{
    int A, B, C;
    int sum;
    cin >> A >> B >> C >> sum;
    int count = 0;
    for (size_t i = 0; i <= A; i++)
    {
        for (size_t j = 0; j <= B; j++)
        {
            for (size_t k = 0; k <= C; k++)
            {
                if (i * 500 + j * 100 + k * 50 == sum)
                    count++;
            }
        }
    }
    cout << count << endl;
}