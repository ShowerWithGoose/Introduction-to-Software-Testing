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
        scanf("%d ", &a[i0]); // @@ [The format string "%d " consumes trailing whitespace, which may cause the next scanf to block or behave unexpectedly; it should be "%d" without the space. Additionally, this scanf is only called when i0 != 100, but if i0 == 100, the program prints "error " but still needs to read the integer argument that follows the '1' in input, otherwise the next operation will read that leftover integer as an operation code.]
        i0++;
    }
    if(n==1&&i0==100)
    {
        printf("error ");
    }
    if(n==0 && i0>0)
    {
        printf("%d ",a[i0-1]);
        a[i0]='\0'; // @@ [Unnecessary and potentially misleading: assigning '\0' to an int array element has no effect on stack logic and is not required. However, this is not the primary cause of failure. The real issue is missing input consumption on error cases.]
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