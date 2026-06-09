#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#define ll long long
#define ull unsigned long long

int main()
{
    int a,i,n=0,op,ed=0,z[107]={0},re[100],e[100]={0};
    scanf("%d",&op);
    do
    {
        if (!op)
        {
            if (!ed) e[n++]=1;
            else re[n++]=z[ed--];
        }
        else
        {
            scanf("%d",&a);
            if (ed==100) e[n++]=1;
            else z[++ed]=a;
        }
        scanf("%d",&op);
    } while (op!=-1);
    for ( i = 0; i < n; i++)
    {
        if (e[i]) printf("error ");
        else printf("%d ",re[i]);
    }
    return 0;
}
