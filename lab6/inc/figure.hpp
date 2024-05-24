#include "point.hpp"
#include <vector>
#pragma once

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

        virtual std::string getName() const = 0;
        virtual std::vector<mt::Point> getPoints() const = 0;
        // virtual std::vector<mt::Point> getInfo() const = 0;
        virtual float getSquare() const = 0;

        std::string getColor() { return color; };

        ~Figure(){};
    };
}