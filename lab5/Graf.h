#include <time.h>
#include <iostream>
#include <math.h>



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
	krawedz *MDR;
	int sumawag;

	macierzs();
	macierzs(int x, int y);
	~macierzs();
	void wyswietlMDR();
	void wypelnij(int gest);
	void wyswietl();
	void kruskal();
	void prim();
	
};

class listas
{
public:
	int rozmx;
	int rozmy;
	int gest;
	krawedz **tab;
	krawedz *lista;
	krawedz *MDR;
	int sumawag;

	listas();
	listas(int x, int y);
	~listas();
	void wyswietlMDR();
	void wypelnij(int gest);
	void wyswietl();
	void kruskal();
	void prim();
	
};


