#include<stdio.h>
#include<string.h>
char s[10086];
char m[10086];
int main()
{
    gets(s);
    int i,j,k;
    for(i=0,j=0;s[i]!='\0';i++)
    {
        if(s[i]=='-')
        {
            for(k=0;k<s[i+1]-s[i-1]-1;k++) // @@ [Error: No bounds check; s[i-1] and s[i+1] may be out of bounds; no type/range validation; negative difference causes large loop leading to long output.]
            {
                m[j]=m[j-1]+1; // @@ [Error: When j=0, m[-1] is out-of-bounds; also m[j-1] is not yet set with left character, causing undefined behavior.]
                j++;
            }
        }
        else
        {
            m[j]=s[i];
            j++;
        }
    }
    puts(m);
}