#include <stdio.h>
#include <stdlib.h>

struct tree_node
{
  int value;
  int height;
  struct tree_node *left, *right;
};

struct tree_node* add_tree_node(struct tree_node *parent_node,int value,int height)
{
    if (parent_node == NULL)
    {
        parent_node = (struct tree_node*)malloc(sizeof(struct tree_node));
        parent_node->value = value;
        parent_node->height = height;
        parent_node->left = NULL;
        parent_node->right = NULL;
    } else if (parent_node->value > value)
    {
        parent_node->left = add_tree_node(parent_node->left, value, height+1);
    } else {
        parent_node->right = add_tree_node(parent_node->right, value, height+1);
    }
    return parent_node;
}

void print_and_release_tree_node(struct tree_node *parent_node)
{
    if (parent_node == NULL) return;
    if (parent_node->left != NULL)
    {
        print_and_release_tree_node(parent_node->left);
    }
    if (parent_node->right != NULL)
    {
        print_and_release_tree_node(parent_node->right);
    }
    printf("%d %d\n",parent_node->value,parent_node->height); // @@ This prints all nodes, but the problem requires only leaf nodes. Also, the output format is wrong: it should print each leaf on its own line, but here it prints all nodes in post-order, which is incorrect for the left-to-right leaf order.
    free(parent_node);
}

int main(void)
{
    int total_nodes,value;
    struct tree_node *tree_root=NULL;

    scanf("%d",&total_nodes);
    printf("%d\n",total_nodes); // @@ This extra print of total_nodes is not part of the required output. The problem only expects leaf node values and heights.

    for (int i=0;i<total_nodes;i++)
    {
        scanf("%d",&value);
        printf("%d ",value); // @@ This extra print of each input value is not part of the required output. It should not be here.
        tree_root=add_tree_node(tree_root,value,1);
    }

    print_and_release_tree_node(tree_root);

    return 0;
}