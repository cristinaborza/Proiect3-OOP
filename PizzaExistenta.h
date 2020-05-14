#include <exception>

using namespace std;

class PizzaExistenta: public exception {
public:
    PizzaExistenta () noexcept {}
    PizzaExistenta (const PizzaExistenta&) noexcept = default;
    PizzaExistenta& operator= (const PizzaExistenta&) noexcept = default;
    virtual ~PizzaExistenta() noexcept = default;
    virtual const char* what() const noexcept {
        return "Pizza introdusa exista deja in meniu\n";
    }
};
