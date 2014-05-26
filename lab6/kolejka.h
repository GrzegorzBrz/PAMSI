
#include <stdio.h>
#include <tchar.h>

using namespace std;



//klasa ogniwa kolejki
class ogniwa 
{
public: 
	int dane;
	ogniwa *nast;

	ogniwa();
	ogniwa(int danetym);
}; 

//klasa kolejki
class kolejka
{
	public:
	ogniwa* poczatek;   // poczatek kolejki
	ogniwa* iter;   
	ogniwa* ogon; 
	int dlugosc;      // ilosc elementow kolejki

	kolejka(); 
	void push(int dane); // dodaj element na poczatek
	void pop();      // wyjmij element z poczatku
	void print();         // wyswietl element poczatkowy
	bool inqueue(int x);
	int size();           // wypisz ilosc elementow stosu
	bool empty();         // spradz czy stos jest pusty
	void prio(int dane);
}; 



