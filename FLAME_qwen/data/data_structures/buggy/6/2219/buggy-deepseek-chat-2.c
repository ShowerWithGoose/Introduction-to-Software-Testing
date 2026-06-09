#include <stdio.h>
#include <string.h>
int main ()
{
    int cnt=0;
    int date=0;
    int stack[105];
    int num[1005];
    do{
        scanf_s("%d",&num[cnt]); // @@ [scanf_s is not standard C; should use scanf for compatibility with typical grading environments]
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
        if(num[i]==0)
        {
            if((date>0)&&(date<100)) // @@ [The condition date<100 is incorrect; it should check if the stack is non-empty (date>0) only, as the stack capacity is 100 but date tracks the number of elements, not the capacity limit for pop]
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