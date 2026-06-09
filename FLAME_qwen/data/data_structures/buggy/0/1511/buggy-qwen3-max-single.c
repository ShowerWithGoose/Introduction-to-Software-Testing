#include<stdio.h>
#include<string.h>
char c[10001];
int main()
{
    gets(c); // @@ [Using 'gets' is unsafe and deprecated; may cause compilation error with modern compilers due to removal of 'gets' from standard library]

    for(int i=0;i<=strlen(c)-1;i++)
    {
        if(c[i]=='-'&&c[i-1]<c[i+1]) // @@ [Accessing c[i-1] when i=0 leads to out-of-bounds read (undefined behavior); also, condition order risks reading invalid memory before checking character types]
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