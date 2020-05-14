#include <bits/stdc++.h>

#include "ingredient.h"
#include "pizzaVegetariana.h"

#pragma once

using namespace std;

template <class T>
class Meniu {
    static int idx;
    map <T, vector <Ingredient> > prod;
public:
    ///constructorii
    Meniu() {
    }

    Meniu(map <T, vector <Ingredient> > prod): prod(prod) {
    }

    ///copy-constructorul
    Meniu(const Meniu &other) {
        prod = other.prod;
    }

    ///destructorul
    virtual ~Meniu() {
    }

    ///operatorul +=, =
    void operator +=(const int x) {
        idx = idx + x;
    }

    Meniu& operator =(const Meniu &other) {
        prod = other.prod;
        return *this;
    }

    ///adauga un produs de tip T la meniu
    void adauga(T p) {
        prod[p] = p.getIng();
    }

    ///verifica daca un produs de tip T exista deja
    bool check(string nume) {
        for (auto it: prod) {
            T aux = it.first;
            if (aux.getNume() == nume) return true;
        }

        return false;
    }

    ///returneaza pretul produsului cu numele nume
    int getPret(string nume) {
        for (auto it: prod) {
            T aux = it.first;
            if (aux.getNume() == nume) {
                return aux.calculeazaPret();
            }
        }

        return 0;
    }

    ///scriere
    template <class TT> friend ostream& operator <<(ostream &g, Meniu<TT> &m) {
        g << "Numarul de produse este:" << m.idx << '\n';
        int idx =  0;
        for (auto it: m.prod) {
            TT aux = it.first;
            g << ++idx << "." << aux << '\n';
        }
        return g;
    }
};

template <> class Meniu <PizzaVegetariana> {
    static double valIncasari;
    vector <PizzaVegetariana> v;
public:
    ///constructorii
    Meniu() {
    }

    Meniu(vector <PizzaVegetariana> v): v(v) {
    }

    ///copy-constructorul
    Meniu(const Meniu &other) {
        v = other.v;
    }

    ///destructorul
    ~Meniu() {
    }

    ///opertatorii =, +=
    Meniu& operator =(const Meniu &other) {
        v = other.v;
        return *this;
    }

    void operator +=(const double x) {
        valIncasari += x;
    }

    ///adauga o pizza veg in meniu
    void adauga(PizzaVegetariana p) {
        v.push_back (p);
    }

    ///returneaza pretul prodului p
    int getPret(string nume) {
        for (auto it: v) {
            if (it.getNume() == nume) {
                return it.calculeazaPret();
            }
        }

        return 0;
    }

    ///verifica daca pizza vegetariana p exista deja in meniu
    bool check (string nume) {
        for (auto it: v) {
            if (it.getNume() == nume) return true;
        }
        return false;
    }

    ///returneaza valoarea totala a pizzelor comandate
    static double getValIncasari() {
        return valIncasari;
    }

    ///scrierea
    friend ostream& operator <<(ostream &g, Meniu<PizzaVegetariana> &m) {
        g << "Numarul de produse din meniu este: " << m.v.size() << '\n';
        int idx = 0;
        for (auto it: m.v) {
            g << ++idx << "." << it << '\n';
        }

        return g;
    }
};

