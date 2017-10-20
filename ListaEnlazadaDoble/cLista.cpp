#include "stdafx.h"
#include "cLista.h"


cLista::cLista(int valor)
{
	cNodo *nuevo = new cNodo(valor);
	head = nuevo;
	tail = nuevo;
}

cNodo * cLista::findNode(int valor, cNodo * h, cNodo * t,cNodo *&res)
{
	h = head;
	t = tail;
	while (h->valor < t->valor&&valor > h->valor&&valor < t->valor) {
		h = h->next;
		t = t->ant;
	}
	if (valor == h->valor) {
		res = h;
		return h;
	}
	else if(valor == t->valor) {
		res = t;
		return t;
	}

	if (valor>t->valor) {
		res = t;
	}
	else if (valor < h->valor) {
		res = h;
	}
	return nullptr;
}
bool cLista::insertNode(int valor)
{
	cNodo *h = NULL;
	cNodo *t = NULL;
	cNodo *r = NULL;
	cNodo *res = NULL;
	r = findNode(valor, h, t,res);
	if (r!=NULL) {
		return false;
	}
	cNodo *nuevo = new cNodo(valor);
	if (valor < head->valor) {
		head->ant = nuevo;
		nuevo->next = head;
		head = nuevo;

		return true;
	}
	else if (valor > tail->valor) {
		cNodo *temp = tail;
		temp->next = nuevo;
		nuevo->ant = temp;
		tail = nuevo;
		return true;
	}
	
	if (res->valor < valor) {
		cNodo *temp = res;
		cNodo *tempNext = res->next;
		nuevo->next = tempNext;
		nuevo->ant = temp;
		temp->next = nuevo;
		tempNext->ant = nuevo;
		return true;
	}
	else if (res->valor > valor) {
		cNodo *temp = res;
		cNodo *tempAnt = res->ant;
		nuevo->next = res;
		nuevo->ant = tempAnt;
		temp->ant = nuevo;
		tempAnt->next = nuevo;
		return true;
	}
	return false;
}
bool cLista::removeNode(int valor)
{
	cNodo *h = NULL;
	cNodo *t = NULL;
	cNodo *r = NULL;
	cNodo *res = NULL;
	r = findNode(valor, h, t, res);
	if (r != NULL) {
		if (res->ant == NULL) {
			cNodo *temp = head;
			head = head->next;
			delete temp;
			return true;
		}
		else if (res->next == NULL) {
			cNodo *temp = tail;
			tail = tail->ant;
			delete temp;
			return true;
		}
		else {
			cNodo *prev = res->ant;
			cNodo *next = res->next;
			prev->next = next;
			next->ant = prev;
			delete res;
			return true;
		}
	}
	return false;
}
void cLista::printList()
{
	cNodo *h = head;
	while (h->next != NULL) {
		cout << h->valor << " ";
		h = h->next;
	}
	cout << h->valor << endl;
}
cLista::~cLista()
{
}
