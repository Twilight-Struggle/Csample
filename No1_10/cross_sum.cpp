#include <iostream>
#include <vector>

using std::cout, std::endl, std::cin, std::string;

int main()
{
    int H, W;
    cin >> H >> W;
    std::vector<int> rows(H), widths(W);
    std::vector<std::vector<int>> elems(H), res(H);
    for (auto &&e : elems)
        e.reserve(W);
    for (auto &&e : res)
        e.reserve(W);

    int tmp;
    for (size_t i = 0; i < H; i++)
    {
        int rowsum = 0;
        for (size_t j = 0; j < W; j++)
        {
            cin >> tmp;
            elems[i].push_back(tmp);
            rowsum += tmp;
        }
        rows[i] = rowsum;
    }

    for (size_t j = 0; j < W; j++)
    {
        int widsum = 0;
        for (size_t i = 0; i < H; i++)
        {
            widsum += elems[i][j];
        }
        widths[j] = widsum;
    }

    for (size_t i = 0; i < H; i++)
    {
        for (size_t j = 0; j < W; j++)
        {
            if (j > 0)
                cout << " ";
            res[i].push_back(rows[i] + widths[j] - elems[i][j]);
            cout << res[i][j];
        }
        cout << endl;
    }

    return 0;
}