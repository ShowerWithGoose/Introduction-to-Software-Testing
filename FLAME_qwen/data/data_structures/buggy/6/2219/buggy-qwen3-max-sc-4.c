#include <stdio.h>
#include <string.h>
int main ()
{
    int cnt=0;
    int date=0;
    int stack[105];
    int num[1005];
    do{
        scanf_s("%d",&num[cnt]); // @@ [Use of non-standard function 'scanf_s' which may not be available in all compilers (e.g., GCC), leading to compilation error. Should use 'scanf' instead.]
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
        if(num[i]==0) // @@ [Does not skip the next element after a push operation, causing misinterpretation of input sequence. Also, condition for underflow is incorrect: should check only if stack is empty (date == 0), not (date > 0 && date < 100). Additionally, overflow during push is not checked at all.]
        {
            if((date>0)&&(date<100)) // @@ [Incorrect condition for valid pop: 'date < 100' is irrelevant for pop; only need to check if stack is not empty (date > 0). This logic error may cause missed 'error' outputs or wrong pops.]
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