#include "figure.hpp"
#include "utils.hpp"
#include <iostream>
namespace mt
{
    class Rectangle : public mt::Figure
    {
    private:
        mt::Point a, b, c, d;

    public:
        Rectangle() : mt::Figure("none"), a(mt::Point(0, 0)), b(mt::Point(0, 0)), c(mt::Point(0, 0)), d(mt::Point(0, 0)) {}
        Rectangle(const mt::Point &a, const mt::Point &b, const mt::Point &c, const mt::Point &d, std::string color) : mt::Figure(color), a(mt::Point(0, 0)), b(mt::Point(0, 0)), c(mt::Point(0, 0)), d(mt::Point(0, 0)) {}

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