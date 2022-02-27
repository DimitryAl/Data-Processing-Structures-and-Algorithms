#include <iostream>
//#include "BinaryTree.h"

using namespace std;

//тип для узла дерева
typedef struct node
{
	int key;			 //ключ узла
	node* parent;		//родитель узла
	node* left;		   //левый потомок узла
	node* right;	  //правый потомок узла
} node;

void AddNode(int k, node*& t);
void show(node *&t);
void cut(node*& t);
int searchMin(node*& t);
int Elimination(int kill, node *&t);
node* search(int k, node* t);

int main()
{	
	setlocale(LC_ALL, "ru");
	system("color F0");

	node* tree = NULL;
	node* s = NULL;
	int i = 0;
	int in = -1;
	int k = 9;
	const int length = 25;
	int seq[25] = {
		9, 17, 20, 16, 12, 21, 6, 3, 11, 4,
		19, 14, 13, 1, 5, 2, 8, 18, 7, 10,
		15, 24, 25, 23, 22
	};
	cout << "Заданная последовательность:\n";
	for (i = 0; i < length; i++)
	{
		cout << seq[i];
		if (i != length - 1) cout << ", ";
		if (i == length - 1) cout << endl << endl;
	}
	cout << "1.	Создать бинарное дерево поиска.\n";
	cout << "2.	Выполнить поиск узла с заданным значением ключа.\n";
	cout << "3.	Организовать вставку нового узла.\n";
	cout << "4.	Организовать прямой обход дерева.\n";
	cout << "5.	Найти минимальный ключ.\n";
	cout << "6.	Организовать удаление узла дерева, который имеет один дочерний узел.\n";
	while (in != 0)
	{
		cout << "Введите номер операции или 0 чтобы завершить программу: ";
		cin >> in;
		cout << endl;
		switch (in)
		{
		case 1:
			for (int i = 0; i < length; i++)
			{
				AddNode(seq[i], *&tree);
			}
			cout << "Дерево создано\n\n";
			break;
		case 2:
			cout << "Введите значение узла который надо найти: ";
			cin >> k;
			s = search(k, tree);
			if (s == NULL)
			{
				cout << "\nТакой узел не существует.\n\n";
				break;
			}
			else
			{
				cout << "\nИскомый узел:\n";
				cout << "Адрес в памяти\t" << s << endl;
				cout << "Ключ\t" << s->key << endl;
				if (s->parent != NULL) cout << "Предок\t" << s->parent->key << endl;
				if (s->left != NULL) cout << "Левый потомок\t" << s->left->key << endl;
				if (s->right != NULL) cout << "Правый потомок\t" << s->right->key << endl;
				cout << endl;
			}
			break;
		case 3:
			cout << "Введите значение нового узла: ";
			cin >> k; 
			if (search(k, tree) != NULL)
			{
				cout << "\nТакой узел уже существует.\n\n";
				break;
			}
			AddNode(k, *&tree);
			cout << "\nУзел добавлен\n" << endl;
			break;
		case 4:
			show(tree);
			cout << endl << endl;
			break;
		case 5:
			cout << "Минимальный ключ в дереве равен " << searchMin(*&tree);
			cout << endl << endl;
			break;
		case 6:
			cout << "Введите значение узла, который надо удалить: ";
			cin >> k;
			if (search(k, tree) == NULL)
			{
				cout << "\nТакой узел не существует.\n\n";
				break;
			}
			if (Elimination(k, *&tree) <= 0)
			{
				cout << "\nУ введенного узла не один дочерний узел\n" << endl;
				break;
			}
			cout << "\nУзел удален.\n" << endl;
			break;
		}
	}
	cut(tree);
	return 0;
}

void AddNode(int k, node*& t)
{
	if (t == NULL)
	{
		t = new node;
		t->parent = NULL;
		t->key = k;
		t->left = t->right = NULL;
	}
	if (k < t->key)
	{
		if (t->left != NULL) 
		{
			AddNode(k, t->left);
			t->left->parent = t;
		}
		else
		{
			t->left = new node;
			t->left->left = t->left->right = NULL;
			t->left->key = k;
			t->left->parent = t;
		}
	}
	if (k > t->key)
	{
		if (t->right != NULL)
		{
			AddNode(k, t->right);
			t->right->parent = t;
		}
		else
		{
			t->right = new node;
			t->right->left = t->right->right = NULL;
			t->right->key = k;
			t->right->parent = t;
		}
	}
}

node* search(int k, node* t)
{
	node* res = NULL;
	if (t != NULL)
	{
		if (t->key != k)
		{
			if (t->left != NULL || t->right != NULL)
			{
				if (k < t->key) res = search(k, t->left);
				if (k > t->key) res = search(k, t->right);
			}
		}
		else res = t;
	}

	return res;
}

void show(node*& t)
{
	if (t != NULL)
	{
		cout << t->key << " ";
		show(t->left);
		show(t->right);
	}
}

int searchMin(node*& t)
{
	if (t->left != NULL) searchMin(t->left);
	else return t->key;
}

int Elimination(int aim, node*& t)
{
	int res = 0;
	if (t != NULL)
	{
		if (t->key != aim)
		{
			if (t->left != NULL || t->right != NULL)
			{
				if (aim < t->key) res = Elimination(aim, t->left);
				if (aim > t->key) res = Elimination(aim, t->right);
			}
		}
		else 
		{
			if (t->left != NULL && t->right == NULL)
			{
				res = 1;
				if (t->parent->left == t) 
					t->parent->left = t->left;
				if (t->parent->right == t) t->parent->right = t->right;
			}
			if (t->right != NULL && t->left == NULL)
			{
				res = 1;
				if (t->parent->left == t) t->parent->left = t->left;
				if (t->parent->right == t) t->parent->right = t->right;
			}
		}
	}
	return res;
}

void cut(node*& t) 
{
	if (t != NULL)
	{
		cut(t->left);
		cut(t->right);
		delete t;
		t = NULL;
	}

}
