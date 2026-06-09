#include<stdio.h>
#include<stdlib.h>
typedef struct linknode
{
    struct linknode *prior;
    struct linknode *next;
    int id;
}linknode,*linklist;
linklist *graphnode;
int num_node,num_link;
int flag[400];
int queue[400];
int head,rear;
void cleanflag(int n)
{
    int i;
    for(i=0;i<n;i++)
        flag[i]=0;
}
void initialnode(linklist p,int i)
{
    p->next=NULL;
    p->id=i;
}
void creatgraph(int node1,int node2)
{
    linklist place,tmp;
    place=graphnode[node1];
    while(place->next!=NULL)
    {
        if(place->next->id>node2)
            break;
        place=place->next;
    }
    tmp=(linklist)malloc(sizeof(linknode));
    initialnode(tmp,node2);
    if(place->next!=NULL)
    {
        place->next->prior=tmp;
        tmp->next=place->next;
    }
    tmp->prior=place;
    place->next=tmp;
}
void deepsearch(int id)
{
    linklist p=graphnode[id]->next;
    if(flag[id]==0)
    {
        flag[id]=1;
        printf("%d ",id);
    }
    while(p!=NULL)
    {
        if(flag[p->id]==0)
            deepsearch(p->id);
        p=p->next;
    }
}
void breadsearch(int id)
{
    linklist p=graphnode[id]->next;
    if(flag[id]==0)
    {
        printf("%d ",id);
        flag[id]=1;
    }
    head++;
    while(p!=NULL)
    {
        if(flag[p->id]==0)
        {
            rear++;
            queue[rear]=p->id;
        }
        p=p->next;
    }
    if(head>rear)
        return;
    breadsearch(queue[head]);
}
void delate_link(int s,int d)
{
    linklist p=graphnode[s]->next,t;
    while(p!=NULL)
    {
        if(p->id==d)
        {
            if(p->next!=NULL)
            {
                t=p->prior;
                p=p->next;
                t->next=p;
                p->prior=t;
                return;
            }
            else
            {
                t=p->prior;
                t->next=NULL;
                return;
            }
        }
        else
            p=p->next;
        //printf("test");
    }
}
void delate(int d)
{
    linklist p=graphnode[d]->next;
    while(p!=NULL)
    {
        delate_link(p->id,d);
        p=p->next;
        //printf("test");
    }
    return;
}
int main()
{
    int i;
    int node1,node2;
    int d;
    scanf("%d %d",&num_node,&num_link);
    graphnode=(linklist *)calloc(num_node,sizeof(linklist));
    for(i=0;i<num_node;i++)
    {
        graphnode[i]=(linklist)malloc(sizeof(linknode));
        initialnode(graphnode[i],i);
        graphnode[i]->prior=NULL;
    }
    for(i=1;i<=num_link;i++)
    {
        scanf("%d %d",&node1,&node2);
        creatgraph(node1,node2);
        creatgraph(node2,node1);
    }
    scanf("%d",&d);
    deepsearch(0);
    printf("\n");
    cleanflag(num_node);
    queue[0]=0;
    head=0;
    rear=head;
    breadsearch(0);
    printf("\n");
    delate(d);
    cleanflag(num_node);
    deepsearch(0);
    printf("\n");
    cleanflag(num_node);
    queue[0]=0;
    head=0;
    rear=head;
    breadsearch(0);
    return 0;
}



