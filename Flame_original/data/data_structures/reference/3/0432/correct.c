#include <stdio.h>
char a[10000];
int main()
{
    char b;
    int i,k,j,f=0;
    gets(a);
    for(i=0;a[i]!='\0';i++)
    {
        if(a[i]=='.')
            k=i;
        else if(a[i]!='0'&&f==0)
            {j=i;
            f=1;
            printf("%c",a[i]);
            }
        else if(a[i]=='0'&&f>0)
            {
            printf("%c",a[i]);
            }
        else if (f==1)
            {printf(".%c",a[i]);
            f++;}
        else if (f==2)
            printf("%c",a[i]);

    }
    if(k-j>0)
        j++;
    printf("e%d",k-j);
}

