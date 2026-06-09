#include<stdio.h>
#include<string.h>
int main()
{
    char s[100];
    gets(s);
    if(strlen(s)<=2)
    printf("%s",s);
    else
    {
        for(int i=1;i<=strlen(s)-2;)
        {if(s[i]!='-')
        {printf("%c",s[i-1]); // @@ This line prints the character before a non-dash character, but if that character was already printed as part of a previous expansion (e.g., the 'u' after expanding "a-u"), it causes a duplicate.
        i+=1;
        }
        else
        {
        int flag=0;
        if(s[i-1]<='z'&&s[i-1]>='a')
        {if(s[i+1]<='z'&&s[i+1]>='a'&&s[i+1]>s[i-1])
        flag=1;
        }
        else if(s[i-1]<='Z'&&s[i-1]>='A')
        {if(s[i+1]<='Z'&&s[i+1]>='A'&&s[i+1]>s[i-1])
        flag=1;
        }
        if(flag==1)
        {for(int j=0;j<=s[i+1]-s[i-1];j++)
        printf("%c",s[i-1]+j);
        }
        else
        printf("%c%c%c",s[i-1],s[i],s[i+1]);
        i+=2;}
    }
    
}
}