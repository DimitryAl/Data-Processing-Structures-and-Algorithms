/*
#ifndef _BINARYTREEO_H
#define _BINARYTREEO_H
#include <iostream>
using namespace std;

typedef struct node
{
	int key;			 //���� ����
	node* parent;		//�������� ����
	node* left;		   //����� ������� ����
	node* right;	  //������ ������� ����
};

class BinTree {
private:
	int length;
	node* tree;

public:
	BinTree();
	BinTree(int in[25], int len);
	void Show() const;
	void AddNode(int k);
};
#endif
*/