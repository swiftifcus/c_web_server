#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

struct bst_node *create_node(int value)
{
  struct bst_node *node = (struct bst_node *)malloc(sizeof(struct bst_node));
  node->value = value;
  node->left = NULL;
  node->right = NULL;
  return node;
};

void inorder(struct bst_node *root)
{
  if (root != NULL)
  {
    inorder(root->left);
    printf("%d -> ", root->value);
    inorder(root->right);
  }
}

struct bst_node *insert(struct bst_node *node, int value)
{
  if (node == NULL)
  {
    return create_node(value);
  }

  if (value < node->value)
  {
    node->left = insert(node->left, value);
  }
  else
  {
    node->right = insert(node->right, value);
  }

  return node;
}

struct bst_node *min_value_node(struct bst_node *node)
{
  struct bst_node *current = node;

  while (current && current->left != NULL)
  {
    current = current->left;
  }

  return current;
}

// returns NULL if not in, otherwise return the node
struct bst_node *search(struct bst_node *root, int value)
{
  if (root == NULL || root->value == value)
  {
    return root;
  }

  if (root->value < value)
  {
    return search(root->right, value);
  }

  return search(root->left, value);
}

struct bst_node *delete_node(struct bst_node *root, int value)
{
  if (root == NULL)
  {
    return root;
  }

  if (value < root->value)
  {
    root->left = delete_node(root->left, value);
  }
  else if (value > root->value)
  {
    root->right = delete_node(root->right, value);
  }
  else
  {
    if (root->left == NULL)
    {
      struct bst_node *temp = root->right;
      free(root);
      return temp;
    }
    else if (root->right == NULL)
    {
      struct bst_node *temp = root->left;
      free(root);
      return temp;
    }

    struct bst_node *temp = min_value_node(root->right);

    root->value = temp->value;
    root->right = delete_node(root->right, temp->value);
  }

  return root;
}