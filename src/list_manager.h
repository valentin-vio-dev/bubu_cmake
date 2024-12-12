#ifndef LISTMANAGER_H
#define LISTMANAGER_H

#include <string>

const int MAX_SIZE = 100; // A tömb maximális mérete
extern int elemekSzama;

// Funkciók deklarációja
void hozzaadElem(const std::string& elem);
void eltavolitElem(int index);
void kiirLista();

#endif