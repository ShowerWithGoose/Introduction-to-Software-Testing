#include <stdio.h>
int a[100],o,s,i;
int main()
{
    while(1)
    {
        scanf("%d",&o);
        if(o==-1)
        break;
        else if(o==0&&i>0)
        {
            printf("%d ",a[i-1]);
            a[i-1]=0;
            i--;
        }
        else if(o==1&&i<100)
        {
            scanf("%d",&s);
            a[i]=s;
            i++;
        }
        else
        printf("error ");
    }
    return 0;
}

