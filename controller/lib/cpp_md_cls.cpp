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

// default operations
// default constructor: X() destructor: ~X()
// copy constructor: X(const X&) move constructor: X(X&&)
// copy assignment: operator=(const X&) move assignment: operator=(X&&)
// the rule of zero: let the complier generate destructor/copy constructor...
struct Named_map
{
public:
    // no need to copy/move constructor, destructor, compiler handles it
    explicit Named_map(const string& n) : name(n) {}
private:
    // std::string std::map<> stl containers
    string name;
    map<int, int> rep;
};
// construct
Named_map nm("map");
// compiler-generated copy construct
Named_map nm2 {nm};

// the rule of five: resource manage all special members copy/move/destruct all together
class AbstractBase
{
public:
    // virtual: can be overridden in derived cls
    // call thru ref Base& br=b/ptr* Base* bp=&b br.f() bp->f();
    // non-virtual func call br.Base::f();
    virtual void foo() = 0;
    // suppress with =delete
    virtual ~AbstractBase() = default;
}
// protected
class CloneableBase
{
public:
    virtual unique_ptr<CloneableBase> clone() const;
    virtual ~CloneableBase() = default;
    CloneableBase() = default;
    CloneableBase(const CloneableBase&) = delete;
    CloneableBase& operator=(const CloneableBase&) = delete;
    CloneableBase(CloneableBase&&) = delete;
    CloneableBase& operator=(CloneableBase&&) = delete;
}

// deep copy: copy obj and memory 
// shallow copy: only copy obj
// consistency, dont mix deep and shallow
class Deep
{
    class Impl
    {
    public:
        Impl() = default;
        Impl(const Impl&) = default;
        Impl& operator=(const Impl&) = default;
    };
    std::shared_ptr<Impl> p;
public:
    Deep() : p(std::make_shared<Impl>()) {}
    Deep(const Deep& a) : p(std::make_shared<Impl>(*a.p)) {}
    Deep& operator=(const Deep& a)
    {
        if (this!=&a)
            // dont shallow copy: p=a.p;
            *p = *a.p;
        return *this;
    }
};
class Shallow
{
    class Impl
    {};
    std::shared_ptr<Impl> p;
public:
    Shallow() : p(std::make_shared<Impl>()) {}
    Shallow(const Shallow& a) = default;
    Shallow& operator=(const Shallow& a) = default;
};

// destructor user-defined:vector/final_action-a cls exits to execute upon destruction
// otherwise default
template<typename A>
struct final_action
{
    // final_action owns act() callable
    A act;
    final_action(A a) : act{a} {}
    // on exit, it runs act() 
    ~final_action() { act(); }
};
template<typename A>
// lambda/callable deduce action type
final_action<A> finally(A act)
{
    return final_action<A>{act};
}
void test()
{
    //scope_exit()
    auto act = finally([] {cout<<"Exit test\n";});
    // run lambda
    if () return;
}

// destructor must release resources
class X
{
    // close any file upon X destruction
    ifstream f;
}

// ownership raw ptr(T*) ref(T&)
class legacy_cls
{
    bar* m_observer;
    // dont: foo* m_owning; raw ptr-dont know the owner
    // legacy_class owns it, it needs to del it
    std::unique_ptr<foo> m_owning; 
    gsl::owner<foo*> m_owning;
}

template<typename T>
class Smart_ptr
{
    // T owns *p
    owner<T*> p;
public:
    // copy/move/del
    ~Smart_ptr() {delete p;}
};
void use(Smart_ptr<int> p1)
{
    // no double deletion
    auto p2 = p1;
}

// base class destructor: 
// polymorphic: public-virtual
// non-polymorphic: protected-non-virtual
class Shape
{
public:
    virtual ~Shape()
    {
        std::cout << "Shape destroyed\n";
    }
    virtual void draw() const = 0;
};
class Circle : public Shape
{
public:
    ~Circle()
    {
        std::cout << "Circle destroyed\n";
    }
    void draw() const override {std::cout << "Drawing Circle\n";}
};
void example()
{
    //calls both Shape and Circle destructors
    Shape* s = new Circle();
    delete s;
}
class FileSystemHandle
{
protected:
    ~FileSystemHandle()
    {
        std::cout << "FileSystemHandle destroyed\n";
    }
};
class File : public FileSystemHandle
{
public:
    ~File()
    {
        std::cout << "File destroyed\n";
    }
};
void example()
{
    // dont: FileSystemHandle* f=new File(); destructor is protected
    // derived class being deleted
    File* f = new File();
    delete f;
}

// destructor cant fail: noexcept
class X
{
public:
    ~X() noexcept;
};
X::~X() noexcept
{
    if (cant_release_a_resource) terminate();
}
// dont: if a throwing destructor
struct Details
{
    // might throw exception err
    ~Details();
};
struct X 
{
    Details x; 
    // complier impolicitly noexcept(false)
    ~X() {}
};
// instead: 
struct Safe
{
    ~Safe() noexcept = default;
};
struct Safe
{
    ~Safe() noexcept
    {
        try
        {} catch ()
        {}
    }
}

//constructor if invariant in cls
class Date
{
    Date(int dd, int mm, int yy)
        :d{dd}, m{mm}, y{yy}
    {
        // enforce invariant
        // Ensures()
        if (!is_valid(d, m, y)) throw Bad_date();
    }
private:
    int d, m, y;
};
// sometimes no invariant user-defined constructor
struct Rec
{
    string s;
    // i defaults to 10
    int i {10};
    // overloading other options
    // i defaults to 0
    Rec(const string& ss) : s{ss} {}
    // str defaults to empty str
    Rec(int ii) :i{ii} {}
};
// this wont work: Rec r3 {"Foo", 7};
Rec r1 {7};
Rec r2 {"Foo bar"};
// no constructor, complier auto generates one, aggregate
struct Rec2
{
    std::string s;
    int i {0};
};
Rec2 r1 {"Foo", 7};
Rec2 r2 {"Bar"};
