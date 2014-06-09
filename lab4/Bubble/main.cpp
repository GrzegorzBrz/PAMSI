#include <time.h>
#include <iostream>
using namespace std;
#include "bubble.h"



void main()
{
	clock_t before, after, total = 0;
	bubble test;
	int n,m,i ;

	cin>>n>>m;
	srand(time(NULL));
	int *tab = new int [n];

	for(i=1; i<n; i++)
		tab[i]=rand() % (m+1);



	cout<<"tablica przed sortowaniem:"<<endl;
	for(i=1; i<n; i++)
		cout<<tab[i]<<" ";
	cout<<endl;

	before=clock();
	test.sort(tab,n);
	after=clock();
	total = difftime(after, before);
	cout<<"tablica po sortowaniu:"<<endl;
	for(i=1; i<n; i++)
		cout<<tab[i]<<" ";
	cout<<endl;
	cout<<"czas sortowania: "<<endl<<total<<endl;
	delete tab;

	system("pause");


}
