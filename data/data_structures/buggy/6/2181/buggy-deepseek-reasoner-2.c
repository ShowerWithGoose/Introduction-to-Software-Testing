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
        scanf("%d ", &a[i0]); // @@ Trailing space in format string causes extra input consumption and may block for next non-whitespace, leading to incorrect reading of subsequent operations.
        i0++;
    }
    if(n==1&&i0==100)
    {
        printf("error "); // @@ When the stack is full, the program prints "error" but does not read the integer value that follows the push operation (the problem requires it to be consumed regardless). This misaligns all subsequent input.
    }
    if(n==0 && i0>0)
    {
        printf("%d ",a[i0-1]);
        a[i0]='\0';
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