#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<stdio.h>
#include<conio.h>

using namespace std;

struct Table
{
	int x;
	int key;
	Table *Next; //указатель на следующий элемент
};

void Make(Table *t)
{
	t = NULL;
}

void Push(int x, int key, Table **t) 
{
	Table *temp = new Table;
	temp->x = x;
	temp->key = key;
	temp->Next = *t;
	*t = temp;
}

int CountElements(Table *t) //Подсчет количества элементов в таблице
{
	int c = 0;
	while (t)
	{
		c++;
		t = t->Next;
	}
	return c;
}

void Show(Table *t) //Вывод стека
{
	if (CountElements(t) > 0)
		while (t)
		{
			cout << t->x << " ";
			t = t->Next;
		}
	else
		cout << "Таблица пуста!";
}

void PushToEnd(int x, int key, Table **t)
{
	Table* n1;
	Table* n2;
	n1 = *t;
	n2 = *t;
	while (n1 != NULL)
	{
		n2 = n1;
		n1 = n1->Next;
	}
	n1 = new Table;
	n1->key = key;
	n1->x = x;
	n1->Next = NULL;
	n2->Next = n1;
}

Table* SearchByKey(int key, Table *t)
{
	Table* n1=t;
	Table *temp = new Table;
	while (n1 != NULL && n1->key != key)
		n1->Next;
	temp->key = n1->key;
	temp->x = n1->x;
	temp->Next = NULL;
	return temp;
}

bool IsEmpty(Table *t) //Проверка на пустоту
{
	if (t == NULL) return false;
	else
		return true;
}

void DeleteByKey(int key, Table *t)
{
	Table* n1=t;
	Table* n2=t;
	while (n1!=NULL&&n1->key!=key)
	{
		n2 = n1;
		n1 = n1->Next;
	}
	if (n1 != NULL)
	{
		if (n1==n2)
		{
			t = n1->Next; 
			delete n1;
		}
		else
		{
			n2->Next = n1->Next;
			delete n1;
		}
	}
}

void ClearList(Table *t)//полное очищение таблицы
{
	while (t)
	{
		Table *temp = t->Next; 
		delete t;
		t = temp; 
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	Table *t = NULL;
	Table *t1 = NULL;
	int O = 0, c;			
	short int k;
	cout << "Меню программы:" << endl;
	cout << "Нажмите 1, чтобы создать таблицу" << endl;
	cout << "Нажмите 2, чтобы добавить элемент в начало таблицы" << endl;
	cout << "Нажмите 3, чтобы добавить элемент в конец таблицы" << endl;
	cout << "Нажмите 4, чтобы вывести информационные части таблицы" << endl;
	cout << "Нажмите 5, чтобы вывести количество элементов в таблице" << endl;
	cout << "Нажмите 6, чтобы проверить таблицу на пустоту" << endl;
	cout << "Нажмите 7, чтобы удалить элемент таблицы по ключу" << endl;
	cout << "Нажмите 8, чтобы найти элемент таблицы по ключу" << endl;
	cout << "Нажмите 10, чтобы закрыть программу" << endl;
	cout << endl;
	while (O != 10)
	{
		cout << "Введите значение для перехода по меню: ";
		cin >> O;
		switch (O)
		{
		case 1: 
			Make(t);
			cout << "Таблица создана" << endl; break;

		case 2:
			for (int i = 0; i<5; i++)
				Push(i, i, &t);
			cout << "Элемент добавлен в начало таблицы" << endl; break;

		case 3:
			for (int i = 5; i<10; i++)
				Push(i, i, &t);
			cout << "Элемент добавлен в конец таблицы" << endl; break;

		case 4:
			cout << "Вывод информационной части таблицы: ";
			Show(t);
			cout << endl; break;

		case 5:
			cout << CountElements(t) << endl; break;

		case 6:
			if (IsEmpty(t) == true) 
				cout << "Стек не пустой" << endl;
			   else
				cout << "Стек пустой" << endl;
			break;

		case 7:
			cout << "Введите ключ, по которому вы хотите удалить элемент" << endl;
			cin >> k;
			DeleteByKey(k, t);
			cout << "Элемент по ключу " << k << " удалён" << endl;
			break;

		case 8:
			cout << "Введите ключ, по которому вы хотите осуществить поиск" << endl;
			cin >> k;
			SearchByKey(k, t);
			cout << "Элемент по ключу " << k << " найден" << endl;
			break;
		}
		cout << endl;
	}
	system("pause");
	return 0;
}