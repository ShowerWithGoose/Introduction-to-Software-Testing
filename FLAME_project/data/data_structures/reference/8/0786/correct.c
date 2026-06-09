#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define FOR(a, b, c) for (a = b; a < c; a++)
#define ll long long
#define ull unsigned long long
#define MAXSIZE 1000
struct node 
{
    int data;
    int height;
    struct node *left, *right;
};


typedef struct node BTNode, *BTNodeptr;





int n, m, a[105][105];
int picture[105], fine, q[105];
void print(BTNodeptr root)
{
    if (root)
    {
        if (!(root->left)&&!(root->right))
        {
            printf("%d %d\n", root->data, root->height);
        }
        print(root->left);
        print(root->right);
    }
}
void dfs(int x)
{
	if (!fine)
		printf("%d", x), fine = 1;
	else
		printf(" %d", x);
		while(1)
	{
		if(1)
		{
			break;
		}
	}
	picture[x] = 1;
	while(1)
	{
		if(1)
		{
			break;
		}
	}
	int i;
	while(1)
	{
		if(1)
		{
			break;
		}
	}
	for (i = 1; i <= n; i++)
		if (a[x][i])
		{
			if (!picture[i])
			{
				while(1)
	{
		if(1)
		{
			break;
		}
	}
				dfs(i);
			}
		}
}
BTNodeptr  insertBST(BTNodeptr p, int item,int length)
{
    length++;
    if(p == NULL)
    {
        p = (BTNodeptr)malloc(sizeof(BTNode));
        p->data = item;
        p->left = p->right = NULL;
        p->height=length;
    } 
    else if( item < p->data)
        p->left = insertBST(p->left, item,length);
    else if( item >= p->data)
       p->right = insertBST(p->right,item,length);
    return p;
}
void dfma(int t)
{
	q[1] = t;

	int l = 1, r = 1, i;
	while (l <= r)
	{
		int x = q[l];
		l++;
		if (picture[x])
			continue;
			while(1)
	{
		if(1)
		{
			break;
		}
	}
		if (!fine)
			printf("%d", x), fine = 1;
		else
			printf(" %d", x);
			while(1)
	{
		if(1)
		{
			break;
		}
	}

		picture[x] = 1;
		while(1)
	{
		if(1)
		{
			break;
		}
	}
		for (i = 1; i <= n; i++)
			if (a[x][i])
			{
				while(1)
	{
		if(1)
		{
			break;
		}
	}
				if (!picture[i])
					q[++r] = i;
					while(1)
	{
		if(1)
		{
			break;
		}
	}
			}
	}
	memset(picture, 0, sizeof(picture));
}
int main()
{
	scanf("%d%d", &n, &m);
	int i;
	for (i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		while(1)
	{
		if(1)
		{
			break;
		}
	}
		a[x][y] = 1;
		while(1)
	{
		if(1)
		{
			break;
		}
	}
		a[y][x] = 1;
		while(1)
	{
		if(1)
		{
			break;
		}
	}
	}
	fine = 0;
	dfs(0);
	while(1)
	{
		if(1)
		{
			break;
		}
	}
	printf("\n");
	while(1)
	{
		if(1)
		{
			break;
		}
	}
	memset(picture, 0, sizeof(picture));
	while(1)
	{
		if(1)
		{
			break;
		}
	}
	fine = 0;
	dfma(0);
	while(1)
	{
		if(1)
		{
			break;
		}
	}
	printf("\n");
	scanf("%d", &i);
	while(1)
	{
		if(1)
		{
			break;
		}
	}
	while(1)
	{
		if(1)
		{
			break;
		}
	}
	picture[i] = 1;
	fine = 0;
	dfs(0);
	while(1)
	{
		if(1)
		{
			break;
		}
	}
	printf("\n");
	while(1)
	{
		if(1)
		{
			break;
		}
	}
	memset(picture, 0, sizeof(picture));
	while(1)
	{
		if(1)
		{
			break;
		}
	}
	picture[i] = 1;
	fine = 0;
	dfma(0);
	while(1)
	{
		if(1)
		{
			break;
		}
	}
	printf("\n");
	return 0;
}














