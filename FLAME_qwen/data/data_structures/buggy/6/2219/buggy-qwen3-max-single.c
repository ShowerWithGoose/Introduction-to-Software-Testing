#include <stdio.h>
#include <string.h>
int main ()
{
    int cnt=0;
    int date=0;
    int stack[105];
    int num[1005];
    do{
        scanf_s("%d",&num[cnt]); // @@ [scanf_s is not standard in all C environments and may cause compilation errors; use scanf instead]
        cnt++;
    }
    while(num[cnt-1]!=-1);
     cnt=cnt-1;
    for(int i=0;i<cnt;i++)
    {
//        printf("%d\t",num[i]);
        
        if(num[i]==1)
        {
            stack[date]=num[i+1];
//            printf("%d  ",stack[date]);
            date++;
        }
        if(num[i]==0) // @@ [should be 'else if' to avoid checking pop condition immediately after a push on the same iteration, which can lead to incorrect behavior when input sequence is like "1 5 0"]
        {
            if((date>0)&&(date<100)) // @@ [condition (date<100) is unnecessary for pop; only need to check if stack is not empty (date>0). Also, this condition incorrectly prevents popping when date==100, but date should never exceed 100 due to missing full-stack check during push]
            {
                printf("%d ",stack[date-1]);
                date--;
            }
            else
            {
                printf("error ");
            }
        }
    }
    
    return 0;
}