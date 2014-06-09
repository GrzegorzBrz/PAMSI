
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>

#include <windows.h>
using namespace std;
class spr
{
	int i;
	int j;
	int ik;
	int jk;
	int ** tab_op;
	int tab_rep[9][9][9];//1->powtorzenie
public:
	spr(void);
	~spr(void);
	void set_line(int);		//linia
	void set_sq(int);		//kwadrat
	void set_pil(int);		//kolumna

	void zzz(){Sleep(40);};
	void print();
	bool solution(int**,char);	//glowna funkcja rozwiazujaca
	bool function (char);	//funkcja rekurencyjna
	int find_min_capa();	//znjadz komorke o najmniejszej liczbie mozliwosci
	bool check_number(int,int,int);		//sprawdza czy mozna wpisac bez powtorzen dana liczba w dane pole
	int check_full(int,int);	//sprawdza czy w dane pole mozna jeszcze cos wpisac
	bool finish();
	int find_first_to_write(int, int);	//wpisuje pierwsza dostepna do wpisania
	void clear_rep(int,int);	//czysci uzupelnione liczby dla danego pola
};

