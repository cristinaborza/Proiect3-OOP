#include <bits/stdc++.h>

#pragma once

using namespace std;

class Ingredient {
    string nume;
    int cantitate;
    int pret;
public:
    ///constructorii
    Ingredient();
    Ingredient(string, int, int);

    ///copy-constructorul
    Ingredient(const Ingredient&);

    ///destructorul
    virtual ~Ingredient();

    ///operatirul =
    Ingredient& operator =(const Ingredient&);

    ///citire/scriere
    friend istream& operator >>(istream&, Ingredient&);
    friend ostream& operator <<(ostream&, Ingredient&);

    ///get si set
    int getPret();
    void setPret(int);
    int getCant();
    void setCant(int);
    string getNume();
    void setNume(string);

};
