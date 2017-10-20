#include "stdafx.h"
#include "cNodo.h"


cNodo::cNodo(int valor)
{
	this->valor = valor;
	next = NULL;
	ant = NULL;
}


cNodo::~cNodo()
{
}
