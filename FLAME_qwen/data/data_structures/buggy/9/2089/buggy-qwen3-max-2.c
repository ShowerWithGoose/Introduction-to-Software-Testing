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
    int xji=0,yji=0,sumji=1; // @@ [Variable 'sumji' is redeclared here, conflicting with global array 'sumji[105]']
    if(n==1)
    {
        printf("1 %d %d\n",x1[0],y11[0]);

    }else 
    {
            for(int j=0;j<n;j++)
     {
         if(panduan(x2[j],y2[j])>0)
        {
            if(sum>sumji) // @@ [Comparing 'sum' (global counter) with local variable 'sumji', but 'sum' is not reset properly before each call to 'panduan']
            {
                sumji=sum; // @@ [Assigning to local 'sumji', shadowing the global array; also, 'sum' accumulates across iterations due to being global and not reset before each 'panduan' call]
                xji=x1[j];
                yji=y11[j];
                sum=1; // @@ [Resetting 'sum' after use, but recursive calls in 'panduan' may have already altered it incorrectly due to shared global state]
            }
            

        }
     }
        printf("%d %d %d\n",sumji,xji,yji); // @@ [Printing local 'sumji' which may not reflect the maximum chain length correctly due to flawed logic and variable shadowing]
    }

}