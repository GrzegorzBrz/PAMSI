#include <time.h>
#include <iostream>
using namespace std;
#include "heapo.h"



void main()
{
	clock_t before, after, total = 0;
	heapsort test;
	int n,m,i ;
	//int size[] = {10000, 50000, 100000, 500000, 1000000};

	 //m=1000;

	 cin>>n>>m;
	srand(time(NULL));
	int *tab = new int [n+1];
//	for(int j=0;j<5;j++)
	//{
	
		//int *tab = new int [size[j]+1];
/*		for (i=0; i<size[j];i++)
		{
			tab[i+1]=size[j]-i;
		
		}*/
	
	//for(i=1; i<=size[j]; i++)
		for(i=1; i<=n; i++)
		tab[i]=rand() % (m+1);
	
	
	//for(i=1; i<=size[j]*99.7/100; i++)
	//	tab[i]=0;
	cout<<"tablica przed sortowaniem:"<<endl;
	for(i=1; i<=n; i++)
		cout<<tab[i]<<" ";
	cout<<endl;

	before=clock();
	test.sort(tab,n);
	//test.sort(tab,size[j]);
	after=clock();
	total = difftime(after, before);
	cout<<"tablica po sortowaniu:"<<endl;
	for(i=1; i<=n; i++)
		cout<<tab[i]<<" ";
	cout<<endl;
	cout<<"czas sortowania: "<<endl<<total<<endl;
	delete tab;
//	}
	system("pause");

	
}
