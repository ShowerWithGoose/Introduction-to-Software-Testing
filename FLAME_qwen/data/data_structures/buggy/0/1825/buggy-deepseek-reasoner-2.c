#include <stdio.h>
int main()
{
    char s[1000]={0};
    int i=0;
    while(scanf("%c",&s[i])!=EOF) // @@ [Using scanf("%c") in a loop until EOF does not stop at newline; requires manual EOF (Ctrl+D/Z). Should read the whole line with gets() or fgets().]
    {
        i++;
    }
    int j;
    for(j=0;j<=i;j++) // @@ [Loop runs up to j <= i, but i is the count of characters read, so index i is out of bounds; should be j < i.]
    {
        if(s[j]!='-')
        printf("%c",s[j]);
        else
        {   if((s[j-1]>='0'&&s[j+1]<='9'&&s[j-1]<s[j+1])||(s[j-1]>='a'&&s[j+1]<='z'&&s[j-1]<s[j+1])||(s[j-1]>='A'&&s[j+1]<='Z'&&s[j-1]<s[j+1])) // @@ [Incomplete range checks; both characters must be in the same range. Also missing bounds check for j-1 and j+1.]
            {
                int n=1;
                while(s[j-1]+n<=s[j+1]) // @@ [Should print only intermediate characters (excluding ending char); condition should be < not <=.]
                {
                    printf("%c",s[j-1]+n);
                    n++;
                }
            }
            else
            printf("%c",s[j]);
        }
    }
    return 0;
}