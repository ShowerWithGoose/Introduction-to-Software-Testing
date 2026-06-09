#include<stdio.h>
int main()
{
    int i,n;
    int j=0;
    char ch;
    char c[256]={0};
    while((ch=getchar())!='\n')
    {
        c[j]=ch;
        j++;
    }
    c[j]='\0';
    for(i=0;i<=j;i++) // @@ the loop should be i<j to avoid printing the null terminator; also if j=0, accessing c[0] is fine but later i=j accesses c[j]='\0' which is not a '-', but the condition i<=j may cause out-of-bounds when i=j and the character is '-' (if input ends with '-') because then c[i+1] would be out of bounds.
    {
        if(c[i]!='-')
        {
            printf("%c",c[i]);
        }
        else
        {
            if(c[i-1]>='a'&&c[i-1]<='z'&&c[i+1]>='a'&&c[i+1]<='z'&&c[i+1]>c[i-1]) // @@ possible out-of-bounds access when i=0 (c[-1]) or when i is the last index of input (c[i+1] may be uninitialized or out of bounds). For this input it may not happen, but it's a potential crash.
            {
                for(n=1;n<c[i+1]-c[i-1];n++)
                {
                    printf("%c",c[i-1]+n);
                }
            }
            else if(c[i-1]>='A'&&c[i-1]<='Z'&&c[i+1]>='A'&&c[i+1]<='Z'&&c[i+1]>c[i-1]) // @@ same out-of-bounds issue as above.
            {
                for(n=1;n<c[i+1]-c[i-1];n++)
                {
                    printf("%c",c[i-1]+n);
                }
            }
            else if(c[i-1]>='0'&&c[i-1]<='26'&&c[i+1]>='0'&&c[i+1]<='26'&&c[i+1]>c[i-1]) // @@ error: '26' is a multicharacter constant, should be '9' to check digit range. Also out-of-bounds issue.
            {
                for(n=1;n<c[i+1]-c[i-1];n++)
                {
                    printf("%c",c[i-1]+n);
                }
            }
            else
            {
                printf("%c",c[i]);
            }
        }
    }
    return 0;
}