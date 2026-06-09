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
        scanf("%d ", &a[i0]); // @@ [The format string "%d " consumes trailing whitespace, which may cause the next scanf to block or behave unexpectedly when reading subsequent integers. It should be "%d" without the trailing space.]
        i0++;
    }
    if(n==1&&i0==100)
    {
        printf("error ");
    }
    if(n==0 && i0>0)
    {
        printf("%d ",a[i0-1]);
        a[i0]='\0'; // @@ [Unnecessary and potentially misleading: assigning '\0' to an int array element has no effect on stack logic and is not needed. While not causing functional error here, it indicates confusion between char and int arrays. However, the real issue is elsewhere.]
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