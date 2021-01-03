#include<iostream>
#include<conio.h>
#include<ctime>
#include<stdlib.h>

using namespace std;

//node structure that can store int

struct node {
	int data; //store the char
	node *next;
	node() {
		data = 0;
		next = NULL;
	}
};


//list class, declare data members as discussed and write constructor

class Queue {

private:
	int size;//len use for lenght
	node *head;
	node *tail;
public:
	Queue() {
		size = 0;
		head = NULL;
		tail = NULL;

	}
	~Queue();
	bool  add(int);
	const void display();
	int remove();
	int sizes();
	int sizebypoi();
	bool push(node  );
	int get(int x);
	int search(int);
};

// enter char in list and return ture if add add incrase the list size

bool Queue::add(int x) {
	node *t = new node();
	if (size == 0) {
		t->data = x;
	head = t;
	tail = t;
		size++;
		return true;
	}
	else
		t->data = x;
	tail->next = t;
	tail = t;
	size++;
	return true;
}
//display the lsit 

const void Queue::display() {
	node *t;
	t = head;
	while (t != NULL) {
		std::cout << t->data << endl;
		t = t->next;
	}
}
//remove  data in list and reduce the size of list and return the number 

int Queue::remove(){
	node *t = head;
	int a;
	if (size == 0) {
		return -999;

	}
	else
		
	
	
	a = t->data;
	head = head->next;
	t->next = NULL;
	delete t;
	size--;
	return a;

}
//return size off list
int Queue::sizes() {

	return size;
}
// return size but calculated from loop
int Queue::sizebypoi() {
	node *t = head;
	while (t != NULL) {
		t = t->next;
		size++;

	}
	return size;
}
//Constructer delete all the lite node
 Queue::~Queue() {
	 node *t=head;
	 while (t != NULL) {
		 t = head;
		 head = head->next;
		 delete t;
		 
	 }

}
 // put complete node in list and return true  
 bool Queue::push(node num) {
	 node * t = new node();
	 
	 t->data = num.data;
	 tail->next=t ;
	 tail = t;
	 size++;
	 return true;
 }

 // return the data of index that give user en
 int Queue::get(int x) {
	 node * t = head;
	 if (size == 0 || x >= size) {
		 return -9999;
	 }
	 for (int i = 0; i<x; i++) {
		 t = t->next;
	 }
	 return t->data;
 }
 int Queue::search(int a) {

	 node *t = head;
	 for (int i = 0; i < size; i++) {
		 if (t->data != a) {

			 t = t->next;
		 }
	 }
	 return t->data;

 }
 

 // main of program

void main() {
	Queue A,B,C,D;
	srand((int) time(0));
	for (int i = 0; i < 10; i++) {

		A.add(1 + rand() % 70);

	}
	
	int x;
	while (A.sizes()!=0) {
		//
		// x = A.get(0);
		x = A.remove();
		
		if (x >= 48 && x <= 52) {
			B.add(x);

		}
		else if (x > 52) {
			C.add(x);
		}
		else {
			D.add(x);
		}
	

	}
	cout << "exact wafer " << endl;
int a=B.sizes() ;

	cout<< "solution   " << a*15 << endl;
	
	B.display();
	cout << "over weight " << endl;
	C.display();
	
	cout << "remaing" << endl;
		D.display();

	_getch();
}
