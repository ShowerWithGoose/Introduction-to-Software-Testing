#include<stdio.h>
#include<string.h>
int main()
{
    char s[10000];
    char a,b;
    int i=0,flag=0;
    gets(s);
    while(s[i]!='\0')
    {
        if(s[i]!='-'||i==0)
            printf("%c",s[i]);
        else{
        if(s[i-1]+1<s[i+1])
        {
            a=s[i-1];
            b=s[i+1];
            if((a<='z'&&a>='a'&&b<='z'&&b>='a')||(a<='Z'&&a>='A'&&b<='Z'&&b>='A')||(a<='9'&&a>='0'&&b<='9'&&b>='0'))
            {
                while(a+1<b)
                {
                    a++;
                    printf("%c",a);
                    flag=1;
                }
            }
        }
        if(flag==0)
            printf("-");
        else
            flag=0;
        }
        i++;
    }
    return 0;
}

