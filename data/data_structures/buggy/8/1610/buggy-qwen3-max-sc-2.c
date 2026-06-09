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

    int q[110] = {0}; // @@ [Global variable 'q', 'front', and 'rear' are declared outside any function, but they are used only in 'wide'. However, more critically, 'front' and 'rear' are not reset to 0 before each BFS call, causing incorrect queue state reuse across BFS traversals.]
    int front = 0,rear = 0; // @@ [Same as above: 'front' and 'rear' are global and not reinitialized before each BFS, leading to wrong traversal results after the first BFS.]

void wide(int begin,int n)
{
    int now = 0,i;
    q[rear++] = begin;
    
    while(front <= rear) // @@ [Condition should be 'front < rear' for a standard queue; using '<=' may cause reading beyond valid queue elements. Also, because 'front' and 'rear' are global and not reset, this loop behaves incorrectly on subsequent calls.]
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
    
    scanf("%d %d\n",&nv,&ne); // @@ [Using '\n' in scanf format can cause unexpected blocking or skipping if input doesn't have trailing newline; better to use "%d %d" without \n.]
    
    int i = 0;
    int begin,end;
    
    for(i = 0;i < ne;i ++)
    {
        scanf("%d %d\n",&begin,&end); // @@ [Same issue: trailing '\n' in scanf may consume extra whitespace or cause input misalignment.]
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
    
    //nv--; // @@ [Commented out, but should not decrement 'nv' because traversal still uses original indices up to 'nv-1'; however, since deleted vertex is skipped via zeroed adjacency, it's okay—but the real bug is in BFS queue state.]
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