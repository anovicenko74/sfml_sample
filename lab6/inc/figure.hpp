#include "point.hpp"
#include <vector>

namespace mt
{
    class Figure
    {
    private:
        std::vector<mt::Point> points;

    public:
        Figure(std::vector<mt::Point> points)
        {
            for (int i = 0; i < points.size(); i++)
                this->points.push_back(points[i]);
        };

        virtual float getSquare() const = 0;

        ~Figure()
        {
            points.clear();
        };
    };
}