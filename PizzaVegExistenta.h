#include <exception>

using namespace std;

class PizzaVegExistenta: public exception {
public:
    PizzaVegExistenta () noexcept {}
    PizzaVegExistenta (const PizzaVegExistenta&) noexcept = default;
    PizzaVegExistenta& operator= (const PizzaVegExistenta&) noexcept = default;
    virtual ~PizzaVegExistenta() noexcept = default;
    virtual const char* what() const noexcept {
        return "Pizza vegetariana introdusa exista deja in meniu\n";
    }
};
