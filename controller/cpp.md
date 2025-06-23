auto p=find(begin(v), end(v), val);
change_speed(23_m / 10s);
for (const auto& x : v)
for (auto& x : v)
for_each(v, [](int x))
for_each(par, v, [](int x))
draw_line(Point, Point);
static_assert(sizeof(Int) >= 4);

void read(int* p, int n); 
int a[100];

void read(span<int> r);
int a[100];
read(a);

extern void f4(vector<int>&);
extern void f4(span<int>);
void g3(int n) 
{
    vector<int> v(n);
    f4(v);
    f4(span<int>{v});
}

vector<int> f5(int n)
{
    vector<int> v(n);
    return v;
}

void increment2(span<int> p)
{
    for (int& x : p) ++x;
}
void use3(int m)
{
    const int n = 10;
    int a[n] = {};
    increment2(a);
}

void f(char* name)
{
    ifstream input {name};
    if (something) return;
}

vector<int> v;
v.reserve(100);
for (int x; cin >> x;) 
{
    v.push_back (x);
}

std::sort(begin(v), end(v), std::greater<>());

X& myX()
{
    static X my_x {3};
    return my_x;
}

void draw_rectangle(Point top_left, Point bottom_right);
void draw_rectangle(Point top_left, Size height_width);
draw_rectangle(p, Point{10, 20});
draw_rectangle(p, Size{10, 20});

alarm_settings s{};
s.enabled = true;
s.displayMode = alarm_settings::mode::spinning_light;
s.frequency = alarm_settings::every_10_seconds;
set_setting(s);

enable_lamp_options(lamp_option::on | lamp_option::animate_state_transitions);

void blink_led(milliseconds time_to_blink)
{
}
void use()
{
    blink_led(1500ms);
}

template<class rep, class period>
void blink_led(duration<rep, period> time_to_blink)
{
    auto milliseconds_to_blink = duration_cast<milliseconds>(time_to_blink);
}
void use()
{
    blink_led(2s);
    blink_led(1500ms);
}

double sqrt(double x) { Expects(x >= 0);}

int area(int height, int width)
{
    Expects(height > 0 && width > 0);
}

int area(int height, int width)
{
    auto res = height * width;
    Ensures(res > 0);
    return res;
}

void f() 
{
    char buffer [MAX];
    memset(buffer, 0, sizeof(buffer)); // memset(buffer, 0, MAX);
    Ensures(buffer[0] == 0);
}

void manipulate(Record& r)
{
    lock_guard<mutex> _ {m};
}

template<typename Iter, typename Val>
    requires input_iterator<Iter> && equality_comparable_with<iter_value_t<Iter>, Val>
Iter find(Iter first, Iter last, Val v)
{
}

template<class F, class ...Args>
explicit thread(F&& f, Args&&... args);

auto [val, error_code] = do_somthing();
if (error_code) 
{
}

vector<double> compute(args)
{
    vector<double> res(10000);
    return res;
}

owner<X*> compute(args)
{
    owner<X*> res = new X {};
    return res;
}

int length(not_null<czstring> P);
void copy(span<const T> r, span<T> r2);

void draw2(span<Circle>(arr));
Circle arr[10];
draw2(span<Circle>(arr));
draw2(arr);

template<class InputRange1, class InputRange2, class OutputIterator>
OutputIterator merge(InputRange1 r1, InputRange2 r2, OutputIterator result);

template<class In1, class In2, class Out>
    requires mergeable<In1, In2, Out>
Out merge(In1 r1, In2 r2, Out result);

void f(gsl::span<int> some_ints);
void copy_n(const T* p, T* q, int n);
void copy_n(span<const T>p, span<T> q);

struct SystemParams {
    string config_file;
    string output_path;
    seconds timeout;
}
void initialize(SystemParams p);

class Shape 
{
    public:
        virtual Point center() const = 0;
        virtual void draw() const = 0;
        virtual void rotate(int) = 0;

        virtual ~Shape() = default;
}

 class widget
 {
    class impl;
    std::unique_ptr<impl> pimpl;
 public:
    void draw();
    widget(int);
    ~widget();
    widget(widget&&) noexcept;
    widget(const widget&) = delete;
    widget& operator=(widget&&) noexcept;
    widget& operator=(const widget&) = delete;
 };
 class widget::impl
 {
    int n;
  public:
    void draw(const widget& w) {}
    impl(int n): n(n) {}
 };
 void widget::draw(){piml->draw(*this);}
 widget::widget(int n) : pimpl {std::make_unique<impl>(n)} {}
 widget::widget(widget&&) noexcept = default;
 widget::~widget() = default;
 widget& widget::operator={widget&&} noexcept = default;

class Istream { [[gsl::suppress("lifetime)]]
public:
    enum Opt { from_line = 1};
    Istream() {}
    Istream(czstring p) : owned{true}, inp{new ifstream{p}} {}
    Istream(czstring p, Opt) : owned{true}, inp{new istringstream{p}} {}
    ~Istream() { if (owned) delete inp; }
    operator istream&() { return *inp; }
private:
    bool owned = false;
    istream* inp = &cin;
};

auto lessT = [](T x, T y) {return x.rank() < y.rank() && x.value() < y.value(); }
sort(a, b, lessT);

int read(istream& is)
{
    int x;
    is >> x;
    //check for errors
    return x;
}
void print(ostream& os, int x)
{
    os << x << "\n";
}

void read_and_print()
{
    auto x = read(cin);
    print(cout, x);
}

auto read=[](auto& input, auto& value)
{
    input >> value;
    //check errors
};
void print(auto& output, const auto& value)
{
    output << value << "\n";
}

double func1_muon(double val, int flag)
{
}
double func1_tau(double val, int flag1, int flag2)
{
}
double simple_func(double val, int flag1, int flag2)
{
    if (flag1 > 0)
        return func1_muon(val, flag2);
    if (flag1 == -1)
        return func1_tau(-val, flag1, flag2);
    return 0;
}

constexpr int min(int x, int y) {return x < y ? x : y; >}
void test(int v)
{
    int m1 = min(-1, 2); // probably compile-time
    constexpr int m2 = min(-1, 2); // compile-time
    int m3 = min(-1, v); // run-time
}

inline string cat(const string& s, const string& s2) { return s + s2; }

vector<string> collect(istream& is) noexcept
{
    vector<string> res;
    for (string s; is >> s;)
        res.push_back(s);
    return res;
}

void f(int*); // any int*
void g(unique_ptr<int>); //only transfer ownership
void g(shared_ptr<int>); // only share
void h(const unique_str<int>&); // receive ownership
void h(int&); // any int

void f(widge& w)
{
    use(w);
}
shared_ptr<widget> my_widget = /* ... */;
f(*my_widget);
widget stack_widget;
f(stack_widget);

template<class T>
auto square(T t) { return t * t; }

widget* find(const set<widget>& s, const widget& w, Hint); // unused parameter

template <typename Value>
Value* find(const set<Value>& s, const Value& v, [[maybe_unused]] Hint h)
{
    if constexpr (sizeof(Value) > CacheSize)
    {
        // Hint used
    }
}

struct Rec 
{
    string name;
    string addr;
    int id; // unique identifier
}
bool same(const Rec& a, const Rec& b)
{
    return a.id == b.id;
}
vector<Rec*> find_id(const string& name);
auto x = find_id(vr.begin(), vr.end(), 
    [&](Rec& r) {
        if (r.name.size() != n.size()) return false;
        for (int i=0; i<r.name.size(); ++i)
            if (tolower(r.name[i]) != tolower(n[i])) return false;
        return true;
    }
)

bool compare_insensitive(const string& a, const string& b)
{
    if (a.size() != b.size()) return false;
    for(int i=0; i<a.size(); ++i) if (tolower(a[i]) != tolower(b[i])) return false;
    return true;
}
auto x = find_if(vr.begin(), vr.end(),
    [&](Rec& r) { return compare_insensitive(r.name, n); }
);

auto cmp_to_n = [&n](const string& a) { return compare_insensitive(a, n); };
auto x = find_if(vr.begin(), vr.end(),
    [](const Rec& r) { return cmp_to_n(r.name); }
)

auto earlyUsersEnd = std::remove_if(users.begin(), users.end(),
                        [](const User &a) { return a.id > 100; });