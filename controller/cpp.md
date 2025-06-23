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