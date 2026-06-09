#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int op[101][101]={0};
int v[101]={0};
int n,m;
int queue[101];
int front,rear,count;

void dfs(int start)//…Ó∂»
{
    int i;
    printf("%d ",start);
    v[start]=1;
    for(i=0;i<n;i++)
    {
        if(op[start][i]==1&&v[i]==0)
            dfs(i);
    }
}

void get_in_queue(int a)
{

    rear=(rear+1)%101;
    queue[rear]=a;
    count++;
}


void bfs(int start)
{

    int tmp;
    for(int i=0;i<101;i++)
        queue[i]=-1;

    front=0;
    rear=100;
    count=0;

    get_in_queue(start);
    v[a]=1; // @@ [variable 'a' is not declared in this scope; should be 'start']

    while(count!=0)
    {
        tmp=queue[front];
        count--;
        front=(front+1)%101;
        printf("%d ",tmp);
        for(i=0;i<n;i++) // @@ [variable 'i' is used without declaration in this scope; missing 'int i;' before the loop]
        {
            if(op[i][tmp]==1&&v[i]==0)
            {
                get_in_queue(i);
                v[i]=1;
            }

        }

    }


}


int main()
{
    scanf("%d%d",&n,&m);
    int i;
    int a,b;
    int d;
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&a,&b);
        op[a][b]=1;
        op[b][a]=1;
    }

    scanf("%d",&d);

    dfs(0); // @@ [only performs DFS before deletion and does not perform BFS, nor handles deletion and second traversals as required]

}