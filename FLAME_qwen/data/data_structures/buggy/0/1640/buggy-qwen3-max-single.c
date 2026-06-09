#include<string.h>
#include<stdio.h>
int main()
{
    char s[1000];
    int i=0,j;
    
    gets(s); // @@ [Using gets() is unsafe and deprecated; however, the immediate error causing crash is out-of-bounds access when i=0 and checking s[i-1]]
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]!='-'||s[i-1]>=s[i+1]) printf("%c",s[i]); // @@ [When i=0, s[i-1] accesses s[-1], which is invalid memory; also condition logic flawed: should not print '-' in valid expansion cases]
        else if(s[i-1]<'z'+1&&s[i-1]>'a'-1&&s[i+1]<'z'+1&&s[i+1]>'a'-1) // @@ [Boundary checks are incorrect: 'a'-1 and 'z'+1 include non-lowercase characters; also accesses s[i-1]/s[i+1] without ensuring i>0 and i<len-1]
        {
            for(j=s[i-1]+1;j<s[i+1];j++)
            printf("%c",j);
        }
        else if(s[i-1]<'Z'+1&&s[i-1]>'A'-1&&s[i+1]<'Z'+1&&s[i+1]>'A'-1) // @@ [Same boundary issue: 'A'-1 and 'Z'+1 include non-uppercase characters; unsafe access when i=0 or i at end]
        {
            for(j=s[i-1]+1;j<s[i+1];j++)
            printf("%c",j);
        }
        else if(s[i-1]<'9'+1&&s[i-1]>'0'-1&&s[i+1]<'9'+1&&s[i+1]>'0'-1) // @@ [Boundary issue: '0'-1 is '/', '9'+1 is ':', so includes non-digit chars; unsafe access at string boundaries]
        {
            for(j=s[i-1]+1;j<s[i+1];j++)
            printf("%c",j);
        }
    }
    return 0;
}