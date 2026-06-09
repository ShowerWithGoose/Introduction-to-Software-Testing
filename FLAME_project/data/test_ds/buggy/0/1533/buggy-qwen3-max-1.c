#include<stdio.h>
#include<string.h>
char kz(char s[])
{
    char c[100];
    int j=0; 
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]!='-')
        {
            c[j]=s[i];
            printf("%c",c[j]);
            j++;
        }
        else if(('a'<=s[i-1]&&s[i-1]<s[i+1]&&s[i+1]<'z')||('A'<=s[i-1]&&s[i-1]<s[i+1]&&s[i+1]<'Z')||('0'<=s[i-1]&&s[i-1]<s[i+1]&&s[i+1]<'1')) // @@ [The boundary checks are incorrect: 'z', 'Z', and '1' should be inclusive (<=), and '1' is wrong for digits—it should be '9'. Also, the condition fails to include the end character itself in valid ranges.]
        {
            c[j]=s[i-1]+1;
            printf("%c",c[j]);
            while(c[j]<s[i+1]-1) // @@ [This loop condition stops one character too early; it should continue until c[j] < s[i+1], not s[i+1]-1, to include all characters up to but not including s[i+1]. However, since we already printed s[i-1]+1, we need to print up to s[i+1]-1, but the logic here is flawed due to off-by-one and missing handling of the full range.]
            {
                j++;
                c[j]=c[j-1]+1;
                printf("%c",c[j]);
            }
            j++;
        }
        else
        {
            c[j]=s[i];
            printf("%c",c[j]);
            j++;
        }
    }
}
int main()
{
    char s[100];
    gets(s);
    kz(s);
    return 0;
}