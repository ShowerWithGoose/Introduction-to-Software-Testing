#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXSIZE 100
int front,rear,count;
int vertexnum,sidenum;
int vertex[MAXSIZE]={0};
int side[MAXSIZE][MAXSIZE]={0};
int visited[MAXSIZE]={0};
int queue[MAXSIZE];
void initqueue();
int isempty();
int isfull();
void inqueue(int queue[],int item);
int outqueue(int queue[]);
void graphdfs(int vertex[MAXSIZE],int side[MAXSIZE][MAXSIZE],int vertexnum,int startvertex);
void graphbfs(int vertex[MAXSIZE],int side[MAXSIZE][MAXSIZE],int vertexnum,int startvertex);
void clearvisit(int visited[],int vertexnum);
void deletevertex(int vertex[MAXSIZE],int side[MAXSIZE][MAXSIZE],int vertexnum,int devertex);
int main()
{
    int i,j,k;
    int sidea,sideb;
    int devertex;
    scanf("%d %d",&vertexnum,&sidenum);
    for(i=0;i<vertexnum;i++)
    {
        vertex[i]=1;
    }
    for(i=0;i<sidenum;i++)
    {
        scanf("%d %d",&sidea,&sideb);
        side[sidea][sideb]=1;
        side[sideb][sidea]=1;
    }
    scanf("%d",&devertex);
    graphdfs(vertex,side,vertexnum,0);
    clearvisit(visited,vertexnum);
    graphbfs(vertex,side,vertexnum,0);
    clearvisit(visited,vertexnum);
    deletevertex(vertex,side,vertexnum,devertex);
    graphdfs(vertex,side,vertexnum,0);
    clearvisit(visited,vertexnum);
    graphbfs(vertex,side,vertexnum,0);
    return 0;
}

void graphdfs(int vertex[MAXSIZE],int side[MAXSIZE][MAXSIZE],int vertexnum,int startvertex)
{
    int i;
    visited[startvertex]=1;
    printf("%d ",startvertex);
    for(i=0;i<vertexnum;i++)
    {
        if(side[startvertex][i]==1&&visited[i]!=1)
        {
            graphdfs(vertex,side,vertexnum,i);
        }
    }
}

void graphbfs(int vertex[MAXSIZE],int side[MAXSIZE][MAXSIZE],int vertexnum,int startvertex)
{
    int i,j;
    for(i=0;i<vertexnum;i++)
    {
        if(visited[i]!=1&&vertex[i]==1)
        {
            visited[i]=1;
            printf("%d ",i);
            inqueue(queue,i);
            while(isempty()!=1)
            {
                i=outqueue(queue);
                for(j=0;j<vertexnum;j++)
                {
                    if(side[i][j]==1&&visited[j]!=1&&vertex[j]==1)
                    {
                        visited[j]=1;
                        printf("%d ",j);
                        inqueue(queue,j);
                    }
                    else if(vertex[j]==0)
                    {
                        continue;
                    }
                }
            }
        }
    }

}


void initqueue()
{
    front=0;
    rear=MAXSIZE-1;
    count=0;
}

int isempty()
{
    return count==0;
}

int isfull()
{
    return count==MAXSIZE;
}

void inqueue(int queue[],int item)
{
    if(isfull())
    {
        printf("Error\n");
    }
    else
    {
        rear=(rear+1)%MAXSIZE;
        queue[rear]=item;
        count++;
    }
}

int outqueue(int queue[])
{
    int item;
    if(isempty())
    {
        printf("Error\n");
    }
    else
    {
        item=queue[front+1];
        count--;
        front=(front+1)%MAXSIZE;
    }
    return item;
}

void clearvisit(int visited[],int vertexnum)
{
    int i;
    for(i=0;i<vertexnum;i++)
    {
        visited[i]=0;
    }
    printf("\n");
}

void deletevertex(int vertex[MAXSIZE],int side[MAXSIZE][MAXSIZE],int vertexnum,int devertex)
{
    vertex[devertex]=0;
    int i;
    for(i=0;i<vertexnum;i++)
    {
        side[i][devertex]=0;
        side[devertex][i]=0;
    }
    --vertexnum;
}



