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
        if(num[i]==0) // @@ [should be 'else if' to avoid checking pop condition immediately after a push, which may lead to incorrect behavior when input sequence has consecutive operations]
        {
            if((date>0)&&(date<100)) // @@ [condition 'date<100' is unnecessary for pop; only need to check if stack is not empty (date > 0). Also, max capacity check should be on push, not pop. However, the main error here is logic: this condition prevents popping when date==100, but date can't exceed 100 due to missing push overflow check]
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