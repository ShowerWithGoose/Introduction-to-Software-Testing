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
    int xji=0,yji=0,sumji=1; // @@ [xji and yji are initialized to 0. If the longest chain has length 1, the output will be "1 0 0", but the correct starting point should be the start of some segment (e.g., the first segment). This causes incorrect output.]
    if(n==1)
    {
        printf("1 %d %d\n",x1[0],y11[0]);

    }else 
    {
            for(int j=0;j<n;j++)
     {
         if(panduan(x2[j],y2[j])>0) // @@ [The global variable 'sum' is not reset to 1 before each call to panduan. It is only reset when a new maximum is found. This causes the chain length count to be polluted by previous iterations, leading to incorrect maximum segment counts.]
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