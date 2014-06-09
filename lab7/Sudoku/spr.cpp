#include "StdAfx.h"
#include "spr.h"
using namespace std;

spr::spr(void)
{
	tab_op=new int*[9];
	for (int k=0; k<9; k++)
	{
		tab_op[k]=new int[9];
	}
	for (int a=0; a<9; a++)
	{
		for (int b=0; b<9; b++)
		{
			for (int c=0; c<9; c++) 
				tab_rep[a][b][c]=0;
		}
	}
}

spr::~spr(void)
{
	for (int i=0; i<9; i++) delete [] tab_op[i]; 
	delete tab_op;
}

void spr::set_line (int number)
{
	switch (number)
	{
	case 0:
		i=0;
		j=0;
		ik=1;
		jk=9;
		break;

	case 1:
		i=1;
		j=0;
		ik=2;
		jk=9;
		break;

	case 2:
		i=2;
		j=0;
		ik=3;
		jk=9;
		break;

	case 3:
		i=3;
		j=0;
		ik=4;
		jk=9;
		break;

	case 4:
		i=4;
		j=0;
		ik=5;
		jk=9;
		break;

	case 5:
		i=5;
		j=0;
		ik=6;
		jk=9;
		break;

	case 6:
		i=6;
		j=0;
		ik=7;
		jk=9;
		break;

	case 7:
		i=7;
		j=0;
		ik=8;
		jk=9;
		break;

	case 8:
		i=8;
		j=0;
		ik=9;
		jk=9;
		break;

	default:
		cout << "Blad spr_set_line. Podano number = " << number << endl << endl;
	}
}

void spr::set_sq (int number)
{
	switch (number)
	{
	case 0:
		i=0;
		j=0;
		ik=3;
		jk=3;
		break;

	case 1:
		i=0;
		j=3;
		ik=3;
		jk=6;
		break;

	case 2:
		i=0;
		j=6;
		ik=3;
		jk=9;
		break;

	case 3:
		i=3;
		j=0;
		ik=6;
		jk=3;
		break;

	case 4:
		i=3;
		j=3;
		ik=6;
		jk=6;
		break;

	case 5:
		i=3;
		j=6;
		ik=6;
		jk=9;
		break;

	case 6:
		i=6;
		j=0;
		ik=9;
		jk=3;
		break;

	case 7:
		i=6;
		j=3;
		ik=9;
		jk=6;
		break;

	case 8:
		i=6;
		j=6;
		ik=9;
		jk=9;
		break;

	default:
		cout << "Blad spr_set_sq. Podano number = " << number << endl << endl;
	}
}

void spr::set_pil (int number)
{
	switch (number)
	{
	case 0:
		i=0;
		j=0;
		ik=9;
		jk=1;
		break;

	case 1:
		i=0;
		j=1;
		ik=9;
		jk=2;
		break;

	case 2:
		i=0;
		j=2;
		ik=9;
		jk=3;
		break;

	case 3:
		i=0;
		j=3;
		ik=9;
		jk=4;
		break;

	case 4:
		i=0;
		j=4;
		ik=9;
		jk=5;
		break;

	case 5:
		i=0;
		j=5;
		ik=9;
		jk=6;
		break;

	case 6:
		i=0;
		j=6;
		ik=9;
		jk=7;
		break;

	case 7:
		i=0;
		j=7;
		ik=9;
		jk=8;
		break;

	case 8:
		i=0;
		j=8;
		ik=9;
		jk=9;
		break;

	default:
		cout << "Blad spr_set_pil. Podano number = " << number << endl << endl;
	}
}

bool spr::solution(int ** tab,char qq)
{
	//przepisanie tablicy do operacyjnej
	for (int a=0; a<9; a++)
	{
		for (int b=0; b<9; b++)
		{
			tab_op[a][b]=tab[a][b];
		}
	}


	if (function(qq)) //jest rozwiazanie
	{
		for (int a=0; a<9; a++)
		{
			for (int b=0; b<9; b++)
			{
				tab[a][b]=tab_op[a][b];
			}
		}
		return true;
	}
	return false;
}

//true -> pelna
// false -> trzeba cofnac
bool spr::function(char tt)
{
	if (tt=='l')
	{
		print();
		zzz();
	}
	int min=find_min_capa();
	//cout << "min " << min +11 << endl;
	if (min==-1) 
		return false;

	while (check_full(min/10,min%10))	//mozna cos wstawic
	{

		int now=this->find_first_to_write(min/10, min%10);
		//cout <<"now "<< now << endl;
		if (!now)
		{
			return false;
		}
		tab_op[min/10][min%10]=now;
		function(tt);
		if (finish()) 
		{
			return true;
		}
		else
		{
			tab_op[min/10][min%10]=0;
			tab_rep[min/10][min%10][now-1]=1;
		}
	}
	clear_rep(min/10,min%10);
	return false;
}

//x*10+y
int spr::find_min_capa()
{
	int now_rep=9;	//liczy powtorzenia
	int past_rep=9;
	int xm=-1, ym=-1;		//pole z minimalna liczba powtorzen

	for (int a=0; a<9; a++)
	{
		for (int b=0; b<9; b++)
		{
			if (!tab_op[a][b])
			{
				now_rep=0;
				for (int c=1; c<10; c++)
				{
					if (check_number(c,a,b)) 
						now_rep++;
				}
				if (!now_rep) return -1;
				if (now_rep<past_rep) 
				{
					past_rep=now_rep;
					xm=a;
					ym=b;
				}
			}
		}
	}
	if (xm==-1 && ym==-1) return -1;
	return xm*10+ym;
}

//true -> liczba sie nie powtarza
//false -> liczba bedize sie powtarzac
bool spr::check_number(int number, int x, int y)
{
	if (tab_rep[x][y][number-1])
		return false;

	for (set_line(x);i<ik;i++)
	{
		for (;j<jk;j++)
		{
			if (tab_op[i][j]==number) 
				return false;
		}
	}

	for (set_pil(y);j<jk;j++)
	{
		for (;i<ik;i++)
		{
			if (tab_op[i][j]==number) return false;
		}
	}

	set_sq(3*(x/3)+(y/3));
	int aa=i;
	int bb=j;
	for (i=aa;i<ik;i++)
	{
		for (j=bb;j<jk;j++)
		{
			if (tab_op[i][j]==number) 
				return false;
		}
	}
	return true;
}

//true -> niepelny
// fasle -> pelny
int spr::check_full(int x, int y)
{
	for (int a=1; a<10; a++)
	{
		if (check_number(a,x,y))
			return true;
	}
	return false;
}

// true->pelny
// false -> niepelny
bool spr::finish()
{
	for (int a=0; a<9; a++)
	{
		for (int b=0; b<9; b++)
		{
			if (!tab_op[a][b]) 
				return false;
		}
	}
	return true;
}

//zwraca pierwsza dostepna liczba
int spr::find_first_to_write(int x, int y)
{
	for (int a=1; a<10; a++)
	{
		if (check_number(a,x,y)) 
			return a;
	}
	return 0;
}

void spr::clear_rep(int x, int y)
{
	for (int a=0; a<9; a++)
	{
		tab_rep[x][y][a]=0;
	}
}

void spr::print()
{
	system ("cls");
	cout << "-------------------------" << endl;
	for (int i=0; i<9; i++)
	{
		cout << "| ";
		for (int j=0; j<9; j++)
		{
			if (!tab_op[i][j]) cout << " ";
			else cout << tab_op[i][j];
			if (j%3==2) cout << " | ";
			else cout << " ";

		}
		if (i%3==2) cout << endl << "-------------------------" << endl;
		else cout << endl;
	}
	cout << endl;
}
