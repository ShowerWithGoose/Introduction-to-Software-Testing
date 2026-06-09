#include <stdio.h>

int main()
{
    int a[101];
    int sum=1; // @@ [The initial value of 'sum' should be 0 to represent an empty stack. Starting at 1 causes incorrect indexing and logic for empty/full checks.]
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
            printf("errror "); // @@ [Typo: "errror" should be "error". Also, condition 'sum<=1' is incorrect due to wrong initial 'sum'; should trigger when stack is empty (i.e., sum == 0).]
        }
        
    }
    
    return 0;
}