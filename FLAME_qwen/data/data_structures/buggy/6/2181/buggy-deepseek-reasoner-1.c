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
        scanf("%d ", &a[i0]); // @@ [Error: scanf format includes a trailing space, which can cause input synchronization issues. Reference uses "%d" without space.]
        i0++;
    }
    if(n==1&&i0==100)
    {
        printf("error "); // @@ [Error: When stack is full, the push value must still be read from input to keep the input stream synchronized. Here it is not consumed, causing subsequent inputs to be misaligned.]
    }
    if(n==0 && i0>0)
    {
        printf("%d ",a[i0-1]);
        a[i0]='\0';
        i0--;
    }
    if(n==0 && i0==0)
    {
        printf("error "); // @@ [Error: This condition is not an else-if; after popping the last element, i0 becomes 0 and this branch also executes, printing an extra "error". Should be combined with the previous pop branch using if-else.]
    }
    if(n==-1)
    {
        break;
    }
}

return 0;    
}