#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Tree
{
    int num;
    int depth;
    struct Tree*left;
    struct Tree*right;
}tree;

void DLR(tree*t)
{
    if(t!=NULL)
    {if(t->left==NULL&&t->right==NULL)
    {
        printf("%d %d\n",t->num,t->depth);
    }
      DLR(t->left);
      DLR(t->right);
    }
}
tree *head=NULL,*p,*temp;
int main ()
{int n,i,x,Dep=1,flag;
scanf("%d",&n);
for(i=0;i<n;i++)
{
    scanf("%d",&x);
    //printf("%d ",x);
    temp=(tree*)malloc(sizeof(tree));
    temp->num=x;
    temp->left=NULL;
    temp->right=NULL;
    temp->depth=1;
    if(head==NULL)
    {
        head=temp;
    }
    else{
        p=head;
        Dep=1;
        while(p!=NULL)
        {
            if(x<p->num)
            {
                if(p->left==NULL)
                {Dep++;
                temp->depth=Dep;
                    p->left=temp;
                    break;
                }
                else
                {Dep++;
                    p=p->left;

                }
            }

            if(x>=p->num)
            {
                if(p->right==NULL)
                {Dep++;
                    p->right=temp;
                    temp->depth=Dep;
                    break;
                }
                else
                {Dep++;
                    p=p->right;
                }
            }
        }
    }
}
p=head;
DLR(p);
    return 0;
}

