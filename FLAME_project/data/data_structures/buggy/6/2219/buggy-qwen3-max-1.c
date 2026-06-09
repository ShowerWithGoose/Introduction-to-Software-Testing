#include <stdio.h>
#include <string.h>
int main ()
{
    int cnt=0;
    int date=0;
    int stack[105];
    int num[1005];
    do{
        scanf_s("%d",&num[cnt]); // @@ [The function 'scanf_s' is not standard in GCC and causes a compilation error; it should be 'scanf']
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
            if((date>0)&&(date<100)) // @@ [The condition 'date<100' is incorrect for checking underflow; pop should only check if stack is not empty (date>0). Also, fullness check is missing during push.]
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