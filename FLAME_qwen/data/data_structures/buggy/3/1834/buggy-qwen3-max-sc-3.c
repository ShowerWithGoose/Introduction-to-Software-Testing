#include<stdio.h>
#include<string.h>
int main(void)
{
    
    char s[110];
    while(gets(s)!=NULL) // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings in modern compilers.]
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
            for(int i=0;i<strlen(s)&&s[i]!='.';i++,num++); // @@ [The loop body is empty due to a misplaced semicolon, causing 'num' to be incremented but not used correctly to capture the position of the decimal point. This leads to incorrect logic downstream.]
        
            b=num;
            if(s[num-1]=='0') // @@ [If the input starts with '0.', then num==1, so s[num-1] is '0', which is valid. However, if the number has more than one digit before '.', this condition may incorrectly trigger for numbers like '10.5', where s[num-1] is '0' but it's not a leading zero case. Also, if num==0 (shouldn't happen per problem, but still), this would access s[-1].]
            {
                for(int i=num+1;(i<strlen(s))&&(s[i]=='0');i++)
                {
                    a++;
                }
            
            printf("%c",s[a+2]); // @@ [This assumes that after skipping 'a' zeros, the next digit is at index a+2, which is only true if the string starts with "0.". But if the input is like "0.00123", then num=1, so num+1=2 is the first digit after '.', and after skipping 'a' zeros, the first non-zero is at index 2+a. So it should be s[num+1+a], not s[a+2]. Also, if a+2 >= strlen(s), this accesses out-of-bounds memory.]
                if(a+2!=strlen(s)) // @@ [Same issue: comparing a+2 with strlen(s) is incorrect; should compare num+1+a+1 or similar.]
                {
                    printf(".");
                for(int i=a+3;i<strlen(s);i++) // @@ [Again, indexing is wrong. Should start from num+1+a+1, not a+3.]
                {
                    printf("%c",s[i]);
                }
                }
            printf("e-%d",a+1); // @@ [Exponent calculation is incorrect. For "0.001", we have two leading zeros after '.', so exponent should be -3, but a=2, so a+1=3 → e-3 is correct. However, the indexing errors above may cause wrong 'a' or wrong digit selection, making this unreliable. Also, if there are no trailing digits after the first non-zero, this may print incomplete base.]
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