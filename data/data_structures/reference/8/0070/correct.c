#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
typedef struct node{
	char a[100];
//	int data;
	int num;
	struct node *left,*right;
}ec;
ec *root=NULL;

void search(int a);
void search2(int a);
int a, b, t[105][105], n[105], m[105], flag;
int main()
{
    int x, y,i=0,k=0;
    scanf("%d %d", &a, &b);
    while(i < b)
    {
        scanf("%d %d", &x, &y);
        t[x][y] = 1;
        t[y][x] = 1;
        i++;
    }
    search(0);
    printf("\n");
    for (k = 0; k < 102; k++)
    {
        n[k] = 0;
        flag = 0;
    }
    search2(0);
    printf("\n");
    for (k = 0; k < 102; k++)
    {
        n[k] = 0;
        flag = 0;
    }
    scanf("%d",&x);
    n[x] = 1;
    search(0);
    printf("\n");
    for (k = 0; k < 102; k++)
    {
        n[k] = 0;
        flag = 0;
    }
    n[x] = 1;
    search2(0);
    printf("\n");
    for (k = 0; k < 102; k++)
    {
        n[k] = 0;
        flag = 0;
    }
}

void search(int p)
{
	int i;
    if (flag == 0)
    {
        printf("%d", p);
        flag = 1;
    }
    else
    {
        printf(" %d", p);
    }
    n[p] = 1;
    for (i = 1; i <= a; i++)
    {
        if (t[p][i] == 1 && n[i] == 0)
        {
            search(i);
        }
    }
}

void search2(int p)
{
    int g,i,j,r;
    m[1] = p;
    
    for (j = 1, r = 1; j <= r;)
    {
        g = m[j++];
        if (n[g] == 1)
        {
            continue;
        }
        if (flag == 0)
        {
            printf("%d", g);
            flag = 1;
        }
        else
        {
            printf(" %d",g);
        }

        n[g] = 1;
        for (i = 1; i <= a; i++)
        {
            if (t[g][i] == 1 && n[i] == 0)
            {
                m[++r] = i;
            }
        }
    }
}
ec *bt(ec *root,char b[])
{
	if(root==NULL){
		root=(ec*)malloc(sizeof(ec));
		strcpy(root->a,b);
		root->left=NULL;
		root->right=NULL;
		root->num++;
		
	}else if(strcmp(root->a,b)>0){
		root->left=bt(root->left,b);
		
	}else if(strcmp(root->a,b)<0){
		root->right=bt(root->right,b);
	}else if(strcmp(root->a,b)==0){
		root->num++;
	}
	return root;
}
void zhong(ec *root){
	if(root!=NULL){
		zhong(root->left);
		printf("%s %d\n",root->a,root->num);
		zhong(root->right);
	}
}



