#include <iostream>
#include <cmath>

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

        Complex &operator=(Complex &complex)
        {
            Complex newComplex(complex.getX(), complex.getY());

            return newComplex;
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
            // std::cout << "Delete that object: " << x << " " << y << std::endl;
        }

        static float scalar(Complex &a, Complex &b)
        {
            Complex temp = a * b;

            return temp.getX();
        }

        static float abs(Complex &a, Complex &b)
        {
            float a_abs = sqrtf((a.getX(), 2) + powf(a.getY(), 2));
            float b_abs = sqrtf(powf(b.getX(), 2) + powf(b.getY(), 2));

            return a_abs > b_abs ? a_abs : b_abs;
        }

        static int q(Complex &a)
        {
            float x = a.getX();
            float y = a.getY();

            if (x == 0 || y == 0)
                return 0;

            if (x > 0)
            {
                if (y > 0)
                    return 1;
                if (y < 0)
                    return 4;
            }
            else if (x < 0)
            {
                if (y > 0)
                    return 2;
                if (y < 0)
                    return 3;
            }
        }
    };
};