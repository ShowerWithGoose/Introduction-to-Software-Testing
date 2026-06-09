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
        scanf("%d ", &a[i0]); @@ [Using "scanf" with a space in format string "%d " causes it to wait for additional non-whitespace input after the integer, which may consume the next operation token (like 0 or -1) prematurely. This leads to incorrect parsing of the input sequence.]
        i0++;
    }
    if(n==1&&i0==100)
    {
        printf("error ");
    }
    if(n==0 && i0>0)
    {
        printf("%d ",a[i0-1]);
        a[i0]='\0'; @@ [Unnecessary and potentially misleading; setting a[i0] to '\0' has no effect since the array is of integers and not used as a string. However, this is not the primary cause of the error.]
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