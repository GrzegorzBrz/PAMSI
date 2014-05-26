#include "Grafys.h"
#include <stdio.h>
#include <fstream>
#include <time.h>
#include <Windows.h>
#define wierz 250				//wierzcholki
#define g 25					//gestosc
#define rep 100				//powtorzenia
//#define pocz 1
//#define kon 3

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
		srand((int)time(NULL));	
		int pocz=rand() % wierz;
		cout<<"Wierzcholek poczatkowy: "<<pocz<<endl;
		Sleep(2000);
		srand((int)time(NULL));	
		int kon=rand()% wierz;
		cout<<"Wierzcholek koncowy: "<<kon<<endl;


		clock_t begin,end,find=0;
		fstream plik;
		cin>>wybor;


		switch(wybor)
		{

		case 1:
			{

				for(i=0;i<rep;i++)
				{
					macierzs proba(wierz,wierz);
					proba.wypelnij(g);
					begin = clock();
					proba.dijkstra(pocz,kon);
					end = clock();
					find += difftime(end, begin);
					//		proba.wyswietl();
					//		proba.wyswietlND();

					//		proba.bellman(pocz,kon);
					//		proba.wyswietl();
					//		proba.wyswietlND();

				}
				cout<<"Czas Dijkstry: "<<((float)find)/CLOCKS_PER_SEC<<endl<<endl;

				Sleep(10);
				find=0;
				for(i=0;i<rep;i++)
				{
					macierzs proba(wierz,wierz);
					proba.wypelnij(g);
					begin = clock();
					proba.bellman(pocz,kon);
					end = clock();
					find += difftime(end, begin);
					//		proba.wyswietl();
					//		proba.wyswietlND();
				}
				cout<<"Czas Bellmana-Forda: "<<((float)find)/CLOCKS_PER_SEC<<endl<<endl;
				break;
			}

		case 2:
			{
				for(i=0;i<rep;i++)
				{
					listas2 proba2(wierz,wierz);
					proba2.wypelnij(g);
					begin = clock();
					proba2.dijkstra(pocz,kon);
					end = clock();
					find += difftime(end, begin);
					//		proba2.wyswietl();		
					//		proba2.wyswietlND();

					//		proba.bellman(pocz,kon);
					//		proba.wyswietl();
					//		proba.wyswietlND();
				}
				cout<<"Czas Dijkstry: "<<((float)find)/CLOCKS_PER_SEC<<endl<<endl;

				Sleep(10);
				find=0;
				for(i=0;i<rep;i++)
				{
					listas2 proba2(wierz,wierz);
					proba2.wypelnij(g);
					begin = clock();
					proba2.bellman(pocz,kon);
					end = clock();
					find += difftime(end, begin);
					//		proba2.wyswietl();
					//		proba2.wyswietlND();
				}
				cout<<"Czas Bellmana-Forda: "<<((float)find)/CLOCKS_PER_SEC<<endl<<endl;
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
		//			proba3.dijkstra(pocz,kon);
		//			end = clock();
		//			find += difftime(end, begin);
		//			proba3.wyswietl();		
		//			proba3.wyswietlND();
		//		}
		//		cout<<"Czas Dijkstry: "<<((float)find)/CLOCKS_PER_SEC<<endl<<endl;

		//		Sleep(1);
		//		find=0;
		//		for(i=0;i<1;i++)
		//		{
		//			begin = clock();
		//			proba3.bellman(pocz,kon);
		//			end = clock();
		//			find += difftime(end, begin);
		//			proba3.wyswietl();
		//			proba3.wyswietlND();
		//		}
		//		cout<<"Czas Bellmana-Forda: "<<((float)find)/CLOCKS_PER_SEC<<endl<<endl;
		//		break;
		//	}


		//case 4:
		//	{
		//		int w;
		//		int y;
		//		int x;
		//		plik.open("probny.txt");
		//		plik>>m>>n;
		//		listas2 proba4(m,n);
		//		plik>>proba4.gest;
		//		int u=0;
		//		if(u=((proba4.rozmx-1)*proba4.rozmx)*proba4.gest%100>0)
		//			u=((proba4.rozmx-1)*proba4.rozmx)*proba4.gest/100+1;
		//		else
		//			u=((proba4.rozmx-1)*proba4.rozmx)*proba4.gest/100;

		//		for(i=0;i<u;i++)
		//		{
		//			plik>>y>>x>>w;
		//			proba4.lis[y].push_back(x,w);
		//			//		proba4.lis[x].push_back(y,w);
		//		};


		//		for(i=0;i<1;i++)
		//		{
		//			begin = clock();
		//			proba4.dijkstra(pocz,kon);
		//			end = clock();
		//			find += difftime(end, begin);
		//			proba4.wyswietl();		
		//			proba4.wyswietlND();
		//		}
		//		cout<<"Czas Dijkstry: "<<((float)find)/CLOCKS_PER_SEC<<endl<<endl;
		//		Sleep(100);
		//		find=0;
		//		for(i=0;i<1;i++)
		//		{
		//			begin = clock();
		//			proba4.bellman(pocz,kon);
		//			end = clock();
		//			find += difftime(end, begin);
		//			proba4.wyswietl();
		//			proba4.wyswietlND();
		//		}
		//		cout<<"Czas Bellmana-Forda: "<<((float)find)/CLOCKS_PER_SEC<<endl<<endl;
		//		break;
		//	}


		case 5:
			break;
		}
	}

}
