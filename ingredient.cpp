#include "ingredient.h"

Ingredient::Ingredient(): nume(""), pret(0) {
}

Ingredient::Ingredient(string nume, int pret): nume(nume), pret(pret) {
}

Ingredient::Ingredient(const Ingredient &other) {
    nume = other.nume;
    pret = other.pret;
}

Ingredient& Ingredient::operator =(const Ingredient &other) {
    nume = other.nume;
    pret = other.pret;
    return *this;
}

Ingredient::~Ingredient() {
    nume = "";
    pret = 0;
}

int Ingredient::getPret() {
    return pret;
}

void Ingredient::setPret(int pret) {
    this -> pret = pret;
}

string Ingredient::getNume() {
    return nume;
}

void Ingredient::setNume(string nume) {
    this -> nume = nume;
}

istream& operator >>(istream &f, Ingredient &ing) {
    string nume;
    int pret;

    cout << "Introduceti numele si pretul:\n";
    f >> nume >> pret;

    ing.nume = nume;
    ing.pret = pret;

    return f;
}

ostream& operator <<(ostream &g, Ingredient &ing) {
    g << ing.nume << " ";
}
