#include <iostream>
//#include "BinaryTree.h"

using namespace std;

//��� ��� ���� ������
typedef struct node
{
	int key;			 //���� ����
	node* parent;		//�������� ����
	node* left;		   //����� ������� ����
	node* right;	  //������ ������� ����
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
	cout << "�������� ������������������:\n";
	for (i = 0; i < length; i++)
	{
		cout << seq[i];
		if (i != length - 1) cout << ", ";
		if (i == length - 1) cout << endl << endl;
	}
	cout << "1.	������� �������� ������ ������.\n";
	cout << "2.	��������� ����� ���� � �������� ��������� �����.\n";
	cout << "3.	������������ ������� ������ ����.\n";
	cout << "4.	������������ ������ ����� ������.\n";
	cout << "5.	����� ����������� ����.\n";
	cout << "6.	������������ �������� ���� ������, ������� ����� ���� �������� ����.\n";
	while (in != 0)
	{
		cout << "������� ����� �������� ��� 0 ����� ��������� ���������: ";
		cin >> in;
		cout << endl;
		switch (in)
		{
		case 1:
			for (int i = 0; i < length; i++)
			{
				AddNode(seq[i], *&tree);
			}
			cout << "������ �������\n\n";
			break;
		case 2:
			cout << "������� �������� ���� ������� ���� �����: ";
			cin >> k;
			s = search(k, tree);
			if (s == NULL)
			{
				cout << "\n����� ���� �� ����������.\n\n";
				break;
			}
			else
			{
				cout << "\n������� ����:\n";
				cout << "����� � ������\t" << s << endl;
				cout << "����\t" << s->key << endl;
				if (s->parent != NULL) cout << "������\t" << s->parent->key << endl;
				if (s->left != NULL) cout << "����� �������\t" << s->left->key << endl;
				if (s->right != NULL) cout << "������ �������\t" << s->right->key << endl;
				cout << endl;
			}
			break;
		case 3:
			cout << "������� �������� ������ ����: ";
			cin >> k; 
			if (search(k, tree) != NULL)
			{
				cout << "\n����� ���� ��� ����������.\n\n";
				break;
			}
			AddNode(k, *&tree);
			cout << "\n���� ��������\n" << endl;
			break;
		case 4:
			show(tree);
			cout << endl << endl;
			break;
		case 5:
			cout << "����������� ���� � ������ ����� " << searchMin(*&tree);
			cout << endl << endl;
			break;
		case 6:
			cout << "������� �������� ����, ������� ���� �������: ";
			cin >> k;
			if (search(k, tree) == NULL)
			{
				cout << "\n����� ���� �� ����������.\n\n";
				break;
			}
			if (Elimination(k, *&tree) <= 0)
			{
				cout << "\n� ���������� ���� �� ���� �������� ����\n" << endl;
				break;
			}
			cout << "\n���� ������.\n" << endl;
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
