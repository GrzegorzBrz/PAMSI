
#include "quicksort.h"

#define N 10

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
	int kol=1;
	int pom=1;													//'pamiec' o kolumnie od ktorej zaczynamy kolejny wiersz w macierzy trojkatnej gornej	
								
	komorka *tmp=new komorka [((rozmx-1)*rozmx)/2];             //pomocnicza tablica komorek o rozmiarze ilosci krawedzi

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
	
		tab[tmp[r].y][tmp[r].x].waga=l;							//Wypelnianie gornej czeœci macierzy
		tab[tmp[r].y][tmp[r].x].polacz=true;
		tab[tmp[r].y][tmp[r].x].sasiadx=tmp[r].x;
		tab[tmp[r].y][tmp[r].x].sasiady=tmp[r].y;
		
		tab[tmp[r].x][tmp[r].y].waga=l;							//wypelnianie dolnej czesci macierzy
		tab[tmp[r].x][tmp[r].y].polacz=true;
		tab[tmp[r].x][tmp[r].y].sasiadx=tmp[r].y;
		tab[tmp[r].x][tmp[r].y].sasiady=tmp[r].x;
		tmp[r]=tmp[q-1];											//zmiana ostatniego elementu z wylosowanym (usuniecie wylosowanego elementu)
		q--;													//zmniejszenie zakresu losowania (unikniecie podwojnego losowania)
	}
	
	int	z=rozmx-1;												//zmienna liczaca ile polaczen pozostalo do uzupelnienia(niezbedna do ostatniej petli)
	for(int j=0;j<rozmy;j++)									//Sprawdzanie czy w danym wierszu nie wystepuje brak polaczen(sprawdzanie spojnosci grafu)
	{
		for(int o=0;o<rozmx;o++)
		{
			if(tab[j][o].polacz==true)
				break;
			else
			{
				if(o==(rozmx-1))
				{										
					int l=(rand() % N)+1;							//ZAKRES LOSOWANIA WAG
					int k=rand() % rozmx;
					while(k==j)
						k=rand() % rozmx;

					tab[j][k].waga=l;
					tab[j][k].polacz=true;
					tab[j][k].sasiadx=k;
					tab[j][k].sasiady=j;
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


					tab[k][j].waga=l;
					tab[k][j].polacz=true;
					tab[k][j].sasiadx=j;
					tab[k][j].sasiady=k;
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
			tab[tmp[r].y][tmp[r].x].waga=l;							//Wypelnianie gornej czeœci macierzy
			tab[tmp[r].y][tmp[r].x].polacz=true;
			tab[tmp[r].y][tmp[r].x].sasiadx=tmp[r].x;
			tab[tmp[r].y][tmp[r].x].sasiady=tmp[r].y;
		
			tab[tmp[r].x][tmp[r].y].waga=l;							//wypelnianie dolnej czesci macierzy
			tab[tmp[r].x][tmp[r].y].polacz=true;
			tab[tmp[r].x][tmp[r].y].sasiadx=tmp[r].y;
			tab[tmp[r].x][tmp[r].y].sasiady=tmp[r].x;
			tmp[r]=tmp[q-1];
			q--;
		}
		else
		{
			int r=0;
			int l=(rand() % N)+1;
			tab[tmp[r].y][tmp[r].x].waga=l;							//Wypelnianie gornej czeœci macierzy
			tab[tmp[r].y][tmp[r].x].polacz=true;
			tab[tmp[r].y][tmp[r].x].sasiadx=tmp[r].x;
			tab[tmp[r].y][tmp[r].x].sasiady=tmp[r].y;
		
			tab[tmp[r].x][tmp[r].y].waga=l;							//wypelnianie dolnej czesci macierzy
			tab[tmp[r].x][tmp[r].y].polacz=true;
			tab[tmp[r].x][tmp[r].y].sasiadx=tmp[r].y;
			tab[tmp[r].x][tmp[r].y].sasiady=tmp[r].x;
			tmp[r]=tmp[q-1];
		}
	}
	delete tmp;

};

/*******************************************************************************************************************/	
void macierzs::kruskal()
{
	sumawag=0;
	quicksort sortowanie;
	krawedz *tmp;
	int kol=1;
	int pom=1;
	int i=0;
	int size=0;
	if((((((rozmx-1)*rozmx)/2)*gest)%100)>0)
		size=(((rozmx-1)*rozmx)/2)*gest/100+1;
	else
		size=(((rozmx-1)*rozmx)/2)*gest/100;					//rozmiar tablicy krawedzi
	if (size<rozmx-1)
		size=rozmx-1;
	tmp=new krawedz [size];										//tablica krawedzi
	MDR=new krawedz [rozmx-1];									//tablica krawedzi MDR
	for(int wier=0;wier<rozmy;wier++)							//idziemy po wierszach
	{													
		kol=pom;	
		for(kol;kol<rozmx;kol++)								//idziemy po kolumnach
		{														//wypelnianie tablicy krawedzi 
			if(tab[wier][kol].polacz==true)						//jesli znajdzie w macierzy polaczenie przekopiuje krawedz do tablicy krawedzi
			{
				tmp[i].sasiadx=kol;
				tmp[i].sasiady=wier;

				tmp[i].waga=tab[wier][kol].waga;
				tmp[i].polacz=tab[wier][kol].polacz;

				i++;
			}
		}
		pom++;													//przesuniecie pamieci o kolumnie poczatkowej wiersza
	}

	int *tabkol=new int [rozmx];									//tablica kolorow
	for(i=0;i<rozmx;i++)
	{
		tabkol[i]=i;
	}

	sortowanie.sort(tmp,0,size-1);
	int j=0;
	
/*	cout<<"sort: "<<endl;
	for(i=0;i<size;i++)
		cout<<tmp[i].sasiady<<" "<<tmp[i].sasiadx<<" "<<tmp[i].waga<<endl;
*/
	for(i=0;i<size;i++)
	{
		if(tabkol[tmp[i].sasiadx]!=tabkol[tmp[i].sasiady])		//porownanie kolorow w tablicy na wspolrzednych sasiadow danej krawedzi
		{
			MDR[j]=tmp[i];										//wpisanie w ostateczna tablice krawedzi jesli spelniony powyzszy warunek
			int e=tabkol[tmp[i].sasiadx];
			tabkol[tmp[i].sasiadx]=tabkol[tmp[i].sasiady];		//zaznaczenie tego samego koloru	
			for(int s=0;s<rozmx;s++)							//sprawdzenie macierzy kolorow czy nowo dodane wierzcholki do drzewa nie sa polaczone juz z innymi
				if(tabkol[s]==e)
					tabkol[s]=tabkol[tmp[i].sasiady];
			
			sumawag+=MDR[j].waga;								//sumowanie wag krawedzi MDR
			j++;			
		}
	}

	
	delete tmp;
	delete tabkol;

};

/*******************************************************************************************************************/
void macierzs::wyswietlMDR()
{
	cout<<"Minimalne drzewo rozpinajace wynosi: "<<sumawag<<endl
		<<"Kolejne krawedzie to: "<<endl;
	int	j=0;
	while(MDR[j].polacz==true)
	{
		cout<<"("<<MDR[j].sasiady<<"<->"<<MDR[j].sasiadx<<")"<<endl;
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
void macierzs::prim()
{
	sumawag=0;
	krawedz *tmp;
	int kol=1;
	int pom=1;
	int i=0;
	int size=0;
	if((((((rozmx-1)*rozmx)/2)*gest)%100)>0)
		size=(((rozmx-1)*rozmx)/2)*gest/100+1;
	else
		size=(((rozmx-1)*rozmx)/2)*gest/100;					//rozmiar tablicy krawedzi
	if (size<rozmx-1)
		size=rozmx-1;
	tmp=new krawedz [size];										//tablica krawedzi
	MDR=new krawedz [rozmx-1];									//tablica krawedzi MDR
	for(int wier=0;wier<rozmy;wier++)							//idziemy po wierszach
	{													
		kol=pom;	
		for(kol;kol<rozmx;kol++)								//idziemy po kolumnach
		{														//wypelnianie tablicy krawedzi 
			if(tab[wier][kol].polacz==true)						//jesli znajdzie w macierzy polaczenie przekopiuje krawedz do tablicy krawedzi
			{
				tmp[i].sasiadx=kol;
				tmp[i].sasiady=wier;

				tmp[i].waga=tab[wier][kol].waga;
				tmp[i].polacz=tab[wier][kol].polacz;

				i++;
			}
		}
		pom++;													//przesuniecie pamieci o kolumnie poczatkowej wiersza
	}

	int *kolejka=new int [rozmx];
	for(i=0;i<rozmx;i++)
	{
		kolejka[i]=i;
	}
	
	int q=rozmx;
	int s=size;
	int r=rand() % q;

	int mini=0;
	int j=0;	
	int ktory=0;												//licznik zaznaczajacy ktora najmniejsza krawedz miedzy dwoma wierzcholkami ma byc skopiowana
	
	for(i=0;i<size;i++)										//przeszukiwanie tablicy w celu znalezienia najmniejszej krawedzi wychodzacej od wierzcholka r
		if(tmp[i].sasiady==r||tmp[i].sasiadx==r)
		{
			if(mini==0||tmp[i].waga<mini)
			{
				mini=tmp[i].waga;
				ktory=i;
			}
		};
	
	MDR[j]=tmp[ktory];
	sumawag+=MDR[j].waga;
	tmp[ktory]=tmp[s-1];
	s--;
	kolejka[MDR[j].sasiadx]=kolejka[q-1];
	q--;

	kolejka[MDR[j].sasiady]=kolejka[q-1];
	q--;
	j++;
	while(q>0)
	{
		int m=0;
		int u=j;
		int l=0;
		ktory=0;
		mini=0;
		for(i=0;i<u;i++)
		{
			for(int h=0;h<s;h++)
			{
				if(tmp[h].sasiady==MDR[i].sasiady||tmp[h].sasiadx==MDR[i].sasiady)
				{
					if(mini==0||tmp[h].waga<mini)
						for(l=0;l<q;l++)
							if(kolejka[l]==tmp[h].sasiadx || kolejka[l]==tmp[h].sasiady)
							{
								mini=tmp[h].waga;
								ktory=h;
								m=l;
							}	
				};
			
			
				if(tmp[h].sasiady==MDR[i].sasiadx||tmp[h].sasiadx==MDR[i].sasiadx)
				{
					if(mini==0||tmp[h].waga<mini)
						for(l=0;l<q;l++)
							if(kolejka[l]==tmp[h].sasiadx || kolejka[l]==tmp[h].sasiady)
							{
								mini=tmp[h].waga;
								ktory=h;
								m=l;
							}
				};
			}
		}

		MDR[j]=tmp[ktory];
		sumawag+=MDR[j].waga;
		j++;
		tmp[ktory]=tmp[s-1];
		s--;
		kolejka[m]=kolejka[q-1];
		q--;
	
	}
};



listas::listas()
{
};

listas::listas(int x, int y)
{
	rozmx=x;
	rozmy=y;
	sumawag=0;
	int i;
	int j;

	lista=new krawedz [(rozmx-1)*rozmx/2];
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

listas::~listas()
{
};

void listas::wypelnij(int f)
{
	gest=f;
	int i=0;
	int kol=1;
	int pom=1;													//'pamiec' o kolumnie od ktorej zaczynamy kolejny wiersz w macierzy trojkatnej gornej	
								
	komorka *tmp=new komorka [((rozmx-1)*rozmx)/2];             //pomocnicza tablica komorek o rozmiarze ilosci krawedzi

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
	
		tab[tmp[r].y][tmp[r].x].waga=l;							//Wypelnianie gornej czeœci macierzy
		tab[tmp[r].y][tmp[r].x].polacz=true;
		tab[tmp[r].y][tmp[r].x].sasiadx=tmp[r].x;
		tab[tmp[r].y][tmp[r].x].sasiady=tmp[r].y;
		
		tab[tmp[r].x][tmp[r].y].waga=l;							//wypelnianie dolnej czesci macierzy
		tab[tmp[r].x][tmp[r].y].polacz=true;
		tab[tmp[r].x][tmp[r].y].sasiadx=tmp[r].y;
		tab[tmp[r].x][tmp[r].y].sasiady=tmp[r].x;
		tmp[r]=tmp[q-1];											//zmiana ostatniego elementu z wylosowanym (usuniecie wylosowanego elementu)
		q--;													//zmniejszenie zakresu losowania (unikniecie podwojnego losowania)
	}
	
	int	z=rozmx-1;												//zmienna liczaca ile polaczen pozostalo do uzupelnienia(niezbedna do ostatniej petli)
	for(int j=0;j<rozmy;j++)									//Sprawdzanie czy w danym wierszu nie wystepuje brak polaczen(sprawdzanie spojnosci grafu)
	{
		for(int o=0;o<rozmx;o++)
		{
			if(tab[j][o].polacz==true)
				break;
			else
			{
				if(o==(rozmx-1))
				{										
					int l=(rand() % N)+1;							//ZAKRES LOSOWANIA WAG
					int k=rand() % rozmx;
					while(k==j)
						k=rand() % rozmx;

					tab[j][k].waga=l;
					tab[j][k].polacz=true;
					tab[j][k].sasiadx=k;
					tab[j][k].sasiady=j;
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


					tab[k][j].waga=l;
					tab[k][j].polacz=true;
					tab[k][j].sasiadx=j;
					tab[k][j].sasiady=k;
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
			tab[tmp[r].y][tmp[r].x].waga=l;							//Wypelnianie gornej czeœci macierzy
			tab[tmp[r].y][tmp[r].x].polacz=true;
			tab[tmp[r].y][tmp[r].x].sasiadx=tmp[r].x;
			tab[tmp[r].y][tmp[r].x].sasiady=tmp[r].y;
		
			tab[tmp[r].x][tmp[r].y].waga=l;							//wypelnianie dolnej czesci macierzy
			tab[tmp[r].x][tmp[r].y].polacz=true;
			tab[tmp[r].x][tmp[r].y].sasiadx=tmp[r].y;
			tab[tmp[r].x][tmp[r].y].sasiady=tmp[r].x;
			tmp[r]=tmp[q-1];
			q--;
		}
		else
		{
			int r=0;
			int l=(rand() % N)+1;
			tab[tmp[r].y][tmp[r].x].waga=l;							//Wypelnianie gornej czeœci macierzy
			tab[tmp[r].y][tmp[r].x].polacz=true;
			tab[tmp[r].y][tmp[r].x].sasiadx=tmp[r].x;
			tab[tmp[r].y][tmp[r].x].sasiady=tmp[r].y;
		
			tab[tmp[r].x][tmp[r].y].waga=l;							//wypelnianie dolnej czesci macierzy
			tab[tmp[r].x][tmp[r].y].polacz=true;
			tab[tmp[r].x][tmp[r].y].sasiadx=tmp[r].y;
			tab[tmp[r].x][tmp[r].y].sasiady=tmp[r].x;
			tmp[r]=tmp[q-1];
		}
	}
	delete tmp;
	
	size=0;
	kol=1;
	pom=1;
	i=0;
	if((((((rozmx-1)*rozmx)/2)*gest)%100)>0)
		size=(((rozmx-1)*rozmx)/2)*gest/100+1;
	else
		size=(((rozmx-1)*rozmx)/2)*gest/100;					//rozmiar tablicy krawedzi
	if (size<rozmx-1)
		size=rozmx-1;
	lista=new krawedz [size];

	for(int wier=0;wier<rozmy;wier++)							//idziemy po wierszach
	{													
		kol=pom;	
		for(kol;kol<rozmx;kol++)								//idziemy po kolumnach
		{														//wypelnianie tablicy krawedzi 
			if(tab[wier][kol].polacz==true)						//jesli znajdzie w macierzy polaczenie przekopiuje krawedz do tablicy krawedzi
			{
				lista[i].sasiadx=kol;
				lista[i].sasiady=wier;

				lista[i].waga=tab[wier][kol].waga;
				lista[i].polacz=tab[wier][kol].polacz;

				i++;
			}
		}
		pom++;													//przesuniecie pamieci o kolumnie poczatkowej wiersza
	}

}

void listas::kruskal()
{
	sumawag=0;
	quicksort sortowanie;
	krawedz *tmp;
	int kol=1;
	int pom=1;
	int i=0;
	int size=0;
	if((((((rozmx-1)*rozmx)/2)*gest)%100)>0)
		size=(((rozmx-1)*rozmx)/2)*gest/100+1;
	else
		size=(((rozmx-1)*rozmx)/2)*gest/100;					//rozmiar tablicy krawedzi
	if (size<rozmx-1)
		size=rozmx-1;
	tmp=new krawedz [size];										//tablica krawedzi
	MDR=new krawedz [rozmx-1];									//tablica krawedzi MDR
	for(i=0;i<size;i++)
	{
		tmp[i].sasiadx=lista[i].sasiadx;
		tmp[i].sasiady=lista[i].sasiady;

		tmp[i].waga=lista[i].waga;
		tmp[i].polacz=lista[i].polacz;
	};

	int *tabkol=new int [rozmx];									//tablica kolorow
	for(i=0;i<rozmx;i++)
	{
		tabkol[i]=i;
	}

	sortowanie.sort(tmp,0,size-1);
	int j=0;
	

	for(i=0;i<size;i++)
	{
		if(tabkol[tmp[i].sasiadx]!=tabkol[tmp[i].sasiady])		//porownanie kolorow w tablicy na wspolrzednych sasiadow danej krawedzi
		{
			MDR[j]=tmp[i];										//wpisanie w ostateczna tablice krawedzi jesli spelniony powyzszy warunek
			int e=tabkol[tmp[i].sasiadx];
			tabkol[tmp[i].sasiadx]=tabkol[tmp[i].sasiady];		//zaznaczenie tego samego koloru	
			for(int s=0;s<rozmx;s++)								//sprawdzenie macierzy kolorow czy nowo dodane wierzcholki do drzewa nie sa polaczone juz z innymi
				if(tabkol[s]==e)
					tabkol[s]=tabkol[tmp[i].sasiady];
			
			sumawag+=MDR[j].waga;								//sumowanie wag krawedzi MDR
			j++;			
		}
	}

	
	delete tmp;
	delete tabkol;

}

void listas::wyswietl()
{
	cout<<"Lista wag:"<<endl;
	int i=0;
	while(lista[i].polacz==true)
	{
		cout<<lista[i].sasiady<<" "<<lista[i].sasiadx<<" "<<lista[i].waga<<endl;
		i++;
	}
	cout<<endl;
	
}

void listas::wyswietlMDR()
{
	cout<<"Minimalne drzewo rozpinajace wynosi: "<<sumawag<<endl
		<<"Kolejne krawedzie to: "<<endl;
	int	j=0;
	while(MDR[j].polacz==true)
	{
		cout<<"("<<MDR[j].sasiady<<"<->"<<MDR[j].sasiadx<<")"<<endl;
		j++;
	}
}

void listas::prim()
{
	sumawag=0;
	krawedz *tmp;

	int i=0;
	int size=0;
	if((((((rozmx-1)*rozmx)/2)*gest)%100)>0)
		size=(((rozmx-1)*rozmx)/2)*gest/100+1;
	else
		size=(((rozmx-1)*rozmx)/2)*gest/100;					//rozmiar tablicy krawedzi
	if (size<rozmx-1)
		size=rozmx-1;
	tmp=new krawedz [size];										//tablica krawedzi
	MDR=new krawedz [rozmx-1];									//tablica krawedzi MDR
	for(i=0;i<size;i++)
	{
		tmp[i].sasiadx=lista[i].sasiadx;
		tmp[i].sasiady=lista[i].sasiady;

		tmp[i].waga=lista[i].waga;
		tmp[i].polacz=lista[i].polacz;
	};

	

	int *kolejka=new int [rozmx];
	for(i=0;i<rozmx;i++)
	{
		kolejka[i]=i;
	}
	
	int q=rozmx;
	int s=size;
	int r=rand() % q;

	int mini=0;
	int j=0;	
	int ktory=0;												//licznik zaznaczajacy ktora najmniejsza krawedz miedzy dwoma wierzcholkami ma byc skopiowana
	
	for(i=0;i<size;i++)											//przeszukiwanie tablicy w celu znalezienia najmniejszej krawedzi wychodzacej od wierzcholka r
		if(tmp[i].sasiady==r||tmp[i].sasiadx==r)
		{
			if(mini==0||tmp[i].waga<mini)
			{
				mini=tmp[i].waga;
				ktory=i;
			}
		};
	
	MDR[j]=tmp[ktory];
	sumawag+=MDR[j].waga;
	tmp[ktory]=tmp[s-1];
	s--;
	kolejka[MDR[j].sasiadx]=kolejka[q-1];
	q--;

	kolejka[MDR[j].sasiady]=kolejka[q-1];
	q--;
	j++;
	while(q>0)
	{
		int m=0;
		int u=j;
		int l=0;
		ktory=0;
		mini=0;
		for(i=0;i<u;i++)
		{
			for(int h=0;h<s;h++)
			{
				if(tmp[h].sasiady==MDR[i].sasiady||tmp[h].sasiadx==MDR[i].sasiady)
				{
					if(mini==0||tmp[h].waga<mini)
						for(l=0;l<q;l++)
							if(kolejka[l]==tmp[h].sasiadx || kolejka[l]==tmp[h].sasiady)
							{
								mini=tmp[h].waga;
								ktory=h;
								m=l;
							}	
				};
			
			
				if(tmp[h].sasiady==MDR[i].sasiadx||tmp[h].sasiadx==MDR[i].sasiadx)
				{
					if(mini==0||tmp[h].waga<mini)
						for(l=0;l<q;l++)
							if(kolejka[l]==tmp[h].sasiadx || kolejka[l]==tmp[h].sasiady)
							{
								mini=tmp[h].waga;
								ktory=h;
								m=l;
							}
				};
			}
		}

		MDR[j]=tmp[ktory];
		sumawag+=MDR[j].waga;
		j++;
		tmp[ktory]=tmp[s-1];
		s--;
		kolejka[m]=kolejka[q-1];
		q--;
	
	}
}
