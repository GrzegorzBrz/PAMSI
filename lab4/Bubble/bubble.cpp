#include "bubble.h"
#include <iostream>
using namespace std;

bubble::bubble()
{
}

bubble::~bubble()
{
}

void bubble::sort(int *tab,int size){
	while(size>=0){
		for(int i=1;i<size;i++){
			if (tab[i-1]>tab[i])
				swap(tab[i-1],tab[i]);
		}
		size--;
	}

};