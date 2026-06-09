#include<stdio.h>
#include<string.h>
char c[10001];
int main()
{
    gets(c);

    for(int i=0;i<=strlen(c)-1;i++) @@ [Error: Loop starts at i=0, causing out-of-bounds access to c[i-1]. Should start at 1 or include boundary checks.]
    {
        if(c[i]=='-'&&c[i-1]<c[i+1]) @@ [Error: Missing boundary check for i+1. When c[i]=='-' but character types differ (e.g., B-e), it enters this block, skips the inner if, and fails to print the '-' character.]
        {
            if((c[i-1]>='0'&&c[i-1]<='9')&&(c[i+1]>='0'&&c[i+1]<='9')||(c[i-1]>='a'&&c[i-1]<='z')&&(c[i+1]>='a'&&c[i+1]<='z')||(c[i-1]>='A'&&c[i-1]<='Z')&&(c[i+1]>='A'&&c[i+1]<='Z')) @@ [Error: The condition correctly checks types, but the surrounding logic structure fails to print '-' when types mismatch. The '-' is lost because no else branch handles invalid expansion cases.]

            {
                for(int j=1;j<(c[i+1]-c[i-1]);j++)
                {
                    printf("%c",c[i-1]+j);
                }
            }

        }

        else @@ [Error: This else branch only executes when c[i]!='-' or c[i-1]>=c[i+1]. It does not handle the case where c[i]=='-' but expansion conditions fail, causing the '-' to be omitted from the output.]
        {
            printf("%c",c[i]);
        }
    }

    return 0;
}