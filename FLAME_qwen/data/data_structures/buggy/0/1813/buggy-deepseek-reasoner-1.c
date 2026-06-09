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
        for(int i=1;i<=strlen(s)-2;) @@ [Loop condition and manual increment logic cause failure to print all characters, especially the last character(s). The loop does not handle characters after the last processed index.]
        {if(s[i]!='-')
        {printf("%c",s[i-1]); @@ [Incorrect: prints the character before the current index instead of the current character. This causes missing characters and duplicates.]
        i+=1;
        }
        else
        {
        int flag=0;
        if(s[i-1]<='z'&&s[i-1]>='a') @@ [Missing digit expansion: only checks lowercase and uppercase, does not handle digits [0-9].]
        {if(s[i+1]<='z'&&s[i+1]>='a'&&s[i+1]>s[i-1])
        flag=1;
        }
        else if(s[i-1]<='Z'&&s[i-1]>='A')
        {if(s[i+1]<='Z'&&s[i+1]>='A'&&s[i+1]>s[i-1])
        flag=1;
        }
        if(flag==1)
        {for(int j=0;j<=s[i+1]-s[i-1];j++) @@ [Incorrect: loop includes both endpoints, causing duplication in consecutive expansions. Should exclude endpoints because the first character is printed earlier and the last will be printed by next iteration.]
        printf("%c",s[i-1]+j);
        }
        else
        printf("%c%c%c",s[i-1],s[i],s[i+1]);
        i+=2; @@ [For the non-expansion case, this skips the character after the dash, causing it to be omitted. For expansion case, if endpoints not duplicated, it also skips the last character. The increment should be +1 to continue to next character, not +2.]
    }
    
}
}