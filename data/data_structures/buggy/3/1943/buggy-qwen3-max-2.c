#include<stdio.h>
#include<string.h>
int main()
{
    char c[100];
    gets(c); // @@ [Using 'gets' is unsafe and has been removed from modern C standards; it can cause buffer overflow. Additionally, some compilers may not support 'gets', leading to compilation errors.]
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
            for(num=1,i=2;c[i]=='0';i++) // @@ [This loop assumes the input always has a decimal point at index 1 (i.e., "0.xxx"), but if the input is just "0" followed by non-decimal digits (which shouldn't happen per problem constraints), or malformed, this could access out-of-bounds memory. Also, if there's no decimal point, i starts at 2 which skips index 1 entirely—this logic is flawed.]
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