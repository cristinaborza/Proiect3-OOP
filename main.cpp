#include <bits/stdc++.h>

#include "produs.h"
#include "pizza.h"
#include "pizzaOnline.h"
#include "ingredient.h"
#include "meniu.h"
#include "PizzaExistenta.h"
#include "PizzaInexistenta.h"

using namespace std;

template <> int Meniu <Pizza>::idx = 0;
int Meniu <PizzaOnline>::idx = 0;

void afiseazaMeniu() {
    cout << "MENIU:\n";
    cout << "1.Afiseaza meniul.\n";
    cout << "2.Adauga o pizza in meniu.\n";
    cout << "3.Comanda o pizza.\n";
    cout << "4.Afiseaza incasari.\n";
    cout << "5.Exit.\n";
}

int main() {
    map <int, vector <Ingredient> > mp;
    int n; cin >> n;
    for (int i = 1; i <= n; ++ i) {
        int type; cin >> type;
        if (type == 1) {
            cout << "Introduceti id-ul pizzei:\n";
            int id; cin >> id;
            if (mp.find(id) != mp.end()) {
                cout << "Exista deja o pizza cu aces id!\n";
                continue;
            }

            Pizza p;
            cin >> p;
            mp[id] = p.getIng();
        } else {
            cout << "Introduceti id-ul pizzei:\n";
            int id; cin >> id;
            if (mp.find(id) == mp.end()) cout << "Nu exista o pizza cu acest id!\n";
            else {
                cout << "Ingredientele sunt: ";
                vector <Ingredient> v = mp[id];
                for (auto it: v) {
                    cout << it << " ";
                }
                cout << '\n';
            }
        }
    }



    Meniu<Pizza> meniuPizza;
    Meniu<PizzaOnline> meniuPizzaOnline;

    while (true) {
        afiseazaMeniu();

        int type; cin >> type;
        if (type == 1) {
            cout << "Ce fel de meniu doriti sa se afiseze? (1 - meniu pizza, 2 - meniu pizza online)";
            int type; cin >> type;
            if (type == 1) cout << meniuPizza << '\n';
            else cout << meniuPizzaOnline << '\n';
        }

        else if (type == 2) {
            cout << "In ce meniu vreti sa introduceti produsul? (1 - meniu pizza, 2 - meniu pizza online)\n";
            int type; cin >> type;
            if (type == 1) {
                try {
                    Pizza p; cin >> p;
                    if (meniuPizza.check(p.getNume())) throw (PizzaExistenta());
                    meniuPizza += p;
                } catch (exception &e) {
                    cout << e.what() << '\n';
                }
            }

            else {
                try {
                    PizzaOnline p; cin >> p;
                    if (meniuPizzaOnline.check(p.getNume())) throw (PizzaExistenta());
                    meniuPizzaOnline += p;
                } catch (exception &e) {
                    cout << e.what() << '\n';
                }
            }
        }

        else if (type == 3) {
            cout << "Introdu tipul de comanda(1 - Cu livrare, 2 - Cu ridicare)\n";
            int type; cin >> type;
            cout << "Introduceti indexul produsului:\n";
            int idx; cin >> idx;

            if (type == 2) {
                try {
                    if (idx < 1 || idx > meniuPizza.getIdx()) throw (PizzaInexistenta());
                    meniuPizza.vinde(idx);
                } catch (exception &e) {
                    cout << e.what() << '\n';
                }
            }

            else {
                try {
                    if (idx < 1 || idx > meniuPizzaOnline.getIdx()) throw (PizzaInexistenta());
                    meniuPizzaOnline.vinde(idx);
                } catch (exception &e) {
                    cout << e.what() << '\n';
                }
            }
        }

        else if (type == 4) {
            cout << "Pentru ce meniu sa se afiseze incasarile: (1 - meniu, 2 - meniu online)?\n";
            int type; cin >> type;
            if (type == 1) cout << "Incasarile sunt de: " << meniuPizza.getIncasari() << " lei.\n";
            else {
                cout << "Incasarile sunt de: " << meniuPizzaOnline.getIncasari() << " lei.\n";
                cout << "Incasarile pentru pizzele vegetariene sunt de " << meniuPizzaOnline.getIncasariVeg() << " lei.\n";
            }
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
