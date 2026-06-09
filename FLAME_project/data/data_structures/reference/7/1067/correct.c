/*
//recurse
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<ctype.h>
#define N 10010
int num, idx, n;

int root, e[N], ch[N][2], h[N], stk[N], idx, top = -1;

void add(int *t, int H)
{
    if(!*t)
    {
        e[++ idx] = num;
        h[idx] = H; 
        *t = idx;//tr[*t].l or r = idx
    }
    else if(num < e[*t])
        add(&ch[*t][0], H + 1);
    else if(num >= e[*t])
        add(&ch[*t][1], H + 1);
}
void pre()
{
    stk[++ top] = e[0];
    while(top > -1)
    {
        while()
        printf("%d ", stk[top]);
        while(ch[top][1])
            stk[++ top] = e[ch[top][1]];
        while(ch[top][0])
            stk[++ top] = e[ch[top][0]];
    }
}
void tra(int t)
{
    if(!ch[t][0] && !ch[t][1])
        printf("%d %d\n", e[t], h[t]);
    if(ch[t][0])
        tra(ch[t][0]);
    if(ch[t][1])
        tra(ch[t][1]);
}
int main()
{
    scanf("%d", &n);
    while (n --)
    {
        scanf("%d", &num);
        add(&ch[0][1], 1);
    }   
    pre();
    return 0;
}
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>
typedef struct tree{
    int val;
    struct tree* left;
    struct tree* right;
    int depth;
}tree;
int m,i,n,depth=1;
tree* root=NULL;
int j=0;
void VISIT(tree* t)// 
{
//	printf("j:%d:",j);
//	j++;
 printf("%d %d\n",t->val,t->depth);
}
void inorder(tree* t)
{
    if(t!=NULL){
        inorder(t->left);
        if(t->left==NULL && t->right==NULL)   VISIT(t);    //
        inorder(t->right);
    }
}
tree* InsertBST(tree* t,int value,int depth) //
{
 if(t==NULL)
 {
  t=(tree*)malloc(sizeof(tree));
  t->left=t->right=NULL;
  t->val=value;
  t->depth=depth;
  return t;
 }
 else if(value< t->val)
 {
  t->left=InsertBST(t->left,value,depth+1);
  return t;
 } 
 else
 {
  t->right=InsertBST(t->right,value,depth+1);
  return t;
 } 
}
int main()
{ 
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  scanf("%d",&m);
  root = InsertBST(root,m,1);
 }
//printf("\nin\n");
 inorder(root);
// printf("out\n");
 return 0;
}



/*
non - recurse
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<ctype.h>
#define N 100
int e[N], ch[N][2], h[N], num, idx = 1, n;
void init()
{
    scanf("%d", &n);
    scanf("%d", &e[0]);
    h[0] = 1;
    n --;
}
void add()
{
    scanf("%d", &num);
    int tmp = 0;
    h[idx] = 2; e[idx] = num;
    while (1)
    {
        if(num < e[tmp])
        {
            if(ch[tmp][0])
                tmp = ch[tmp][0];
            else
            {
                ch[tmp][0] = idx;
                idx ++;
                break;
            }  
        }
        else if(num >= e[tmp])
        {
            if(ch[tmp][1])
                tmp = ch[tmp][1];
            else
            {
                ch[tmp][1] = idx;
                idx ++;
                break;
            }
        }
        h[idx] ++;
    }
}
void tra(int t)
{
    if(!ch[t][0] && !ch[t][1])
        printf("%d %d\n", e[t], h[t]);
    if(ch[t][0])
        tra(ch[t][0]);
    if(ch[t][1])
        tra(ch[t][1]);
}
int main()
{
    init();
    while (n --)
        add();
    tra(0);
    return 0;
}
*/
/*
//heap n - branched trees?
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<ctype.h>
#define N 100
int e[N], ch[N][2], h[N], num, idx = 1, n;
void init()
{
    scanf("%d", &n);
    scanf("%d", &e[0]);
    h[0] = 1;
    n --;
}
void add()
{
    scanf("%d", &num);
    int tmp = 0;
    h[idx] = 2; e[idx] = num;
    while (1)
    {
        if(num < e[tmp])
        {
            if(ch[tmp][0])
                tmp = ch[tmp][0];
            else
            {
                ch[tmp][0] = idx;
                idx ++;
                break;
            }  
        }
        else if(num >= e[tmp])
        {
            if(ch[tmp][1])
                tmp = ch[tmp][1];
            else
            {
                ch[tmp][1] = idx;
                idx ++;
                break;
            }
        }
        h[idx] ++;
    }
}
void tra(int t)
{
    if(!ch[t][0] && !ch[t][1])
        printf("%d %d\n", e[t], h[t]);
    if(ch[t][0])
        tra(ch[t][0]);
    if(ch[t][1])
        tra(ch[t][1]);
}
int main()
{
    init();
    while (n --)
        add();
    tra(0);
    return 0;
}
*/
