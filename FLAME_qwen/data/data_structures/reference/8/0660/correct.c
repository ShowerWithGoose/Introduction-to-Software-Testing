

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MaxV    100

//edge
typedef struct edge{
       int  adjvex;
       int  weight;
       struct edge  *next;
 }ELink;
//Vertex
typedef struct ver{
      int  vertex;
      ELink  *link;
}VLink;

void Initialize(VLink *G, int count);
void TransverseDeep(VLink *G,int count, int isdeleted, int deleteVerNo);
void TransverseWide(VLink *G,int count, int isdeleted, int deleteVerNo);
void BuildGraph(VLink *G, int vertex1, int vertex2);
void DeleteOneVertex(VLink *G,int deleteVerNo);
void Cleanup(VLink *G, int count);


int main()
{
    VLink Graph[MaxV];
    int countV, countE;//vertex & Edge count
    int i;
    int vertex1,vertex2;
    int vertexDelete;
    //1.read vertex count and edge count
    scanf("%d %d", &countV,&countE);
    //1.1.Initialize Graph;
    Initialize(Graph,countV);
    //2.read edges
    for(i=0;i<countE;i++)
    {
        scanf("%d %d", &vertex1,&vertex2);
        //2.1 build the graph // little vertex in front
        BuildGraph(Graph,vertex1,vertex2);
    }
    //3.read vertex no to be deleted
    scanf("%d",&vertexDelete);
    //4.Transverse deep
    TransverseDeep(Graph,countV,0,0);
    //5.Transverse wide
    TransverseWide(Graph,countV,0,0);
    //6.delete vertex
    DeleteOneVertex(Graph,vertexDelete);
    //7.Transverse deep
    TransverseDeep(Graph,countV,1,vertexDelete);
    //8.transverse wide
    TransverseWide(Graph,countV,1,vertexDelete);
    //9.cleanup
    Cleanup(Graph,countV);
    return 0;
}
void Initialize(VLink *G, int count)
{
    int i;
    for (i=0;i<count;i++)
    {
        G[i].link=NULL;
        G[i].vertex=i;
    }
}
void AddELink(VLink *Vertex, int vertexAdj)
{
    ELink *nextE,*temp,*prior;
    nextE=malloc(sizeof(ELink));
    nextE->adjvex=vertexAdj;
    //nextE->weight=0;
    nextE->next=NULL;
    if(Vertex->link==NULL)Vertex->link=nextE;
    else
    {
        temp=Vertex->link;
        if(temp->adjvex>vertexAdj)
        {
            nextE->next=Vertex->link;
            Vertex->link=nextE;
        }
        else
        {
            //sort
            prior=temp=Vertex->link;
            while(temp!=NULL)
            {
                //sort
                if(temp->adjvex>vertexAdj)
                {
                    prior->next=nextE;
                    nextE->next=temp;
                    break;
                }
                else
                {
                    prior=temp;
                    temp=temp->next;
                    if(temp==NULL)
                    {
                        prior->next=nextE;
                        break;
                    }
                }
            }
        }
    }
}
void BuildGraph(VLink *G, int vertex1, int vertex2)
{
    //add vertex2 ELink to vertex1
    AddELink(&G[vertex1],vertex2);
    //add vertex1 ELink to vertex2
    AddELink(&G[vertex2],vertex1);
}
void DeleteOneVertex(VLink *G,int deleteVerNo)
{
    return;
}
void Cleanup(VLink *G, int count)
{
    int i;
    ELink  *temp,*nextp;
    for (i=0;i<count;i++)
    {
        temp=G[i].link;
        while(temp!=NULL)
        {
            nextp=temp->next;
            free(temp);
            temp=nextp;
        }
    }
}
void TransDeep(int i,VLink *G,int isdeleted, int deleteVerNo, int *IsTransversed)
{
    ELink *edge;
    if(isdeleted&&i==deleteVerNo)return;
    if(IsTransversed[i]==0)
    {
        IsTransversed[i]=1;
        if(i==0)printf("%d",i);
        else printf(" %d", i);
        edge=G[i].link;
        while(edge!=NULL)
        {
            TransDeep(edge->adjvex, G,isdeleted,deleteVerNo,IsTransversed);
            edge=edge->next;
        }
    }
}
void TransverseDeep(VLink *G,int count, int isdeleted, int deleteVerNo)
{
    int IsTransversed[MaxV];
    int i;
    for (i=0;i<count;i++)IsTransversed[i]=0;
    for (i=0;i<count;i++)
    {
        TransDeep(i,G,isdeleted,deleteVerNo,IsTransversed);
    }
    printf("\n");
    return;
}
void TransWideEdges(int i,VLink *G,int isdeleted, int deleteVerNo, int *IsTransversed,int *quene,int *queneStart,int *queneEnd)
{
    int j;
    ELink *edge;
    if(isdeleted&&i==deleteVerNo)return;
    if(IsTransversed[i]==0)
    {
        IsTransversed[i]=1;
        if(i==0)printf("%d",i);
        else printf(" %d", i);
    }
    edge=G[i].link;
    while(edge!=NULL)
    {
        if(isdeleted&&edge->adjvex==deleteVerNo)
        {
            edge=edge->next;
            continue;
        }
        if(!IsTransversed[edge->adjvex])
        {
            printf(" %d",edge->adjvex);
            quene[*queneEnd]=edge->adjvex;
            (*queneEnd)++;
            IsTransversed[edge->adjvex]=1;
        }
        edge=edge->next;
    }
    for (j=*queneStart;j<*queneEnd;j++)
    {
        (*queneStart)++;
        TransWideEdges(quene[j],G,isdeleted,deleteVerNo,IsTransversed,quene,queneStart,queneEnd);
    }
    return;
}
void TransverseWide(VLink *G,int count, int isdeleted, int deleteVerNo)
{
    int IsTransversed[MaxV];
    int i;
    int quene[MaxV*MaxV];
    int queneStart,queneEnd;
    queneStart=queneEnd=0;
    for (i=0;i<count;i++)IsTransversed[i]=0;
    for (i=0;i<count;i++)
    {
        if(isdeleted&&i==deleteVerNo)continue;
        if(!IsTransversed[i])TransWideEdges(i,G,isdeleted,deleteVerNo,IsTransversed,quene,&queneStart,&queneEnd);
    }
    printf("\n");
    return;
}

