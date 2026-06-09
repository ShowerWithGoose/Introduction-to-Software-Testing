#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

#define MAXLINE 1024
#define MAXWORD 103
#define isletter(c) ((c>='A'&&c<='Z')||(c>='a'&&c<='z')? 1:0)
#define isnum(c) (c>='0'&&c<='9'? 1:0)

int visited[MAXWORD];
int queue[MAXWORD];
int front=0;
int rear=-1;

void DFS(int a[][MAXWORD], int i, int m)
{
    visited[i]=1;
    printf("%d ", i);
    int j;
    for (j=0; j<m; j++)
    {
        if ((a[i][j]==1)&&(!visited[j]))
        {
            DFS(a, j, m);
        }
    }

}
void travelDFS(int a[][MAXWORD], int m, int n)
{
    int i;
    for(i=0; i<m; i++)
    {
        if(!visited[i])
        {
            DFS(a, i, m);
        }
    }
}
void travelDFS1(int a[][MAXWORD], int m, int n, int d)
{
    int i;
    for(i=0; i<m; i++)
    {
        if (i==d)
            continue;
        if(!visited[i])
        {
            DFS(a, i, m);
        }
    }
}

void BFS(int a[][MAXWORD], int i, int m)
{
    visited[i]=1;
    printf("%d ", i);
    int j;
    for (j=0; j<m; j++)
    {
        if ((a[i][j]==1)&&(!visited[j]))
        {
            queue[++rear]=j;
            visited[queue[rear]]=1;
        }
    }
    if(rear-front>=0)
        BFS(a, queue[front++], m);
}
void travelBFS(int a[][MAXWORD], int m, int n)
{
    int i;
    BFS(a, 0, m);
    /*for(i=0; i<m; i++)
    {
        if(!visited[i])
        {
            BFS(a, i, m);
        }
    }*/
}
int main()
{
    int a[MAXWORD][MAXWORD]={0};
    int m, n;
    scanf("%d%d", &m, &n);
    int b[n][2];
    int i, j;
    for (i=0; i<n; i++)
    {
        scanf("%d%d", &b[i][0], &b[i][1]);
    }
    int d;
    scanf("%d", &d);
    for (i=0; i<n; i++)
    {
        a[b[i][0]][b[i][1]]=1;
        a[b[i][1]][b[i][0]]=1;
    }
    travelDFS(a, m, n);
    printf("%c", '\n');
    memset(visited, 0, sizeof(visited));
    travelBFS(a, m, n);
    printf("%c", '\n');
    memset(visited, 0, sizeof(visited));
    for (i=0; i<m; i++)
    {
        a[d][i]=0;
        a[i][d]=0;
    }
    travelDFS1(a, m, n, d);
    printf("%c", '\n');
    memset(visited, 0, sizeof(visited));
    travelBFS(a, m, n);
    return 0;
}



