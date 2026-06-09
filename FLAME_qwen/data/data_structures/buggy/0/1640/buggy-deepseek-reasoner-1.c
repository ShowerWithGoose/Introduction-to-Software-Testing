#include<string.h>
#include<stdio.h>
int main()
{
    char s[1000];
    int i=0,j;
    
    gets(s);
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]!='-'||s[i-1]>=s[i+1]) printf("%c",s[i]); // @@ [When i==0, s[-1] is out‑of‑bounds; when i==strlen(s)-1, s[i+1] is the null terminator, which may cause incorrect logic.]
        else if(s[i-1]<'z'+1&&s[i-1]>'a'-1&&s[i+1]<'z'+1&&s[i+1]>'a'-1) // @@ [Same out‑of‑bounds issue for s[i-1] and s[i+1] at the boundaries.]
        {
            for(j=s[i-1]+1;j<s[i+1];j++) // @@ [s[i-1] and s[i+1] may be out‑of‑bounds when i==0 or i==strlen(s)-1.]
            printf("%c",j);
        }
        else if(s[i-1]<'Z'+1&&s[i-1]>'A'-1&&s[i+1]<'Z'+1&&s[i+1]>'A'-1) // @@ [Same out‑of‑bounds issue.]
        {
            for(j=s[i-1]+1;j<s[i+1];j++) // @@ [Same out‑of‑bounds issue.]
            printf("%c",j);
        }
        else if(s[i-1]<'9'+1&&s[i-1]>'0'-1&&s[i+1]<'9'+1&&s[i+1]>'0'-1) // @@ [Same out‑of‑bounds issue.]
        {
            for(j=s[i-1]+1;j<s[i+1];j++) // @@ [Same out‑of‑bounds issue.]
            printf("%c",j);
        }
    }
    return 0;
}