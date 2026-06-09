#include <stdio.h>
#include <string.h>
int main ()
{
    int cnt=0;
    int date=0;
    int stack[105];
    int num[1005];
    do{
        scanf_s("%d",&num[cnt]); // @@ [scanf_s is not standard in all C environments and may cause compilation errors; should use scanf instead]
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
        if(num[i]==0) // @@ [should be 'else if' to avoid processing the same element as both push and pop when input is 0 following a 1]
        {
            if((date>0)&&(date<100)) // @@ [condition (date<100) is incorrect for checking underflow; only (date>0) is needed for pop validity. Also, full condition for push overflow is missing entirely in the code]
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