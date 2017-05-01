// Модуль внешнее - внуреннее представление
#include "code.h"

// вспомогательная функция для удобства кодирования, возвращает для node.x
int return_var(char a) {
	if (a == 'x')
		return 1;
	if (a == 'y')
		return 2;
	if (a == 'z')
		return 3;
	if (a == 't')
		return 4;
}
// вспомогательная функция для удобства кодирования
bool is_var(char a)
{
	return(a == 'x' || a == 'y' || a == 'z' || a == 't');
}
// кодирование: построение днф, заданной массив в файле
// в качестве параметров передается список, в котором будет построенна днф и текстовый поток ввода
// процесс построения можно представить в виде автомата состояний
void code(List*b, ifstream &in) {

	char a;
	do										// 
	{
		in.get(a);							
		DNF* temp = new DNF;				// вспомогательная структура, временно в ней формируем онъюнкцию
		while (a != '+' && !in.eof())		// в цикле парсим массив на конъюнкции
		{
			if (in.eof())					
				return;
			if (a == '-')					// обрабатывание отрицательных переменных конъюнкций
			{
				in.get(a);
				if (is_var(a))				// запись переменной в конъюнкцию
				{
					temp->dnf[temp->size_dnf].inv = false;
					temp->dnf[temp->size_dnf].x = return_var(a);
					temp->size_dnf++;
					in.get(a);
				}
			}
			else
				if (is_var(a))			// запись переменной в конъюнкцию(не отрицательной)
				{
					temp->dnf[temp->size_dnf].inv = true;
					temp->dnf[temp->size_dnf].x = return_var(a);
					temp->size_dnf++;
					in.get(a);
				}
		}

		b->add(*temp);  // к моменту, когда в массиве встречается '+', сформированна конъюнкция, ее и добавляем в список
		delete temp;	// удаляем вспомагательную конъюнкцию
	} while (!in.eof());
}
// декодирование, обратная функция кодированию, восстановление днф с выводом в текстовый файл
// параметры функции - декодируемый список и выходной текстовый поток
void decode(List*a, ofstream&out)
{
	DNF *i = new DNF;							
	for (i = a->head; i != NULL; i = i->next)
	{
		// процесс востановления конъюнкций 
		for (int j = 0; j < i->size_dnf; j++) {
			if (!i->dnf[j].inv)
				out << '-';
			if (i->dnf[j].x == 1)
				out << 'x';
			if (i->dnf[j].x == 2)
				out << 'y';
			if (i->dnf[j].x == 3)
				out << 'z';
			if (i->dnf[j].x == 4)
				out << 't';
		}
		out << ' ';
		if (i->next != NULL)
			out << '+';
		out << ' ';

	}
	delete i;
	a->~List(); // освобождение памяти
}