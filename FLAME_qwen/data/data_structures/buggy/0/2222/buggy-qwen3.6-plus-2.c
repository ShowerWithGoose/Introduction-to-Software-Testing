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
            if(s[i-1]>='a'&&s[i+1]<='z'||s[i-1]>='A'&&s[i+1]<='Z'||s[i-1]>='0'&&s[i+1]<='9') // @@ Missing check for s[i+1] > s[i-1] and incomplete range validation; should ensure both characters are strictly within the same type range and the right character is greater than the left.
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
    t[j]=s[l-1]; // @@ Missing null terminator assignment (t[j+1] = '\0';) after copying the last character, causing strlen(t) to potentially read out of bounds.
    int le=strlen(t); // @@ Using strlen on a string that may not be null-terminated leads to undefined behavior or incorrect length calculation.
    int k=0;
    while(k<le)
    {
        printf("%1c",t[k]);
        k++;
    }
    return 0;
}