#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <string>
using namespace std;

// Include the code being tested
const int MAX_SIZE = 100;  // Definition with the value you want
extern string lista[];
extern int elemekSzama;
void hozzaadElem(const string& elem);
void eltavolitElem(int index);
void kiirLista();

TEST_CASE("hozzaadElem function") {
    elemekSzama = 0; // Reset the global state
    hozzaadElem("apple");
    REQUIRE(elemekSzama == 1);
    REQUIRE(lista[0] == "apple");

    SECTION("Adding multiple elements") {
        hozzaadElem("banana");
        hozzaadElem("cherry");
        REQUIRE(elemekSzama == 3);
        REQUIRE(lista[1] == "banana");
        REQUIRE(lista[2] == "cherry");
    }

    SECTION("Exceeding maximum size") {
        elemekSzama = MAX_SIZE; // Simulate a full list
        hozzaadElem("overflow");
        REQUIRE(elemekSzama == MAX_SIZE);
    }
}

TEST_CASE("eltavolitElem function") {
    elemekSzama = 3;
    lista[0] = "apple";
    lista[1] = "banana";
    lista[2] = "cherry";

    eltavolitElem(1);
    REQUIRE(elemekSzama == 2);
    REQUIRE(lista[0] == "apple");
    REQUIRE(lista[1] == "cherry");

    SECTION("Removing first element") {
        eltavolitElem(0);
        REQUIRE(elemekSzama == 1);
        REQUIRE(lista[0] == "cherry");
    }

    SECTION("Invalid index") {
        int oldSize = elemekSzama;

        eltavolitElem(-1);
        REQUIRE(elemekSzama == oldSize); // No change to the list size

        eltavolitElem(3);
        REQUIRE(elemekSzama == oldSize); // No change to the list size
    }
}


TEST_CASE("kiirLista function") {
    elemekSzama = 0;
    SECTION("Empty list") {
        // Just verify no crashes/errors
        REQUIRE_NOTHROW(kiirLista());
    }

    SECTION("Non-empty list") {
        elemekSzama = 2;
        lista[0] = "apple";
        lista[1] = "banana";
        REQUIRE_NOTHROW(kiirLista());
    }
}