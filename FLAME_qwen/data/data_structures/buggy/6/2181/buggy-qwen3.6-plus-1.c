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
        scanf("%d ", &a[i0]); // @@ The trailing space in the format string causes scanf to skip whitespace and wait for non-whitespace input, which will hang the program or misread subsequent inputs. It should be "%d".
        i0++;
    }
    if(n==1&&i0==100)
    {
        printf("error "); // @@ Fails to consume the integer following '1' when the stack is full, leaving it in the input buffer and causing subsequent scanf calls to read this integer as an operation code.
    }
    if(n==0 && i0>0)
    {
        printf("%d ",a[i0-1]);
        a[i0]='\0'; // @@ Unnecessary assignment for an integer array; '\0' is just 0 and does not logically clear the stack element. It can be safely removed.
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