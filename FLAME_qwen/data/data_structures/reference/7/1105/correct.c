#include <stdio.h>
#include <stdlib.h>
struct tree{
int num;
int tall;
int x;
struct tree *left;
struct tree *right;
};
struct tree *p,*first,op[100];
void putout(struct tree q)
{
    struct tree *up;
    if(q.left!=NULL)
    {
        up=q.left;putout(*up);
    }
    if(q.right!=NULL)
    {
        up=q.right;putout(*up);
    }
            if(q.left==NULL&&q.right==NULL)
            printf("%d %d\n",q.num,q.tall);
}
int main()
{
    int n,k,i,m;
    scanf("%d",&n);
    first=NULL;
    for(i=0;i<n;i++)
    {
        scanf("%d",&k);
        op[i].num=k;
        op[i].x=i;
        if(i==0)
        {
            op[i].tall=1;
            continue;
        }
        m=0;
        while(1)
        {
            if(op[i].num<op[m].num)
            {
                if(op[m].left==NULL)
                {
                    op[m].left=&op[i];
                    op[i].tall=op[m].tall+1;
                    break;
                }
                else
                {
                    m=op[m].left->x;continue;
                }
            }
            if(op[i].num>=op[m].num)
            {
                if(op[m].right==NULL)
                {
                    op[m].right=&op[i];
                    op[i].tall=op[m].tall+1;
                    break;
                }
                else
                {
                    m=op[m].right->x;continue;
                }
            }
        }
    }
    putout(op[0]);
    return 0;
}

