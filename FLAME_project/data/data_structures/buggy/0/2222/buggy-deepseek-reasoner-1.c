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
        if(s[i]=='-')
        {
            if(s[i-1]>='a'&&s[i+1]<='z'||s[i-1]>='A'&&s[i+1]<='Z'||s[i-1]>='0'&&s[i+1]<='9') // @@ Incorrect condition: does not ensure both characters are in the same range (lowercase, uppercase, or digit); needs separate checks for each type.
            {
                int c=s[i+1]-s[i-1];
                int k=0;
                while(k<c-1)
                {
                    t[j]=s[i-1]+1+k;
                    k++;
                    j++;
                }
                j--; // @@ Unnecessary and causes off-by-one indexing; after the while loop j already points to next free slot, decrementing here will cause a gap and later increment at line 34 may overwrite.
            }
        }
        else
        {
            t[j]=s[i]; // @@ This else is attached to the outer if (line 14), so it only runs when s[i]!='-'. When s[i]=='-' and the inner condition fails, the '-' is not copied to t, causing it to be lost.
        }
        i++;
        j++;
    }
    t[j]=s[l-1];
    int le=strlen(t);
    int k=0;
    while(k<le)
    {
        printf("%1c",t[k]);
        k++;
    }
    return 0;
}