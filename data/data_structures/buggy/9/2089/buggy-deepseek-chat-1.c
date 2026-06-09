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
            panduan(x2[k],y2[k]); // @@ The recursive call does not check if the next segment's start point matches the current segment's end point correctly; it assumes the first matching segment is always the next one, but there could be multiple segments with the same start point, and the recursion may not follow the correct chain. Also, the function does not return the correct value to indicate success or failure for the caller.
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
         if(panduan(x2[j],y2[j])>0) // @@ The function panduan returns 1 or -1, but the condition checks >0, which is correct for 1, but the recursion logic inside panduan is flawed, causing incorrect counting and potential infinite recursion or wrong results. Additionally, the variable sum is global and not reset properly for each starting segment j, leading to cumulative counts across different starting points.
        {
            if(sum>sumji)
            {
                sumji=sum;
                xji=x1[j];
                yji=y11[j];
                sum=1; // @@ Resetting sum here is incorrect because sum is used in the recursive panduan function; resetting it after the condition may cause the next iteration to start with sum=1 even if the previous chain was longer, but the logic for tracking the maximum is flawed overall.
            }
            

        }
     }
        printf("%d %d %d\n",sumji,xji,yji);
    }

}