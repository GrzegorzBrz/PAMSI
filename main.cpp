#include <iostream>
#include <stddef.h>
#include <fstream>


using namespace std;

// ZADANIE 1

char* tablica(int rozmiar){
	char *tablica=new char[rozmiar];
	return tablica;
};

char* kopiujTab(int rozmiar,char *tab){
	
	char *temp=new char[rozmiar];
	for(int i=0;i<rozmiar;i++)
		temp[i]=tab[i];

	return temp;
};

void usun(char *tab){
	delete tab;
};


char* zmienrozm(int rozmiar, int &nrozmiar, char *tab){
	
	char *temp=new char[nrozmiar];
	for(int i=0;i<rozmiar;i++)
		temp[i]=tab[i];
	if(nrozmiar>rozmiar)
		for(int i=rozmiar;i<nrozmiar;i++)
			temp[i]=0;

	return temp;
};

char* wczytaj_plik(char *tablica, size_t rozmiar,std::istream& in){

	for(int i=0;i<rozmiar;i++)
		in>>tablica[i];
	return tablica;
};

char* zapisz_plik(char *tablica, int rozmiar, std::ostream& out){

	for(int i=0;i<rozmiar;i++)
		out<<tablica[i];
	return tablica;
};

char* wyswietl(int rozmiar, char *tablica){
	for(int i=0;i<rozmiar;i++)
		cout<<tablica[i]<<endl;
	return tablica;
};



void main(){
	char *tab=new char[12];
	for(int i=0;i<12;i++)
		tab[i]=i;
	zapisz_plik(tab,12,cout);
	system("pause");
}