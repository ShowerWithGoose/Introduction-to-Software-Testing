#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define eps 1e-10



int main()
{
int i,j;
int s[1200],a[102];


i=0;
j=0;
while(scanf("%d",&s[i]))
{
    if(s[i]==1)
    {
        scanf("%d",&a[j]);
        if(j==100)
        {
            printf("error ");
            a[j]=0;
        }
        else
            j++;
    }
    else if(s[i]==0)
    {
        if(j==0)
            printf("error ");
        else
        {
            printf("%d ",a[--j]);
            a[j]=0;
        }
    }
    else if(s[i]==-1)
        return 0;

}


return 0;
}

