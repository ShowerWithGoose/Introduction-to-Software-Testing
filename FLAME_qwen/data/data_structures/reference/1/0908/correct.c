#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void dfs(bool *used,int usedSize,int depth,int *stack);

int main()
{
    int n;
    scanf("%d",&n);
    bool *used = malloc(n);
    int *stack = malloc(n*sizeof(int));
    memset(used,0,n);
    memset(stack,0,sizeof(int)*n);
    dfs(used,n,0,stack);
    return 0;
}

void dfs(bool *used,int usedSize,int depth,int *stack)
{
    if(depth==usedSize)
    {
        for(int i=0;i<usedSize;i++)
        {
            printf("%d ",stack[i]);
        }
        printf("\n");
        return;
    }
    int pointer = 0;
    for(int i=1;i<=usedSize-depth;i++)
    {
        while(used[pointer])pointer++;
        used[pointer] = true;
        stack[depth] = pointer+1;
        dfs(used,usedSize,depth+1,stack);
        used[pointer++] = false;
    }
}



