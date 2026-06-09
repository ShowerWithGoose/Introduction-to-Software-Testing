#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
struct dian
{
    int data;
    int high;
    struct dian *left;
    struct dian *right;
};
struct dian *top=NULL;

struct dian *build(struct dian *b,int item,int h)
{
    h++;
    if(b==NULL)
    {
        b=(struct dian *)malloc(sizeof(struct dian));
        b->data=item;
        b->high=h;
        b->left=NULL;
        b->right=NULL;
    }
    else if(item<b->data)
        b->left=build(b->left,item,h);
    else if(item>=b->data)
        b->right=build(b->right,item,h);
    return b;
}

void print(struct dian *a)
{
    if(a!=NULL)
    {
        if(a->left==NULL&&a->right==NULL)
        {
            printf("%d %d\n",a->data,a->high);
        }
        print(a->left);
        print(a->right);
    }
    else
        return;
}

int main()
{
    int n,i,item;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&item);
        top=build(top,item,0);
    }
    print(top);
return 0;
}

