#include "lista.h"


using namespace std;

ogniwo::ogniwo() 
{
	waga = 0;
	nast = NULL;
};

ogniwo::ogniwo(int x,int w) 
{ 
	waga=w;
	sasiadx=x;
	nast=NULL; 
};

lista::lista() 
{
	dlugosc = 0;
	glowa = NULL;
	ogon = NULL;
	iter = NULL;
};


// dodaj element na poczatek
void lista::push_front(int x,int w) 
{

	if(dlugosc==0)      // czy lista jest pusta
	{ 
		glowa = new ogniwo(x,w);
		ogon = glowa;
		dlugosc++;
	}
	else 
	{
		ogniwo * temp = new ogniwo(x,w);
		temp->nast = glowa; 
		glowa = temp;
		dlugosc++;
	}
};


// dodaj element na koniec   
void lista::push_back(int x,int w) 
{ 
 
	if(dlugosc==0)       // czy lista jest pusta
	{ 
		ogon = new ogniwo(x,w);
		glowa = ogon;
		dlugosc++;
	}
	else 
	{
		ogniwo * temp = new ogniwo(x,w);
		ogon->nast = temp; 
		ogon = temp;
		dlugosc++;
	}
}; 

 // wyjmij element z konca listy
void lista::pop_back() 
{	
	iter=glowa;
	if(dlugosc!=0)
	{
		for(int i=1;i<dlugosc-1;i++)
			iter=glowa->nast;
		delete ogon;
		ogon = iter;
		dlugosc--;
	}
	else cout<<"Pusta lista";
}

// wyjmij element z poczatku listy
void lista::pop_front() 
{
	
	iter = glowa->nast;
	if(dlugosc!=0) 
	{
		delete glowa;
		glowa=iter;
		dlugosc--;
	}
	else cout<<"Pusta lista";
}

// wypisz wszystkie elementy listy
void lista::print() 
{
	
	iter = glowa;

	if(dlugosc!=0) 
	{
		for(int i=0; i<dlugosc; i++) 
		{
			cout << iter->waga << " ";
			iter=iter->nast;
		}
		cout<<endl;
	} 
	else cout<<"Pusta lista";
};
