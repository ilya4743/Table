#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<stdio.h>
#include<conio.h>

using namespace std;

struct Table
{
	int x;
	int key;
	Table *Next; //��������� �� ��������� �������
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

int CountElements(Table *t) //������� ���������� ��������� � �������
{
	int c = 0;
	while (t)
	{
		c++;
		t = t->Next;
	}
	return c;
}

void Show(Table *t) //����� �����
{
	if (CountElements(t) > 0)
		while (t)
		{
			cout << t->x << " ";
			t = t->Next;
		}
	else
		cout << "������� �����!";
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

bool IsEmpty(Table *t) //�������� �� �������
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

void ClearList(Table *t)//������ �������� �������
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
	cout << "���� ���������:" << endl;
	cout << "������� 1, ����� ������� �������" << endl;
	cout << "������� 2, ����� �������� ������� � ������ �������" << endl;
	cout << "������� 3, ����� �������� ������� � ����� �������" << endl;
	cout << "������� 4, ����� ������� �������������� ����� �������" << endl;
	cout << "������� 5, ����� ������� ���������� ��������� � �������" << endl;
	cout << "������� 6, ����� ��������� ������� �� �������" << endl;
	cout << "������� 7, ����� ������� ������� ������� �� �����" << endl;
	cout << "������� 8, ����� ����� ������� ������� �� �����" << endl;
	cout << "������� 10, ����� ������� ���������" << endl;
	cout << endl;
	while (O != 10)
	{
		cout << "������� �������� ��� �������� �� ����: ";
		cin >> O;
		switch (O)
		{
		case 1: 
			Make(t);
			cout << "������� �������" << endl; break;

		case 2:
			for (int i = 0; i<5; i++)
				Push(i, i, &t);
			cout << "������� �������� � ������ �������" << endl; break;

		case 3:
			for (int i = 5; i<10; i++)
				Push(i, i, &t);
			cout << "������� �������� � ����� �������" << endl; break;

		case 4:
			cout << "����� �������������� ����� �������: ";
			Show(t);
			cout << endl; break;

		case 5:
			cout << CountElements(t) << endl; break;

		case 6:
			if (IsEmpty(t) == true) 
				cout << "���� �� ������" << endl;
			   else
				cout << "���� ������" << endl;
			break;

		case 7:
			cout << "������� ����, �� �������� �� ������ ������� �������" << endl;
			cin >> k;
			DeleteByKey(k, t);
			cout << "������� �� ����� " << k << " �����" << endl;
			break;

		case 8:
			cout << "������� ����, �� �������� �� ������ ����������� �����" << endl;
			cin >> k;
			SearchByKey(k, t);
			cout << "������� �� ����� " << k << " ������" << endl;
			break;
		}
		cout << endl;
	}
	system("pause");
	return 0;
}