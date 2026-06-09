#include<stdio.h>
#include<string.h>
int main()
{
    char num[10000]={};
    int i,j=0,sign=0,sign2=0;
    int front=0,back=0,count=0;
    scanf("%s",num);
    int len=strlen(num);
    
    for(i=0;num[i]!='\0';i++)
    {
        if(sign==0)
        {
            if(num[i]!='.')        
            front++;

        
            else
            sign=1;
        }        
     }
     
    if(front==1&&num[0]=='0')
    {
        if(sign2==0)
        for(i=2;num[i]!='\0';i++)
        {
            if(num[i]=='0')
            back++;
            else
            sign2=1;
        }
    }
    
    
    if(back>0)
    {
        count=0-back-1; @@ [Incorrect exponent calculation: should be -(back+1), but logic fails to handle cases where non-zero digit appears after zeros correctly. Also, 'back' counts leading zeros after "0.", so exponent should be -(back+1), but expression 0-back-1 is equivalent; however, the bigger issue is that 'back' is only computed when front==1 and num[0]=='0', but sign2 logic doesn't break early, so 'back' may overcount if there are zeros after non-zero digits.]
        if(len==back+3)
        printf("%c",num[back+2]);
        
        else
        {
            printf("%c.",num[back+2]);
            for(i=back+3;i<len;i++)
            printf("%c",num[i]);
        }
    }
    else
    {
        count=front-1;
        if(len==1)
        printf("%c",num[0]);
        
        else
        {
            printf("%c.",num[0]);
        
            for(i=1;i<len;i++)
            {
                if(num[i]!='.')
                printf("%c",num[i]); @@ [This prints all non-decimal characters after the first digit, including digits before the decimal point beyond the first, which violates scientific notation format. For example, input "123.45" would print "1.2345", but the loop includes '2','3' from before the decimal and '4','5' after, which is correct in this case, BUT if input has more than one digit before '.', e.g., "12.3", front=2, then it prints "1.23", which is correct. However, the real error is that this branch assumes there is a decimal point somewhere, but if input has no decimal point (which shouldn't happen per problem, but code doesn't ensure it), behavior is undefined. More critically, the condition for entering this else branch is "if(back>0)" being false, which includes cases like "0.1" where back==0 but front==1 and num[0]=='0' — but in that case, the first if (front==1 && num[0]=='0') runs, but if the number is "0.1", then back=0 (since first digit after '.' is '1', not '0'), so sign2 becomes 1 immediately, back remains 0, so it goes to else branch and treats it as a normal number with front=1, printing "0."... which is wrong because base must have non-zero digit before decimal. So the core error is misclassification of numbers starting with "0." where the first non-zero digit is immediately after decimal — they should go into the 'back>0' logic only if there are leading zeros, but if back==0 (i.e., "0.1"), then it incorrectly falls into the else branch and outputs "0.1e0", which violates the rule that base must have non-zero digit before decimal.]
            }
        }
    }
    printf("e%d",count); @@ [Exponent sign handling is incorrect for negative exponents: per problem, negative exponents must be printed with '-', but positive ones without '+'. This line prints "e%d", which for negative count prints "e-...", which is correct, and for positive prints "e...", which is also correct. So this line is actually okay. The real issue is incorrect count value due to flawed logic above.]
      
    return 0;
}