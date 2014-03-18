#include <iostream>

using namespace std;


// ZADANIE 2

template <class T>
class tablica{
public:
	int n;
	size_t *tab;

	tablica(int rozmiar);
	tablica(const tablica &tab);


}