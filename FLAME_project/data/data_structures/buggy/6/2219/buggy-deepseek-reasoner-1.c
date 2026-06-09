#include <stdio.h>
#include <string.h>
int main ()
{
    int cnt=0;
    int date=0;
    int stack[105];
    int num[1005];
    do{
        scanf_s("%d",&num[cnt]); // @@ error: scanf_s is not standard; should be scanf.
        cnt++;
    }
    while(num[cnt-1]!=-1);
     cnt=cnt-1;
    for(int i=0;i<cnt;i++)
    {
//        printf("%d\t",num[i]);
        
        if(num[i]==1)
        {
            stack[date]=num[i+1]; // @@ error: no check for stack full (date >= 100); should output "error" and skip.
//            printf("%d  ",stack[date]);
            date++; // @@ error: date should only be incremented if push is successful; here it increments unconditionally.
        }
        if(num[i]==0)
        {
            if((date>0)&&(date<100)) // @@ error: condition should be just date>0; date<100 incorrectly prevents pop when stack is full.
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