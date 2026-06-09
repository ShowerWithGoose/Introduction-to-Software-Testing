#include <stdio.h>
#include <string.h>

int main()
{
    char s[1000000]="",c;
    int i=0;
    gets(s);
    for(;s[i]!='\0';i++)
    {

        if(s[i]=='-' && s[i-1]<s[i+1])
        {
            if(s[i-1]>='a'&&s[i-1]<='y' && s[i+1]<='z')
                {
                    for(int j=1;(c=s[i-1]+j)!=s[i+1];j++)
                        printf("%c",c);
                    continue;
                }
            else if(s[i-1]>='A'&&s[i-1]<='Y' && s[i+1]<='Z')
                {
                    for(int j=1;(c=s[i-1]+j)!=s[i+1];j++)
                        printf("%c",c);
                    continue;
                }
            else if(s[i-1]>='0'&&s[i-1]<='8' && s[i+1]<='9')
                {
                    for(int j=1;(c=s[i-1]+j)!=s[i+1];j++)
                        printf("%c",c);
                    continue;
                }
        }
        printf("%c",s[i]);
    }
    printf("%c",'\0');
    return 0;
}



