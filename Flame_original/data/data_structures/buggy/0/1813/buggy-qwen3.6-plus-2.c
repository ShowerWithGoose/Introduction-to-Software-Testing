#include<stdio.h>
#include<string.h>
int main()
{
    char s[100];
    gets(s); // @@ [Compilation error: gets() is removed in the C11 standard and causes compilation failure in modern environments; also unsafe due to buffer overflow]
    if(strlen(s)<=2)
    printf("%s",s);
    else
    {
        for(int i=1;i<=strlen(s)-2;) // @@ [Logical error: the loop condition i<=strlen(s)-2 prevents the last character of the string from being processed and printed]
        {if(s[i]!='-')
        {printf("%c",s[i-1]);
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
        } // @@ [Logical error: missing condition to check for the digit range [0-9] as required by the problem description]
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