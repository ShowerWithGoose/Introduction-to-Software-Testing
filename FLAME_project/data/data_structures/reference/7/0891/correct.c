#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct tree{
    int data;
    int line;
    struct tree *left,*right;
};
typedef struct tree *tr;
tr t,q,p,r;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            ;

void pr(tr t)
{
    if(t==NULL)
        return;
    if(t->left==NULL&&t->right==NULL)
        printf("%d %d\n",t->data,t->line);
    pr(t->left);
    pr(t->right);
    return;
}
int main()
{
    int n,h=0;
    scanf("%d",&n);
    t=NULL;

    for(int i=0;i<n;i++)
    {
        p=(tr)malloc(sizeof(tr));
        p->left=NULL;
        p->right=NULL;

        scanf("%d",&p->data);
        if(t==NULL)
        {
            p->line=1;
            t=p;
            q=p;
            h=t->line;
            continue;
        }
        else
        {
            for(int j=0;j<h+1;j++)
            {
                p->line=q->line;
                if(p->data<q->data)
                {
                    if(q->left==NULL)
                    {
                        q->left=p;
                        q=p;
                        q->line++;
                        break;
                    }
                    else
                    {
                        q=q->left;
                    }
                }
                else
                {
                    if(q->right==NULL)
                    {
                        q->right=p;
                        q=p;
                        q->line++;
                        break;
                    }
                    else
                        q=q->right;
                }
            }
            h=p->line;
        }
        q=t;
    }
    pr(t);
}

