#include<stdio.h>
#include<string.h>
char c[10001];
int main()
{
    gets(c);

    for(int i=0;i<=strlen(c)-1;i++) // @@ Out-of-bounds access when i=0 or i=strlen(c)-1 if c[i] is '-'
    {
        if(c[i]=='-'&&c[i-1]<c[i+1]) // @@ Accessing c[i-1] and c[i+1] without bounds check; also if types differ but c[i-1]<c[i+1], the inner type check fails and '-' is omitted (missing else)
        {
            if((c[i-1]>='0'&&c[i-1]<='9')&&(c[i+1]>='0'&&c[i+1]<='9')||(c[i-1]>='a'&&c[i-1]<='z')&&(c[i+1]>='a'&&c[i+1]<='z')||(c[i-1]>='A'&&c[i-1]<='Z')&&(c[i+1]>='A'&&c[i+1]<='Z'))

            {
                for(int j=1;j<(c[i+1]-c[i-1]);j++)
                {
                    printf("%c",c[i-1]+j);
                }
            } // @@ Missing else clause to print the '-' when the inner type condition fails

        }

        else
        {
            printf("%c",c[i]);
        }
    }

    return 0;
}