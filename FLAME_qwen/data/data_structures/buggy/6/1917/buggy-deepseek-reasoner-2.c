#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a[101]={0};
    int x,y,i=0;
    while(1)
    {
        scanf("%d",&y);
        if(y==1)
        {
            if(i==-1) // @@ [Unnecessary condition; i never becomes -1, but if it did, this would cause logical issues]
            i++;
            if(i<100)
            {
                scanf("%d ",&a[i]); // @@ [Trailing space in scanf format may cause the program to wait for additional non-whitespace input, leading to indefinite blocking when input ends. Also, this reads before the overflow check, but the check is above.]
                i++;
            }
            else if(i==100)
            {
                printf("error "); // @@ [After printing error for full stack, i is incremented on the next line, which should not happen. The reference does not change i on a push error.]
                i++;
            }
        }
        else if(y==0)
        {
            if(i==101) // @@ [This condition attempts to handle an overflowed index but is logically incorrect. i should never become 101.]
            i--;
            if(i!=0)
            {
                i--; // @@ [Double decrement: i is decremented here after possibly being decremented on line 30, causing two elements to be removed on a single pop operation. The correct behavior is to decrement once after confirming stack is not empty.]
                if(i<0) // @@ [This condition will never be true because i is checked i!=0 before decrement; if i is 1, after decrement it becomes 0, not negative. Thus the error message for pop on empty stack is never printed.]
                printf("error ");
                else
                {
                     printf("%d ",a[i]);
                       a[i]=0; // @@ [Zeroing the popped element is unnecessary and not present in the reference program.]
                } 
            }
        }
        else if(y==-1)
        break; 
    }
    return 0;
}