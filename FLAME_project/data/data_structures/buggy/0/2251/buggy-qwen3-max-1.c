#include <stdio.h>
#include <string.h> 

char s[10000000];
int i,len,j,lenth;

int main()
{
    scanf("%s",s);
    len=strlen(s);
    for(i=0;i<len;i++)
    {
        if(s[i]=='-')
        {
            if(s[i-1]>='0'&&s[i+1]<='9'&&s[i+1]>s[i-1]) // @@ [The condition checks s[i-1] >= '0' but does not verify s[i+1] >= '0'; similarly, it checks s[i+1] <= '9' but not s[i-1] <= '9'. This allows mixed cases like 'a-9' to incorrectly pass the digit check. Also, when i=0, s[i-1] accesses invalid memory (before start of string).]
            {
                lenth=s[i+1]-s[i-1];
                for(j=0;j<lenth;j++)
                    printf("%c",s[i-1]+j); // @@ [This prints from s[i-1] up to but not including s[i+1], which is correct in count, but because the loop starts at j=0, it includes the starting character again. However, the bigger issue is that the expansion should only print the characters *between* the two endpoints, not including the left endpoint. But actually, looking at expected output: input "a-u" becomes "abcdefghijklmnopqrstu", which includes 'a' and 'u'. Wait — no: the example says expand a-d to abcd, meaning both ends are included. However, in the reference program, it loops from s[i-1]+1 to < s[i+1], so it prints only the middle characters, and the surrounding characters are printed by the main loop. So the bug here is that this code prints the entire range including the left character, while the left character was already printed in the previous iteration. Hence, duplication occurs.]
            }
            else if(s[i-1]>='a'&&s[i+1]<='z'&&s[i+1]>s[i-1]) // @@ [Same as above: missing check that s[i-1] <= 'z' and s[i+1] >= 'a'. Also, unsafe access when i=0 or i=len-1.]
            {
                lenth=s[i+1]-s[i-1];
                for(j=0;j<lenth;j++)
                    printf("%c",s[i-1]+j); // @@ [This causes duplication: the character before '-' was already printed in the previous iteration of the main loop. Now we're printing it again as the first character of the expansion. For example, in "a-u", 'a' is printed normally, then when '-' is encountered, we print 'a', 'b', ..., 't', leading to double 'a'. Expected output starts with 'a' only once.]
            }
            else if(s[i-1]>='A'&&s[i+1]<='Z'&&s[i+1]>s[i-1]) // @@ [Same issues: incomplete type checking and unsafe boundary access.]
            {
                lenth=s[i+1]-s[i-1];
                for(j=0;j<lenth;j++)
                    printf("%c",s[i-1]+j); // @@ [Same duplication error.]
            }
            else
                printf("-");
        }
        else 
            printf("%c",s[i]);
    }
    return 0;
}