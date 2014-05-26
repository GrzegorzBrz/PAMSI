
#include "Grafys.h"
#include "kolejka.h"


#define N 230

using namespace std;

komorka::komorka()
{
};

macierzs::macierzs()
{
};

/*******************************************************************************************************************/
krawedz::krawedz()
{
	polacz=false;
};

/*******************************************************************************************************************/
macierzs::macierzs(int x, int y)
{
	rozmx=x;
	rozmy=y;
	sumawag=0;
	int i;
	int j;
	
	tab=new krawedz *[rozmx];
	for (i=0;i<rozmx;i++)
		tab[i] = new krawedz [rozmy];
	for(i=0;i<rozmx;i++)							//Tworzenie pustej macierzy 
		for(j=0;j<rozmy;j++)
		{
				tab[i][j].waga=0;
				tab[i][j].polacz=false;
				tab[i][j].sasiadx=j;                
				tab[i][j].sasiady=i;
		}

};

/*******************************************************************************************************************/
macierzs::~macierzs()
{
};

/*******************************************************************************************************************/
void macierzs::wypelnij(int f)
{
	gest=f;
	int i=0;
	int kol=0;
	srand((int)time(NULL));											
	int h=(rozmx-1)*rozmx;						
	
	int size=0;
//	int q=((rozmx-1)*rozmx)/2;
	if(((h*f)%100)>0)
		size=(h*f)/100+1;
	else
		size=(h*f)/100;
	if (size<rozmx-1)
		size=rozmx-1;
	
	int dlug=rozmy;
	int *tabw=new int [rozmy];
	for(i=0;i<dlug;i++)
		tabw[i]=i;
	int r=rand() % dlug;
	tabw[r]=tabw[dlug-1];
	dlug--;
	int l=(rand() % N)+1;	
	int u=rand() % dlug;
	tab[r][tabw[u]].sasiadx=tabw[u];
	tab[r][tabw[u]].sasiady=r;
	tab[r][tabw[u]].waga=l;
	tab[r][tabw[u]].polacz=true;
	int a=r;
	r=tabw[u];
	tabw[u]=tabw[dlug-1];
	dlug--;
	h--;
	size--;
	for(i=0;i<rozmy-2;i++)
	{
		int l=(rand() % N)+1;	
		int u=rand() % dlug;
		tab[r][tabw[u]].sasiadx=tabw[u];
		tab[r][tabw[u]].sasiady=r;
		tab[r][tabw[u]].waga=l;
		tab[r][tabw[u]].polacz=true;

		r=tabw[u];
		tabw[u]=tabw[dlug-1];
		dlug--;
		size--;
		h--;
	};
	l=(rand() % N)+1;
	tab[r][a].sasiadx=a;
	tab[r][a].sasiady=tabw[r];
	tab[r][a].waga=l;
	tab[r][a].polacz=true;
	size--;
	h--;
	delete tabw;
	
		
		
	komorka *tmp=new komorka [h];             //pomocnicza tablica komorek o rozmiarze ilosci krawedzi
	i=0;
	for(int wier=0;wier<rozmy;wier++)							//idziemy po wierszach
	{													
			
		for(kol=0;kol<rozmx;kol++)								//idziemy po kolumnach
		{														//generowanie tablicy komorek ze wspolrzednymi krawedzi
			if(wier!=kol)
			{
				if(tab[wier][kol].polacz==false)
				{
					int t;
					if((h%2)>0)
						t=h/2+1;
					else
						t=h/2;
					tmp[i].x=kol;
					tmp[i].y=wier;
					if(i<h/2)
					{
						tmp[t+i].x=wier;
						tmp[t+i].y=kol;
					}
	
					i++;
				}
			}
		}
													
	}


	

	for(i=0;i<size;i++)											//dalsze wypelnianie macierzy, 
	{
		if (h!=0)
		{
			r=rand() % h;
			l=(rand() % N)+1;									//ZAKRES LOSOWANIA WAG
			tab[tmp[r].y][tmp[r].x].waga=l;							//Wypelnianie  macierzy
			tab[tmp[r].y][tmp[r].x].polacz=true;
			tab[tmp[r].y][tmp[r].x].sasiadx=tmp[r].x;
			tab[tmp[r].y][tmp[r].x].sasiady=tmp[r].y;
			
			tmp[r]=tmp[h-1];
			h--;

		}
		else
		{
			r=0;
			l=(rand() % N)+1;
			tab[tmp[r].y][tmp[r].x].waga=l;							
			tab[tmp[r].y][tmp[r].x].polacz=true;
			tab[tmp[r].y][tmp[r].x].sasiadx=tmp[r].x;
			tab[tmp[r].y][tmp[r].x].sasiady=tmp[r].y;
			tmp[r]=tmp[h-1];
	
		
		}
	}


};

/*******************************************************************************************************************/	
void macierzs::wyswietlND()
{
	cout<<"Najkrotsza droga wynosi: "<<sumawag<<endl
		<<"Kolejne krawedzie to: "<<endl;
	int	j=0;
	while(ND[j].polacz==true)
	{
		cout<<"("<<ND[j].sasiady<<"<->"<<ND[j].sasiadx<<")"<<endl;
		j++;
	}
};

/*******************************************************************************************************************/
void macierzs::wyswietl()
{
	cout<<"Macierz wag:"<<endl;
	for(int i=0;i<rozmy;i++)
	{
		for(int j=0;j<rozmx;j++)
		{
			cout<<tab[i][j].waga<<" ";
		}
		cout<<endl;
	}
};

/*******************************************************************************************************************/
void macierzs::dijkstra(int zrodlo,int ujscie)
{

	int q=rozmx;
	int *tabwierz=new int[rozmx];
	for(int i=0;i<rozmx;i++)
		tabwierz[i]=i;
	lista *tabpom=new lista [rozmx];
	
	for(int i=0;i<rozmx;i++)
	{
		tabpom[i].waga=1000000000;
	};
	tabpom[zrodlo].waga=0;

	for(int i=0;i<rozmx;i++)
	{
		if(tab[zrodlo][i].polacz==true)
		{
			tabpom[i].push_back(zrodlo,tab[zrodlo][i].waga);
			tabpom[i].waga=tab[zrodlo][i].waga;
		};
	};
	tabwierz[zrodlo]=tabwierz[q-1];
	q--;
	
	int k=0;
	int l=0;
	int j=0;
	while(q>0)
	{
		int min=1000000000;															//rozpoczynamy szukanie najmniejszej sciezki do wierzcho³ka nieustalonego
			for(int o=0;o<rozmx;o++)												//idziemy po kolei
				if(min>tabpom[o].waga)												//jesli waga sciezki danego wierzcholka jest mniejsza od wagi sciezki poprzedniego wierzcholka	
					for(j=0;j<q;j++)												//sprawdz czy
						if(o==tabwierz[j])											//wsytepuje wierzcholek w tablicy wierzcholkow niewykorzystanych
						{
							min=tabpom[o].waga;										//jesli tak przypisz najmmniejsza wage sciezki
							k=o;													//zapamieaj ktory to byl wierzcholek
							l=j;													//i gdzie wystepowal w tablicy wierzcholkow
							break;
						};
			tabwierz[l]=tabwierz[q-1];												//potraktuj go jako ustalony
			q--;
			for(int f=0;f<rozmx;f++)
			{
				if(tab[k][f].polacz==true)
					if(tab[k][f].waga+tabpom[k].waga<tabpom[f].waga)
					{
					//	tabpom[f]=tabpom[k];
						tabpom[f].dlugosc=0;
						tabpom[f].waga=0;
						tabpom[f].glowa=NULL;
						tabpom[f].iter=NULL;
						tabpom[f].ogon=NULL;
						tabpom[k].iter=tabpom[k].glowa;
						for(int g=0;g<tabpom[k].dlugosc;g++)
						{
							tabpom[f].push_back(tabpom[k].iter->sasiadx,tabpom[k].iter->waga);
							tabpom[f].waga+=tabpom[k].iter->waga;
							tabpom[k].iter=tabpom[k].iter->nast;
						}

						tabpom[f].push_back(k,tab[k][f].waga);
						tabpom[f].waga+=tab[k][f].waga;
					
					};
			};
			
	}
	
	int h;
	ND=new krawedz[rozmx];
	tabpom[ujscie].iter=tabpom[ujscie].glowa;
	ND[0].sasiady=tabpom[ujscie].glowa->sasiadx;
	ND[0].waga=tabpom[ujscie].glowa->waga;
	ND[0].polacz=true;
	sumawag=tabpom[ujscie].waga;
	tabpom[ujscie].iter=tabpom[ujscie].glowa->nast;

	for(h=1;h<tabpom[ujscie].dlugosc;h++)
	{

		ND[h-1].sasiadx=tabpom[ujscie].iter->sasiadx;
		ND[h].sasiady=tabpom[ujscie].iter->sasiadx;
		ND[h].waga=tabpom[ujscie].iter->waga;
		ND[h].polacz=true;
	
		tabpom[ujscie].iter=tabpom[ujscie].iter->nast;

	}
	ND[h-1].sasiadx=ujscie;
};


void macierzs::bellman(int zrodlo,int ujscie)
{
	lista *tabpom=new lista [rozmx];
	for(int i=0;i<rozmx;i++)
	{
		tabpom[i].waga=1000000000;
	};
	kolejka kolejka;
	int *wyst=new int [rozmx];
	tabpom[zrodlo].waga=0;
	wyst[zrodlo]=zrodlo;
	for(int i=0;i<rozmx;i++)
		if(tab[zrodlo][i].polacz==true)
		{
			tabpom[i].push_back(zrodlo,tab[zrodlo][i].waga);
			tabpom[i].waga=tab[zrodlo][i].waga;
			kolejka.push(i);
			wyst[i]=i;
		};
	while(!kolejka.empty())
	{
		int q=kolejka.poczatek->dane;
		kolejka.pop();
		for(int d=0;d<rozmx;d++)
		{
			if(tab[q][d].polacz==true)
			{
				if(tabpom[q].waga+tab[q][d].waga<tabpom[d].waga)
				{
		
						tabpom[d].dlugosc=0;
						tabpom[d].waga=0;
						tabpom[d].glowa=NULL;
						tabpom[d].iter=NULL;
						tabpom[d].ogon=NULL;
						tabpom[q].iter=tabpom[q].glowa;
						for(int g=0;g<tabpom[q].dlugosc;g++)
						{
							tabpom[d].push_back(tabpom[q].iter->sasiadx,tabpom[q].iter->waga);
							tabpom[d].waga+=tabpom[q].iter->waga;
							tabpom[q].iter=tabpom[q].iter->nast;
						}

					tabpom[d].push_back(q,tab[q][d].waga);
					tabpom[d].waga+=tab[q][d].waga;
					

					if(wyst[d]==d && kolejka.inqueue(d)==false)
					{
					
						kolejka.prio(d);
					};
					if(wyst[d]!=d && kolejka.inqueue(d)==false)
					{
						kolejka.push(d);
						wyst[d]=d;
					};
				}
			
					
			}
		}
		
	}
	int h;
	ND=new krawedz[rozmx];
	ND[0].sasiady=tabpom[ujscie].glowa->sasiadx;
	ND[0].waga=tabpom[ujscie].glowa->waga;
	ND[0].polacz=true;
	sumawag=tabpom[ujscie].waga;
	tabpom[ujscie].iter=tabpom[ujscie].glowa->nast;
	for(h=1;h<tabpom[ujscie].dlugosc;h++)
	{
		ND[h-1].sasiadx=tabpom[ujscie].iter->sasiadx;
		ND[h].sasiady=tabpom[ujscie].iter->sasiadx;
		ND[h].waga=tabpom[ujscie].iter->waga;
		ND[h].polacz=true;
	
		tabpom[ujscie].iter=tabpom[ujscie].iter->nast;
	}
	ND[h-1].sasiadx=ujscie;


};


listas2::listas2()
{
};

listas2::~listas2()
{
};

listas2::listas2(int x, int y)
{
	rozmx=x;
	rozmy=y;
	sumawag=0;

	lis=new lista [rozmx];
};

void listas2::wypelnij(int f)
{

	gest=f;
	int i=0;
	int kol=1;
	int pom=1;													//'pamiec' o kolumnie od ktorej zaczynamy kolejny wiersz w macierzy trojkatnej gornej	
	macierzs tab2(rozmx,rozmy);
	tab2.wypelnij(f);
/*	komorka *tmp=new komorka [((rozmx-1)*rozmx)/2];				//pomocnicza tablica komorek o rozmiarze ilosci krawedzi
	krawedz **tab2;
	tab2=new krawedz *[rozmx];
	for (int i=0;i<rozmx;i++)
		tab2[i] = new krawedz [rozmy];
	srand((int)time(NULL));

	for(int wier=0;wier<rozmy-1;wier++)							//idziemy po wierszach
	{													
		kol=pom;	
		for(kol;kol<rozmx;kol++)								//idziemy po kolumnach
		{														//generowanie tablicy komorek ze wspolrzednymi krawedzi
			tmp[i].x=kol;
			tmp[i].y=wier;

			i++;
			
		}
		pom++;													//przesuniecie pamieci o kolumnie poczatkowej wiersza
	}
	int size=0;
	int q=((rozmx-1)*rozmx)/2;
	if(((q*f)%100)>0)
		size=(q*f)/100+1;
	else
		size=(q*f)/100;
	if (size<rozmx-1)
		size=rozmx-1;
	

	for(i=0;i<(size-(rozmx-1));i++)		//wypelnianie macierzy do momentu,gdy zostanie ilosc wystarczajaca do minimalnego zapelnienia (na wszelki wyadek)
	{
		
		int r=rand() % q;
		int l=(rand() % N)+1;									//ZAKRES LOSOWANIA WAG
	
		tab2[tmp[r].y][tmp[r].x].waga=l;							//Wypelnianie gornej czeœci macierzy
		tab2[tmp[r].y][tmp[r].x].polacz=true;
		tab2[tmp[r].y][tmp[r].x].sasiadx=tmp[r].x;
		tab2[tmp[r].y][tmp[r].x].sasiady=tmp[r].y;
		
		tab2[tmp[r].x][tmp[r].y].waga=l;							//wypelnianie dolnej czesci macierzy
		tab2[tmp[r].x][tmp[r].y].polacz=true;
		tab2[tmp[r].x][tmp[r].y].sasiadx=tmp[r].y;
		tab2[tmp[r].x][tmp[r].y].sasiady=tmp[r].x;
		tmp[r]=tmp[q-1];											//zmiana ostatniego elementu z wylosowanym (usuniecie wylosowanego elementu)
		q--;													//zmniejszenie zakresu losowania (unikniecie podwojnego losowania)
	}
	
	int	z=rozmx-1;												//zmienna liczaca ile polaczen pozostalo do uzupelnienia(niezbedna do ostatniej petli)
	for(int j=0;j<rozmy;j++)									//Sprawdzanie czy w danym wierszu nie wystepuje brak polaczen(sprawdzanie spojnosci grafu)
	{
		for(int o=0;o<rozmx;o++)
		{
			if(tab2[j][o].polacz==true)
				break;
			else
			{
				if(o==(rozmx-1))
				{										
					int l=(rand() % N)+1;							//ZAKRES LOSOWANIA WAG
					int k=rand() % rozmx;
					while(k==j)
						k=rand() % rozmx;

					tab2[j][k].waga=l;
					tab2[j][k].polacz=true;
					tab2[j][k].sasiadx=k;
					tab2[j][k].sasiady=j;
					if(j<k)
					{
					for(i=0;i<q;i++)
						if (tmp[i].x==k && tmp[i].y==j)
							tmp[i]=tmp[q-1];
						q--;
					}
					else
					{
					for(i=0;i<q;i++)
						if (tmp[i].x==j && tmp[i].y==k)
							tmp[i]=tmp[q-1];
						q--;
					}


					tab2[k][j].waga=l;
					tab2[k][j].polacz=true;
					tab2[k][j].sasiadx=j;
					tab2[k][j].sasiady=k;
					z--;
				}
			}
		}
	
	}


	for(i=0;i<z;i++)											//dalsze wypelnianie macierzy, zmienna 'z' ogranicza ilosc wypelnien do odpowiedniej liczby,ktora zostala zdefiniowana w pierwszej petli
	{
		if (q!=0)
		{
			int r=rand() % q;
			int l=(rand() % N)+1;									//ZAKRES LOSOWANIA WAG
			tab2[tmp[r].y][tmp[r].x].waga=l;							//Wypelnianie gornej czeœci macierzy
			tab2[tmp[r].y][tmp[r].x].polacz=true;
			tab2[tmp[r].y][tmp[r].x].sasiadx=tmp[r].x;
			tab2[tmp[r].y][tmp[r].x].sasiady=tmp[r].y;
		
			tab2[tmp[r].x][tmp[r].y].waga=l;							//wypelnianie dolnej czesci macierzy
			tab2[tmp[r].x][tmp[r].y].polacz=true;
			tab2[tmp[r].x][tmp[r].y].sasiadx=tmp[r].y;
			tab2[tmp[r].x][tmp[r].y].sasiady=tmp[r].x;
			tmp[r]=tmp[q-1];
			q--;
		}
		else
		{
			int r=0;
			int l=(rand() % N)+1;
			tab2[tmp[r].y][tmp[r].x].waga=l;							//Wypelnianie gornej czeœci macierzy
			tab2[tmp[r].y][tmp[r].x].polacz=true;
			tab2[tmp[r].y][tmp[r].x].sasiadx=tmp[r].x;
			tab2[tmp[r].y][tmp[r].x].sasiady=tmp[r].y;
		
			tab2[tmp[r].x][tmp[r].y].waga=l;							//wypelnianie dolnej czesci macierzy
			tab2[tmp[r].x][tmp[r].y].polacz=true;
			tab2[tmp[r].x][tmp[r].y].sasiadx=tmp[r].y;
			tab2[tmp[r].x][tmp[r].y].sasiady=tmp[r].x;
			tmp[r]=tmp[q-1];
		}
	}
	delete tmp;
	*/
	
	int size=0;
	kol=1;
	pom=1;
	i=0;
	if((((((rozmx-1)*rozmx)/2)*gest)%100)>0)
		size=(((rozmx-1)*rozmx)/2)*gest/100+1;
	else
		size=(((rozmx-1)*rozmx)/2)*gest/100;					//rozmiar tablicy krawedzi
	if (size<rozmx-1)
		size=rozmx-1;

	lis=new lista [rozmx];

	for(int wier=0;wier<rozmy;wier++)							//idziemy po wierszach
	{														
		for(kol=0;kol<rozmx;kol++)								//idziemy po kolumnach
		{														//wypelnianie tablicy krawedzi 
			if(tab2.tab[wier][kol].polacz==true)						//jesli znajdzie w macierzy polaczenie przekopiuje krawedz do listy sasiadow
			{
				lis[wier].push_back(kol,tab2.tab[wier][kol].waga);
				i++;
			}
		}
																//przesuniecie pamieci o kolumnie poczatkowej wiersza
	}
	
};

void listas2::wyswietl()
{
	cout<<"Lista wag:"<<endl;
	int i=0;
	for(i=0;i<rozmy;i++)
	{
		lis[i].iter=lis[i].glowa;
		if(lis[i].dlugosc==0)
			break;
		while(lis[i].iter->nast!=NULL)
		{
			cout<<i<<" "<<lis[i].iter->sasiadx<<" "<<lis[i].iter->waga<<endl;
			lis[i].iter=lis[i].iter->nast;
		};
		cout<<i<<" "<<lis[i].iter->sasiadx<<" "<<lis[i].iter->waga<<endl;
	}
	cout<<endl;
};

void listas2::wyswietlND()
{
	cout<<"Najkrotsza droga wynosi: "<<sumawag<<endl
		<<"Kolejne krawedzie to: "<<endl;
	int	j=0;
	while(ND[j].polacz==true)
	{
		cout<<"("<<ND[j].sasiady<<"<->"<<ND[j].sasiadx<<")"<<endl;
		j++;
	}
};

void listas2::dijkstra(int zrodlo,int ujscie)
{

	int q=rozmx;
	int *tabwierz=new int[rozmx];
	for(int i=0;i<rozmx;i++)
		tabwierz[i]=i;
	lista *tabpom=new lista [rozmx];
	
	for(int i=0;i<rozmx;i++)
	{
		tabpom[i].waga=1000000000;
	};
	tabpom[zrodlo].waga=0;

	lis[zrodlo].iter=lis[zrodlo].glowa;
	for(int i=0;i<lis[zrodlo].dlugosc;i++)
	{
			tabpom[lis[zrodlo].iter->sasiadx].iter=tabpom[lis[zrodlo].iter->sasiadx].glowa;
			tabpom[lis[zrodlo].iter->sasiadx].push_back(zrodlo,lis[zrodlo].iter->waga);
			tabpom[lis[zrodlo].iter->sasiadx].waga=lis[zrodlo].iter->waga;
			lis[zrodlo].iter=lis[zrodlo].iter->nast;

	};
	tabwierz[zrodlo]=tabwierz[q-1];
	q--;
	
	int k=0;
	int l=0;
	int j=0;
	while(q>0)
	{
		
		int min=1000000000;															//rozpoczynamy szukanie najmniejszej sciezki do wierzcho³ka nieustalonego
			for(int o=0;o<rozmx;o++)												//idziemy po kolei
				if(min>tabpom[o].waga)												//jesli waga sciezki danego wierzcholka jest mniejsza od wagi sciezki poprzedniego wierzcholka
					for(j=0;j<q;j++)												//sprawdz czy
						if(o==tabwierz[j])											//wystepuje wierzcholek w tablicy wierzcholkow niewykorzystanych
						{
							min=tabpom[o].waga;
							k=o;
							l=j;
							break;
						};
			tabwierz[l]=tabwierz[q-1];
			q--;
			lis[k].iter=lis[k].glowa;
			for(int v=0;v<lis[k].dlugosc;v++)
			{
				if(lis[k].iter->waga+tabpom[k].waga<tabpom[lis[k].iter->sasiadx].waga)
				{
				//	tabpom[lis[k].iter->sasiadx]=tabpom[k];

						tabpom[lis[k].iter->sasiadx].dlugosc=0;
						tabpom[lis[k].iter->sasiadx].waga=0;
						tabpom[lis[k].iter->sasiadx].glowa=NULL;
						tabpom[lis[k].iter->sasiadx].iter=NULL;
						tabpom[lis[k].iter->sasiadx].ogon=NULL;
						tabpom[k].iter=tabpom[k].glowa;
						for(int g=0;g<tabpom[k].dlugosc;g++)
						{
							tabpom[lis[k].iter->sasiadx].push_back(tabpom[k].iter->sasiadx,tabpom[k].iter->waga);
							tabpom[lis[k].iter->sasiadx].waga+=tabpom[k].iter->waga;
							tabpom[k].iter=tabpom[k].iter->nast;
						}


					tabpom[lis[k].iter->sasiadx].push_back(k,lis[k].iter->waga);
					tabpom[lis[k].iter->sasiadx].waga+=lis[k].iter->waga;
					
				};
				lis[k].iter=lis[k].iter->nast;
			};
			
	}
	int h;
	ND=new krawedz[rozmx];
	ND[0].sasiady=tabpom[ujscie].glowa->sasiadx;
	ND[0].waga=tabpom[ujscie].glowa->waga;
	ND[0].polacz=true;
	sumawag=tabpom[ujscie].waga;
	tabpom[ujscie].iter=tabpom[ujscie].glowa->nast;
	for(h=1;h<tabpom[ujscie].dlugosc;h++)
	{
		ND[h-1].sasiadx=tabpom[ujscie].iter->sasiadx;
		ND[h].sasiady=tabpom[ujscie].iter->sasiadx;
		ND[h].waga=tabpom[ujscie].iter->waga;
		ND[h].polacz=true;
	
		tabpom[ujscie].iter=tabpom[ujscie].iter->nast;
	}
	ND[h-1].sasiadx=ujscie;
};

void listas2::bellman(int zrodlo,int ujscie)
{
	lista *tabpom=new lista [rozmx];
	for(int i=0;i<rozmx;i++)
	{
		tabpom[i].waga=1000000000;
	};
	kolejka kolejka;
	int *wyst=new int [rozmx];
	tabpom[zrodlo].waga=0;
	lis[zrodlo].iter=lis[zrodlo].glowa;
	wyst[zrodlo]=zrodlo;
	for(int i=0;i<lis[zrodlo].dlugosc;i++)
		{
			tabpom[lis[zrodlo].iter->sasiadx].push_back(zrodlo,lis[zrodlo].iter->waga);
			tabpom[lis[zrodlo].iter->sasiadx].waga=lis[zrodlo].iter->waga;
			kolejka.push(lis[zrodlo].iter->sasiadx);
			wyst[lis[zrodlo].iter->sasiadx]=lis[zrodlo].iter->sasiadx;
			lis[zrodlo].iter=lis[zrodlo].iter->nast;
			
		};

	while(!kolejka.empty())
	{
		int q=kolejka.poczatek->dane;
		lis[q].iter=lis[q].glowa;
		
		kolejka.pop();
		
		for(int d=0;d<lis[q].dlugosc;d++)
		{
			
			if(tabpom[q].waga+lis[q].iter->waga<tabpom[lis[q].iter->sasiadx].waga)
			{
			//	tabpom[d]=tabpom[q];
				tabpom[lis[q].iter->sasiadx].dlugosc=0;
				tabpom[lis[q].iter->sasiadx].waga=0;
				tabpom[lis[q].iter->sasiadx].glowa=NULL;
				tabpom[lis[q].iter->sasiadx].iter=NULL;
				tabpom[lis[q].iter->sasiadx].ogon=NULL;
				tabpom[q].iter=tabpom[q].glowa;
				for(int g=0;g<tabpom[q].dlugosc;g++)
				{
					tabpom[lis[q].iter->sasiadx].push_back(tabpom[q].iter->sasiadx,tabpom[q].iter->waga);
					tabpom[lis[q].iter->sasiadx].waga+=tabpom[q].iter->waga;
					tabpom[q].iter=tabpom[q].iter->nast;
				}

				tabpom[lis[q].iter->sasiadx].push_back(q,lis[q].iter->waga);
				tabpom[lis[q].iter->sasiadx].waga+=lis[q].iter->waga;
			
			
		
				if(lis[q].iter->sasiadx==wyst[lis[q].iter->sasiadx] && kolejka.inqueue(lis[q].iter->sasiadx)==false)
				{
					kolejka.prio(lis[q].iter->sasiadx);
				};
				if(lis[q].iter->sasiadx!=wyst[lis[q].iter->sasiadx] && kolejka.inqueue(lis[q].iter->sasiadx)==false)
				{
					kolejka.push(lis[q].iter->sasiadx);
					wyst[lis[q].iter->sasiadx]=lis[q].iter->sasiadx;
				};
			
				
			}
			lis[q].iter=lis[q].iter->nast;
			
		}
		
	}
	int h;
	ND=new krawedz[rozmx];
	ND[0].sasiady=tabpom[ujscie].glowa->sasiadx;
	ND[0].waga=tabpom[ujscie].glowa->waga;
	ND[0].polacz=true;
	sumawag=tabpom[ujscie].waga;
	tabpom[ujscie].iter=tabpom[ujscie].glowa->nast;
	for(h=1;h<tabpom[ujscie].dlugosc;h++)
	{
		ND[h-1].sasiadx=tabpom[ujscie].iter->sasiadx;
		ND[h].sasiady=tabpom[ujscie].iter->sasiadx;
		ND[h].waga=tabpom[ujscie].iter->waga;
		ND[h].polacz=true;
	
		tabpom[ujscie].iter=tabpom[ujscie].iter->nast;
	}
	ND[h-1].sasiadx=ujscie;


};