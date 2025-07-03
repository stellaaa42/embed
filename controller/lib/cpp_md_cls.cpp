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

// exception: overload set(multiple funcs same name, diff params types)
// some dont directly access private->all keep as memeber funcs for consistency
class Foobar
{
public:
    void foo(long x) 
    {/* manipulate private data*/ 
        data += x;
    }
    void foo(double x) 
    { 
        // dont need direct access->could technically be non-member
        // it only calls foo(long);
        foo(std::lround(x));
    }
private:
    long data;
}

// func set->chain
x.scale(0.5).rotate(45).set_color(Color::red);

// helper func->same namespace
namespace Chrono
{
    class Time {}
    class Date {}
    // helper func
    Date next_weekday(Date);
    bool operator==(Date, Date);
}

// dont: define class/enum and declare var the same time
// struct Data {} data {}
struct Data {};
Data data {};

// class over struct if non-public
enum class Month { Jan = 1, Feb, ..., Dec };
class Date
{
public:
    int day;
    Month month;
    // constructor params
    Date(int i, Month m, int y)
    // initialize members
    : d(d), m(m), y(y) {}
private:
    // only Date's member functions/constructor can access 'year'
    int year;
}

// data encapsulation/invariant(relationshiop)->protect internal state
// make it private& member func to maintain/public controller cls access
class Distance
{
public:
    // constructor
    Distance(double magnituce, duoble unit)
        : magnitude(magnitude), unit(unit)
    {
        if (!is_valid_unit(unit))
            throw std::invalid_argument("Unit must be a factor of 10.");
    }
    // 3km 3*1000=3000m
    double meters() const {return magnitude*unit;}
    void set_unit(double u)
    {
        if (!is_valid_unit(u)) 
        {
            throw std::invalid_argument("Unit must be a factor of 10.");
        }
        //adjust magnitude to keep total distance constant in m
        magnitude = meters() / u;
        unit = u;
    }
// only needs the unit val that are factors of 10
private:
    double magnitude;
    // scaling 0.001=mm 1=meters 1000=km
    double unit;

    bool is_valid_unit(double u) const
    {
        // check if u is a power of 10(factor of 10)
        // log10(1000)->3 log10(0.1)->-1 log10(5)->0.69897... 0
        double log10u = std:log10(u);
        return std::floor(log10u) == log10u;
    }
};

// cls two interfaces: public, derived
// derived/protected cls->can skip run-time ck 'cause already guaranteed
class Foo
{
public:
    int bar(int x) 
    {
        // run-time validation
        check(x); 
        // op
        return do_bar(x);
    }
protected:
    // only base and derived cls can call this
    // op on data
    int do_bar(int x);
private:
    // helper check func
    // only Foo can call 
    void check(int x);
    // data
};
// derived cls
class Dir : public Foo
{
    int mem(int x, int y)
    {
        // Dir inherits do_bar()
        // base cls already did the check
        return do_bar(x + y);
    }
};
// outside user
void user(Foo& x)
{
    // not accessible to protected
    // dont: int r = x.do_bar(1);
    int r = x.bar(1);
}

// prefer concrete types over class hierarchies
// Point1->simpler concrete type
// e.g. 2D point, RGB color, date etc that dont need polymorphism
// no inheritance/virtual func/run-time overhead
// copyable by val
class Point1
{
    int x, y;
    // op
}
// Point2->polymorpic type, complexity if not for run-time type-dependent/dynamic lifetime management
// allocated on the free store->new/make_unique
// virtual func->clone()
// vtable ptr(table of func ptrs)->overhead 
// used via base cls ptr/ref
// support polymorphic/derived cls->depend on actual derived type at runtime
class Point2
{
    int x, y;
    virtual ~Point2();
    //op
}
void use()
{
    // make an obj->directly on the stack
    // stack mem->efficient/short-lived data within the func scope
    // mem size cannot be changed
    Point1 p11 {1, 2};
    // direct val copy
    Point1 p12 {p11};
    // obj->dynamically allocate on the heap
    // heap->persist data beyond the func scope
    // instances of ref types->manually allocate
    auto p21 = make_unique<Point2>(1, 2);
    // make a polymorphic copy via virtual func
    auto p22 = p21->clone();
}

// concrete types->regular built-in types
// copy/assign/compare(for equality)/destroy it predictably
struct Bundle
{
    string name;
    vector<Record> vr;
};
bool operator==(const Bundle& a, const Bundle& b)
{
    return a.name == b.name && a.vr == b.vr;
}
Bundle b1 {"my bundle", {r1, r2, r3}};
// shoudl be equal after copying 
Bundle b2 = b1;
if (!(b1 == b2)) error("impossible");
// now they're diff
b2.name = "the other bundle";
if (b1 == b2) error("no");

// const/ref not useful in copyable/movable type
// dont: 
/*
class bad
{
    const int i;
    string& s;
}
*/
// const->cant assign after initialization, copy operator is deleted, its a constant
// ref must be initialized at construction cant be reseated, copy/move operator is deleted
// instead: use smart ptr/unique_ptr/val->copyable/movable constructors
class good
{
    int i;
    // val
    std::string s;
}
