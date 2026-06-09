#include<stdio.h>
#include <string.h>
int x1[105];
int x2[105];
int y11[105];
int y2[105];
int n;
int sum=1; // @@ [Error: sum should be reset to 1 for each chain start; global initialization is arbitrary and not reset properly before each panduan call]
int sumji[105];
int panduan(int a,int b)
{
    for(int k=0;k<n;k++)
    {
        if((x1[k]==a&&y11[k]==b))
        {
            sum++; // @@ [Error: sum increments but does not include the starting segment; also sum is not reset between different chains, causing accumulation across multiple calls]
            panduan(x2[k],y2[k]); // @@ [Error: return value ignored; recursion continues but sum accumulates without proper base reset]
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
    int xji=0,yji=0,sumji=1; // @@ [Error: initializing xji,yji to 0,0 may produce wrong output if no chain found; also sumji=1 but chain length may be 1]
    if(n==1)
    {
        printf("1 %d %d\n",x1[0],y11[0]);

    }else 
    {
            for(int j=0;j<n;j++)
     {
         if(panduan(x2[j],y2[j])>0) // @@ [Error: panduan looks for subsequent segments, but the segment j itself is not counted in sum; also sum is not reset before call]
        {
            if(sum>sumji) // @@ [Error: sum may include counts from previous calls because it was not reset; comparison wrong]
            {
                sumji=sum;
                xji=x1[j];
                yji=y11[j];
                sum=1; // @@ [Error: reset only when new max found; if no new max, sum retains previous value, corrupting subsequent counts]
            }
            

        }
     }
        printf("%d %d %d\n",sumji,xji,yji);
    }

}