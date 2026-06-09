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
        count=0-back-1; @@ [Incorrect exponent calculation: should be -(back+1), but logic fails to handle cases where non-zero digit appears after zeros correctly. Also, 'back' counts leading zeros after "0.", so exponent should be -(back+1), but expression 0-back-1 is equivalent; however, the real issue is that this block only executes if back>0, but sign2 may remain 0 if all digits after decimal are zero, violating problem constraints. More critically, the program does not ensure that the mantissa has exactly one non-zero digit before decimal and proper significant digits after.]
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
                printf("%c",num[i]); @@ [This prints all non-decimal digits after the first, but if the input has more than one digit before the decimal (e.g., "123.45"), it will print "1.2345", which is correct, but if the input is like "10.0", it would print "1.00", which violates the "no trailing zeros" rule. However, per problem statement, input has no trailing zeros, so this might be acceptable. The bigger issue is in the 'back>0' branch logic.]
            }
        }
    }
    printf("e%d",count); @@ [Exponent sign is always printed without '+' for positive, which is correct, but when count is negative (as in back>0 case), it prints e-... which is correct format. However, the value of 'count' in the back>0 case is computed as negative, so e%d will print e-..., which is okay. But the main logical flaw is that the condition 'if(back>0)' does not account for the fact that if the number is like "0.001", then back=2, sign2=1, and it enters this block. However, if the number is "0.1", then back=0, so it goes to else block, which assumes front>1 or non-zero first digit — but front==1 and num[0]=='0', so else block prints "0." followed by "1", resulting in "0.1e0", which is invalid because scientific notation requires the base to have a non-zero digit before the decimal. This is the critical error: when input is "0.1", front=1, num[0]=='0', back=0 (since first digit after '.' is '1', not '0'), so sign2 becomes 1 but back remains 0, so it skips the first if(back>0) block and goes to else, printing "0.1e0", which violates the requirement that the base must have a non-zero digit before the decimal point.]
      
    return 0;
}