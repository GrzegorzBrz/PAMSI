#include "heapo.h"
#include <iostream>
#include <math.h>
using namespace std;

heapsort::heapsort()
{
}

heapsort::~heapsort()
{
}

void heapsort::sort(int *tablica, int size)
{
	int i,j,k,m,n,x;
	for(i=2; i<=size; i++)
    {
        j=i;
        k=j/2;
        x=tablica[i];
        while(k>0 && tablica[k]<x)
        {
            tablica[j]=tablica[k];
            j=k;
            k=j/2;
        }
        tablica[j]=x;
    }
    for(i=size; i>1; i--)
    {
        swap(tablica[1], tablica[i]);
        j=1;
        k=2;
        while(k<i)
        {
            if(k+1<i && tablica[k+1]>tablica[k]) 
				m=k+1;
            else 
m=k;
            if(tablica[m]<=tablica[j]) 
				break;
            swap(tablica[j], tablica[m]);
            j=m;
            k=2*j;
        }
    }



}