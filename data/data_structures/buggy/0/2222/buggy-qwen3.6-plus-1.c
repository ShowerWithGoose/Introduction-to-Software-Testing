#include<stdio.h>
#include<string.h>
char s[100000];
char t[100000];
int main()
{
    scanf("%s",s);
    int i,j;
    t[0]=s[0];
    i=j=1;
    int l=strlen(s);
    while(i<l-1)
    {
        if(s[i]=='-') // @@ When the expansion condition is not met, the '-' character is not copied to t, causing it to be omitted from the output.
        {
            if(s[i-1]>='a'&&s[i+1]<='z'||s[i-1]>='A'&&s[i+1]<='Z'||s[i-1]>='0'&&s[i+1]<='9') // @@ Logic error: Fails to verify that both characters are of the same type (e.g., 'a' and 'Z' incorrectly pass) and does not check if the right character is strictly greater than the left character.
            {
                int c=s[i+1]-s[i-1];
                int k=0;
                while(k<c-1)
                {
                    t[j]=s[i-1]+1+k;
                    k++;
                    j++;
                }
                j--;
            }
        }
        else
        {
            t[j]=s[i];
        }
        i++;
        j++;
    }
    t[j]=s[l-1];
    int le=strlen(t); // @@ The array t is not explicitly null-terminated before calling strlen, which may cause undefined behavior or incorrect string length calculation.
    int k=0;
    while(k<le)
    {
        printf("%1c",t[k]);
        k++;
    }
    return 0;
}