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
    for(i=0;i<=j;i++)
    {
        if(c[i]!='-')
        {
            printf("%c",c[i]);
        }
        else
        {
            if(c[i-1]>='a'&&c[i-1]<='z'&&c[i+1]>='a'&&c[i+1]<='z'&&c[i+1]>c[i-1])
            {
                for(n=1;n<c[i+1]-c[i-1];n++)
                {
                    printf("%c",c[i-1]+n);
                }
            }
            else if(c[i-1]>='A'&&c[i-1]<='Z'&&c[i+1]>='A'&&c[i+1]<='Z'&&c[i+1]>c[i-1])
            {
                for(n=1;n<c[i+1]-c[i-1];n++)
                {
                    printf("%c",c[i-1]+n);
                }
            }
            else if(c[i-1]>='0'&&c[i-1]<='26'&&c[i+1]>='0'&&c[i+1]<='26'&&c[i+1]>c[i-1]) // @@ [The condition checks if characters are between '0' and '26', but '26' is not a valid character; it should be '9' to represent digit characters correctly.]
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