#include <iostream>

using namespace std;


// ZADANIE 2

template <class T>
class tablica{
public:
	int n;
	size_t *tab;

	tablica(int rozmiar);
	tablica(const tablica <T> &tab);
	~tablica();
	tablica <T> & operator=(const tablica <T> &tmp);
	T & operator[](T elem);
	const T & operator[](T elem) const;
	friend ostream & operator << (ostream &wyjscie, const tablica<T> &tab);
	friend istream & operator >> (istream &wejscie, const tablica<T> &tab);
	void push_back(T const &elem);
	void pop_back();
	int rozmiar();
	void zamien(tablica <T> zmiana);
	void resize();
	T &begin();
	T &end();
};