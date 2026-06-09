#include<stdio.h>
#include <string.h>
int x1[105];
int x2[105];
int y11[105];
int y2[105];
int n;
int sum=1;
int sumji[105];
int panduan(int a,int b)
{
    for(int k=0;k<n;k++)
    {
        if((x1[k]==a&&y11[k]==b))
        {
            sum++;
            panduan(x2[k],y2[k]); // @@ The recursive call does not check if the next segment's endpoint matches any segment's start point correctly; it always increments sum even if no match is found, and the return value is ignored, leading to incorrect counting and potential infinite recursion.
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
         if(panduan(x2[j],y2[j])>0) // @@ The function panduan returns 1 or -1, but the logic here assumes it returns the count; it only checks if a chain exists, not the length, and sum is a global variable that accumulates across different starting points without resetting properly.
        {
            if(sum>sumji)
            {
                sumji=sum;
                xji=x1[j];
                yji=y11[j];
                sum=1; // @@ Resetting sum to 1 here is incorrect because sum is a global variable used across multiple calls; it should be reset before each new chain search, not after finding a longer chain.
            }
            

        }
     }
        printf("%d %d %d\n",sumji,xji,yji);
    }

}