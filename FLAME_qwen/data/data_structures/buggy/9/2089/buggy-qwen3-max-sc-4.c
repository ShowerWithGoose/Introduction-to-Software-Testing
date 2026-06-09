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
    int xji=0,yji=0,sumji=1;
    if(n==1)
    {
        printf("1 %d %d\n",x1[0],y11[0]);

    }else 
    {
            for(int j=0;j<n;j++)
     {
         sum = 1; // @@ [The global variable 'sum' is not reset before each call to 'panduan', leading to incorrect accumulation across different starting segments. It should be reset to 1 at the start of each iteration.]
         if(panduan(x2[j],y2[j])>0)
        {
            if(sum>sumji)
            {
                sumji=sum;
                xji=x1[j];
                yji=y11[j];
                // sum=1; // @@ [This line incorrectly resets 'sum' after updating 'sumji', but 'sum' is already corrupted due to recursive calls and lack of proper backtracking or local state. The logic of using a global 'sum' in a recursive function causes incorrect counting.]
            }
            

        }
     }
        printf("%d %d %d\n",sumji,xji,yji);
    }

}