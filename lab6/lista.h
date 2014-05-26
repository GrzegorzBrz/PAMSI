#include <iostream>
using namespace std;

class ogniwo 
{
public: 
	int waga;
	int sasiadx;
	ogniwo();
	ogniwo(int x,int w);
	ogniwo *nast;
}; 


class lista 
{
public:
	ogniwo *glowa;   // glowa listy
	ogniwo *ogon;    // ogon listy
	ogniwo *iter;    // wskaznik do przeskakiwania po elementach listy
	int dlugosc;    // ilosc elementow listy
	int waga;

	lista(); 
	void push_front(int x,int w); // dodaj element na poczatek
	void push_back(int x,int w);  // dodaj element na koniec  
	void pop_front();     // wyjmij element z konca listy
	void pop_back();      // wyjmij element z poczatku listy
	void print();         // wypisz wszystkie elementy listy


};