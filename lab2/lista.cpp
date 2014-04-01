#include <iostream>

using namespace std;

template <class T>
class Node{
public:
	T data;
	Node <T> *next;
	Node <T> *prev;
	Node(T tmp);
};

template <class T>
class Iterator{
public:
	Node <T> *iter;
	Node <T> &next();
	Node <T> &prev();
	T &data();
	bool operator == (const Iterator <T> &tmp);
};

template <class T>
class ListFunction{
public:
	Iterator <T> iter;
	bool isOff();
	bool isOn();
	Node <T> *putLast(Node <T> &tmp);
	Node <T> *putFirst(Node <T> &tmp);
	Node <T> *putBefore(Node <T> &tmp);
	Node <T> *takeOff();

};

template <class T>
class List{
public:
	size_t size;
	Node <T> *head;
	Node <T> *tail;
	Iterator <T> iter;

	List();
	List(const List <T> &list);
	List<T> & operator=(const List <T> &tmp);
	~List();
	void push_front(T const &tmp);
	void push_back(T const &tmp);
	void pop_front();
	void pop_back();
	Node <T> &begin();
	Node <T> &end();
	size_t sizeList();
	void swap(List <T> &tmp);
	friend ostream & operator << (ostream &wyjscie, const List<T> &list);
	friend istream & operator >> (istream &wejscie, const List<T> &list);
};


//---------Klasa wezla----------------------------------------------------------------------------------------
template <class T>
Node <T>::Node(T tmp){
	data=tmp;
	next=NULL;
	prev=NULL;
};


//---------Klasa Iteratora----------------------------------------------------------------------------------------
template <class T>
Node <T> & Iterator <T>::next(){
	return iter=next;
};

template <class T>
Node <T> & Iterator <T>::prev(){
	return iter=prev;
};

template <class T>
T & Iterator <T>::data(){
	return data;
};

template <class T>
bool Iterator <T>::operator==(const Iterator <T> &tmp){
	return (&iter==&tmp.iter);
};

//---------Klasa funkcji listy----------------------------------------------------------------------------------------

template <class T>
bool ListFunction <T>::isOff(){
	if(iter.iter->next==NULL && iter.iter->prev==NULL)
		return true;
	if(iter.iter->next!=NULL){
		iter.next();
		if(iter.iter->prev==NULL)
			return true;
		else 
			return false;
	}
	if(iter.iter->prev!=NULL){
		iter.prev();
		if(iter.iter->next==NULL)
			return true;
		else
			return false;
	}
};

template <class T>
bool ListFunction <T>::isOn(){
	if(iter.iter->next!=NULL){
		iter.next();
		if(iter.iter->prev!=NULL){
			iter.prev();
			return true;
		}
		else 
			return false;
	}
	if(iter.iter->prev!=NULL){
		iter.prev();
		if(iter.iter->next!=NULL){
			iter.next();
			return true;
		}
		else
			return false;
	};
}

template <class T>
Node <T> *ListFunction <T>::putLast(Node <T> &tmp){
	while(iter.iter->next!=NULL)
		iter.next();
	iter.iter->next=tmp;
	tmp.prev=iter.iter;
	iter.next();
	return iter.iter;
};

template <class T>
Node <T> *ListFunction <T>::putFirst(Node <T> &tmp){
	while(iter.iter->prev!=NULL)
		iter.prev();
	iter.iter->prev=tmp;
	tmp.next=iter.iter;
	iter.prev();
	return iter.iter;
};

template <class T>
Node <T> *ListFunction <T>::putBefore(Node <T> &tmp){
	while(iter.iter->prev!=NULL)
		iter.prev();
	iter.iter->prev=tmp;
	tmp.next=iter.iter;
	return iter.iter;
};

template <class T>
Node <T> *ListFunction <T>::takeOff(){
	iter.iter->next->prev=NULL;
	iter.iter->prev->next=NULL;
	iter.iter->next=NULL;
	iter.iter->prev=NULL;
};

//---------Klasa listy----------------------------------------------------------------------------------------

template <class T>
List <T>::List(){
	size=0;
	head=NULL;
	tail=NULL;
	iter.iter=NULL
};

template <class T>
List <T>::List(const List <T> &tmp)
{
	size=tmp.size;
	head=tmp.head;
	tail=tmp.tail;
	iter.iter=tmp.iter.iter;
};

template <class T>
List <T> & List <T>::operator=(const List <T> &tmp){
	size=tmp.size;
	head=tmp.head;
	tail=tmp.tail;
	iter.iter=tmp.iter.iter;
	return *this;
};

template <class T>
List <T>::~List(){
	delete head;
	delete tail;
	delete iter;
};

template <class T>
void List <T>::push_front(T const &tmp){
	if(size==0){
		head=new Node(*tmp);
		tail=head;
		size++;
	}
	else{
		Node <T> *temp=new Node(*tmp);
		temp->next=head;
		temp->next->prev=temp;
		head=temp;
		size++;
	}
};

template <class T>
void List <T>::push_back(T const &tmp){
	if(size==0){
		head=new Node(*tmp);
		head=tail;
		size++;
	}
	else{
		Node <T> *temp=new Node(*tmp);
		tail->next=temp;
		temp->prev=tail;
		tail=temp;
		size++;
	}
};

template <class T>
void List <T>::pop_front(){
	iter.iter=head->next;
	head=iter.iter;
	head->prev->next=NULL;
	head->prev=NULL;
	size--;
};

template <class T>
void List <T>::pop_back(){
	iter.iter=tail->prev;
	tail=iter.iter;
	tail->next->prev=NULL;
	tail->next=NULL;
	size--;
};

template <class T>
Node <T> &List <T>::begin(){
	return head;
};

template <class T>
Node <T> &List <T>::end(){
	return tail->next;
};

template <class T>
size_t List <T>::sizeList(){
	return size;
};

template <class T>
void List <T>::swap(List <T> &tmp){
	List <T> temp=List(*tmp);
	tmp.head=head;
	tmp.tail=tail;
	tmp.size=size;
	tmp.iter=iter;
	head=temp.head;
	tail=temp.tail;
	size=temp.size;
	iter=temp.iter;
	delete tmp;
};


template <class T>
ostream & operator <<(ostream &wyjscie, const List <T> &list){
	wyjscie<<list.size;
	list.iter.iter=head;
	while(list.iter.iter->next!=NULL){
		wyjscie<<list.iter.iter->data<<' ';
		list.iter.next();
	}
	wyjscie<<list.iter.iter->data<<' ';
};

template <class T>
istream & operator >> (istream &wejscie, const List <T> &list){
	T k;
	wejscie>>list.size;
	for (int i=0;i<list.size;i++){
		wejscie>>k;
		list.push_back(k);
	}
};


void main(){
};