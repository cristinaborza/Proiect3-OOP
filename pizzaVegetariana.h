#include <bits/stdc++.h>
#include "pizza.h"

#pragma once

using namespace std;

class PizzaVegetariana: public Pizza {
public:
    ///constructorii
    PizzaVegetariana();
    PizzaVegetariana(string, vector <Ingredient>);

    ///copy-constructorul
    PizzaVegetariana(const PizzaVegetariana&);

    ///destructorul
    virtual ~PizzaVegetariana();

    ///operatorul =
    PizzaVegetariana& operator =(const PizzaVegetariana&);
};
