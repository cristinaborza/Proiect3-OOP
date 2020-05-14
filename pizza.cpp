#include "pizza.h"

Pizza::Pizza() {
}

Pizza::Pizza(string nume, vector <Ingredient> v): Produs(nume, v) {
}

Pizza::Pizza(const Pizza &other): Produs(other) {
}

Pizza& Pizza::operator =(const Pizza &other) {
    this -> Produs::operator=(other);
    return *this;
}

Pizza::~Pizza() {
}

bool Pizza::operator <(const Pizza &other) const {
    if (this -> calculeazaPret() < other.calculeazaPret()) return true;
    return false;
}

int Pizza::calculeazaPret() const {
    int ans = 0;
    for (auto it: ing) {
        ans += it.getPret();
    }

    ans = ans + comision;
    return ans;
}

istream& operator >>(istream &f, Pizza &p) {
    cout << "Intruduceti numele produsului:\n";
    string nume; f >> nume;
    p.setNume(nume);

    cout << "Introduceti numarul de ingrediente:\n";
    int n; f >> n;
    vector <Ingredient> v;
    for (int i = 1; i <= n; ++ i) {
        Ingredient aux;
        f >> aux;
        v.push_back(aux);
    }

    p.setIng(v);
    return f;
}

ostream& operator <<(ostream &g, Pizza &p) {
    g << "Numele produsului: " << p.getNume() << '\n';
    g << "Ingrediente: ";
    vector <Ingredient> v = p.getIng();
    for (auto it: v) {
        g << it << " ";
    }

    g << '\n';
    return g;
}
