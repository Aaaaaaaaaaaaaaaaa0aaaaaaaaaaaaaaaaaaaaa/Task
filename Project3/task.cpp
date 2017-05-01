//Модуль задача
#pragma once
#include "task.h"
// задача : используя списки, построить конъюнкцию двух днф
// реализуемм с помощью метода insert класса List
// параметры - список а, списо b, и список - ответ на задачу
void connecnt(List*a, List*b) {
	int size = 0;
	for (DNF*i = a->head; i != NULL; i = i->next)
		size++;
	
	for (DNF*i = b->head; i != NULL; i = i->next)
	{
		a->insert(*i, size);
		size++;
	}
}

// задача : вычислить значение днф в некоторй вершине четырехмерного куба
// параматры - заданная днф и значения переменных
bool task2(List*a, bool x, bool y, bool z, bool t) {

	bool ans;
	DNF *i = new DNF;
	for (i = a->head; i != NULL; i = i->next)
	{
		bool t;
		if (!i->dnf[0].inv)
			t = ~i->dnf[0].inv&i->dnf[1].inv;
		else
			if (!i->dnf[1].inv)
				t = i->dnf[0].inv&~i->dnf[1].inv;
			else
				t = i->dnf[0].inv&i->dnf[1].inv;
		for (int j = 0; j < i->size_dnf; j++) {
			if (!i->dnf[j].inv)
				t = t&~i->dnf[j].inv;
			else
				t = t&i->dnf[j].inv;
		}
		ans = ans | t;
	}
	return ans;
}

// задача: сформировать список из конъюнкций, число переменных в которых не провосходит 3
void task3(List*a, List*ans) {
	DNF* temp = a->head;
	while (temp != NULL) {
		if (temp->size_dnf <= 3)
			ans->add(*temp);
		temp = temp->next;
	}
}

// задача : построить новый список из конъюнкций, содержащих переменные x и y
void task4(List*a, List*ans) {
	DNF* temp = a->head;

	while (temp != NULL) {
		int tx = 0, ty = 0;
		for (int i = 0; i < temp->size_dnf; i++)
		{
			if (temp->dnf[i].x == 1)
				tx++;
			if (temp->dnf[i].x == 2)
				ty++;

			if (tx != 0 && ty != 0)
			{
				ans->add(*temp);
				break;
			}
		}
		temp = temp->next;
	}
}