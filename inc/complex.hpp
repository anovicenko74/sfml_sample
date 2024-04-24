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
            this->y = c.y;
        }

        Complex operator+(const Complex complex) const
        {
            return Complex{this->x + complex.x, this->y + complex.y};
        }

        Complex &operator+=(const Complex complex)
        {
            this->x += complex.x;
            this->y += complex.y;
            return *this;
        }

        Complex operator*(const Complex complex)
        {
            float temp_x = this->x;
            float temp_y = this->y;

            float x = temp_x * complex.x - temp_y * complex.y;
            float y = temp_y * complex.x + temp_x * complex.y;

            return Complex(x, y);
        }

        Complex &operator*=(const Complex complex)
        {
            float temp_x = this->x;
            float temp_y = this->y;

            this->x = temp_x * complex.x - temp_y * complex.y;
            this->y = temp_x * complex.x + temp_y * complex.y;

            return *this;
        }

        // prefix increment operator.
        Complex &operator++()
        {
            x++;
            return *this;
        }

        // postfix increment operator.
        Complex operator++(int)
        {
            Complex temp = *this;
            ++*this;
            return temp;
        }

        float getX()
        {
            return x;
        }

        float getY()
        {
            return y;
        }

        Complex &setX(float x)
        {
            this->x = x;

            return *this;
        }

        Complex &setY(float y)
        {
            this->y = y;

            return *this;
        }

        ~Complex()
        {
            std::cout << "Delete that object: " << x << " " << y << std::endl;
        }
    };
};