#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include "circle.hpp"
#include "point.hpp"
#include <vector>

int main()
{
    std::vector<mt::Point> circle_points;
    circle_points.push_back(mt::Point({0, 0}));
    mt::Circle circle(circle_points, 10, 'a');
}
