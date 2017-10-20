// ListaEnlazadaDoble.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "cLista.h"

int main()
{
	cLista l(5);
	l.insertNode(1);
	l.insertNode(3);
	l.insertNode(4);
	l.insertNode(2);
	l.insertNode(7);
	l.removeNode(4);
	l.insertNode(6);
	l.printList();
    return 0;
}

