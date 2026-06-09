#include <stdio.h>
int main()
{
    int a,b=-1,c[100005];
    while (1)
    {
        scanf("%d",&a);
        if (a==-1) return 0;
        else if (a==1)
        {
            scanf("%d",&a);
            if (b==99) printf("error ");
            else
            {
                c[++b]=a;
            }
        }
        else
        {
            if (b<0) printf("error ");
            else printf("%d ",c[b--]);
        }
    }
    return 0;
}

