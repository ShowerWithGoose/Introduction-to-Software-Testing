#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    int high;
    struct node *left, *right;
} Tree;
Tree *first;

Tree *New(Tree *r, int temp, int len)
{
    len++;
    if (r == NULL)
    {
        r= (Tree *)malloc(sizeof(Tree));
        r->data = temp;
        r->left = r->right = NULL;
        first = r;
        r->high = len;
    }
    else if (temp >= r->data)
    {
    	 r->right = New(r->right, temp, len);
	}
    else if (temp < r->data)
    {
    	r->left = New(r->left, temp, len);
	}
       
    return r;
}
void print(Tree *r)
{
    if (r)
    {
        if (!(r->left) && !(r->right))
        {
            printf("%d %d\n", r->data, r->high);
        }
        print(r->left);
        print(r->right);
    }
}

int main()
{
    Tree *r = NULL;
    int n, temp,i,len=0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        r= New(r, temp, len);
    }
    print(r);
    return 0;
}









