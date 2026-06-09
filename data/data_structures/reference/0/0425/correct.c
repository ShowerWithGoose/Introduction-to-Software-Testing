#include <stdio.h>
char a[10000],b[10000];
int main()
{
    int i,j,k;
    scanf("%s",a);
    for(i=0,j=0;a[i]!=0;i++)
    {
        b[j++]=a[i];
        if(a[i+1]=='-')
            if(a[i]<a[i+2])
                if((a[i]>='0'&&a[i+2]<='9')||(a[i]>='a'&&a[i+2]<='z')||(a[i]>='A'&&a[i+2]<='Z'))
                {
                    for(k=1;k<a[i+2]-a[i];k++)
                    b[j++]=a[i]+k;
                    i++;
                }
    }
    printf("%s",b);
    return 0;
}

