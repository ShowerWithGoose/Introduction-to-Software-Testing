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
            for(int i=0;i<strlen(s)&&s[i]!='.';i++,num++); // @@ [This loop does nothing useful because it ends with a semicolon; the variable 'num' counts digits before '.', but the loop body is empty due to the misplaced semicolon.]
        
            b=num;
            if(s[num-1]=='0') // @@ [If the input starts with multiple zeros like "00.123", num could be 2, but s[1] might not be '0'; also, if the number is "0.123", then num=1 and s[0]=='0', so s[num-1] is safe, but logic assumes leading zero only when first digit is zero, which may not hold for invalid inputs—but problem states valid input. However, more critically: this branch assumes that if the last digit before '.' is '0', then we are in the case like "0.00...", but actually the condition should check if the first digit is '0', not the last before dot. This leads to incorrect handling of numbers like "10.5" where s[num-1] is '0' but it's not a leading-zero case.]
            {
                for(int i=num+1;(i<strlen(s))&&(s[i]=='0');i++)
                {
                    a++;
                }
            
            printf("%c",s[a+2]); // @@ [If input is "0.00123", then num=1 (since one digit before '.'), so num+1 = 2; then a counts zeros after '.', so a=2 for "0.00123". Then s[a+2] = s[4], which is '1' — correct. But if input is "0.0", this would access out-of-bound memory. Also, if there are no non-zero digits after zeros (e.g., "0.000"), undefined behavior occurs. Moreover, the index a+2 assumes at least a+3 characters exist, which may not be true. Additionally, if the number is like "0.1", then a=0, so s[2] is accessed — but "0.1" has length 3, so s[2] is '1' — okay. However, the logic fails for cases where the first non-zero after decimal is at position num+1+a, which is correct, but printing s[a+2] is only valid if the string starts with "0." — which it does in this branch — so index = 2 + a. So s[2+a] is correct. BUT: what if the input is "00.1"? Problem states: "If there’s only one digit before the decimal point, it can be 0; otherwise, the first digit before the decimal point cannot be 0." So "00.1" is invalid input, so we assume it won't occur. Still, the bigger issue is the condition `if(s[num-1]=='0')` is wrong: it should be `if(num == 1 && s[0] == '0')` to detect numbers less than 1.]
                if(a+2!=strlen(s))
                {
                    printf(".");
                for(int i=a+3;i<strlen(s);i++)
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