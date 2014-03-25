#include "zadanie2.h"
#include <iostream>

using namespace std;


//ZADANIE 2

template <class T>
tablica <T>::tablica(int rozmiar)
{
	T *tab=new T[rozmiar];
	n=rozmiar;
};

template <class T>
tablica <T>::tablica(const tablica <T> &tab)
{
	n=tab.n;
	tab=tab.tab;
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
void tablica <T>::zamien(tablica <T> zmiana)
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
T &tablica <T>::begin()
{
	return tab[0];
};

template <class T>
T &tablica <T>::end()
{
	return tab[n];
};

template <class T>
tablica<T> & tablica <T>::operator=(const tablica<T> &tmp){
	n=tmp.n;
	tab=tmp.tab;
	return *this;
};

template <class T>
T & tablica <T>:: operator[](T elem){
	return tab[elem];
};

template <class T>
const T & tablica <T>::operator[](T elem) const{
	return tab[elem];
};

template <class T>
ostream & operator <<(ostream &wyjscie, const tablica <T> &tab){
	for (int i=0;i<n;i++)
		wyjscie << tab.tab[i]<<' ';
};

template <class T>
istream & operator >> (istream &wejscie, const tablica<T> &tab){
	wejscie>>tab.n;
	for (int i=0;i<n;i++)
		wejscie>>tab.tab[i];
};

template <class T>
void tablica<T>::push_back(T const &elem){
	tablica tmp(n+1);
	tmp.n=n;
	for(int i=0;i<n;i++)
		tmp.tab[i]=tab[i];
	tmp.tab[n]=elem;
	tab=tmp;
};

template <class T>
void tablica <T>::pop_back(){
	tablica tmp(n-1);
	for(int i=0;i<n-1;i++)
		tmp.tab[i]=tab[i];
	tab=tmp;
}

void main()
{
};

