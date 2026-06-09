#include<stdio.h>
int main()
{
    char a[500];
    int i,j,pow;
    gets(a);
    for(i=0; a[i]!='\0'; i++)
    {
        if(a[i]=='.')
        {
            if(a[i-1]=='0')
            {
                for(j=i+1; a[j]!='\0'&&a[j]=='0'; j++)
                    ;
                pow=j-i;
                if(a[j+1]!='\0')
                {
                    printf("%d.",a[j]-'0');
                    j++;
                    for(; a[j]!='\0'; j++)
                        printf("%d",a[j]-'0');
                    printf("e-%d",pow);
                    break;
                }
                if(a[j+1]=='\0')
                {
                    printf("%d",a[j]-'0');
                    printf("e-%d",pow);
                    break;
                }
            }
            else
            {
                printf("%d.",a[0]-'0');
                for(j=1; j<i; j++)
                    printf("%d",a[j]-'0');
                for(j=i+1; a[j]!='\0'; j++)
                    printf("%d",a[j]-'0');
                printf("e%d",i-1);
                break;
            }

        }
    }
    return 0;
}



