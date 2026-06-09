#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Traversal
{int node;
struct Traversal *next;
}trave;
trave *v[105],*p,*q,*temp;
int judge[105]={0},queue[105]={0};
//深度优先遍历；
int DFS(trave *a)
{int k;
trave*p;
if(a==NULL){return 0;}
      if(judge[a->node]==0)
      {printf("%d ",a->node);judge[a->node]=1;}

      for(p=v[a->node];p!=NULL;p=p->next)
      {//printf("%d-",p->node);
          if(judge[p->node]==0)
      {
          DFS(v[p->node]);
      }

      }
    return 0;
}
//广度优先遍历；
int BFS(trave *a,int top)
{
    int k;
    trave*p;
    p=a;
    //printf("%d ",a->node);
    if(p->next!=NULL)
    {
        printf("%d ",a->node);
    judge[a->node]=1;
        for(p=a->next;p!=NULL;p=p->next)
        {if(judge[p->node]==0)
           {top++;
        queue[top]=p->node;
        //printf("%d-",p->node);
           }
        }

        for(k=0;k<=top;k++)
        {p=v[queue[k]];
            if(judge[queue[k]]==0)
        BFS(p,top);
        }

    }

    return 0;
}
int main()
{int Node,Line,point1,point2,i,_delet;
scanf("%d%d",&Node,&Line);
for(i=0;i<Node;i++)
    {v[i]=(trave*)malloc(sizeof(trave));
    v[i]->next=NULL;
    v[i]->node=i;}
for(i=0;i<Line;i++)
{
    scanf("%d%d",&point1,&point2);

    q=p=v[point1];
    //printf("%d\n",p->node);
    if(p->next==NULL)
    {
    p=(trave*)malloc(sizeof(trave));
    p->node=point2;
    p->next=NULL;
    q->next=p;
    q=p;
    }
    else if(p->next!=NULL)
    {
        p=p->next;
        while(point2>=p->node)
        {
            if(p->next!=NULL)
            {
                p=p->next;
                q=q->next;
            }
            else if(p->next==NULL)
            {
                temp=(trave*)malloc(sizeof(trave));
                temp->node=point2;
                temp->next=NULL;
                p->next=temp;
                q=p;
                break;
            }
        }

        if(point2<p->node)
        {
            temp=(trave*)malloc(sizeof(trave));
            temp->node=point2;
            temp->next=p;
            q->next=temp;
        }
    }


q=p=v[point2];
    //printf("%d\n",p->node);
    if(p->next==NULL)
    {
    p=(trave*)malloc(sizeof(trave));
    p->node=point1;
    p->next=NULL;
    q->next=p;
    q=p;
    }
    else if(p->next!=NULL)
    {
        p=p->next;
        while(point1>=p->node)
        {
            if(p->next!=NULL)
            {
                p=p->next;
                q=q->next;
            }
            else if(p->next==NULL)
            {
                temp=(trave*)malloc(sizeof(trave));
                temp->node=point1;
                temp->next=NULL;
                p->next=temp;
                q=p;
                break;
            }
        }

        if(point1<p->node)
        {
            temp=(trave*)malloc(sizeof(trave));
            temp->node=point1;
            temp->next=p;
            q->next=temp;
        }
    }
}
/*for(i=0;i<Node;i++)
{if(v[i]!=NULL)
    {p=v[i];
        while(p!=NULL)
            {
                printf("%d ",p->node);
                p=p->next;
            }
            printf("\n");
        }
}*/
DFS(v[0]);
for(i=0;i<Node+1;i++)
{
    judge[i]=0;
}
printf("\n");
BFS(v[0],-1);
for(i=0;i<Node+1;i++)
{
    judge[i]=0;
}
printf("\n");
scanf("%d",&_delet);
for(i=0;i<Node;i++)
{if(i==_delet)
{
    judge[i]=1;
    p=v[i]->next;
    free(p);
    v[i]->next=NULL;
}
else if(i!=_delet){p=v[i]->next;q=v[i];
    for(p;p!=NULL;q=q->next,p=p->next)
    { //printf("----%d---\n",p->node);
        if(p->node==_delet)
        {if(p->next==NULL)q->next=NULL;
        else if(p->next!=NULL)
        {

            q->next=p->next;

        }
            free(p);
            break;
        }
    }
       }

}

/*for(i=0;i<Node;i++)
{if(v[i]!=NULL)
    {p=v[i];
        while(p!=NULL)
            {
                printf("%d ",p->node);
                p=p->next;
            }
            printf("\n");
        }
}*/
DFS(v[0]);
for(i=0;i<Node+1;i++)
{if(i!=_delet)
    judge[i]=0;
}
for(i=0;i<3*Node;i++)
{
    queue[i]=0;
}
printf("\n");
BFS(v[0],-1);
return 0;}

