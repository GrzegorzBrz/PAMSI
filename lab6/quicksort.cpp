#include "quicksort.h"
#include <iostream>


using namespace std;

zadanie::zadanie(int n){
	tab=new int[n];
	maszy=n;
};

void zadanie::sum(){
	for(int i=0;i<maszy;i++)
		suma+=tab[i];
};


quicksort::quicksort()
{
};

quicksort::~quicksort()
{
};

void quicksort::sort(zadanie tab[], int pocz, int kon)
{
	int i, j, h;
	i=pocz;
	j=kon;
	h=tab[(pocz+kon)/2].suma;

	do
	{
		while(tab[i].suma<h)
			i++;
		while(h<tab[j].suma)
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