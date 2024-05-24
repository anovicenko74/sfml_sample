#pragma once

namespace mt
{
    class Point
    {
    private:
        float x = 0;
        float y = 0;
        std::string name;

    public:
        Point(float x, float y) : x(x), y(y){};

        Point &s(std::string name)
        {
            this->name = name;

            return *this;
        }

        std::string getName() const
        {
            return this->name;
        }

        float getX() const { return x; };
        float getY() const { return y; };
    };
}
