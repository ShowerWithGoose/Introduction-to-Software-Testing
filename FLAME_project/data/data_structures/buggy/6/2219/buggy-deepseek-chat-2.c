#include <stdio.h>
#include <string.h>
int main ()
{
    int cnt=0;
    int date=0;
    int stack[105];
    int num[1005];
    do{
        scanf_s("%d",&num[cnt]); // @@ [Error: scanf_s is not a standard C function; use scanf instead. This causes a compilation error.]
        cnt++;
    }
    while(num[cnt-1]!=-1);
     cnt=cnt-1;
    for(int i=0;i<cnt;i++)
    {
//        printf("%d\t",num[i]);
        
        if(num[i]==1)
        {
            stack[date]=num[i+1]; // @@ [Error: When a push operation (1) is encountered, the next element in num is the value to push, but this code does not check if the stack is full (date >= 100) before pushing, which can lead to buffer overflow and missing "error" output.]
//            printf("%d  ",stack[date]);
            date++;
        }
        if(num[i]==0)
        {
            if((date>0)&&(date<100)) // @@ [Error: The condition should be date > 0 only; date < 100 is unnecessary and incorrect for pop. Also, the pop operation should not check date < 100, as the stack may have fewer than 100 elements.]
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