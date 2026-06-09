#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
int main()
{
    char str[10000];
	char a;
    scanf("%s",str);
    int i,j;
    for(i=0;i<strlen(str);i++)
    {
        if(str[i]=='-')
        {
            if(i==0)
            {
                printf("-");
            }
            else if(str[i-1]>='0'&&str[i+1]<='9'&&str[i+1]>str[i-1])
            {
                for(j=1;j<(str[i+1]-str[i-1]);j++)
                {
                    a=str[i-1]+j;
                    printf("%c",a);
                }
            }
            else if(str[i-1]>='a'&&str[i+1]<='z'&&str[i+1]>str[i-1])
            {
                for(j=1;j<(str[i+1]-str[i-1]);j++)
                {
                    a=str[i-1]+j;
                    printf("%c",a);
                }
            }
            else if(str[i-1]>='A'&&str[i+1]<='Z'&&str[i+1]>str[i-1])
            {
                for(j=1;j<(str[i+1]-str[i-1]);j++)
                {
                    a=str[i-1]+j;
                    printf("%c",a);
                }
            }
            else
            {
                printf("-");
            }
        }
        else
        {
            printf("%c",str[i]);
        }
    }
    return 0;
}


