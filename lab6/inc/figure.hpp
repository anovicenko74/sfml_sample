#include "point.hpp"
#include <vector>

namespace mt
{
    class Figure
    {
    protected:
        std::string color;

    public:
        Figure(std::string color)
        {
            this->color = color;
        };

        virtual float getSquare() const = 0;

        ~Figure(){};
    };
}