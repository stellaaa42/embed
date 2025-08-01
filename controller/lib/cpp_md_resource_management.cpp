// RAII(Resource Acquisition Is Initialization)
// port wrapper
class Port
{
    PortHandle port;
public:
    Port(string_view destination) : port{open_port(destination)} {}
    ~Port() { close_port(port);}
    operator PortHandle() { return port; }
    // port handles cant be cloned, no copy assign
    Port(const Port&) = delete;
    Port& operator=(const Port&) = delete;
};
void send(unique_ptr<X> x, string_view destination)
{
    // port owns the PortHandle
    // auto port = open_port(destination); -> unlock close_port delete x
    Port port{destination};
    // guard owns the lock
    lock_guard<mutex> guard{my_mutex};
    send(port, x);
    // automatically unlocks my_mutex, closes port, deletes the pointer in x
}

//