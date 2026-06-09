#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#define ll long long
char s[105];
int main()
{
    scanf("%s",s);
    int i=0,len=strlen(s),j,k=0,i1;
    if(s[0]=='0')
    {
        i++;
        while(s[i+1]=='0')
            i++;
        printf("%c.",s[i+1]); // @@ [If the input is "0.0", this accesses s[2] which may be '\0', leading to undefined behavior or printing garbage. Also, for inputs like "0.1", i starts at 1, then checks s[2], but "0.1" has length 3 (indices 0='0',1='.',2='1'), so s[i+1] = s[2] is correct, but loop condition fails; however, if input is "0.0001", the loop increments i until s[i+1] != '0', but initial i=1, so it checks s[2], s[3], etc. However, if all digits after decimal are zero (which shouldn't happen per problem statement), it may go out of bounds. More critically, the logic assumes there's always a non-zero digit, but doesn't validate index bounds before accessing s[i+1].]
        for(j=i+2;j<len;j++)
            printf("%c",s[j]);
        printf("e-%d",i);
    }
    else
    {
        while(s[i+1]!='.'&&i<len-1)
            i++;
        if(i==len-1)
        {
        while(s[len-1-k]=='0')
            k++;
        if(k==len-1)
            printf("%c",s[0]);
        else
        {
        printf("%c.",s[0]);
        for(j=1;j<i+1-k;j++)
            printf("%c",s[j]);
        }
        printf("e%d",i);
        }
        else
        {
            printf("%c.",s[0]);
            for(j=1;j<len;j++)
            {
                if(s[j]!='.')
                    printf("%c",s[j]);
            }
            printf("e%d",i);
        }
    }
    return 0; 
}