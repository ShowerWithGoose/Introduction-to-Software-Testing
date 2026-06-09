#include <stdio.h>

int main()
{
    int a[101];
    int sum=1;
    int caozuo;
    while(scanf("%d",&caozuo)!=EOF) // @@ missing break when caozuo == -1 (end of operations); program should stop.
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
            printf("errror "); // @@ typo: should be "error " instead of "errror "
        }
        
    }
    
    return 0;
}