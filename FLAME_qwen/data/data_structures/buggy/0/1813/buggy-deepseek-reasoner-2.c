#include<stdio.h>
#include<string.h>
int main()
{
    char s[100];
    gets(s); // @@ [gets is unsafe and deprecated; may cause compilation error on modern compilers.]
    if(strlen(s)<=2)
    printf("%s",s);
    else
    {
        for(int i=1;i<=strlen(s)-2;) // @@ [Loop condition and C99 declaration may cause compilation error in C89; also logic error: never processes the last character.]
        {if(s[i]!='-')
        {printf("%c",s[i-1]);
        i+=1;
        }
        else
        {
        int flag=0;
        if(s[i-1]<='z'&&s[i-1]>='a') // @@ [Missing digit case; should also check for '0'..'9'.]
        {if(s[i+1]<='z'&&s[i+1]>='a'&&s[i+1]>s[i-1])
        flag=1;
        }
        else if(s[i-1]<='Z'&&s[i-1]>='A') // @@ [Missing digit case; only handles lowercase and uppercase.]
        {if(s[i+1]<='Z'&&s[i+1]>='A'&&s[i+1]>s[i-1])
        flag=1;
        }
        if(flag==1)
        {for(int j=0;j<=s[i+1]-s[i-1];j++) // @@ [Expansion loop includes the start character (j=0); this may cause double printing or incorrect output, and combined with the loop increment logic leads to missing characters.]
        printf("%c",s[i-1]+j);
        }
        else
        printf("%c%c%c",s[i-1],s[i],s[i+1]);
        i+=2;} // @@ [Incrementing by 2 after a dash, together with the loop bound, causes the last character to be skipped.]
    }
    
}