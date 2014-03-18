#include "zadanie2.h"
#include <iostream>

using namespace std;

template <class T>
tablica <T>::tablica(int rozmiar)
{
	size_t *tab=new size_t[rozmiar];
	n=rozmiar;
};

template <class T>
tablica <T>::tablica(const tablica &tab)
{
	n=tablica.n;
	tab=tablica.tab;
};

template <class T>
tablica <T>::~tablica()
{
};

template <class T>
int tablica <T>::rozmiar()
{
	return n;
};

template <class T>
void tablica <T>::zamien(tablica zmiana)
{
	tablica tmp;
	tmp.n=n;
	tmp.tab=tab;
	n=zmiana.n;
	tab=zmiana.tab;
	zmiana.n=tmp.n;
	zmiana.tab=tmp.tab;
};
	
template <class T>
void tablica <T>::resize()
{
	size_t tmp=new size_t[n+1];
	for(int i=0;i<n;i++)
		tmp[i]=tab[i];
	tmp[i+1]=0;
	tab=tmp;
	delete tmp;
};

template <class T>
size_t *tablica <T>::begin()
{
	return tab[0];
};

template <class T>
size_t *tablica <T>::end()
{
	return tab[n];
};


void main()
{
};

