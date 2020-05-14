#include <exception>

using namespace std;

class PizzaVegInexistenta: public exception {
public:
    PizzaVegInexistenta () noexcept {}
    PizzaVegInexistenta (const PizzaVegInexistenta&) noexcept = default;
    PizzaVegInexistenta& operator= (const PizzaVegInexistenta&) noexcept = default;
    virtual ~PizzaVegInexistenta() noexcept = default;
    virtual const char* what() const noexcept {
        return "Pizza vegetariana introdusa nu exista in meniu\n";
    }
};
