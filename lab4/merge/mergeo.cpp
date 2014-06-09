#include "mergeo.h"


scal::scal(void)
{
}


scal::~scal(void)
{
}


void scal::merge(int * tab, int left, int right)
{
	int size = right - left+ 1; 
	int mid = (left+right)/2;
	int now = 0;
	int * pom=new int [size];
	int one = left, two= mid + 1;

	while((one<= mid) && (two<= right))
	{
		if(tab[one] < tab[two])
		{
			pom[now] = tab[one];
			one++;
		} else 
		{
			pom[now] = tab[two];
			two++;
		}
		now++;
	}
	while(one <= mid)
	{
		pom[now] = tab[one];
		one++;
		now++;
	}
	while(two <= right)
	{
		pom[now] = tab[two];
		two++;
		now++;
	}
	for(int i = 0; i< size; i++)
	{ 
		tab[left+i] = pom[i];
	}
	delete [] pom; 
}


void scal::sort(int * tab, int left, int right)
{

	if(left + 1 < right)
	{
		sort(tab, left, (right+left)/2);
		sort(tab, (right+left)/2+1, right);
	}
	merge(tab, left, right);
}
