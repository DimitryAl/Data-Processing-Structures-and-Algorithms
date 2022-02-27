/*
#ifndef _BINARYTREEO_H
#define _BINARYTREEO_H
#include <iostream>
using namespace std;

typedef struct node
{
	int key;			 //ключ узла
	node* parent;		//родитель узла
	node* left;		   //левый потомок узла
	node* right;	  //правый потомок узла
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