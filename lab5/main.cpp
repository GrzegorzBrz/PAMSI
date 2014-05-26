#include "quicksort.h"
#include <stdio.h>
#include <fstream>
#include <time.h>
#include <Windows.h>
#define r 10			//ilosc wierzcholkow
#define g 50			//gestosc wypelnienia macierzy


using namespace std;


void main()
{
	int n;
	int m;
	int i;
	int j;
	int wybor=0;



	while(wybor!=5)
	{
		cout<<"Co chcesz zrobic?"<<endl<<endl
			<<"Test macierzy losowej - 1"<<endl
			<<"Test listy losowej - 2"<<endl
			//<<"Test macierzy z pliku - 3"<<endl
			//<<"Test listy z pliku - 4"<<endl
			<<"Wyjscie - 5"<<endl;


		clock_t begin,end,find=0;
		fstream plik;
		cin>>wybor;


		switch(wybor)
		{

		case 1:
			{

				for(i=0;i<1;i++)
				{
					macierzs proba(r,r);
					proba.wypelnij(g);
					begin = clock();
					proba.kruskal();
					end = clock();
					find += difftime(end, begin);
					proba.wyswietl();		
					proba.wyswietlMDR();
				}
				cout<<"Czas Kruskala: "<<((float)find)/CLOCKS_PER_SEC<<endl<<endl;

				Sleep(100);
				find=0;
				for(i=0;i<1;i++)
				{
					macierzs proba(r,r);
					proba.wypelnij(g);
					begin = clock();
					proba.prim();
					end = clock();
					find += difftime(end, begin);
					proba.wyswietl();
					proba.wyswietlMDR();
				}
				cout<<"Czas Prima: "<<((float)find)/CLOCKS_PER_SEC<<endl<<endl;
				break;
			}

		case 2:
			{
				for(i=0;i<1;i++)
				{
					listas proba2(r,r);
					proba2.wypelnij(g);
					begin = clock();
					proba2.kruskal();
					end = clock();
					find += difftime(end, begin);
					proba2.wyswietl();		
					proba2.wyswietlMDR();
				}
				cout<<"Czas Kruskala: "<<((float)find)/CLOCKS_PER_SEC<<endl<<endl;

				Sleep(100);
				find=0;
				for(i=0;i<1;i++)
				{
					listas proba2(r,r);
					proba2.wypelnij(g);
					begin = clock();
					proba2.prim();
					end = clock();
					find += difftime(end, begin);
					proba2.wyswietl();
					proba2.wyswietlMDR();
				}
				cout<<"Czas Prima: "<<((float)find)/CLOCKS_PER_SEC<<endl<<endl;
				break;
			}

		//case 3:
		//	{
		//		plik.open("probny2.txt");
		//		plik>>m>>n;
		//		macierzs proba3(m,n);
		//		plik>>proba3.gest;
		//		for(i=0;i<proba3.rozmy;i++)
		//		{
		//			for(j=0;j<proba3.rozmx;j++)
		//			{
		//				plik>>proba3.tab[i][j].waga;
		//				proba3.tab[i][j].sasiady=j;
		//				proba3.tab[i][j].sasiadx=i;
		//				if(i!=j && proba3.tab[i][j].waga!=0)
		//					proba3.tab[i][j].polacz=true;
		//			};
		//		}

		//		plik.close();
		//		for(int f=0;f<1;f++)
		//		{
		//			begin = clock();
		//			proba3.kruskal();
		//			end = clock();
		//			find += difftime(end, begin);
		//			proba3.wyswietl();		
		//			proba3.wyswietlMDR();
		//		}
		//		cout<<"Czas Kruskala: "<<((float)find)/CLOCKS_PER_SEC<<endl<<endl;

		//		Sleep(100);
		//		find=0;
		//		for(i=0;i<1;i++)
		//		{
		//			begin = clock();
		//			proba3.prim();
		//			end = clock();
		//			find += difftime(end, begin);
		//			proba3.wyswietl();
		//			proba3.wyswietlMDR();
		//		}
		//		cout<<"Czas Prima: "<<((float)find)/CLOCKS_PER_SEC<<endl<<endl;
		//		break;
		//	}


		//case 4:
		//	{

		//		plik.open("probny.txt");
		//		plik>>m>>n;
		//		listas proba4(m,n);
		//		plik>>proba4.gest;
		//		int size=0;
		//		if((((((proba4.rozmx-1)*proba4.rozmx)/2)*proba4.gest)%100)>0)
		//			size=(((proba4.rozmx-1)*proba4.rozmx)/2)*proba4.gest/100+1;
		//		else
		//			size=(((proba4.rozmx-1)*proba4.rozmx)/2)*proba4.gest/100;					//rozmiar tablicy krawedzi
		//		if (size<proba4.rozmx-1)
		//			size=proba4.rozmx-1;
		//		for(i=0;i<size;i++)
		//		{
		//			plik>>proba4.lista[i].sasiady>>proba4.lista[i].sasiadx>>proba4.lista[i].waga;
		//			proba4.lista[i].polacz=true;

		//		};
		//		proba4.wyswietl();
		//		for(i=0;i<1;i++)
		//		{
		//			begin = clock();
		//			proba4.kruskal();
		//			end = clock();
		//			find += difftime(end, begin);
		//			proba4.wyswietl();		
		//			proba4.wyswietlMDR();
		//		}
		//		cout<<"Czas Kruskala: "<<((float)find)/CLOCKS_PER_SEC<<endl<<endl;
		//		Sleep(100);
		//		find=0;
		//		for(i=0;i<1;i++)
		//		{
		//			begin = clock();
		//			proba4.prim();
		//			end = clock();
		//			find += difftime(end, begin);
		//			proba4.wyswietl();
		//			proba4.wyswietlMDR();
		//		}
		//		cout<<"Czas Prima: "<<((float)find)/CLOCKS_PER_SEC<<endl<<endl;
		//		break;
		//	}

		case 5:
			break;
		}
	}

}
