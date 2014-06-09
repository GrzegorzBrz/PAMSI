
#include "spr.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
using namespace std;
class Plansza
{
	int **tab;
public:
	Plansza(void);
	~Plansza(void);

	void clear();
	void print();
	void insert_1();
	void insert_2();
	bool insert_3();
	bool open();
	bool save(char);

	void hand_play();
	void resolve(char);
};

