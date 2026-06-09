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
    int xji=0,yji=0,sumji=1; // @@ [Variable 'sumji' is redeclared here, conflicting with the global array 'sumji[105]'. This causes a compilation error due to name shadowing and type mismatch.]
    if(n==1)
    {
        printf("1 %d %d\n",x1[0],y11[0]);

    }else 
    {
            for(int j=0;j<n;j++)
     {
         if(panduan(x2[j],y2[j])>0)
        {
            if(sum>sumji) // @@ [Here, 'sumji' refers to the local integer variable, but the logic incorrectly resets 'sum' without properly handling recursive state, leading to incorrect counting. However, the primary issue is the redeclaration above causing a compilation error.]
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