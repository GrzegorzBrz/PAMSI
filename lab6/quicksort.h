

using namespace std;



class zadanie{
public:
	int *tab;
	int maszy;
	int suma;

	zadanie(int n);
	void sum();
};

class quicksort
{
public:
	quicksort();
	~quicksort();
	void sort(zadanie tab[], int pocz, int kon);
};