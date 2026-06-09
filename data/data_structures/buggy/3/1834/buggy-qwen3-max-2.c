#include<stdio.h>
#include<string.h>
int main(void)
{
    
    char s[110];
    while(gets(s)!=NULL) // @@ [Using gets() is unsafe and deprecated; it was removed in C11, causing compilation errors with modern compilers]
    {
        int num=0,isok=0;
        int a=0,b=0;
        for(int i=0;i<strlen(s);i++)
        {
            if(s[i]=='.')
            {
            isok=1;
            }
        }
        if(isok)
        {
            for(int i=0;i<strlen(s)&&s[i]!='.';i++,num++); // @@ [The loop body is empty due to misplaced semicolon; 'num' won't be updated correctly]
        
            b=num;
            if(s[num-1]=='0') // @@ [If the input starts with non-zero digit before '.', this condition may access invalid index or misinterpret leading zeros]
            {
                for(int i=num+1;(i<strlen(s))&&(s[i]=='0');i++)
                {
                    a++;
                }
            
            printf("%c",s[a+2]); // @@ [Incorrect index: after decimal point, first non-zero digit is at 'num + 1 + a', not 'a+2']
                if(a+2!=strlen(s))
                {
                    printf(".");
                for(int i=a+3;i<strlen(s);i++) // @@ [Indexing error: should start from 'num + 1 + a + 1', not 'a+3']
                {
                    printf("%c",s[i]);
                }
                }
            printf("e-%d",a+1);
            }
            else
            {
                printf("%c.",s[0]);
                for(int i=1;i<strlen(s);i++)
                {
                    if(s[i]!='.')
                    printf("%c",s[i]);
                }
                printf("e%d",b-1);

            }
        }
        else 
        {
            printf("%c.",s[0]);
                for(int i=1;i<strlen(s);i++)
                {
                    printf("%c",s[i]);
                }
                printf("e%d",strlen(s)-1);
        }
    }
    return 0;
}