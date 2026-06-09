#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int val;
    unsigned int height;
    struct Node *left;
    struct Node *right;
} node;

void traversal(node *);
void traversal(node *r)
{
    if (r == NULL)
        return;
    // printf("Now %d at %u\n", r->val, r->height);
    // if deepest node is reached, print the value and the height
    if (r->left == NULL && r->right == NULL)
    {
        printf("%d %u\n", r->val, r->height);
        return;
    }
    // if not, traverse the left and right subtrees
    traversal(r->left);
    traversal(r->right);
}

node root;

int main()
{
    int count;
    scanf("%d", &count);
    {
        int rootval;
        scanf("%d", &rootval);
        root.val = rootval;
        root.height = 1;
    }
    for (int i = 1; i < count; i++)
    {
        int n;
        node *curr = &root;
        scanf("%d", &n);
        // printf("%d\n", n);
        unsigned int height = 2;
        while (1)
        {
            // if (n == curr->val)
            //     break;
            if (n < (curr->val))
            {
                if (curr->left != NULL)
                {
                    curr = curr->left;
                }
                else
                {
                    curr->left = (node *)malloc(sizeof(node));
                    curr->left->val = n;
                    curr->left->height = height;
                    break;
                }
            }
            else
            {
                if (curr->right != NULL)
                {
                    curr = curr->right;
                }
                else
                {
                    curr->right = (node *)malloc(sizeof(node));
                    curr->right->val = n;
                    curr->right->height = height;
                    break;
                }
            }
            height++;
        }
    }
    node *curr = &root;
    traversal(curr);
    return 0;
}

