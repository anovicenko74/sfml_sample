#include "figure.hpp"
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

namespace mt
{
    class Circle : public Figure
    {
    private:
        float radius;
        mt::Point o;

    public:
        Circle() : mt::Figure("none"), o(mt::Point(0, 0)), radius(1) {}
        Circle(const mt::Point &o, const float radius, const std::string color) : mt::Figure(color), o(o), radius(radius) {}

        float getSquare() const override
        {
            return M_PI * std::pow(radius, 2);
        }

        ~Circle(){

        };
    };
}