#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;

struct Valuta {
    string oznaka;
    double vEur;
};

const Valuta VALUTE[] = {
    {"EUR", 1.00},
    {"USD", 0.92},
    {"GBP", 1.18},
    {"CHF", 0.95},
    {"PLN", 0.22}
};

const int STEVILO_VALUT = 5;

void izpisiMenu() {
    cout << "\n=== Menjalnik valut ===\n";
    cout << "1. EUR\n";
    cout << "2. USD\n";
    cout << "3. GBP\n";
    cout << "4. CHF\n";
    cout << "5. PLN\n";
    cout << "0. Izhod\n";
    cout << "----------------------\n";
}

int izberiValuto(const string& opis) {
    int izbira;

    while (true) {
        cout << opis << " (0-5): ";
        cin >> izbira;

        if (izbira >= 0 && izbira <= 5) {
            return izbira;
        }

        cout << "Neveljavna izbira. Poskusite ponovno.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

double pretvori(double znesek, int izValute, int vValuto) {
    if (izValute == vValuto) {
        return znesek;
    }

    double eur = znesek * VALUTE[izValute].vEur;
    double rezultat = eur / VALUTE[vValuto].vEur;
    return rezultat;
}

int main() {
    int izValute;
    int vValuto;
    double znesek;
    double rezultat;
    char ponovniPogled;

    do {
        system("cls");
        izpisiMenu();

        cout << "Izberite valuto, iz katere boste pretvorili:\n";
        izValute = izberiValuto("Vnesite stevilko valute");

        if (izValute == 0) {
            cout << "Nasvidenje!\n";
            return 0;
        }

        cout << "Izberite valuto, v katero boste pretvorili:\n";
        vValuto = izberiValuto("Vnesite stevilko valute");

        if (vValuto == 0) {
            cout << "Nasvidenje!\n";
            return 0;
        }

        cout << "Vnesite znesek: ";
        while (!(cin >> znesek) || znesek < 0) {
            cout << "Neveljaven znesek. Vnesite pozitivno stevilo: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        rezultat = pretvori(znesek, izValute - 1, vValuto - 1);

        cout << fixed << setprecision(2);
        cout << "\n" << znesek << " " << VALUTE[izValute - 1].oznaka
             << " = " << rezultat << " " << VALUTE[vValuto - 1].oznaka << "\n";

        cout << "\nAli zelite izvajati novo pretvorbo? (d/n): ";
        cin >> ponovniPogled;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (ponovniPogled == 'd' || ponovniPogled == 'D');

    cout << "Nasvidenje!\n";
    return 0;
}
