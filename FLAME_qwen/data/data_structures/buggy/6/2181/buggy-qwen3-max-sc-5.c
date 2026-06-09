#include<stdio.h>
#include<math.h> 
#include<string.h>
#include<stdlib.h>

int main()
{
int a[101];
int n, i0;

i0=0;
while(1)
{    
    scanf("%d", &n);
    if(n==1&& i0!=100)
    {
        scanf("%d ", &a[i0]); // @@ [The format string "%d " consumes trailing whitespace, which may cause the next scanf to block or behave unexpectedly; also, if stack is full (i0==100), the push value is still read but ignored, violating the specification that no value should be read after detecting a full stack.]
        i0++;
    }
    if(n==1&&i0==100)
    {
        printf("error ");
    }
    if(n==0 && i0>0)
    {
        printf("%d ",a[i0-1]);
        a[i0]='\0'; // @@ [Unnecessary and potentially misleading; writing '\0' to an int array element has no effect on logic and may confuse readers. More critically, this line does not cause runtime error but reflects flawed reasoning. However, the real issue is that when n==1 and stack is full, the program still reads the next integer due to misplaced scanf, leading to input desynchronization.]
        i0--;
    }
    if(n==0 && i0==0)
    {
        printf("error ");
    }
    if(n==-1)
    {
        break;
    }
}

return 0;    
}