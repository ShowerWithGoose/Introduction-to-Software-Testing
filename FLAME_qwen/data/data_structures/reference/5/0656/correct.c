#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coe;
    int power;
    struct node * next;
};

int main()
{
    int co,po;
    char t;
    struct node *(head[4])={NULL},*(p[4])={NULL},*(q[4])={NULL};
    while(1)
    {
        scanf("%d%d",&co,&po);
        p[1]=(struct node *)malloc(sizeof(struct node));
        p[1]->coe=co;
        p[1]->power=po;
        if(head[1]==NULL)
        {
            head[1]=p[1];
            q[1]=p[1];
        }
        else
        {
            q[1]->next=p[1];
            q[1]=p[1];
        }
        scanf("%c",&t);
        if(t=='\n') break;
    }
    p[1]->next=NULL;
    p[1]=head[1];
    while(1)
    {
        scanf("%d%d",&co,&po);
        p[2]=(struct node *)malloc(sizeof(struct node));
        p[2]->coe=co;
        p[2]->power=po;
        if(head[2]==NULL)
        {
            head[2]=p[2];
            q[2]=p[2];
        }
        else
        {
            q[2]->next=p[2];
            q[2]=p[2];
        }
        scanf("%c",&t);
        if(t=='\n') break;
    }
    p[2]->next=NULL;
    p[2]=head[2];
    while(p[1]!=NULL)
    {
        p[2]=head[2];
        while(p[2]!=NULL)
        {
            co=p[1]->coe*p[2]->coe;
            po=p[1]->power+p[2]->power;
            if(head[3]==NULL)
            {
                p[3]=(struct node *)malloc(sizeof(struct node));
                p[3]->coe=co;
                p[3]->power=po;
                head[3]=p[3];
                q[3]=p[3];
                p[3]->next=NULL;
            }
            else
            {
                q[3]=head[3];
                p[3]=head[3];
                if(po>head[3]->power)
                {
                    p[3]=(struct node *)malloc(sizeof(struct node));
                    p[3]->coe=co;
                    p[3]->power=po;
                    p[3]->next=head[3];
                    q[3]=p[3];
                }
                else if(po==head[3]->power)  head[3]->coe+=co;
                else
                {
                    p[3]=head[3];
                    while(p[3]->next!=NULL)
                    {
                        if(po>=p[3]->next->power)
                        {
                            if(po==p[3]->next->power)    
                            {
                                p[3]->next->coe+=co;
                                break;
                            }
                            else
                            {
                                q[3]=p[3];
                                p[3]=(struct node *)malloc(sizeof(struct node));
                                p[3]->coe=co;
                                p[3]->power=po;
                                p[3]->next=q[3]->next;
                                q[3]->next=p[3];
                                break;
                            }
                        }
                        p[3]=p[3]->next;
                    }
                    if(p[3]->next==NULL)
                    {
                        q[3]=p[3];
                        p[3]=(struct node *)malloc(sizeof(struct node));
                        p[3]->coe=co;
                        p[3]->power=po;
                        p[3]->next=NULL;
                        q[3]->next=p[3];
                    }
                }
            }
            p[2]=p[2]->next;
        }
        p[1]=p[1]->next;
    }
    p[3]=head[3];
    while(p[3]!=NULL)
    {
        printf("%d %d ",p[3]->coe,p[3]->power);
        p[3]=p[3]->next;
    }
    return 0;
}

