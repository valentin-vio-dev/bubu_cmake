#include "list_manager.h"
#include <iostream>
using namespace std;

// Globális változók
string lista[MAX_SIZE]; // A tömb deklarálása
int elemekSzama = 0;    // A jelenlegi elemek száma a listában

void hozzaadElem(const string& elem) {
    if (elemekSzama < MAX_SIZE) {
        lista[elemekSzama] = elem; // Az új elem hozzáadása a következő szabad helyre
        elemekSzama++;
        cout << "Elem hozzáadva: " << elem << endl;
    } else {
        cout << "Hiba: A lista megtelt, nem lehet további elemet hozzáadni!" << endl;
    }
}

// Elem eltávolítása a listából (index alapján)
void eltavolitElem(int index) {
    if (index < 0 || index >= elemekSzama) {
        cout << "Hiba: Érvénytelen index!" << endl;
        return;
    }

    // Az indexelt elem törlése, és a lista elemeinek eltolása
    string toroltElem = lista[index];
    for (int i = index; i < elemekSzama - 1; ++i) {
        lista[i] = lista[i + 1];
    }
    elemekSzama--; // Csökkentjük a lista méretét
    cout << "Eltávolított elem: " << toroltElem << endl;
}

// Lista elemeinek kiírása
void kiirLista() {
    if (elemekSzama > 0) {
        cout << "A lista elemei: ";
        for (int i = 0; i < elemekSzama; ++i) {
            cout << "[" << i << "] " << lista[i] << " ";
        }
        cout << endl;
    } else {
        cout << "A lista üres." << endl;
    }
}