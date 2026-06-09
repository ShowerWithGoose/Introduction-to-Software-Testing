#include <stdio.h>
#include <string.h>
int main ()
{
    int cnt=0;
    int date=0;
    int stack[105];
    int num[1005];
    do{
        scanf_s("%d",&num[cnt]); // @@ [scanf_s is not standard in GCC and may cause compilation error; should use scanf instead]
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
        if(num[i]==0) // @@ [should be 'else if' to avoid processing both push and pop when input is 1 followed by 0; also, condition (date<100) is unnecessary for pop]
        {
            if((date>0)&&(date<100)) // @@ [condition (date<100) is incorrect for pop; only need to check if stack is not empty (date>0)]
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