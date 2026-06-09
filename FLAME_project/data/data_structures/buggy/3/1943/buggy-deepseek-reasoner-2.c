#include<stdio.h>
#include<string.h>
int main()
{
    char c[100];
    gets(c);
    int num=0,flag=0,i=0,judge=0;
    if(strlen(c)==1)
    {
        printf("%c",c[0]);
        printf("e0");
    }
    else
    {
        if(c[0]=='0')
        {
            for(num=1,i=2;c[i]=='0';i++)
                num++;
            while(c[i]!='\0')
            {
                if(judge==1)
                    printf(".");
                judge++;
                printf("%c",c[i]);    
                i++;
            }
            printf("e-%d",num);
        }
        else
        {
            while(c[i]!='.'&&c[i]!='\0')
            {
                if(judge==1)
                    printf(".");
                judge++;
                printf("%c",c[i]);
                i++;
            }
            if(c[i]=='\0')
            {
                printf("e%d",judge-1);
            }
            else
            {
                printf("."); // @@ This prints an extra dot when there are multiple integer digits. Should be conditional: if(judge==1) printf(".");
                for(i++;c[i]!='\0';i++)
                {
                    printf("%c",c[i]);
                }
                printf("e%d",judge-1);
            }
        }
    }
        

    return 0;
}