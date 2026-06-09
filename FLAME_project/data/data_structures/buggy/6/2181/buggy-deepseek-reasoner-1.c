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
        scanf("%d ", &a[i0]);
        i0++;
    }
    if(n==1&&i0==100)
    {
        printf("error ");
    }
    if(n==0 && i0>0)
    {
        printf("%d ",a[i0-1]);
        a[i0]='\0';
        i0--;
    }
    if(n==0 && i0==0) // @@ [After a successful pop, i0 becomes 0, causing this condition to also be true and printing an extra "error". These two conditions should be mutually exclusive, e.g., using else if.]
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