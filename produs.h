#include <bits/stdc++.h>
#include "ingredient.h"

#pragma once

using namespace std;

class Produs {
protected:
    static const int comision = 10;
    string nume;
    vector <Ingredient> ing;
public:
    ///constructorii
    Produs();
    Produs(string, vector <Ingredient>);

    ///destructorul
    virtual ~Produs();

    ///copy-constructorul
    Produs(const Produs&);

    ///operatorul =
    Produs& operator =(const Produs&);

    ///medoda virtuala pura care calculeaza pretul
    virtual int calculeazaPret() const = 0;

    ///get si set
    string getNume();
    void setNume(string);
    vector <Ingredient> getIng();
    void setIng(vector <Ingredient>);
};
