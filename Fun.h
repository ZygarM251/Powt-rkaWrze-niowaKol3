#pragma once

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

struct fun 
{
	int* dane;
	int rozmiar;
};

fun stworzTablice(int rozmiar);
void zwolnijTablice(fun& m_tab);
void zapisz(fun& m_tab, const char* nazwaPliku);
fun odczytajTablice(const char* nazwaPliku);
bool porownaj(const fun& tab1, const fun& tab2);