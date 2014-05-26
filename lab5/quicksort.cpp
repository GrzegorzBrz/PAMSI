#include "quicksort.h"
#include <iostream>


using namespace std;

quicksort::quicksort()
{
};

quicksort::~quicksort()
{
};

void quicksort::sort(krawedz tab[], int pocz, int kon)
{
    int i, j, h;
    i=pocz;
    j=kon;
    h=tab[(pocz+kon)/2].waga;
    do
    {
		while(tab[i].waga<h)
            i++;
        while(h<tab[j].waga)
            j--;
        if(i<=j)
        {
            swap(tab[i], tab[j]);
            i++;
            j--;
        }
    }
    while(i<=j);
    if(pocz<j) 
		sort(tab, pocz, j);
    if(i<kon) 
		sort(tab, i, kon);
};