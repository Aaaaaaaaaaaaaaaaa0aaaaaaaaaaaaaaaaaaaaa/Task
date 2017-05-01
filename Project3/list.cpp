// Модуль инструменты
#include "list.h"
#include <iostream>
// деструктор
List::~List()
{
	while (head != NULL)
	{
		DNF *temp = head;
		head = head->next;
		delete temp;

	}
}

// процедура вставки элемнта в список с учетом существования подобного элемента
void List::insert(DNF &x, int j)
{
	bool f = 0;
	DNF *i = new DNF;
		for (i = this->head; i != NULL; i = i->next)
		{
				if (i == &x)
				{
					f = 1;
					break;
				}
		}
		
		if (f == 0)
		{
			DNF *temp = new DNF;
			temp = head;
			int i = 0;
			while (temp != NULL && i != j-1) {
				temp = temp->next;
				i++;
			}
			DNF *t = new DNF;
			DNF *a = new DNF;
			a->dnf = x.dnf;
			a->size_dnf = x.size_dnf;
			t = temp->next;
			a->next = t;
			temp->next = a;

		}
}
// процедур добавления элемента в список
// целнсообразность процедуры обусловлена тем, что асимптотика меньше, чем у функции insert,
//и когда не важно место вставки и существование подобного элемента выгоднее использовать эту функцию
void List::add(DNF &x)
{
	DNF *temp = new DNF;
	temp->dnf = x.dnf;
	temp->size_dnf = x.size_dnf;
	temp->next = head;
	head = temp;
}
// процедура вывода списка на консоль (в кодированном виде)
void List::show()
{
	DNF* t = head;
	while (t != NULL)
	{
		for (int i = 0; i <t->size_dnf; i++)
		{
			cout << ' ' << t->dnf[i].inv << ' ' << t->dnf[i].x << endl;
		}
		t = t->next;
		cout << endl;
	}
	delete t;
}
// удаление элемента, находящегося на j-ой позиции
void List::del(int j)
{

	DNF *top = head;
	DNF *temp = new DNF;
	int i = 0;
	while (i != j) 
	{
		temp = top->next; 
		top = temp;
		i++;
	}
	top->next = temp->next; 
	delete temp; 
}