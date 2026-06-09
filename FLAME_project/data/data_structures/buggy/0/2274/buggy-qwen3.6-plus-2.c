#include<stdio.h>
#include<string.h>
int main()
{
    int i=0,j=0,k=0,l;
    char s[100],s1[200];
    scanf("%s",s);
    int len = strlen(s);
    for(i=0;i<len;i++)
    {
        if(s[i]!='-') s1[j++] = s[i];
        else
        {
            if((isupper(s[i-1])&&isupper(s[i+1])&&(s[i-1]<s[i+1]))||(islower(s[i-1])&&islower(s[i+1])&&(s[i-1]<s[i+1]))||isdigit(s[i-1])&& isdigit(s[i+1])&&(s[i-1]<s[i+1]))
            {
                k = s[i+1] - s[i-1];
                for(l=1;l<k;l++)
                {
                    s1[j++]=s[i-1]+l;
                }
            }
            else s1[j++]= s[i]; // @@ The original code wrote to s[j++] instead of s1[j++]. This causes the '-' character to be missing from the output buffer s1, and potentially corrupts the input string s. For input "B-e", the 'e' is written to s1, but the '-' is written to s, so s1 only contains "B" (from the first iteration) and "e" is actually at index 1? Wait. i=0 ('B') -> s1[0]='B'. i=1 ('-') -> else branch. Condition fails. Original: s[1]='-'. s1 is unchanged. i=2 ('e') -> s1[1]='e'. s1 becomes "Be". But the expected output is "B-e". The bug in the provided buggy output is "B". Let's re-read carefully.
            // If the code writes to s[j++], j increments. 
            // i=0: s[0]='B'. s1[0]='B'. j=1.
            // i=1: s[1]='-'. Condition fails. s[1]='-' (no change). BUT j increments to 2.
            // i=2: s[2]='e'. s1[2]='e'. j=3.
            // s1 contains 'B', \0 (uninitialized or garbage?), 'e'. 
            // Actually s1[1] was never written. It contains garbage. 
            // However, the test case output says "B". This implies that maybe the garbage at s1[1] is interpreted as end of string or the print stops? 
            // Regardless, the logical error is writing to `s` instead of `s1`.
        }
    }
    s1[j]='\0';
    printf("%s",s1);
    return 0;
}