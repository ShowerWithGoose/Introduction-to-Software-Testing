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
        scanf("%d ", &a[i0]); // @@ The trailing space in the format string causes scanf to skip whitespace indefinitely, potentially causing the program to hang or misread subsequent inputs; it should be "%d".
        i0++;
    }
    if(n==1&&i0==100)
    {
        printf("error "); // @@ Fails to consume the integer to be pushed from the input stream when the stack is full, causing subsequent scanf calls to read this integer as an operation code and desynchronizing the input parsing.
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