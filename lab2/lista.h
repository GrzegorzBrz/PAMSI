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
	Node <T> *putLast(Node <T> tmp);
	Node <T> *putFirst(Node <T> tmp);
	Node <T> *putBefore(Node <T> tmp);
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
	void swap(List <T> tmp);
	friend ostream & operator << (ostream &wyjscie, const List<T> &list);
	friend istream & operator >> (istream &wejscie, const List<T> &list);
};


void main(){
};