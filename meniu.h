#include <bits/stdc++.h>
#include "pizzaOnline.h"

#pragma once

using namespace std;

template <class T>
class Meniu {
    vector <T> prod;
    static int idx;
    int valoareIncasata;
public:
    ///constructorii
    Meniu() {
        valoareIncasata = 0;
    }

    Meniu(vector <T> prod, int val): prod(prod), valoareIncasata(val){
    }

    ///copy-constructorul
    Meniu(const Meniu &other) {
        prod = other.prod;
        valoareIncasata = other.valoareIncasata;
    }

    ///destructorul
    virtual ~Meniu() {
    }

    ///operatorul +=, =
    void operator +=(const T &x) {
        prod.push_back (x);
        idx = idx + 1;
    }

    Meniu& operator =(const Meniu &other) {
        prod = other.prod;
        valoareIncasata = other.valoareIncasata;
        return *this;
    }

    ///verifica daca un produs de tip T exista deja
    bool check(string nume) {
        for (auto it: prod) {
            if (it.getNume() == nume) return true;
        }

        return false;
    }

    ///returneaza pretul produsului de pe pozitia pos
    int getPret(int pos) {
        T p = prod[pos];
        return p.calculeazaPret();
    }


    ///vinde produsul de la pozitia pos
    void vinde(const int pos) {
        T p = prod[pos - 1];
        valoareIncasata = valoareIncasata + p.calculeazaPret();
        cout << "Costul este de: " << p.calculeazaPret() << " lei.\n";
    }

    static int getIdx() {
        return idx;
    }

    int getIncasari() {
        return valoareIncasata;
    }

    ///scriere
    template <class TT> friend ostream& operator <<(ostream &g, Meniu<TT> &m) {
        g << "Numarul de produse este:" << m.idx << '\n';
        int idx =  0;
        for (auto it: m.prod) {
            g << ++idx << "." << it << '\n';
        }

        return g;
    }
};

template <> class Meniu <PizzaOnline> {
    vector <PizzaOnline> prod;
    static int idx;
    int valoareIncasata;
    int valoareVegetariene;
public:
    ///constructorii
    Meniu() {
        valoareIncasata = 0;
        valoareVegetariene = 0;
    }

    Meniu(vector <PizzaOnline> v, int val, int valVeg): prod(v), valoareIncasata(val), valoareVegetariene(valVeg) {
    }

    ///copy-constructorul
    Meniu(const Meniu &other) {
        prod = other.prod;
        valoareIncasata = other.valoareIncasata;
        valoareVegetariene = other.valoareVegetariene;
    }

    ///destructorul
    ~Meniu() {
    }

    ///opertatorii =, +=
    Meniu& operator =(const Meniu &other) {
        prod = other.prod;
        valoareIncasata = other.valoareIncasata;
        valoareVegetariene = other.valoareVegetariene;
        return *this;
    }

    void operator +=(const PizzaOnline &x) {
        prod.push_back(x);
        idx = idx + 1;
    }

    ///returneaza pretul prodului p
    int getPret(int idx) {
        PizzaOnline p = prod[idx];
        return p.calculeazaPret();
    }

    ///verifica daca pizza vegetariana p exista deja in meniu
    bool check (string nume) {
        for (auto it: prod) {
            if (it.getNume() == nume) return true;
        }
        return false;
    }

    ///vinde produsul de pe pozitia pos
    void vinde(const int pos) {
        PizzaOnline p = prod[pos - 1];
        valoareIncasata = valoareIncasata + p.calculeazaPret();
        if (p.getVeg() == true) valoareVegetariene = valoareVegetariene + p.calculeazaPret();
        cout << "Costul este de: " << p.calculeazaPret() << " lei.\n";
    }

    static int getIdx() {
        return idx;
    }

    int getIncasari() {
        return valoareIncasata;
    }

    int getIncasariVeg() {
        return valoareVegetariene;
    }

    ///scrierea
    friend ostream& operator <<(ostream &g, Meniu<PizzaOnline> &m) {
        g << "Numarul de produse din meniu este: " << m.idx << '\n';
        int idx = 0;
        for (auto it: m.prod) {
            g << ++idx << "." << it << '\n';
        }

        return g;
    }
};

