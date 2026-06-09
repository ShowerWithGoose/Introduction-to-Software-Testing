#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define clear(a) memset(a,0,sizeof(a))
typedef struct student
{
    int score;
    int le_sw,ri_sw;
    struct student *left,*right;
}LinkList;
LinkList *creat(int n);
int main()
{
    int total,in;
    scanf("%d",&total);
    scanf("%d",&in);
    LinkList *hd=creat(in);
    hd=hd->left;
    LinkList *moving,*cre,*parent;
    int i1,i2;
    for(i1=2;i1<=total;i1++)
    {
        scanf("%d",&in);
        moving=hd;
        while(1)
        {
            if(in<moving->score)
            {
                if(moving->le_sw==0)
                {
                    moving->le_sw=1;
                    cre=(LinkList*)malloc(sizeof(LinkList));
                    moving->left=cre;
                    cre->le_sw=0;
                    cre->ri_sw=0;
                    cre->score=in;
                    cre->left=NULL;
                    cre->right=NULL;
                    break;
                }
                else
                {
                    moving=moving->left;
                }
            }
            else
            {
                if(moving->ri_sw==0)
                {
                    moving->ri_sw=1;
                    cre=(LinkList*)malloc(sizeof(LinkList));
                    moving->right=cre;
                    cre->le_sw=0;
                    cre->ri_sw=0;
                    cre->score=in;
                    cre->left=NULL;
                    cre->right=NULL;
                    break;
                }
                else
                {
                    moving=moving->right;
                }
            }
        }
    }
    int cnt,turn;
    while(1)
    {
        if(total==1)
        {
            printf("%d 1\n",hd->score);
            break;
        }
        moving=hd;
        cnt=1;
        if(moving->le_sw!=1 && moving->ri_sw!=1)
        {
            break;
        }
        while(1)
        {
            if(moving->le_sw==1)
            {
                turn=0;
                parent=moving;
                moving=moving->left;
                cnt++;
            }
            else if(moving->ri_sw==1)
            {
                turn=1;
                parent=moving;
                moving=moving->right;
                cnt++;
            }
            else if(moving->le_sw==0 && moving->ri_sw==0)
            {
                printf("%d %d\n",moving->score,cnt);
                if(turn==0)
                {
                    parent->le_sw=2;
                }
                else
                {
                    parent->ri_sw=2;
                }
                break;
            }
            else
            {
                if(turn==0)
                {
                    parent->le_sw=2;
                }
                else
                {
                    parent->ri_sw=2;
                }
                break;
            }
        }
    }
    return 0;
}
LinkList *creat(int n)
{
    LinkList *head,*node,*end;
    head=(LinkList*)malloc(sizeof(LinkList));
    end=head;
    node=(LinkList*)malloc(sizeof(LinkList));
    node->score=n;
    node->le_sw=0;
    node->ri_sw=0;
    end->left=node;
    end->right=NULL;
    end=node;
    end->left=NULL;
    end->right=NULL;
    return head;
}
