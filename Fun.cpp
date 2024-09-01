#include "Fun.h"
#include <iostream>
#include <fstream>
#include <cstring>

fun stworzTablice(int m_rozmiar) 
{
	fun tab;
	tab.rozmiar = m_rozmiar;
	tab.dane = new int[m_rozmiar];
	return tab;
}

void zwolnijTablice(fun& m_tab) 
{
	delete[] m_tab.dane;
	m_tab.dane = nullptr;
	m_tab.rozmiar = 0;
}

void zapisz(fun& m_tab, const char* nazwaPliku)
{
	FILE* zPlik = fopen(nazwaPliku, "w");

	if (!zPlik) {
		cerr << "B³¹d otwarcia pliku";
		return;
	}

	fwrite(&m_tab.rozmiar, sizeof(size_t), 1, zPlik);
	fwrite(m_tab.dane, sizeof(int), m_tab.rozmiar, zPlik);

	fclose(zPlik);
}

fun odczytajTablice(const char* nazwaPliku)
{
	FILE* oPlik = fopen(nazwaPliku, "r");

	if (!oPlik) {
		cerr << "B³¹d otwarcia pliku";
		return { nullptr, 0 };
	}
	int rozmiarTablicy;
	fread(&rozmiarTablicy, sizeof(int), 1, oPlik);
	fun tab = stworzTablice(rozmiarTablicy);

	fread(tab.dane, sizeof(int), rozmiarTablicy, oPlik);

	fclose(oPlik);
	return tab;
}

bool porownaj(const fun& tab1, const fun& tab2)
{
	if (tab1.rozmiar != tab2.rozmiar) {
		return false;
	}

	for (int i = 0; i < tab1.rozmiar; ++i) {
		if (tab1.dane[i] != tab2.dane[i]) {
			return false;
		}
	}

	return true;
}