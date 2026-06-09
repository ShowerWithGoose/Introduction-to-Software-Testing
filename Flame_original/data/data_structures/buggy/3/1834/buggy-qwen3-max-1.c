#include<stdio.h>
#include<string.h>
int main(void)
{
    
    char s[110];
    while(gets(s)!=NULL) // @@ [Use of unsafe and deprecated function 'gets' which may cause buffer overflow; also, in some environments, 'gets' is not available leading to compilation error]
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
            for(int i=0;i<strlen(s)&&s[i]!='.';i++,num++); // @@ [The loop body is empty due to misplaced semicolon; 'num' will not be incremented correctly as intended]
        
            b=num;
            if(s[num-1]=='0') // @@ [If the input starts with '0.' (e.g., "0.123"), then num=1, so s[0]=='0', but this condition checks s[num-1] which is safe; however, logic after this assumes leading zeros after decimal, but indexing may go out of bounds if string is too short]
            {
                for(int i=num+1;(i<strlen(s))&&(s[i]=='0');i++)
                {
                    a++;
                }
            
            printf("%c",s[a+2]); // @@ [Incorrect index: after decimal point starts at num+1; skipping 'a' zeros leads to first non-zero at num+1+a, not a+2. Also, if a+2 >= strlen(s), this accesses out-of-bounds memory]
                if(a+2!=strlen(s))
                {
                    printf(".");
                for(int i=a+3;i<strlen(s);i++) // @@ [Same indexing issue: should start from num+1+a+1, not a+3]
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