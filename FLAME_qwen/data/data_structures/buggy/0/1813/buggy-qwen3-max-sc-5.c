#include<stdio.h>
#include<string.h>
int main()
{
    char s[100];
    gets(s); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; many compilers no longer support it, leading to compilation errors. It should be replaced with 'fgets'.]
    if(strlen(s)<=2)
    printf("%s",s);
    else
    {
        for(int i=1;i<=strlen(s)-2;) // @@ [Using 'int i=1' in the for loop initializer is valid in C99+, but if the compiler defaults to an older standard like C89, this will cause a compilation error because variable declarations must be at the beginning of a block.]
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
        {for(int j=0;j<=s[i+1]-s[i-1];j++) // @@ [Same issue as above: declaring 'int j' inside the for loop may cause a compilation error under C89 standard.]
        printf("%c",s[i-1]+j);
        }
        else
        printf("%c%c%c",s[i-1],s[i],s[i+1]);
        i+=2;}
    }
    
}
}