#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using std::cout, std::endl, std::cin, std::string;

std::vector<int> roadcount(int startnode, const std::vector<std::vector<int>> &roads)
{
    constexpr int INTMAX = std::numeric_limits<int>::max();
    std::vector<int> nodes(roads.size());
    for (auto &&e : nodes)
        e = INTMAX;
    std::queue<int> looks;
    looks.push(startnode);
    nodes[startnode] = 0;
    while (!looks.empty())
    {
        auto node = looks.front();
        looks.pop();
        for (const auto &con_node : roads[node])
        {
            if (nodes[con_node] == INTMAX)
            {
                nodes[con_node] = nodes[node] + 1;
                looks.push(con_node);
            }
        }
    }

    return nodes;
}

int main()
{
    int N;
    cin >> N;
    std::vector<std::vector<int>> roads(N);
    for (size_t i = 0; i < N - 1; i++)
    {
        int A, B;
        cin >> A >> B;
        roads[A - 1].push_back(B - 1);
        roads[B - 1].push_back(A - 1);
    }

    std::vector<int> first_nodes = roadcount(0, roads);
    int max_value = -1, max_node = -1;
    for (size_t i = 0; i < first_nodes.size(); i++)
    {
        if (max_value < first_nodes[i])
        {
            max_value = first_nodes[i];
            max_node = i;
        }
    }

    std::vector<int> res_nodes = roadcount(max_node, roads);
    max_value = -1;
    for (const auto &node : res_nodes)
        if (max_value < node)
            max_value = node;

    cout << max_value + 1 << endl;

    return 0;
}