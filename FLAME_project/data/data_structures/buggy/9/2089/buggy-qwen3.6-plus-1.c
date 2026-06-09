#include<stdio.h>
#include <string.h>
int x1[105];
int x2[105];
int y11[105];
int y2[105];
int n;
int sum=1; // @@ The global variable 'sum' is not reset to 1 before each new chain calculation in the loop, and its usage in recursion combined with the global state leads to incorrect counting. It should be local or properly managed.
int sumji[105];
int panduan(int a,int b)
{
    for(int k=0;k<n;k++)
    {
        if((x1[k]==a&&y11[k]==b))
        {
            sum++; // @@ Logic Error: This recursively follows a path but doesn't handle backtracking or visited segments correctly. Also, it modifies the global 'sum' which affects other iterations. It assumes a unique next segment which might not be true if not careful, though constraints say no 3 share endpoint. However, the main issue is that 'sum' is global and accumulates across different starting points if not reset, and the recursion structure is flawed for counting length of a specific chain starting from a specific segment.
            panduan(x2[k],y2[k]);
            return 1;
        }
    }
    return -1;
}
int main()
{
    
    
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d %d %d",&x1[i],&y11[i],&x2[i],&y2[i]);
    }
    int xji=0,yji=0,sumji=1;
    if(n==1)
    {
        printf("1 %d %d\n",x1[0],y11[0]);

    }else 
    {
            for(int j=0;j<n;j++)
     {
         sum = 1; // @@ Missing Reset: The global variable 'sum' must be reset to 1 for each starting segment 'j' to correctly count the length of the chain starting at segment 'j'. Without this, 'sum' retains values from previous iterations.
         if(panduan(x2[j],y2[j])>0)
        {
            if(sum>sumji)
            {
                sumji=sum;
                xji=x1[j];
                yji=y11[j];
                sum=1;
            }
            

        }
     }
        printf("%d %d %d\n",sumji,xji,yji);
    }

}