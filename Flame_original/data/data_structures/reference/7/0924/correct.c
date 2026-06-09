#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
int g1, g2, g3, g4, g5;
typedef struct node
{
    int data;
    int high;
    struct node *left, *right;
} Tree;
Tree *first;

Tree *New(Tree *root, int temp, int len); 
void print(Tree *root);                   

int main()
{
    Tree *root = NULL;
    int n, temp, i;
    scanf("%d", &n);
    for(g1=0;g1<15;g1++)
	{
		for(g2=0;g2<n;g2++)
		{
			if(g2%2==0)
			g3=g1;
			else
			g4=g3;
			g5=g4;
			g3=g5;
		}
	}
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &temp);
for(g1=0;g1<15;g1++)
	{
		for(g2=0;g2<n;g2++)
		{
			if(g2%2==0)
			g3=g1;
			else
			g4=g3;
			g5=g4;
			g3=g5;
		}
	}
        int len = 0;
        root = New(root, temp, len);
    }
    print(root);
    return 0;
}

Tree *New(Tree *root, int temp, int len)
{
    len++;
    if (root == NULL)
    {
    	for(g1=0;g1<15;g1++)
	{
		for(g2=0;g2<14;g2++)
		{
			if(g2%2==0)
			g3=g1;
			else
			g4=g3;
			g5=g4;
			g3=g5;
		}
	}
        root = (Tree *)malloc(sizeof(Tree));
        root->data = temp;
        root->left = root->right = NULL;
        first = root;
        root->high = len;
        	for(g1=0;g1<15;g1++)
	{
		for(g2=0;g2<14;g2++)
		{
			if(g2%2==0)
			g3=g1;
			else
			g4=g3;
			g5=g4;
			g3=g5;
		}
	}
    }
    else if (temp < root->data)
        root->left = New(root->left, temp, len);
    else if (temp >= root->data)
        root->right = New(root->right, temp, len);
    return root;
}

void print(Tree *root)
{
    if (root)
    {
        if (!(root->left) && !(root->right))
        {
        		for(g1=0;g1<15;g1++)
	{
		for(g2=0;g2<14;g2++)
		{
			if(g2%2==0)
			g3=g1;
			else
			g4=g3;
			g5=g4;
			g3=g5;
		}
	}
            printf("%d %d\n", root->data, root->high);
        }
        print(root->left);
        print(root->right);
    }
}





