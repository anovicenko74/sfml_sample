#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include "complex.hpp"

std::ostream &operator<<(std::ostream &stream, mt::Complex &complex)
{
    stream << "X: " << complex.getX() << " Y: " << complex.getY() << std::endl;

    return stream;
}

std::istream &operator>>(std::istream &in, mt::Complex &complex)
{
    float x, y;
    std::cout << "X Y" << std::endl;
    in >> x >> y;

    complex.setX(x);
    complex.setY(y);

    return in;
}

int main()
{
    mt::Complex complex_1(1, 2);
    mt::Complex complex_2(9, 10);

    std::cout << "copy: ";
    mt::Complex newComplex = complex_1;
    std::cout << newComplex;

    std::cout << "scalar: ";
    float scalar = mt::Complex::scalar(complex_1, complex_2);
    std::cout << scalar << std::endl;

    std::cout << "great abs: ";
    float abs = mt::Complex::abs(complex_1, complex_2);
    std::cout << abs << std::endl;

    std::cout << "quadrant: ";
    mt::Complex complex_quadrant(-10, -1);
    int quadrant = mt::Complex::q(complex_quadrant);
    std::cout << quadrant << std::endl;

    std::cout << "complex_sum: ";
    mt::Complex complex_sum(0, 0);
    complex_sum += complex_2 + complex_1;
    std::cout << complex_sum;

    std::cout << "complex_mult: ";
    mt::Complex complex_mult(2, 2);
    complex_mult *= complex_1 * complex_2;
    mt::Complex complex_mult2 = complex_1 * complex_2;
    std::cout << complex_mult;

    std::cout << "prefix_increment: ";
    mt::Complex prefix_increment = ++complex_1;
    std::cout << prefix_increment;

    mt::Complex postfix_increment = complex_1++;
    std::cout << "postfix_increment: ";
    std::cout << postfix_increment;
    std::cout << "complex_1: ";
    std::cout << complex_1;

    mt::Complex complex_input;
    std::cin >> complex_input;
    std::cout << complex_input;

    return 0;
}
