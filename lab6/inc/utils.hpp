#include "point.hpp"
#include <math.h>

namespace Utils
{
    float distance(mt::Point z, mt::Point v)
    {
        const float a = std::pow(z.getX() - v.getX(), 2);
        const float b = std::pow(z.getY() - v.getY(), 2);

        return std::sqrt(a + b); // sqrt(a**2 + b**2)
    }
}