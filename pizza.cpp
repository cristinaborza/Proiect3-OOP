#include "pizza.h"

Pizza::Pizza() {
}

Pizza::Pizza(string nume, vector <Ingredient> v, bool veg): Produs(nume, v), vegetariana(veg) {
}

Pizza::Pizza(const Pizza &other): Produs(other), vegetariana(other.vegetariana){
}

Pizza& Pizza::operator =(const Pizza &other) {
    this -> Produs::operator=(other);
    this -> vegetariana = other.vegetariana;
    return *this;
}

Pizza::~Pizza() {
    vegetariana = false;
}

bool Pizza::operator <(const Pizza &other) const {
    if (this -> calculeazaPret() < other.calculeazaPret()) return true;
    return false;
}

int Pizza::calculeazaPret() const {
    int ans = 0;
    for (auto it: ing) {
        ans += it.getPret() * it.getCant();
    }

    ans = ans + Pizza::manopera;
    return ans;
}

void Pizza::setVeg(bool veg) {
    vegetariana = veg;
}

bool Pizza::getVeg() {
    return vegetariana;
}

istream& operator >>(istream &f, Pizza &p) {
    cout << "Intruduceti numele produsului:\n";
    string nume; f >> nume;
    p.setNume(nume);

    cout << "Introduceti daca e sau nu vegetariana(0 - nu e, 1 - e):\n";
    bool veg; f >> veg;
    p.setVeg(veg);

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
