
#include "kolejka.h"
#include <tchar.h>
#include <iostream>

using namespace std;

ogniwa::ogniwa() 
{
	dane = 0;
	nast = NULL;
}

ogniwa::ogniwa(int danetym) 
{ 
	dane = danetym; 
	nast = NULL; 
}

kolejka::kolejka() 
{
	dlugosc = 0;
	poczatek = NULL;
	iter = NULL;
	ogon=NULL;
}

// spradz czy kolejki jest pusta
bool kolejka::empty() 
{	
	if(dlugosc==0) return true;
	else return false;
}

// dodaj element na koniec   
void kolejka::push(int dane) 
{ 
 
	if(this->empty())       // czy kolejki jest pusta
	{ 
		ogon = new ogniwa(dane);
		poczatek = ogon;
		dlugosc++;
	}
	else 
	{

		ogniwa * temp = new ogniwa(dane);
		ogon->nast = temp; 
		ogon = ogon->nast;
		dlugosc++;
	}
} 
// wyjmij element z poczatku kolejki
void kolejka::pop() 
{
	if(dlugosc!=0) 
	{
		iter=poczatek->nast;
		delete poczatek;
		poczatek = iter;
		dlugosc--;
		
	}
	else cout<<"Pusta kolejka";
}


// wypisz wszystkie elementy kolejki
void kolejka::print() 
{
	
	iter = poczatek;

	if(!(this->empty())) 
	{
			cout << iter->dane << " ";
		    cout<<endl;
	} 
	else cout<<"Pusta kolejka";
}


// wypisz ilosc elementow kolejki

int kolejka::size() 
{
	return dlugosc;
}

bool kolejka::inqueue(int x)
{
	int i;
	iter=poczatek;
	if(dlugosc==0)
		return false;
	for(i=0;i<dlugosc;i++)
	{
		if(iter->dane==x)
		{
			i=dlugosc;
			return true;
			break;
		}
		if(iter->dane!=x && i==dlugosc-1)
		{
			return false;
			break;
		};
		iter=iter->nast;
	};
};


void kolejka::prio(int dane)
{
	if(dlugosc==0)
	{
		ogon = new ogniwa(dane);
		poczatek = ogon;
		dlugosc++;
	}
	else
	{
		ogniwa * temp = new ogniwa(dane);
		iter=poczatek;
		poczatek=temp;
		poczatek->nast=iter;
		dlugosc++;
	}
	
};