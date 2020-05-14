#include <bits/stdc++.h>

#include "produs.h"
#include "pizza.h"
#include "pizzaVegetariana.h"
#include "ingredient.h"
#include "meniu.h"
#include "PizzaExistenta.h"
#include "PizzaVegExistenta.h"
#include "PizzaInexistenta.h"
#include "PizzaVegInexistenta.h"

using namespace std;

template <> int Meniu<Pizza>::idx = 0;
double Meniu<PizzaVegetariana>::valIncasari = 0;

void afiseazaMeniu() {
    cout << "MENIU:\n";
    cout << "1.Afiseaza meniul\n";
    cout << "2.Adauga o pizza in meniu\n";
    cout << "3.Comanda o pizza\n";
    cout << "4.Afiseaza pretul total al pizzelor vegetariene comandate pana acum\n";
    cout << "5.Exit\n";
}

int main() {
    Meniu<Pizza> mp;
    Meniu<PizzaVegetariana> mpv;

    while (true) {
        afiseazaMeniu();

        int type; cin >> type;
        if (type == 1) {
            cout << "Ce fel de meniu doriti sa se afiseze? (1 - meniu pizza, 2 - meniu pizza vegetariana)";
            int type; cin >> type;
            if (type == 1) cout << mp << '\n';
            else cout << mpv << '\n';
        }

        else if (type == 2) {
            cout << "Introdu tipul produsului(1 - pizza, 2 - pizza vegetariana)\n";
            int type; cin >> type;
            if (type == 1) {
                try {
                    Pizza p; cin >> p;
                    if (mp.check(p.getNume())) throw (PizzaExistenta());

                    mp += 1;
                    mp.adauga(p);
                } catch (exception &e) {
                    cout << e.what() << '\n';
                }
            }

            else {
                try {
                    PizzaVegetariana p; cin >> p;
                    if (mpv.check(p.getNume())) throw (PizzaVegExistenta());
                    mpv.adauga(p);
                } catch (exception &e) {
                    cout << e.what() << '\n';
                }

            }
        }

        else if (type == 3) {
            cout << "Introdu tipul produsului(1 - pizza, 2 - pizza vegetariana)\n";
            int tip; cin >> tip;
            cout << "Introdu numele produsului pe care vrei sa il comanzi:\n";
            string nume; cin >> nume;
            cout << "Introdu tipul de comanda(1 - Cu livrare, 2 - Cu ridicare)\n";
            int type; cin >> type;

            if (tip == 1) {
                if (type == 2) {
                    try {
                        if (!mp.check(nume)) throw (PizzaInexistenta());
                        cout << "Costul este de " << mp.getPret(nume) << " lei.\n";
                    } catch (exception &e) {
                        cout << e.what() << '\n';
                    }
                }
                else {
                    cout << "Introdu distanta pana la destinatie:\n";
                    int dist; cin >> dist;

                    try {
                        if (!mp.check(nume)) throw (PizzaInexistenta());
                        double ans = (double) mp.getPret(nume);
                        ans = ans + 0.05 * ans * (dist / 10);
                        cout << "Costul este de " << ans << " lei.\n";
                    } catch (exception &e) {
                        cout << e.what() << '\n';
                    }
                }
            }

            else {
                if (type == 2) {
                    try {
                        if (!mpv.check(nume)) throw (PizzaVegInexistenta());
                        int ans = mpv.getPret(nume);
                        mpv += (double)ans;
                        cout << "Costul este de " << ans << " lei.\n";
                    } catch (exception &e) {
                        cout << e.what() << '\n';
                    }

                }
                else {
                    cout << "Introdu distanta pana la destinatie:\n";
                    int dist; cin >> dist;

                    try {
                        if (!mpv.check(nume)) throw (PizzaVegInexistenta());
                        double ans = (double) mpv.getPret(nume);
                        ans = ans + 0.05 * ans * (dist / 10);
                        mpv += ans;
                        cout << "Costul este de " << ans << " lei.\n";
                    } catch (exception &e) {
                        cout << e.what() << '\n';
                    }
                }
            }
        }

        else if (type == 4) {
            cout << "Pretul total al pizzelor vegetariene este de: " << Meniu<PizzaVegetariana>::getValIncasari() << " lei\n";
        }

        else if (type == 5) {
            break;
        }

        else {
            cout << "Comanda introdusa nu este valida!\n";
        }
    }

    return 0;
}
