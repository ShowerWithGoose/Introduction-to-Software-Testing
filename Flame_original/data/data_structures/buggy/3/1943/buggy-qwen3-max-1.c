#include<stdio.h>
#include<string.h>
int main()
{
    char c[100];
    gets(c); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings with modern compilers.]
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
            for(num=1,i=2;c[i]=='0';i++) // @@ [If the input is "0.0...", accessing c[2] assumes there are at least 3 characters (e.g., "0.x"), but if input is "0." followed by nothing or only one digit, this leads to out-of-bounds access or incorrect logic. Also, 'num' starts at 1 but should count leading zeros after the decimal point correctly.]
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
                printf("."); 
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