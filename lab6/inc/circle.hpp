#include "figure.hpp"
#include <iostream>
namespace mt
{
    class Circle : public Figure
    {
    private:
        std::vector<mt::Point> points;
        float r = 0;

    public:
        Circle(std::vector<mt::Point> points, float r, char c) : Figure(points)
        {
            this->r = r;
        };

        float getSquare() const override
        {
            // std::cout << this->points;
            return 5;
        }

        ~Circle()
        {
            points.clear();
        };
    };
}