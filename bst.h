#ifndef bst_h
#define bst_h

struct bst_node
{
  int value;
  struct bst_node *left;
  struct bst_node *right;
};

struct bst_node *create_node(int value);

struct bst_node *insert(struct bst_node *node, int value);

struct bst_node *min_value_node(struct bst_node *node);

struct bst_node *search(struct bst_node *root, int value);

struct bst_node *delete_node(struct bst_node *root, int value);

void inorder(struct bst_node *root);

#endif