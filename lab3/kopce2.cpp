#include <iostream>

using namespace std;
//#define s 100


template <class T>
class heaps{
public:
	T *tab;
	int rozmiar;
	heaps();
	heaps(int s);
	~heaps();
	heaps<T>& operator=(const heaps <T> &wz);
	heaps(const heaps <T> &kopiec);
	void swaps(heaps <T> k);
	void insert(const T &k);

	int parent(int ind);
	int left(int ind);
	int right(int ind);
	void up(int ind);
	void down(int ind);
	T top();
	void pop();
	T take(int ind);
	void remove(int ind);
	void decreased(int ind);
	void increased(int ind);
	void merge(heaps <T> k);
};

template <class T>
heaps<T>::heaps(){
	tab=NULL;
	rozmiar=NULL;
}


template <class T>
heaps<T>::heaps(int s){
	tab=new T [s];
	rozmiar=s;
	for(int i=0;i<rozmiar;i++)
		tab[i]=NULL;
}

template <class T>
heaps<T>::~heaps(){
	rozmiar=NULL;
	delete tab;
}

template <class T>
heaps<T>& heaps<T>::operator=(const heaps <T> & wz)
{
	if (tab==NULL && rozmiar==NULL){
		tab=new T [wz.rozmiar];
		rozmiar=wz.rozmiar;
	}
	for(int i=0;i<rozmiar;i++)
		tab[i]=wz.tab[i];
	return *this;
}

template <class T>
heaps <T>::heaps(const heaps <T> &kopiec){
	rozmiar=kopiec.rozmiar;
	tab=new T [rozmiar];
	for(int i=0;i<rozmiar;i++)
		tab[i]=kopiec.tab[i];
}

template <class T>
void heaps <T>::swaps(heaps <T> k){
	T tmp;
	for(int i=0;i<rozmiar;i++){
		tmp=tab[i];
		tab[i]=k.tab[i];
		k.tab[i]=tmp;
	}
}

template <class T>
void heaps <T>::insert(const T &k){
	for(int i=0;i<rozmiar;i++)
		if(i==rozmiar-1 && tab[i]!=NULL)
			cout<<"kopiec pe³ny"<<endl;
		else 
			if (tab[i]==NULL)
				tab[i]=k;
}

template <class T>
int heaps <T>::parent(int ind){
	if(ind%2==1)
		return ind/2;
	if(ind%2==0)
		return ind/2-1;
}

template <class T>
int heaps <T>::left(int ind){
	/*if(ind>(rozmiar-1)/2){
	cout<<"Brak dziecka";
	return -1;
	}*/
	return 2*ind+1;
}

template <class T>
int heaps <T>::right(int ind){
	//if(ind>=(rozmiar-1)/2){
	//	cout<<"Brak dziecka";
	//	return -1;
	//}

	return 2*ind+2;
}

template <class T>
void heaps <T>::up(int ind){
	int k,pok=0;
	if(ind%2==0)
		k=ind-1;
	else
		k=ind;
	while(k!=0){
		k=k/2;
		pok++;
	}
	for(int j=0;j<pok;j++)
		for(int i=ind;i>0;i--)
			if(tab[i]<tab[parent(i)])
				swap(tab[i],tab[parent(i)]);
}

template <class T>
void heaps <T>::down(int ind){
	int pok=0,k=ind;
	while((2*k+1)<rozmiar){
		k=2*k+1;
		pok++;
	}

	if(rozmiar%2==0)
		for(int j=0;j<pok;j++)
			for(int i=ind;i<rozmiar;i++){
				if(tab[i]>tab[(i*2)+1])
					swap(tab[i],tab[(i*2)+1]);
				if(i==(rozmiar-1)/2)
					break;
				else
					if(tab[i]>tab[(i*2)+2])
						swap(tab[i],tab[(i*2)+2]);

			}
			if(rozmiar%2==1)
				for(int j=0;j<pok;j++)
					for(int i=ind;i<rozmiar;i++){
						if(tab[i]>tab[(i*2)+1])
							swap(tab[i],tab[(i*2)+1]);
						if(tab[i]>tab[(i*2)+2])
							swap(tab[i],tab[(i*2)+2]);
						if(i==(rozmiar-2)/2)
							break;

					}


}



template <class T>
T heaps <T>::top(){
	return tab[0];
}

template <class T>
void heaps <T>::pop(){
	heaps <T> tab2(rozmiar-1);

	/*for(int i=0;i<rozmiar-1;i++)
	swap(tab[i],tab[i+1]);*/
	for(int i=0;i<tab2.rozmiar;i++)
		tab2.tab[i]=tab[i+1];
	delete tab;
	tab=new T[rozmiar-1];
	for(int i=0;i<tab2.rozmiar;i++)
		tab[i]=tab2.tab[i];
	rozmiar--;
	down(0);

}

template <class T>
T heaps <T>::take(int ind){
	return tab[ind];
}

template <class T>
void heaps <T>::remove(int ind){
	heaps <T> tab2(rozmiar-1);
	tab[ind]=NULL;
	int iter=0;

	for(int i=0;i<rozmiar;i++){
		
		if(tab[i]!=NULL){
			tab2.tab[iter]=tab[i];
			iter++;
		}
	}
	delete tab;
	tab=new T[rozmiar-1];
	for(int i=0;i<tab2.rozmiar;i++)
		tab[i]=tab2.tab[i];
	rozmiar--;
	down(0);

}

template <class T>
void heaps <T>::decreased(int ind){

	up(ind);
}

template <class T>
void heaps <T>::increased(int ind){

	down(ind);
}

template <class T>
void heaps <T>::merge(heaps <T> k){
	T *tmp= new T [rozmiar+k.rozmiar];
	int f=0;
	for(int i=0;i<rozmiar;i++)
		tmp[i]=tab[i];
	for(int i=rozmiar;i<(k.rozmiar+rozmiar);i++){
		tmp[i]=k.tab[f];
		f++;
	}
	delete tab;
	tab= new T [rozmiar+k.rozmiar];
	rozmiar=rozmiar+k.rozmiar;
	for(int i=0;i<rozmiar;i++)
		tab[i]=tmp[i];
	down(0);
}

void main(){

	int rozm=10;
	heaps <int> t(rozm),c;
	heaps <int> b(t);

	t.tab[0]=2;
	b.swaps(t);
	t.insert(45);
	c=t;
	int d=t.top();
	int f=t.parent(7);
	int g=t.left(3);
	int h=t.right(3);
	cout<<b.tab[0]<<" "<<t.tab[3]<<" "<<c.tab[3]<<" "<<d<<" "<<f<<" "<<g<<" "<<h<<endl;
	for(int i=0;i<t.rozmiar;i++)
		t.tab[i]=rozm-1-i;
	for(int i=0;i<t.rozmiar;i++)
		cout<<t.tab[i]<<" ";
	cout<<endl;
	c=t;
	cout<<"Kopiec c: "<<endl;
	for(int i=0;i<c.rozmiar;i++)
		cout<<c.tab[i]<<" ";
	cout<<endl;
	t.down(0);
	for(int i=0;i<t.rozmiar;i++)
		cout<<t.tab[i]<<" ";
	cout<<endl;
	t.pop();
	for(int i=0;i<t.rozmiar;i++)
		cout<<t.tab[i]<<" ";
	cout<<endl;

	t.remove(2);
	for(int i=0;i<t.rozmiar;i++)
		cout<<t.tab[i]<<" ";
	cout<<endl;
	t.merge(c);
	cout<<"Scalak: "<<endl;
	for(int i=0;i<t.rozmiar;i++)
		cout<<t.tab[i]<<" ";
	cout<<endl;
	system("pause");
};