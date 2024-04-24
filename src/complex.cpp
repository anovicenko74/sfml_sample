#include <iostream>

namespace mt
{
    class Complex
    {
    private:
        float x = 0;
        float y = 0;

    public:
        Complex() = default;
        Complex(float x, float y)
        {
            this->x = x;
            this->y = y;
        };
        Complex(const Complex &c)
        {
            this->x = c.x;
            this->y = c.y; // для примера
        }

        void print()
        {
            std::cout << "x " << x << " y " << y;
        }
    };
};