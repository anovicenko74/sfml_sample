#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"
#include "point.hpp"
#include <vector>

using namespace mt;

void figureInfo(Figure &figure)
{
    std::cout << "Type: " << figure.getName() << std::endl
              << "Color: " << figure.getColor() << std::endl;

    std::cout << "Points: ";
    for (const Point &point : figure.getPoints())
        std::cout << point << " ";
    std::cout << std::endl;

    std::cout
        << "Square: " << figure.getSquare() << std::endl
        << std::endl;
}

int main()
{
    // Figure *figures[5];
    // figures[0] = new Circle(Point(0, 0).s("O"), 10, "Red");
    // figures[1] = new Circle(Point(10, 1000).s("A"), 44, "Blue");
    // figures[2] = new Rectangle(Point(5, 5).s("A"), Point(10, 0).s("B"), Point(10, 5).s("C"), Point(0, 5).s("D"), "Purple");
    // figures[3] = new Rectangle(Point(15, 20).s("A"), Point(10, 0).s("B"), Point(10, 5).s("C"), Point(0, 5).s("D"), "Violet");
    // figures[4] = new Circle(Point(1, 50).s("A"), 3, "Blue");

    // for (int i = 0; i < 5; i++)
    //     figureInfo(figures[i] &);

    Circle circle(Point(0, 0).s("O"), 10, "Red");
    Rectangle rectangle(Point(0, 0).s("A"), Point(10, 0).s("B"), Point(10, 5).s("C"), Point(0, 5).s("D"), "Blue");

    figureInfo(circle);
    figureInfo(rectangle);
}
