#include<stdio.h>
#include<string.h>
char c[10001];
int main()
{
    gets(c); // @@ [Using gets() is unsafe and may cause buffer overflow; however, the main logic error is elsewhere. More critically, the loop accesses c[i-1] and c[i+1] without checking bounds, leading to undefined behavior for '-' at start/end.]

    for(int i=0;i<=strlen(c)-1;i++)
    {
        if(c[i]=='-'&&c[i-1]<c[i+1]) // @@ [This condition accesses c[i-1] and c[i+1] without ensuring i>=1 and i<=strlen(c)-2, causing out-of-bounds reads when '-' is at the beginning or end of the string. Also, it doesn't verify that both surrounding characters are of the same valid type before comparing them.]
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