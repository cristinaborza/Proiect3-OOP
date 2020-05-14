#include "produs.h"

Produs::Produs() {
}

Produs::Produs(string nume, vector <Ingredient> ing): nume(nume), ing(ing){
}

Produs::~Produs() {
}

Produs::Produs(const Produs &other) {
    nume = other.nume;
    ing = other.ing;
}

Produs& Produs::operator =(const Produs &other) {
    nume = other.nume;
    ing = other.ing;
    return *this;
}

string Produs::getNume() {
    return nume;
}

void Produs::setNume(string nume) {
    this -> nume = nume;
}

vector <Ingredient> Produs::getIng() {
    return ing;
}

void Produs::setIng(vector <Ingredient> ing) {
    this -> ing = ing;
}
