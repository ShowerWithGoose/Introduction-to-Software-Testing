#include <stdio.h>

int main()
{
    char c[105];
    int i,n=0,j,k;
    scanf("%s",c);
    if(c[0]=='0'&&c[1]=='.')
    {
        for(i=2;c[i]!='\0';i++)
        {
            n--;
            if(c[i]!='0')break;
        }
        printf("%c",c[i]);
        if(c[i+1]=='\0')printf("e%d",n);
        else
        {
            printf(".");i++;
            while(c[i]!='\0')
            {
                printf("%c",c[i]);
                i++;
            }
            printf("e%d",n);
        }
    }
    else
    {
            k=0;
        while(c[k+1]!='.')
            k++;
        printf("%c.",c[0]);
        i=1;
        while(c[i]!='.')
        {
            printf("%c",c[i]);
            i++;
        }
        if(c[i]!='.')printf("e%d",k);
        else
        {
            for(i=i+1;c[i]!='\0';i++)
                printf("%c",c[i]);
            printf("e%d",k);
        }
    }

    return 0;
}

