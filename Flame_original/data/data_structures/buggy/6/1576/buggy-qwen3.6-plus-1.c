#include <stdio.h>

int main()
{
    int a[101];
    int sum=1;
    int caozuo;
    while(scanf("%d",&caozuo)!=EOF) // @@ The loop condition does not check for -1 to terminate the program as specified in the problem description.
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
            printf("errror "); // @@ Typo in the error message string: "errror" should be "error".
        }
        
    }
    
    return 0;
}