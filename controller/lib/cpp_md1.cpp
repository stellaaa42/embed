// class struct
// dont: void draw(int x, int y, int z, int y2);
void draw(Point from, Point to);

//class->invariant struct->vary independently
class Date
{
public:
    // validate and initialize
    Date(int yy, Month mm, char dd);
private:
    int y;
    Month m;
    char d;
};
struct Pair
{
    string name;
    int volume;
}

// func only if it needs direct access to the rep of a cls
class Date
{
    // relatively small interface
};
// helper->no need to direct access
Date next_weekday(Date);
bool operator==(Date, Date);

// overload set->some members that dont directly access private
class Foobar
{
public:
    void foo(long x) {/* manipulate private data*/}
    void foo(double x) { foo(std::lround(x));}
private:
    //
}
// a set of func->chain
x.scale(0.5).rotate(45).set_color(Color::red);