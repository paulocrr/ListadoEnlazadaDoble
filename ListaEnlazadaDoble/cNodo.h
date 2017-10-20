#pragma once
class cNodo
{
public:
	int valor;
	cNodo *next;
	cNodo *ant;
	cNodo(int valor);
	~cNodo();
};

