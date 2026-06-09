#include <stdio.h>
#include <string.h>
int main ()
{
    int cnt=0;
    int date=0;
    int stack[105];
    int num[1005];
    do{
        scanf_s("%d",&num[cnt]); // @@ [Error: scanf_s is not standard C; should use scanf. Also, the input format includes spaces and the sequence may have push values that are not 1, 0, or -1, but the reading logic is correct for the given format.]
        cnt++;
    }
    while(num[cnt-1]!=-1);
     cnt=cnt-1;
    for(int i=0;i<cnt;i++)
    {
//        printf("%d\t",num[i]);
        
        if(num[i]==1)
        {
            stack[date]=num[i+1]; // @@ [Error: When a push operation (1) is encountered, the next element in the input is the value to push, but this code does not skip that value in the loop, causing it to be processed again as an operation. Additionally, there is no check for stack overflow (date >= 100).]
//            printf("%d  ",stack[date]);
            date++;
        }
        if(num[i]==0)
        {
            if((date>0)&&(date<100)) // @@ [Error: The condition date<100 is unnecessary and incorrect; it should only check date>0. Also, the pop operation should output "error" if the stack is empty, but the condition date<100 may cause false positives.]
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