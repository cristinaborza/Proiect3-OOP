#include <bits/stdc++.h>
#include "pizza.h"

#pragma once

using namespace std;

class PizzaOnline: public Pizza {
    int distantaLivrare;
public:
    ///constructorii
    PizzaOnline();
    PizzaOnline(string, vector <Ingredient>, bool, int);

    ///copy-constructorul
    PizzaOnline(const PizzaOnline&);

    ///destructorul
    ~PizzaOnline();

    ///operatorul =
    PizzaOnline& operator =(const PizzaOnline&);

    ///metoda de calcul al pretului
    virtual int calculeazaPret() const;

    ///get si set
    int getDist();
    void setDist(int);
};
