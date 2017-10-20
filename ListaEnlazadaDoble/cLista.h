#pragma once
#include <iostream>
#include "cNodo.h"
using namespace std;
class cLista
{
public:
	cNodo *head = NULL;
	cNodo *tail = NULL;
	cLista(int valor);
	cNodo* findNode(int valor, cNodo *h, cNodo *t, cNodo *&res);
	bool insertNode(int valor);
	bool removeNode(int valor);
	void printList();
	~cLista();
};

