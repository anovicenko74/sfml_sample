namespace mt
{
    class Point
    {
    private:
        float x = 0;
        float y = 0;

    public:
        Point(float x, float y) : x(x), y(y){};

        float getX() { return x; };
        float getY() { return y; };

        ~Point();
    };

}
