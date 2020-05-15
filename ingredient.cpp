#include "ingredient.h"

Ingredient::Ingredient(): nume(""), cantitate(0), pret(0){
}

Ingredient::Ingredient(string nume, int cantitate, int pret): nume(nume), cantitate(cantitate), pret(pret) {
}

Ingredient::Ingredient(const Ingredient &other) {
    nume = other.nume;
    cantitate = other.cantitate;
    pret = other.pret;
}

Ingredient& Ingredient::operator =(const Ingredient &other) {
    nume = other.nume;
    cantitate = other.cantitate;
    pret = other.pret;
    return *this;
}

Ingredient::~Ingredient() {
    nume = "";
    cantitate = 0;
    pret = 0;
}

int Ingredient::getPret() {
    return pret;
}

void Ingredient::setPret(int pret) {
    this -> pret = pret;
}

int Ingredient::getCant() {
    return cantitate;
}

void Ingredient::setCant(int cant) {
    this -> cantitate = cant;
}

string Ingredient::getNume() {
    return nume;
}

void Ingredient::setNume(string nume) {
    this -> nume = nume;
}

istream& operator >>(istream &f, Ingredient &ing) {
    string nume;
    int pret, cantitate;

    cout << "Introduceti numele, cantitatea si pretul:\n";
    f >> nume >> cantitate >> pret;

    ing.nume = nume;
    ing.cantitate = cantitate;
    ing.pret = pret;

    return f;
}

ostream& operator <<(ostream &g, Ingredient &ing) {
    g << ing.nume << " ";
}
