#include<stdio.h>
#include<string.h>
char c[10001];
int main()
{
    gets(c); // @@ [Using gets() is unsafe and may cause buffer overflow; however, the main logic error is elsewhere.]

    for(int i=0;i<=strlen(c)-1;i++)
    {
        if(c[i]=='-'&&c[i-1]<c[i+1]) // @@ [This condition accesses c[i-1] and c[i+1] without checking if i is within valid bounds (i>=1 and i<=strlen(c)-2), leading to undefined behavior for '-' at start or end. Also, it doesn't ensure both sides are same type before comparing c[i-1] < c[i+1].]
        {
            if((c[i-1]>='0'&&c[i-1]<='9')&&(c[i+1]>='0'&&c[i+1]<='9')||(c[i-1]>='a'&&c[i-1]<='z')&&(c[i+1]>='a'&&c[i+1]<='z')||(c[i-1]>='A'&&c[i-1]<='Z')&&(c[i+1]>='A'&&c[i+1]<='Z'))

            {
                for(int j=1;j<(c[i+1]-c[i-1]);j++)
                {
                    printf("%c",c[i-1]+j);
                }
            }

        }

        else
        {
            printf("%c",c[i]);
        }
    }

    return 0;
}