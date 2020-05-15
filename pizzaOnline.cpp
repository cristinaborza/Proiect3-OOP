#include "pizzaOnline.h"

PizzaOnline::PizzaOnline() {
}

PizzaOnline::PizzaOnline(string nume, vector <Ingredient> ing, bool veg, int dist): Pizza(nume, ing, veg), distantaLivrare(dist) {
}

PizzaOnline::PizzaOnline(const PizzaOnline &other): Pizza(other), distantaLivrare(other.distantaLivrare) {
}

PizzaOnline::~PizzaOnline() {
}

PizzaOnline& PizzaOnline::operator =(const PizzaOnline &other) {
    this -> Pizza::operator=(other);
    this -> distantaLivrare = other.distantaLivrare;
    return *this;
}

int PizzaOnline::calculeazaPret() const {
    int ans = this -> Pizza::calculeazaPret();
    ans = ans + ans * (distantaLivrare / 10) / 20;
    return ans;
}

int PizzaOnline::getDist() {
    return distantaLivrare;
}

void PizzaOnline::setDist(int dist) {
    distantaLivrare = dist;
}
