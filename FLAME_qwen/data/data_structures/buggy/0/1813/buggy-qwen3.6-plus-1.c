#include<stdio.h>
#include<string.h>
int main()
{
    char s[100];
    gets(s); // @@ gets() is removed in the C11 standard and causes a compilation error in modern compilers; use fgets() instead.
    if(strlen(s)<=2)
    printf("%s",s);
    else
    {
        for(int i=1;i<=strlen(s)-2;) // @@ Declaring loop variable 'i' inside the for statement is not supported in C89/C90, causing a compilation error on strict/older compilers.
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
        }
        if(flag==1)
        {for(int j=0;j<=s[i+1]-s[i-1];j++) // @@ Declaring loop variable 'j' inside for causes C89 compilation error; logically, starting j from 0 reprints s[i-1], causing duplicate output.
        printf("%c",s[i-1]+j);
        }
        else
        printf("%c%c%c",s[i-1],s[i],s[i+1]);
        i+=2;}
    }

}
}