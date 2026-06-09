#include<string.h>
#include<stdio.h>
int main()
{
    char s[1000];
    int i=0,j;
    
    gets(s);
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]!='-'||s[i-1]>=s[i+1]) printf("%c",s[i]); // @@ [Error: When i=0, s[i-1] accesses index -1, causing undefined behavior. Also, the condition should be '&&' not '||' to correctly skip non-expandable cases.]
        else if(s[i-1]<'z'+1&&s[i-1]>'a'-1&&s[i+1]<'z'+1&&s[i+1]>'a'-1) // @@ [Error: The condition uses '<' and '>' with character comparisons, but the logic is incorrect; it should check if both characters are lowercase letters. Also, s[i-1] and s[i+1] may be out of bounds at string boundaries.]
        {
            for(j=s[i-1]+1;j<s[i+1];j++)
            printf("%c",j);
        }
        else if(s[i-1]<'Z'+1&&s[i-1]>'A'-1&&s[i+1]<'Z'+1&&s[i+1]>'A'-1) // @@ [Error: Same issue as above for uppercase letters; incorrect range checking and potential out-of-bounds access.]
        {
            for(j=s[i-1]+1;j<s[i+1];j++)
            printf("%c",j);
        }
        else if(s[i-1]<'9'+1&&s[i-1]>'0'-1&&s[i+1]<'9'+1&&s[i+1]>'0'-1) // @@ [Error: Same issue for digits; incorrect range checking and potential out-of-bounds access.]
        {
            for(j=s[i-1]+1;j<s[i+1];j++)
            printf("%c",j);
        }
    }
    return 0;
}