#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char str[10000];

bool legal(char a,char b);

int main()
{
    scanf("%s",str);
    int length = strlen(str);
    for(int i=0;i<length;i++)
    {
        if(str[i]!='-')
            printf("%c",str[i]);
        else
        {
            if(legal(str[i-1],str[i+1]))
            {
                for(char j=str[i-1]+1;j<str[i+1];j++)
                    printf("%c",j);
            }
            else
                printf("-");
        }
    }
    return 0;
}

bool legal(char a,char b)
{
    if(a>='a'&&a<='z')
    {
        if(b>='a'&&b<='z'&&a<b)
            return true;
        else return false;
    }
    if(a>='A'&&a<='Z')
    {
        if(b>='A'&&b<='Z'&&a<b)
            return true;
        else return false;
    }
    if(a>='0'&&a<='9')
    {
        if(b>='0'&&b<='9'&&a<b)
            return true;
        else return false;
    }

}



