#include <time.h>
#include <iostream>

using namespace std;
#include "mergeo.h"



void main()
{
	clock_t before, after;
	scal test;
	int n,m,i;
	cout<<"Podaj wielkosc tablicy: ";
	cin >> n;
	cout<<endl<<"Podaj zakres losowania liczb: 0-...";
	cin>> m;
	cout<<endl;
	srand(time(NULL));

	int *tablica = new int [n];
	for(i=0; i<n; i++)
		tablica[i]=rand() % (m+1);
	cout<<"tablica przed sortowaniem:"<<endl;
	for(i=0; i<n; i++)
		cout<<tablica[i]<<" ";
	cout<<endl;

	before=clock();
	test.sort(tablica,0,n-1);
	after=clock();
	clock_t clockTicksTaken = after - before;
	double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
	cout<<"tablica po sortowaniu:"<<endl;
	for(i=0; i<n; i++)
		cout<<tablica[i]<<" ";
	cout<<endl;
	cout<<"czas sortowania: "<<endl<<timeInSeconds<<endl;

	system("pause");

	delete tablica;
}
