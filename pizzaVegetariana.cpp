#include "pizzaVegetariana.h"

PizzaVegetariana::PizzaVegetariana() {
}

PizzaVegetariana::PizzaVegetariana(string nume, vector <Ingredient> v): Pizza(nume, v) {
}

PizzaVegetariana::~PizzaVegetariana() {
}

PizzaVegetariana::PizzaVegetariana(const PizzaVegetariana &other): Pizza(other) {
}

PizzaVegetariana& PizzaVegetariana::operator =(const PizzaVegetariana &other) {
    this -> Pizza::operator=(other);
    return *this;
}
