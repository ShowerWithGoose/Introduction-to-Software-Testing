#include<stdio.h>
int try(int );
int main()
{
    char a[102];
    int i,j,m;
    gets(a);
        if(a[0]=='0')
            {
                for(i=2;a[i]!='\0';i++)
                {
                    if(a[i]!='0')
                    {
                        m=i-1;
                    break;
                    }
                }
                for(i=2;a[i]!='\0';i++)
                {
                    if(a[i]!='0'&&a[i+1]=='\0')
                    {
                        j=i+1;
                        printf("%c",a[i]);
                        break;
                    }
                     if(a[i]!='0'&&a[i+1]!='\0')
                    {
                        j=i+1;
                        printf("%c.",a[i]);
                        break;
                    }
                }

                for(i=j;a[i]!='\0';i++)
                {
                    printf("%c",a[i]);
                }
                printf("e-%d",m);

            }
        else if(a[0]!='0')
        {
            for(i=0;a[i]!='\0';i++)
            {
                if(a[i]=='.')
                {
                    m=i-1;
                    break;
                }
            }
            printf("%c.",a[0]);
            for(i=1;i<=m;i++)
            {
                printf("%c",a[i]);
            }
            for(i=m+2;a[i]!='\0';i++)
            {
                printf("%c",a[i]);
            }
            printf("e%d",m);

        }


    return 0;
}

