#include <bits/stdc++.h>

#include "produs.h"
#include "ingredient.h"

#pragma once

using namespace std;

class Pizza: public Produs {
    static const int manopera = 10;
    bool vegetariana;
public:
    ///constructorii
    Pizza();
    Pizza(string, vector <Ingredient> ing, bool);

    ///copy-constructorul
    Pizza(const Pizza&);

    ///destructorul
    virtual ~Pizza();

    ///operatrul >, =
    bool operator <(const Pizza&) const;
    Pizza& operator =(const Pizza&);

    ///metoda care calculeaza pretul
    virtual int calculeazaPret() const;

    ///get si set
    void setVeg(bool);
    bool getVeg();

    ///citire / scriere
    friend istream& operator >>(istream&, Pizza&);
    friend ostream& operator <<(ostream&, Pizza&);
};
