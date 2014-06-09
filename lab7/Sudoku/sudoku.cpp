

#include "stdafx.h"
#include "Plansza.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	/********************************************************/
	/*	zeby wyjsc z wpisywania recznego nalezy nacisnac	*/
	/*					k "endl" k "endl"					*/
	/*	liczba wprowadza sie w jednym z dwoch formatow:		*/
	/*	- liczbaliczbaliczba								*/
	/*	- liczba liczba liczba								*/
	/*														*/
	/*	zapisanie z menu nastepuje do tego samego pliku		*/
	/*	z ktorego wczytuje (sudoku.txt)						*/
	/*														*/
	/*	program po rozwiazaniu zapisuje do pliku			*/
	/*	sudoku_rozwiazanie.txt								*/
	/********************************************************/

	Plansza test;

	int procent, wier;

	clock_t beginn, end, find=0;
	
	char menu = '9', opcja='1';

	cout << "!!!!!!!!!!!!!!!!!!!!!!!!    Wazne    !!!!!!!!!!!!!!!!!!!!!!!!" << endl << endl
	<< "/************************************************************/" << endl
	<< "/*	zeby wyjsc z wpisywania recznego nalezy nacisnac    */" << endl
	<< "/*	k '/n' k '/n'                                       */" << endl
	<< "/*	                                                    */" << endl
	<< "/*	liczba wprowadza sie w jednym z dwoch formatow:     */" << endl
	<< "/*	- liczbaliczbaliczba                                */" << endl
	<< "/*	- liczba liczba liczba                              */" << endl
	<< "/*	                                                    */" << endl
	<< "/*	zapisanie z menu nastepuje do tego samego pliku     */" << endl
	<< "/*	z ktorego wczytuje (sudoku.txt)                     */" << endl
	<< "/*	                                                    */" << endl
	<< "/*	program rozwiazanie zapisuje do pliku               */" << endl
	<< "/*	sudoku_rozwiazanie.txt                              */" << endl
	<< "/************************************************************/" << endl << endl;

	system("pause");
	system("cls");

	while (menu!='0'){//petla menu

	switch (menu)
	{

	case '1': //reczne utorzenie sudoku
		test.clear();
		test.print();
		opcja='1';

		while (opcja!='k')
		{
		test.print();
		cout << "Wpisz dane wejsciowe: ";
		if (!test.insert_3()) opcja='k';
		}
	break;

	case '2': //wczytanie sudoku z pilku
		test.open();
	break;

	case '3': //zapis sudoku do pliku
		test.save('n');
	break;
	
	case '4': //reczne rozwiazanie sudoku
		test.hand_play();
	break;

	case '5': //szybkie rozwiazanie sudoku
		beginn = clock();
		test.resolve('n');
		end = clock();
		find = difftime(end, beginn);
		test.print();
		cout << "Znaleziono sudoku w " << find << "ms" << endl;
	break;
	
	case '6': //szybkie rozwiazanie sudoku
		beginn = clock();
		test.resolve('l');
		end = clock();
		find = difftime(end, beginn);
		test.print();
		cout << "Znaleziono sudoku w " << find << "ms" << endl;
	break;

	case '7'://wyswietlenie sudoku
		test.print();
	break;

	case '8'://inne wprowadzenie
		test.insert_1();
		break;
	
	case '9': //wyswietlenie menu
		cout << "Menu" << endl
			<< "1-reczne utorzenie sudoku" << endl
			<< "2-wczytanie sudoku z pilku" << endl
			<< "3-zapis sudoku do pliku" << endl
			<< "4-reczne rozwiazanie sudoku" << endl
			<< "5-szybkie rozwiazanie sudoku" << endl
			<< "6-ladne rozwiazanie sudoku" << endl
			<< "7-wyswietlenie sudoku" << endl
			<< "9-wyswietlenie menu" << endl
			<< "0-zakoncz program" << endl << endl;
	break;

	default:
		cout << "Bledna opcja" << endl;
		cin.ignore(10000,'\n');//wyczyszczenie bufora
	}
	
	cout << endl << "Wybierz opcje <9-menu>: ";
	cin >> menu;
	cout << endl;

	}//koniec petli
	return 0;
}


