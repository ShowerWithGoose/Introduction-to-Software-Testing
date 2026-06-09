#include<stdio.h>
#include<string.h>
int main(void)
{
    
    char s[110];
    while(gets(s)!=NULL) // @@ [Using 'gets' is unsafe and deprecated; it was removed in C11, causing compilation errors with modern compilers.]
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
            for(int i=0;i<strlen(s)&&s[i]!='.';i++,num++); // @@ [The loop body is empty due to misplaced semicolon; 'num' counts digits before '.', but logic is flawed because 'num' ends up being the count, yet used as index later incorrectly.]
        
            b=num;
            if(s[num-1]=='0') // @@ [If input has more than one digit before '.', and last digit before '.' is '0', this condition triggers incorrectly; also, if num==0 (e.g., ".123"), s[-1] is accessed → undefined behavior.]
            {
                for(int i=num+1;(i<strlen(s))&&(s[i]=='0');i++)
                {
                    a++;
                }
            
            printf("%c",s[a+2]); // @@ [Incorrect index: after decimal point starts at num+1; skipping 'a' zeros leads to s[num+1+a], not s[a+2]. Also, if all fractional digits are zero, this accesses beyond string or wrong position.]
                if(a+2!=strlen(s))
                {
                    printf(".");
                for(int i=a+3;i<strlen(s);i++) // @@ [Indexing error: should start from num+1+a+1 = num+a+2, not a+3. This causes wrong digits to be printed or out-of-bounds access.]
                {
                    printf("%c",s[i]);
                }
                }
            printf("e-%d",a+1); // @@ [Exponent calculation is incorrect. For "0.00123", exponent should be -3, but this prints e-1 if a=0, etc. Correct exponent is -(number of leading zeros after decimal + 1).]
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