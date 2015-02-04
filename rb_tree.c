#include "rb_tree.h"
#include <stdio.h>
#include <stdlib.h>

static struct rb_node_t *rb_node_alloc(int key);
static struct rb_node_t *rb_tree_minimum(struct rb_tree_t *, struct rb_node_t *);

struct rb_tree_t *rb_tree_init(void)
{
	struct rb_tree_t *tree = malloc(sizeof(*tree));
	tree->nil = rb_node_alloc(0);
	tree->nil->left = NULL;
	tree->nil->right = NULL;
	tree->nil->parent = NULL;
	tree->nil->color = BLACK;
	tree->root = tree->nil;
	return tree;
}

void rb_rotate_left(struct rb_tree_t *tree, struct rb_node_t *x)
{
	struct rb_node_t *y = x->right;

	y->parent = x->parent;
	if (x->parent == tree->nil)
		tree->root = y;
	else if (x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;
	x->right = y->left;
	if (y->left != tree->nil)
		x->right->parent = x;
	y->left = x;
	x->parent = y;
}

void rb_rotate_right(struct rb_tree_t *tree, struct rb_node_t *x)
{
	struct rb_node_t *y = x->left;

	y->parent = x->parent;
	if (x->parent == tree->nil) 
		tree->root = y;
	else if (x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;

	x->left = y->right;
	if (y->right != tree->nil)
		x->left->parent = y;
	y->right = x;
	x->parent = y;
}

void rb_tree_insert(struct rb_tree_t *tree, struct rb_node_t *z)
{
	struct rb_node_t *y, *x;

	y = tree->nil;
	x = tree->root;
	while (x != tree->nil) {
		y = x;
		if (z->key < x->key)
			x = x->left;
		else
			x = x->right;
	}

	z->parent = y;
	if (y == tree->nil)
		tree->root = z;
	else if (z->key < y->key)
		y->left = z;
	else
		y->right = z;
	z->left = tree->nil;
	z->right = tree->nil;
	z->color = RED;
	rb_tree_insert_fixup(tree, z);
}

void rb_tree_insert_fixup(struct rb_tree_t *tree, struct rb_node_t *z)
{
	while (z->parent->color == RED) {
		if (z->parent == z->parent->parent->left) {
			struct rb_node_t *y = z->parent->parent->right;
			if (y->color == RED) {
				z->parent->color = BLACK;
				y->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
				/* if z->parent->color == RED, then next loop */
			} else {       /* y->color == BLACK */
				if (z == z->parent->right) {
					z = z->parent;
					rb_rotate_left(tree, z);
				}
				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				rb_rotate_right(tree, z->parent->parent);
			}
		} else {    /* z->parent == z->p->p->right */
			struct rb_node_t *y = z->parent->parent->left;
			if (y->color == RED) {
				z->parent->color = BLACK;
				y->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			} else {
				if (z == z->parent->left) {
					z = z->parent;
					rb_rotate_right(tree, z);
				}
				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				rb_rotate_left(tree, z->parent->parent);
			}
		}
	}
	tree->root->color = BLACK;
}

void rb_tree_delete(struct rb_tree_t *tree, struct rb_node_t *z)
{
	struct rb_node_t *x, *y;
	enum color_t y_original_color;

	y = z;
	y_original_color = y->color;

	if (z->left == tree->nil) {
		x = z->right;
		rb_tree_transplant(tree, z, z->right);
	} else if (z->right == tree->nil) {
		x = z->left;
		rb_tree_transplant(tree, z, z->left);
	} else {
		y = rb_tree_minimum(tree, z->right);
		y_original_color = y->color;
		x = y->right;
		if (y != z->right) {
			rb_tree_transplant(tree, y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}
		rb_tree_transplant(tree, z, y);
		y->left = z->left;
		y->left->parent = y;
		y->color = z->color;
	}

	free(z);

	if (y_original_color == BLACK)
		rb_tree_delete_fixup(tree, x);
}

void rb_tree_delete_fixup(struct rb_tree_t *tree, struct rb_node_t *x)
{
	struct rb_node_t *w;

	while (x != tree->root && x != tree->nil && x->color == BLACK) {
		if (x == x->parent->left) {
			w = x->parent->right;

			/* case 1 */
			if (w->color == RED) {
				w->color = BLACK;
				x->parent->color = RED;
				rb_rotate_left(tree, x->parent);
				w = x->parent->right;
			}

			/* case 2 3 4 : w->color == BLACK */

			/* case 2 */
			if (w->left->color == BLACK &&
			    w->right->color == BLACK) {
				w->color = RED;
				x = x->parent;
			} else {

				/* case 3 : w->right->color is BLACK */

				if (w->right->color == BLACK) {
					w->left->color = BLACK;
					rb_rotate_right(tree, w);
					w = x->parent->right;
				}

				/* case 4 : w->right->color is RED */
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->right->color = BLACK;
				rb_rotate_left(tree, x->parent);
				x = tree->root;
			}
		} else {
			w = x->parent->left;

			if (w->color == RED) {
				w->color = BLACK;
				x->parent->color = RED;
				rb_rotate_right(tree, x->parent);
				w = x->parent->left;
			}
			if (w->left->color == BLACK && w->right->color == BLACK) {
				w->color = RED;
				x = x->parent;
			} else {
				if (w->left->color == BLACK) {
					w->color = RED;
					w->right->color = BLACK;
					rb_rotate_left(tree, w);
					w = x->parent->left;
				}
				w->color = x->parent->color;
				w->left->color = BLACK;
				rb_rotate_right(tree, x->parent);
				x = tree->root;
			}
		}
	}
	x->color = BLACK;
}

/* replace u with v */
void rb_tree_transplant(struct rb_tree_t *tree, struct rb_node_t *u,
			struct rb_node_t *v)
{
	if (u->parent == tree->nil)
		tree->root = v;
	else if (u == u->parent->left)
		u->parent->left = v;
	else
		u->parent->right = v;
	v->parent = u->parent;
}

static struct rb_node_t *rb_node_alloc(int key)
{
	struct rb_node_t *x = malloc(sizeof(*x));
	x->key = key;
	return x;
}

static struct rb_node_t *rb_tree_minimum(struct rb_tree_t *tree,
					 struct rb_node_t *x)
{
	while (x->left != tree->nil)
		x = x->left;
	return x;
}

static void rb_tree_destroy(struct rb_tree_t *tree)
{
	while (tree->root != tree->nil)
		rb_tree_delete(tree, tree->root);
	free(tree->nil);
	free(tree);
}

static void rb_tree_visit(struct rb_tree_t *tree, struct rb_node_t *node)
{
	if (node != tree->nil) {
		rb_tree_visit(tree, node->left);
		printf(" %d", node->key);
		rb_tree_visit(tree, node->right);
	}
}

/* test routine */
int main(void)
{
	struct rb_tree_t *tree = rb_tree_init();
	struct rb_node_t *node;
	FILE *fp;
	int key;

	if ((fp = fopen("rbtreedb", "r")) == NULL) {
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	while (fscanf(fp, "%d", &key) != EOF) {
		node = rb_node_alloc(key);
		rb_tree_insert(tree, node);
	}

	rb_tree_visit(tree, tree->root);
	printf("\n");

	rb_tree_destroy(tree);

	return 0;
}
