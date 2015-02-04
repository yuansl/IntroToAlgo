#ifndef RB_TREE_H
#define RB_TREE_H

enum color_t { RED, BLACK };

struct rb_node_t {
	int key;
	struct rb_node_t *left;
	struct rb_node_t *right;
	struct rb_node_t *parent;
	enum color_t color;
};

struct rb_tree_t {
	struct rb_node_t *root;
	struct rb_node_t *nil;
};

struct rb_tree_t *rb_tree_init(void);
void rb_rotate_left(struct rb_tree_t *tree, struct rb_node_t *x);
void rb_rotate_right(struct rb_tree_t *tree, struct rb_node_t *x);	
void rb_tree_insert(struct rb_tree_t *tree, struct rb_node_t *z);
void rb_tree_insert_fixup(struct rb_tree_t *tree, struct rb_node_t *z);
void rb_tree_delete(struct rb_tree_t *tree, struct rb_node_t *z);
void rb_tree_delete_fixup(struct rb_tree_t *tree, struct rb_node_t *x);
void rb_tree_transplant(struct rb_tree_t *tree, struct rb_node_t *u,
			struct rb_node_t *v);

#endif
