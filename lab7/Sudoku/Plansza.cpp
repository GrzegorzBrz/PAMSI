#include "StdAfx.h"
#include "Plansza.h"

Plansza::Plansza(void)
{
	tab=new int*[9];
	for (int i=0; i<9; i++)
	{
		tab[i]=new int[9];
	}
	this->clear();
}


Plansza::~Plansza(void)
{
	for (int i=0; i<9; i++) delete [] tab[i]; 
	delete tab;
}

void Plansza::clear()
{
	for (int i=0; i<9; i++)
	{
		for (int j=0; j<9; j++)
		{
			tab[i][j]=0;
		}
	}
}


void Plansza::insert_1()
{
	clear();
	int liczba=-1;
	for (int i=0; i<9; i++)
	{
		for (int j=0; j<9; j++)
		{
			tab[i][j]=11;
			print();
			cout << "Wprowadz liczbe do komorki " 
				<< i+1 << "," << j+1 << " :";
			for (;liczba>9 || liczba<0;) cin >> liczba;
			tab[i][j]=liczba;
			liczba=-1;
		}
	}
}
//
////lepsze
//void Plansza::insert_2()
//{
//	clear();
//	int x=-1, y=-1, liczba=-1;
//	char koniec='0';
//
//	while (koniec=='0')
//	{
//		cout << "Wprowadz numer pola 'x_y_wartosc' :";
//		//for (;x>9 || x<1;cin >> x) cout << "x:";
//		//for (;y>9 || y<1;cin >> y) cout << "y:";
//		//for (;liczba>9 || liczba<1;cin >> liczba) cout << "wartosc:";
//		cin >> x;
//		cin >> y;
//		cin >> liczba;
//
//		if (x>9 || x<1)
//		{
//			cout << "Wprowadzono zla wartosc 'x'." << endl
//				<< "Wprowadz ja poprawnie: ";
//			for (;x>9 || x<1;) cin >> x;
//		}
//
//		if (y>9 || y<1)
//		{
//			cout << "Wprowadzono zla wartosc 'y'." << endl
//				<< "Wprowadz ja poprawnie: ";
//			for (;y>9 || y<1;) cin >> y;
//		}
//
//		if (liczba>9 || liczba<1)
//		{
//			cout << "Wprowadzono zla wartosc pola." << endl
//				<< "Wprowadz ja poprawnie: ";
//			for (;liczba>9 || liczba<1;) cin >> liczba;
//		}
//
//		tab[x-1][y-1]=liczba;
//		//liczba=x=y=-1;
//
//		cout << "Zakonczyc wpisywanie? <y> :";
//		cin >> koniec;
//		if (koniec=='y') koniec='1';
//		else koniec='0';
//	}
//}


bool Plansza::insert_3()
{
	int liczba[3]={-1,-1,-1};
	int flag=0, number=0;

	while (!flag)
	{
		if (cin.get()=='k') {
			return false;
			break;
		}

		cin >> liczba[number];
		if (cin.fail()) 
		{
			print();
			for (int a=0; a<number;a++) cout << liczba[a] << " ";
			cout << endl;
			cout << "Liczba zostala blednie wprowadzona."	<< endl;
			cin.clear();            // Reset znacznikow bledu
			cin.ignore(10000,'\n'); // Ignorowanie wszystkich znakow,
		}
		else if (liczba[0] >109 && liczba [0] <1000)
		{
			flag=2;
		}
		else if (liczba[number]>9 || liczba[number]<1)
		{
			print();
			for (int a=0; a<number;a++) cout << liczba[a] << " ";
			cout << endl;
			cout << "Przekroczona wartosc."	<< endl;
		}
		else
		{
			number++;
			if (number>2)flag=1;
		}
	}
	if (flag==1) 
		tab[liczba[0]-1][liczba[1]-1]=liczba[2];
	if (flag==2) 
		tab[(liczba[0]/100)-1][((liczba[0]%100)/10)-1]=liczba[0]%10;
	return true;
}

//wczytanie z pliku
bool Plansza::open()
{
	fstream file;

	file.open( "sudoku.txt");
	if( file.good() == true )
	{
		cout << "Otwarto plik do odczytu" << endl;

		clear();

		for (int i=0; i<9; i++){
			for (int j=0; j<9; j++)	file>>tab[i][j];
		}
	} 

	else 
	{
		cout << "Oczyt nie powiodl sie" << endl;
		return false;
	}
	return true;
}

//zapisanie do pliku
bool Plansza::save(char aa)
{
	fstream file;

	if (aa=='r') file.open( "sudoku_rozwiazane.txt");
	if (aa=='n') file.open( "sudoku.txt");
	if( file.good() == true )
	{
		cout << "Otwarto plik do zapisu" << endl;

		for (int i=0; i<9; i++)
		{
			for (int j=0; j<9; j++)	file << tab[i][j] << " ";
			file << endl;
		}
	} 

	else 
	{
		cout << "Odczyt nie powiodl sie" << endl;
		return false;
	}
	return true;
}

void Plansza::print()
{
	system ("cls");
	cout << "   ";
	for (int i=0; i<9; i++) 
	{
		cout << i+1 << " ";
		if (i%3==2) cout << "  ";
	}
	cout << endl << " -------------------------" << endl;
	for (int i=0; i<9; i++)
	{
		cout << i+1 << "| ";
		for (int j=0; j<9; j++)
		{
			if (!tab[i][j]) cout << " ";
			else cout << tab[i][j];
			if (j%3==2) cout << " | ";
			else cout << " ";

		}
		if (i%3==2) cout << endl << " -------------------------" << endl;
		else cout << endl;
	}
	cout << endl;
}

void Plansza::hand_play()
{
	system("cls");
	cout << "Wczytac dane z pliku? <y> ";
	char opcja;
	cin >> opcja;
	if (opcja=='y') open();
	opcja='1';

	while (opcja!='k')
	{
		this->print();
		cout << "Wpisz dane wejsciowe: ";
		if (!this->insert_3()) 
			opcja='k';
	}
}

void Plansza::resolve(char aa)
{
	spr cos;
	cos.solution(tab,aa);
}
