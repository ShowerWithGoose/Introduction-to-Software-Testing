#include <stdio.h>

int main()
{
    int a[101];
    int sum=1;
    int caozuo;
    while(scanf("%d",&caozuo)!=EOF) // @@ The loop does not check for the termination condition -1, which should break the loop immediately as specified in the problem.
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
            printf("errror "); // @@ Typographical error in the output string, it should be "error " instead of "errror ".
        }
        
    }
    
    return 0;
}