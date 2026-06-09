#include <stdio.h>
#include <string.h>
int main ()
{
    int cnt=0;
    int date=0;
    int stack[105];
    int num[1005];
    do{
        scanf_s("%d",&num[cnt]); // @@ scanf_s is a Microsoft-specific extension and not supported by standard GCC compilers, causing a compilation error. Use scanf instead.
        cnt++;
    }
    while(num[cnt-1]!=-1);
     cnt=cnt-1;
    for(int i=0;i<cnt;i++)
    {
//        printf("%d\t",num[i]);
        
        if(num[i]==1)
        {
            stack[date]=num[i+1]; // @@ Missing check for stack full condition (date >= 100). Should output "error " if stack is full before pushing.
//            printf("%d  ",stack[date]);
            date++;
        }
        if(num[i]==0)
        {
            if((date>0)&&(date<100))
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