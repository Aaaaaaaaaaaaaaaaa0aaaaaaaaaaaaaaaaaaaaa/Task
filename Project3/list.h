// Модуль инструменты
#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
using namespace std;

//структура переменной, входящей в днф; inv - знак (+ или -)б, x  принимает значения от 1 до 4
// и соотвествует одной их переменной в функции днф
//1 - x
//2 - y
//3 - z
//4 - t соотвественно 
struct node {
	int x;     
	bool inv;
};

// структура, представляющая собой конъюнкцию днф, элемент списка; 
//для удобства реализациив в структуру добавлен размер  конъюнции
//(т.е. если в конъюнкии, например, две перемееные, то ее размер - 2, если четеры переменные, то размер - 4)
struct DNF {
	int size_dnf = 0;
	node dnf[4];
	DNF* next;
};

// днф в виде списка, элементами являются конъюнкции
class List
{
public:
	DNF *head;
	List() :head(NULL) {}; 
	~List();			
	void del(int j);
	void insert(DNF &a, int j);
	void add(DNF &x);
	void show();
	
};
