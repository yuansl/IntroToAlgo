#ifndef BINSTREE_H
#define BINSTREE_H

struct tnode {
	int key;
	struct tnode *left, *right;
	struct tnode *parent;
};

struct tree {
	struct tnode *root;
};

struct tree *create_tree(void);
struct tree *create_binstree(void);
void inorder_tree_walk(struct tnode *x);
struct tnode *iterative_tree_search(struct tnode *x, int key);
struct tnode *tree_search(struct tnode *x, int key);
struct tnode *tree_minimum(struct tnode *x);
struct tnode *tree_maximum(struct tnode *x);
struct tnode *tree_successor(struct tnode *x);
struct tnode *tree_predecessor(struct tnode *x);
void tree_transplant(struct tree *T, struct tnode *u, struct tnode *v);
void tree_insert(struct tree *T, struct tnode *z);
void tree_delete(struct tree *T, struct tnode *z);
void tree_destroy(struct tree *T);

#endif
