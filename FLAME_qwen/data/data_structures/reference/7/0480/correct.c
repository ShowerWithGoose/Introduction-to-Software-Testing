#include<stdio.h>
#include<ctype.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>

struct tNode{
    int num;
    int high;
    struct tNode *left,*right,*parent;
}node;

struct tNode *root,*p;


void insert(int k)
{
    struct tNode *pp,*pt;
    pp = root;
    //printf("\np->num:%d",p->num);
    while(pp != NULL)
    {
        pt = pp;
        if(pp->num > k)
        {
            pp=pp->left;
        }
        else if(pp->num <= k)
        {
            pp=pp->right;
        }
        else if(pp->num == k)
        {
            break;
        }
        p->high++;
    }

    if(pt->num > k)
    {
        pt->left = p;
    }
    else if(pt->num <= k)
    {
        pt->right = p;
    }
    else if(pt->num == k)
    {
        //printf("\nhenhenaaaaaa\n");
    }
    //printf("pt->num:%d\n",pt->num);
}
void ori(struct tNode *z,int temp)
{
        p->left = NULL;
        p->right = NULL;
        p->parent = NULL;
        p->num = temp;
        p->high = 1;
}

void outputLeaf(struct tNode *a)
{
    if(a == NULL)
    {

    }
    else if(a->left == NULL&&a->right == NULL)
    {
        printf("%d %d\n",a->num,a->high);
        free(a);
    }
    else
    {
        outputLeaf(a->left);
        outputLeaf(a->right);
        free(a);
    }


}

int main()
{
    int n,temp,h =1;
    int i,j,k;
    //int
    scanf("%d",&n);
    for(i = 1;i <= n;i++)
    {
        scanf("%d",&temp);
        p = malloc(sizeof(struct tNode));
        ori(p,temp);
        if(i == 1)
        {
            root = p;
            continue;
        }
        p->num = temp;
        //printf("\np->num:%d\n",p->num);
        insert(p->num);
    }
    //printf("\nsuccess\n");
    outputLeaf(root);
    return 0;
}

