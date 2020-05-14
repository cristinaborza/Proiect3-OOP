#include <exception>

using namespace std;

class PizzaInexistenta: public exception {
public:
    PizzaInexistenta () noexcept {}
    PizzaInexistenta (const PizzaInexistenta&) noexcept = default;
    PizzaInexistenta& operator= (const PizzaInexistenta&) noexcept = default;
    virtual ~PizzaInexistenta() noexcept = default;
    virtual const char* what() const noexcept {
        return "Pizza introdusa nu exista in meniu\n";
    }
};
