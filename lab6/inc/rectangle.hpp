#include "figure.hpp"
#include "utils.hpp"
#include <iostream>
#pragma once

std::ostream &operator<<(std::ostream &os, const mt::Point &point)
{
    return os << point.getName() << "(" << point.getX() << ", " << point.getY() << ")";
}

namespace mt
{
    class Rectangle : public mt::Figure
    {
    private:
        mt::Point a, b, c, d;

    public:
        Rectangle() : mt::Figure("none"), a(mt::Point(0, 0)), b(mt::Point(0, 0)), c(mt::Point(0, 0)), d(mt::Point(0, 0)) {}
        Rectangle(const mt::Point &a, const mt::Point &b, const mt::Point &c, const mt::Point &d, std::string color) : mt::Figure(color), a(a), b(b), c(c), d(d) {}

        std::string getName() const override
        {
            return "Rectangle";
        }

        std::vector<mt::Point> getPoints() const override
        {
            std::vector<mt::Point> result{a, b, c, d};

            return result;
        }

        float getSquare() const override
        {
            const float ab = Utils::distance(a, b);
            const float bc = Utils::distance(b, c);

            return ab * bc;
        }

        ~Rectangle(){

        };
    };
}