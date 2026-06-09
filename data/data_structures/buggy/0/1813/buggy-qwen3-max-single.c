#include<stdio.h>
#include<string.h>
int main()
{
    char s[100];
    gets(s); // @@ [Using 'gets' is unsafe and deprecated; may cause compilation error with modern compilers due to removal from standard library]
    if(strlen(s)<=2)
    printf("%s",s);
    else
    {
        for(int i=1;i<=strlen(s)-2;) // @@ [Loop condition and increment logic skips the last character when no '-' is at the end, leading to incomplete output]
        {if(s[i]!='-')
        {printf("%c",s[i-1]); // @@ [Only prints previous character, causing missing current character and potential duplication or omission]
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
        {for(int j=0;j<=s[i+1]-s[i-1];j++) // @@ [Loop includes both endpoints, causing duplicate printing of s[i-1] and s[i+1] which are already handled elsewhere]
        printf("%c",s[i-1]+j);
        }
        else
        printf("%c%c%c",s[i-1],s[i],s[i+1]); // @@ [Prints three characters at once, but outer loop logic doesn't skip ahead correctly, leading to reprocessing]
        i+=2;}
    }
    
}
}