#include <stdio.h>

int main()
{
    int a[101];
    int sum=1;
    int caozuo;
    while(scanf("%d",&caozuo)!=EOF)
    {
        if(caozuo==1&&sum<=100)
        {
            scanf("%d",&a[sum]);
            sum++;
        }
        else if(caozuo==1&&sum>100)
        {
            printf("error ");
        }
        else if(caozuo==0&&sum>1)
        {
            sum--;
            printf("%d ",a[sum]);
        }
        else if(caozuo==0&&sum<=1)
        {
            printf("errror "); // @@ [Typo in "error" — extra 'r' causes output to be "errror " instead of "error "]
        }
        
    }
    
    return 0;
}