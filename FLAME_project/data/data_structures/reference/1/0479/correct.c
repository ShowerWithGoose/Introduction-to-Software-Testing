#include <stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
int flag[20];
char chu[20];
int a;
void rank(int m,int n);
int main()
{
    scanf("%d",&a);
    rank(0,a);
    return 0;
}

void rank(int m,int n)
{
    int i,k;
    for(i=1;i<=a;i++)
    {
         if(n==0)
        {
            for(k=0;k<a;k++)
                printf("%c ",chu[k]);
            printf("\n");
            return;
        }

        if(flag[i]==0)
        {
            flag[i]=1;
            chu[m]=i+'0';
            rank(m+1,n-1);
            flag[i]=0;
        }

    }
}

