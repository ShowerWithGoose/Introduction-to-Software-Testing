#include<stdio.h>
#include<string.h>
char c[10001];
int main()
{
    gets(c); // @@ [Use of unsafe function 'gets' which has been removed from C standard; causes compilation error in modern compilers]

    for(int i=0;i<=strlen(c)-1;i++)
    {
        if(c[i]=='-'&&c[i-1]<c[i+1])
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