#include <stdio.h>
#include <string.h>

int main()
{
    int i,j,k;
    char str[400]={'\0'};
    gets(str);
    j=strlen(str);
    for(i=0;i<j;i++)
    {
        if((str[i]=='-')&&(i>0))
        {
            if(str[i-1]>='a'&&str[i+1]<='z'&&(str[i-1]<str[i+1]))
            {
            for(k=1;str[i-1]+k<str[i+1];k++)
            printf("%c",str[i-1]+k);
            }
            else if(str[i-1]>='A'&&str[i+1]<='Z'&&(str[i-1]<str[i+1]))
            {
            for(k=1;str[i-1]+k<str[i+1];k++)
            printf("%c",str[i-1]+k);
            }
            else if(str[i-1]>='0'&&str[i+1]<='9'&&(str[i-1]<str[i+1]))
            {
            for(k=1;str[i-1]+k<str[i+1];k++)
            printf("%c",str[i-1]+k);
            }
            else
            printf("-");
        }
        else
        printf("%c",str[i]);
    }
    system("pause");
    return 0;
}
