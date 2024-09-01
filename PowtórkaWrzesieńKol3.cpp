
#include <iostream>
#include "Fun.h"

int main()
{
    fun tab = stworzTablice(5);
    for (size_t i = 0; i < tab.rozmiar; ++i) {
        tab.dane[i] = i + 1;  
    }

    // Zapis do pliku
    zapisz(tab, "test.txt");

    // Odczyt z pliku
    fun tablica = odczytajTablice("test.txt");

    // Porównanie tablic
    if (porownaj(tab, tablica)) {
        cout << "Tablice sa takie same";
    }
    else {
        cout << "Tablice sie roznia";
    }

    zwolnijTablice(tab);
    zwolnijTablice(tablica);
}

