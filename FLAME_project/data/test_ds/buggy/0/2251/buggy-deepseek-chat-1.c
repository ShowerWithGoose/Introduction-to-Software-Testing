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
            if(s[i-1]>='0'&&s[i+1]<='9'&&s[i+1]>s[i-1]) // @@ Error: The condition `s[i+1]<='9'` does not check that `s[i+1]` is a digit; it only checks the upper bound. It should be `s[i+1]>='0'&&s[i+1]<='9'` to ensure both characters are digits. Also, the loop prints `s[i-1]+j` for j from 0 to lenth-1, which includes the starting character `s[i-1]` but the expansion should exclude the starting character (e.g., a-d should output bc, not abcd). The loop should start from j=1 to avoid printing the starting character.
            {
                lenth=s[i+1]-s[i-1];
                for(j=0;j<lenth;j++)
                    printf("%c",s[i-1]+j);
            }
            else if(s[i-1]>='a'&&s[i+1]<='z'&&s[i+1]>s[i-1]) // @@ Error: Same issue as above; `s[i+1]<='z'` does not ensure `s[i+1]` is a lowercase letter. Should be `s[i+1]>='a'&&s[i+1]<='z'`. Also, the loop includes the starting character.
            {
                lenth=s[i+1]-s[i-1];
                for(j=0;j<lenth;j++)
                    printf("%c",s[i-1]+j);
            }
            else if(s[i-1]>='A'&&s[i+1]<='Z'&&s[i+1]>s[i-1]) // @@ Error: Same issue; `s[i+1]<='Z'` does not ensure uppercase. Should be `s[i+1]>='A'&&s[i+1]<='Z'`. Also, loop includes starting character.
            {
                lenth=s[i+1]-s[i-1];
                for(j=0;j<lenth;j++)
                    printf("%c",s[i-1]+j);
            }
            else
                printf("-");
        }
        else 
            printf("%c",s[i]);
    }
    return 0;
}