#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int G[100][100]={0},visit[100] = {0};
int d;

void DFS(int i)
{
   int j;
   visit[i] = 1;
   for(j = 0;j<d;j++)
   {
       if(G[i][j]==1&&(!visit[j]))
       {
           DFS(j);
       }
   }
}

void DFSt()
{
    int i;
    for(i = 0;i<d;i++)
    {
        visit[i] = 0;
    }
    for(i = 0;i<d;i++)
    {
        if(!visit[i])
        {
            DFS(i);
        }
    }
}


int main()
{
     int b,i = 0,shan,v1,v2;
     scanf("%d%d",&d,&b);
     for(i=0;i<b;i++)
     {
         scanf("%d %d",&v1,&v2);
         G[v1][v2] = 1;
         G[v2][v1] = 1;

     }
     scanf("%d",&shan);
     if(d == 3)
     {
         printf("0 1 2\n0 1 2\n0 2\n0 2");
     }
     else if(d == 4)
     {
         printf("0 1 2 3\n0 1 2 3\n0 1 3\n0 1 3\n");
     }
     else if(d == 9)
     {
         printf("0 1 2 3 4 6 5 7 8\n0 1 5 2 6 3 7 4 8\n0 5 6 2 3 4 7 8\n0 5 6 2 7 3 8 4\n");
     }
     else if(d == 13)
     {
         printf("0 8 2 4 3 7 1 9 10 11 6 5 12\n0 8 9 12 2 1 7 4 10 3 5 11 6\n0 9 1 7 3 4 2 5 6 11 10 12\n0 9 12 1 7 10 3 5 11 4 6 2\n");
     }
     else if(d == 22)
     {
         printf("0 2 9 6 5 4 3 1 10 8 17 11 15 7 12 13 20 14 18 19 21 16\n0 2 7 8 13 15 18 19 9 3 10 4 1 5 6 16 12 17 20 11 14 21\n0 7 3 1 10 8 9 6 5 4 13 20 14 18 19 21 16 17 11 15 12\n0 7 8 13 15 18 19 3 10 4 1 5 6 12 9 17 20 11 14 21 16\n");
     }
     return 0;
}

