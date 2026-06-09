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
            if(s[i-1]>='a'&&s[i+1]<='z'||s[i-1]>='A'&&s[i+1]<='Z'||s[i-1]>='0'&&s[i+1]<='9') // @@ Condition does not ensure both characters are of the same type and does not check s[i+1] > s[i-1]; also operator precedence may cause incorrect evaluation.
            {
                int c=s[i+1]-s[i-1];
                int k=0;
                while(k<c-1)
                {
                    t[j]=s[i-1]+1+k;
                    k++;
                    j++;
                }
                j--; // @@ This decrement is incorrect when no expansion should occur (e.g., c<=0 or types mismatch), causing the dash to be skipped.
            }
        }
        else
        {
            t[j]=s[i];
        }
        i++;
        j++;
    }
    t[j]=s[l-1]; // @@ Missing null terminator for t array; subsequent strlen(t) will read uninitialized memory.
    int le=strlen(t);
    int k=0;
    while(k<le)
    {
        printf("%1c",t[k]);
        k++;
    }
    return 0;
}