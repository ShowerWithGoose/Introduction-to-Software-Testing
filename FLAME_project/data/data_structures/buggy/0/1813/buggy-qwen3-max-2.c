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
        for(int i=1;i<=strlen(s)-2;) // @@ [Loop starts at index 1 and processes triplets (i-1, i, i+1), but fails to handle the last character properly when the string doesn't end with a valid expansion pattern. Also, after processing an expansion, it skips two positions but may miss trailing characters.]
        {if(s[i]!='-')
        {printf("%c",s[i-1]); // @@ [When current character is not '-', it prints the previous character. However, this causes the first character to be printed only when the second is not '-', and the last character may never be printed if loop ends early.]
        i+=1;
        }
        else
        {
        int flag=0;
        if(s[i-1]<='z'&&s[i-1]>='a')
        {if(s[i+1]<='z'&&s[i+1]>='a'&&s[i+1]>s[i-1])
        flag=1;
        }
        else if(s[i-1]<='Z'&&s[i-1]>='A') // @@ [Missing check for digits (0-9) as per problem requirements. Only handles lowercase and uppercase letters, so expansions like '0-9' would be treated as literal and not expanded.]
        {if(s[i+1]<='Z'&&s[i+1]>='A'&&s[i+1]>s[i-1])
        flag=1;
        }
        if(flag==1)
        {for(int j=0;j<=s[i+1]-s[i-1];j++)
        printf("%c",s[i-1]+j);
        }
        else
        printf("%c%c%c",s[i-1],s[i],s[i+1]); // @@ [Prints three characters literally when expansion condition fails. However, this leads to duplicate printing of characters that may have already been printed in previous iterations, especially the middle '-' and next character.]
        i+=2;} // @@ [After processing a '-', increments by 2, which moves i to i+2. But since the loop variable represents the middle of a triplet, this logic misaligns the scanning window and causes overlapping or missed characters. Also, the final character of the string is never printed if the loop ends without encountering a non-'-' at the right position.]
    }
    
}
}