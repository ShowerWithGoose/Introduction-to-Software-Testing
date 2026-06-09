#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>

int a[110][110],visited[110] = {0};

int t1 = 0,t2 = 0;

void deep(int begin,int n)
{
    int i = 0;
    visited[begin] = 1;
    printf("%d ",begin);
    for(i = 0;i < n;i ++)
    {
        if(visited[i] == 0 && a[begin][i] == 1)
        {
            deep(i,n);
        }
    }
}

    int q[110] = {0}; // @@ [Global variable 'q' is declared in the middle of the file outside any function, which is invalid in C prior to C99 and may cause compilation errors depending on compiler settings. Also, 'front' and 'rear' are global but used only in wide(), causing state retention across calls.]
    int front = 0,rear = 0; // @@ [Same issue as above: global variables declared mid-file. Additionally, these should be local to wide() to reset queue state per BFS call.]

void wide(int begin,int n)
{
    int now = 0,i;
    q[rear++] = begin;
    
    while(front <= rear) // @@ [Condition should be 'front < rear' to avoid accessing beyond enqueued elements. Using '<=' may cause reading uninitialized or stale data.]
    {    //printf("aaaaa\n");
        now = q[front++];//³ö¶Ó 
        if(visited[now])
        {
            continue; 
        }
        
        printf("%d ",now);
        visited[now] = 1;
        for(i = 0;i < n;i ++)
        {
            if(visited[i] == 0 && a[now][i] == 1)
            {
                q[rear++] = i;
                
            }
        }
    }        
}

void dele(int i,int n)
{
    int j = 0;
    for(j = 0;j < n;j ++)
    {
        a[i][j] = 0;
        a[j][i] = 0;
        
     }

}

int main()
{
    int nv,ne;
    
    scanf("%d %d\n",&nv,&ne); // @@ [Using '\n' in scanf format can cause unexpected blocking or input consumption issues; it's unnecessary and may lead to runtime hangs or incorrect parsing.]
    
    int i = 0;
    int begin,end;
    
    for(i = 0;i < ne;i ++)
    {
        scanf("%d %d\n",&begin,&end); // @@ [Same issue: trailing '\n' in scanf can cause input problems.]
        a[begin][end] = 1;
        a[end][begin] = 1;
    }
    int del;
    scanf("%d",&del);
    
    deep(0,nv);
    printf("\n");
    for(i = 0;i < 110;i ++)
    {
        visited[i] = 0;
    }
    wide(0,nv);
    printf("\n");
    for(i = 0;i < 110;i ++)
    {
        visited[i] = 0;
    }    
    dele(del,nv);
    
    //nv--;
    deep(0,nv);
    printf("\n");
    printf("pppp\n"); // @@ [This debug print statement produces extra output not in expected format, causing mismatch with expected output.]
    for(i = 0;i < 110;i ++)
    {
        visited[i] = 0;
    }
    wide(0,nv);
    printf("\n");
    
    return 0;
}