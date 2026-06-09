#include<stdio.h>
int main()
{
    char a;
    int b=0,c=-1,d=1,biao1=0,biao2=0;
    while(scanf("%c",&a)!=EOF)
    {
        if(a=='.')
        {
            biao2=1;
        }
        else if(a>='0'&&a<='9')
        {
            if(a!='0')
            {
                biao1=1;
            }
            if(biao1==1)
            {
                printf("%c",a);
                if(d==1)
                {
                    printf(".");
                    d=0;
                }
                c++;
            }
            if(biao2==1)
            {
                b++;
            }
        }
    }
    printf("e%d",c-b);
    return 0;
}