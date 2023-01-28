#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>>

using std::cout, std::endl, std::cin, std::string;

struct Point
{
    double x, y;
};
Point operator-(const Point &a1, const Point &a2)
{
    return Point{a1.x - a2.x, a1.y - a2.y};
}

double getangle(Point P)
{
    double I = P.x / std::sqrt(P.x * P.x + P.y * P.y);
    double angle = std::acos(I) * 180 / M_PI;
    if (P.y >= 0.0)
        return angle;
    else
        return 360.0 - angle;
}

double solve(const int pos, const std::vector<Point> &points)
{
    std::vector<double> angles;
    for (size_t i = 0; i < points.size(); i++)
    {
        if (i == pos)
            continue;
        angles.push_back(getangle(points[i] - points[pos]));
    }
    std::sort(angles.begin(), angles.end());

    for (size_t i = 0; i < angles.size(); i++)
    {
    }

    return 0.0;
}

int main()
{
    int N;
    cin >> N;
    std::vector<Point> points(N);
    for (auto &&p : points)
        cin >> p.x >> p.y;

    double Answer = 0.0;
    for (size_t i = 0; i < points.size(); i++)
    {
        auto tmp_ans = solve(i, points);
        Answer = std::max(tmp_ans, Answer);
    }
    cout << Answer << endl;

    return 0;
}