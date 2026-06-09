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
    if(n==1&&i0==100) @@ // Should be else if to avoid printing error after a successful push when stack becomes full
    {
        printf("error ");
    }
    if(n==0 && i0>0)
    {
        printf("%d ",a[i0-1]);
        a[i0]='\0';
        i0--;
    }
    if(n==0 && i0==0) @@ // Should be else if to avoid printing error after a successful pop
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