#include "binstree.h"
#include <stdio.h>
#include <stdlib.h>

static struct tnode *tnode_alloc(int key)
{
	struct tnode *node = malloc(sizeof(*node));

	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->parent = NULL;
	return node;
}

struct tree *create_tree(void)
{
	return NULL;
}

struct tree *create_binstree(void)
{
	struct tree *tree;
	struct tnode *node;
	int key;

	tree= malloc(sizeof(*tree));
	tree->root = NULL;

	while (scanf("%d", &key) == 1) {
		node = tnode_alloc(key);
		tree_insert(tree, node);
	}
	return tree;
}

void inorder_tree_walk(struct tnode *x)
{
}

struct tnode *iterative_tree_search(struct tnode *x, int key)
{
}

struct tnode *tree_search(struct tnode *x, int key)
{
	if (x != NULL) {
		if (x->key == key)
			return x;
		else if (key < x->key)
			return tree_search(x->left, key);
		else 
			return tree_search(x->right, key);
	}
	return NULL;
}

struct tnode *tree_minimum(struct tnode *x)
{
	while (x->left != NULL)
		x = x->left;
	return x;
}

struct tnode *tree_maximum(struct tnode *x)
{
	while (x->right != NULL)
		x = x->right;
	return x;
}

struct tnode *tree_successor(struct tnode *x)
{
	if (x->right != NULL)
		return tree_minimum(x->right);

	struct tnode *y = x->parent;
	while (y != NULL && x == y->right) {
		x = y;
		y = y->parent;
	}
	return y;
}

struct tnode *tree_predecessor(struct tnode *x)
{
	if (x->left != NULL)
		return tree_maximum(x->left);

	struct tnode *y = x->parent;
	while (y != NULL && x == y->left) {
		x = y;
		y = y->parent;
	}
	return y;
}

void tree_transplant(struct tree *T, struct tnode *u, struct tnode *v)
{
	if (u->parent == NULL)
		T->root = v;
	else if (u == u->parent->left)
		u->parent->left = v;
	else
		u->parent->right = v;
	if (v != NULL)
		v->parent = u->parent;
}

void tree_insert(struct tree *T, struct tnode *z)
{
	struct tnode *x, *y;

	y = NULL;
	x = T->root;
	while (x != NULL) {
		y = x;
		if (z->key < x->key)
			x = x->left;
		else
			x = x->right;
	}

	z->parent = y;
	if (y == NULL)
		T->root = z;
	else if (z->key < y->key)
		y->left = z;
	else
		y->right = z;
}

void tree_delete(struct tree *T, struct tnode *z)
{
	if (z->left == NULL) 
		tree_transplant(T, z, z->right);
	else if (z->right == NULL) 
		tree_transplant(T, z, z->left);
	else {
		struct tnode *y = tree_minimum(z->right);

		if (y != z->right) {
			tree_transplant(T, y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}
		tree_transplant(T, z, y);
		y->left = z->left;
		y->left->parent = y;
	}
	free(z);
}

void tree_destroy(struct tree *T)
{
	while (T->root != NULL)
		tree_delete(T, T->root);
	free(T);
}
