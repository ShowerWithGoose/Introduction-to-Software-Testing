#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#define LL long long
#define max 128
#define true 1
int a[105];
int main()
{
    int i,j,k,ru=0,top=-1,button=0;
    while(1)
    {
        scanf("%d",&i);
        if(i==-1)
            break;
        else if(i==1)
        {
            scanf("%d",&ru);
            if(top==99)
            {
                printf("error ");
            }
            else
            {
                top++;
                a[top]=ru;
            }
        }
        else if(i==0)
        {
            if(top==-1)
            {
                printf("error ");
            }
            else
            {
                printf("%d ",a[top]);
                top--;
            }
        }
    }
    return 0;
}
