#include <iostream>
#include <string>
#include "list_manager.h"

using namespace std;

int main() {
    int valasztas;
    string elem;

    do {
        // Menü kiírása
        cout << "\n--- Menü ---" << endl;
        cout << "1. Elem hozzáadása" << endl;
        cout << "2. Elem eltávolítása (index alapján)" << endl;
        cout << "3. Lista kiírása" << endl;
        cout << "0. Kilépés" << endl;
        cout << "Választás: ";
        cin >> valasztas;
        cin.ignore(); // Fontos az std::string bemenetekhez a maradék newline karakter eltávolítása

        switch (valasztas) {
            case 1:
                cout << "Add meg az elemet: ";
                getline(cin, elem); // Bemenet beolvasása (egész sor)
                hozzaadElem(elem);
                break;
            case 2: {
                int index;
                cout << "Add meg a törlendő elem indexét (0-" << elemekSzama - 1 << "): ";
                cin >> index;
                eltavolitElem(index);
                break;
            }
            case 3:
                kiirLista();
                break;
            case 0:
                cout << "Kilépés..." << endl;
                break;
            default:
                cout << "Érvénytelen választás!" << endl;
        }
    } while (valasztas != 0);

    return 0;
}