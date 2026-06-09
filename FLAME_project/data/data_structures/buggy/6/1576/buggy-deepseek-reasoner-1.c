#include <stdio.h>

int main()
{
    int a[101];
    int sum=1;
    int caozuo;
    while(scanf("%d",&caozuo)!=EOF) // @@ [This loop should also check for caozuo == -1 to break, as per problem specification. Currently it only terminates on EOF, which may lead to incorrect behavior if input does not end immediately after -1.]
    {
        if(caozuo==1&&sum<=100)
        {
            scanf("%d",&a[sum]);
            sum++;
        }
        else if(caozuo==1&&sum>100) // @@ [When pushing onto a full stack, the program prints "error " but does not consume the integer that follows. This will cause subsequent input to be misread. The integer should be read and discarded.]
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
            printf("errror "); // @@ [Spelling error: should be "error" instead of "errror". This causes the output to mismatch the expected "error".]
        }
        
    }
    
    return 0;
}