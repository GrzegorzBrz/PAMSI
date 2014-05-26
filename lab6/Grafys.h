#include <time.h>
#include <iostream>
#include <math.h>
#include "lista.h"


using namespace std;

/*******************************************************************
deklaracje klas:
macierzs-macierz krawedzi;
krawedz-komorka w macierzy zawierajaca wage i informacje na temat polaczenia jednego wirzcholka z drugim;
komorka-sluzy do tworzenia losowego i spojnego grafu, zawiera wspolrzedne poszczegolnej krawedzi w grafie;
********************************************************************/

class komorka
{
public:
	int x;
	int y;
	komorka();
};


class krawedz
{
public:
	int waga;
	bool polacz;
	int sasiadx;
	int sasiady;

	krawedz();
};

class macierzs
{
public:
	int rozmx;
	int rozmy;
	int gest;
	krawedz **tab;
	krawedz *ND;
	int sumawag;

	macierzs();
	macierzs(int x, int y);
	~macierzs();
	void wyswietlND();
	void wypelnij(int gest);
	void wyswietl();
	void dijkstra(int zrodlo,int ujscie);
	void bellman(int zrodlo,int ujscie);

};



class listas2
{
public:
	int rozmx;
	int rozmy;
	int gest;
	lista *lis;
	krawedz *ND;
	int sumawag;

	listas2();
	listas2(int x, int y);
	~listas2();
	void wyswietlND();
	void wypelnij(int gest);
	void wyswietl();
	void dijkstra(int zrodlo,int ujscie);
	void bellman(int zrodlo,int ujscie);

};

