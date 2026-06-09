#include<stdio.h>
#include<string.h>
int main(void)
{
    
    char s[110];
    while(gets(s)!=NULL) // @@ [Use of unsafe and deprecated function 'gets' which may cause buffer overflow and is removed in C11; also, the problem states input ends with a newline, so using fgets would be safer and standard-compliant]
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
            for(int i=0;i<strlen(s)&&s[i]!='.';i++,num++); // @@ [The loop body is empty due to misplaced semicolon; 'num' counts digits before '.', but the increment happens after condition check, leading to off-by-one error: 'num' becomes the index of '.', not the count of digits before it]
        
            b=num;
            if(s[num-1]=='0') // @@ [This condition assumes the last digit before '.' is '0', but according to problem, if there's more than one digit before '.', the first cannot be '0'; however, this logic incorrectly triggers for numbers like "10.5", treating them as if they start with zero]
            {
                for(int i=num+1;(i<strlen(s))&&(s[i]=='0');i++)
                {
                    a++;
                }
            
            printf("%c",s[a+2]); // @@ [Incorrect indexing: after decimal point starts at num+1; skipping 'a' zeros leads to first non-zero at num+1+a, so index should be num+1+a, not a+2. This fails when num != 1 (e.g., "100.005" -> num=3, a=2, then s[4] is correct, but a+2=4 only by coincidence; for "123.005", num=3, a=2, a+2=4, but correct index is 3+1+2=6)]
                if(a+2!=strlen(s)) // @@ [Same incorrect index used in length comparison; should compare actual position of next digit]
                {
                    printf(".");
                for(int i=a+3;i<strlen(s);i++) // @@ [Incorrect starting index for fractional part; should start from num+1+a+1]
                {
                    printf("%c",s[i]);
                }
                }
            printf("e-%d",a+1); // @@ [Exponent calculation is wrong; for "0.005", exponent should be -3, but here a=2 → e-3 (correct by accident), but for "0.05", a=1 → e-2 (correct). However, this branch is entered only if s[num-1]=='0', which for "0.05", num=1, s[0]=='0' → OK, but for "10.05", num=2, s[1]=='0' → enters this branch incorrectly, leading to wrong output]
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