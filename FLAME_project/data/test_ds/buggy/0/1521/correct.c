#include<stdio.h>
#include<string.h>
char fm[10000];
int main()
{    scanf("%s",&fm);
    int i,j;
    for(i=0;i<strlen(fm);i++)
    {

        if(fm[i]=='-'&&fm[i-1]<fm[i+1])
        {
            if((('a'<=fm[i-1]&&fm[i-1]<='z')&&('a'<=fm[i+1]&&fm[i+1]<='z'))||(('A'<=fm[i-1]&&fm[i-1]<='Z')&&('A'<=fm[i+1]&&fm[i+1]<='Z'))||(('0'<=fm[i-1]&&fm[i-1]<='9')&&('0'<=fm[i+1]&&fm[i+1]<='9')))
            {
                for(j=1;j<=fm[i+1]-fm[i-1];j++)
                {
                    printf("%c",fm[i-1]+j);
                }
                i++;
                continue;
            }
            else
            {

            }
        }
        printf("%c",fm[i]);
    }
    return 0;
}


