#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
int n, m, a[200][200];
int z[200],y,q[200];
void ppp(int x)
{
	if (!y)
		printf("%d", x), y = 1;
	else
		printf(" %d", x);
	z[x] = 1;
	int i;
	for (i = 1; i <= n; i++)
		if (a[x][i])
		{
			if (!z[i])
			{
			
				ppp(i);
			}
		}
}
void qqq(int t)
{
	q[1] = t;

	int l = 1, r = 1, i;
	while (l <= r)
	{
		int xx = q[l];
		l++;
		if (z[xx])
			continue;
		if (!y)
			printf("%d", xx), y = 1;
		else
			printf(" %d", xx);

		z[xx] = 1;
		for (i = 1; i <= n; i++)
			if (a[xx][i])
			{
				if (!z[i])
					q[++r] = i;
			}
	}
	memset(z, 0, sizeof(z));
}
struct student{
    int no;
    char name[25];
    int num;
};
typedef struct student mmm;
mmm c[200];
int d[200];

int cmp(const void*a,const void *b) {
    mmm aa = *(mmm*)a;
    mmm bb = *(mmm*)b;
    if(aa.num==bb.num){
        return aa.no-bb.no;
    }
    else{
        return aa.num-bb.num;
    }
}

int cmpp(const void*a,const void *b) {
    mmm aa = *(mmm*)a;
    mmm bb = *(mmm*)b;
    return aa.no-bb.no;
}
struct nnn{
	char word[105];
	int nu;
}p[1005];
typedef struct node
{
    char word[20];
    int nu;
    struct node *lchild, *rchild;
} Tree;
Tree *temp, *tempp, *root = NULL, *add = NULL;

Tree *New(char w[]);
Tree *PTFT(Tree *root);
int main()
{
	scanf("%d%d", &n, &m);
	int i;
	for (i = 1; i <= m; i++)
	{
		int xx, y;
		scanf("%d%d", &xx, &y);
		a[xx][y] = 1;
		a[y][xx] = 1;
	}
	y = 0;
	ppp(0);
	printf("\n");
	memset(z, 0, sizeof(z));
	y = 0;
	qqq(0);
	printf("\n");
	scanf("%d", &i);
	z[i] = 1;
	y = 0;
	ppp(0);
	printf("\n");
	memset(z, 0, sizeof(z));
	z[i] = 1;
	y = 0;
	qqq(0);
	printf("\n");
	return 0;
}
Tree *New(char w[])
{
	int i;
    temp = (Tree *)malloc(sizeof(Tree));
    temp->lchild = temp->rchild = NULL;
    for (i = 0; i < 20; i++)
    {
        temp->word[i] = 0;
    }
    strcpy(temp->word, w);
    if (root == NULL)
    {
        temp->nu = 1;
        root = tempp = temp;
    }
    else
    {
        temp->nu = 1;
        for (i = 0; strlen(tempp->word) != 0; i++)
        {
            if (strcmp(temp->word, tempp->word) > 0 && tempp->rchild == NULL)
            {
                tempp = tempp->rchild = temp;
                break;
            }
            if (strcmp(temp->word, tempp->word) > 0 && tempp->rchild != NULL)
                tempp = tempp->rchild;
            if (strcmp(temp->word, tempp->word) == 0)
            {
                tempp->nu++;
                break;
            }
            if (strcmp(temp->word, tempp->word) < 0 && tempp->lchild != NULL)
                tempp = tempp->lchild;
            if (strcmp(temp->word, tempp->word) < 0 && tempp->lchild == NULL)
            {
                tempp = tempp->lchild = temp;
                break;
            }
        }
        tempp = root;
    }
    tempp = root;
    return root;
}

Tree *PTFT(Tree *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    PTFT(root->lchild);
    printf("%s %d", root->word, root->nu);
    printf("\n");
    PTFT(root->rchild);
    /*printf("%s %d", root->word, root->nu);
    printf("\n");*/
    return NULL;
}



