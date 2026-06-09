#include<stdio.h>
#include<string.h>
int main(void)
{
    
    char s[110];
    while(gets(s)!=NULL)
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
            for(int i=0;i<strlen(s)&&s[i]!='.';i++,num++);
        
            b=num;
            if(s[num-1]=='0') // @@ [This condition checks if the last digit before '.' is '0', but it should check if the first digit (s[0]) is '0' to determine if the number is less than 1. For input "0.9", s[0]=='0', so this branch should be taken, but s[num-1] is s[0] which is '0', so it works by accident. However, logic is flawed and leads to wrong indexing later.]
            {
                for(int i=num+1;(i<strlen(s))&&(s[i]=='0');i++) // @@ [This loop counts leading zeros after the decimal point, but variable 'a' is used incorrectly later. For "0.9", there are no zeros after '.', so a=0, but then s[a+2] = s[2] = '9', which is correct, but the logic is fragile and misaligned with problem requirements.]
                {
                    a++;
                }
            
            printf("%c",s[a+2]); // @@ [For "0.9", this prints '9', which is correct, but the index a+2 assumes the format "0.00...x...", which fails when there are no leading zeros after decimal (like "0.9"). It should be s[num + 1 + a], not a+2. Also, this prints a digit without checking if more digits follow, leading to unnecessary decimal point.]
                if(a+2!=strlen(s)) // @@ [This condition checks if there are more digits after the first non-zero, but uses wrong index. For "0.9", a+2=2, strlen=3, so condition true, prints ".", but according to expected output "9e-1", no decimal point should appear when only one significant digit remains. The problem states: if base is integer (only one digit), no decimal point.]
                {
                    printf(".");
                for(int i=a+3;i<strlen(s);i++) // @@ [Wrong starting index; should start from a+num+2 or similar. For "0.9", this loop doesn't run (a+3=3, strlen=3), so only "9." is printed before exponent, causing "9.e-1" instead of "9e-1".]
                {
                    printf("%c",s[i]);
                }
                }
            printf("e-%d",a+1); // @@ [Exponent calculation is off. For "0.9", it should be -1, and a+1=1, so "e-1" is correct, but only because a=0. However, the logic doesn't generalize well. The real issue is printing an unnecessary decimal point.]
            }
            else
            {
                printf("%c.",s[0]); // @@ [When number >=1 (e.g., "123.45"), this prints "1." which is correct per spec (one digit before decimal, rest after). But for numbers like "1.0" (though input guarantees no trailing zeros), it would still print "1." which may be acceptable. However, this branch is not taken for "0.9".]
                for(int i=1;i<strlen(s);i++)
                {
                    if(s[i]!='.')
                    printf("%c",s[i]);
                }
                printf("e%d",b-1); // @@ [Correct for numbers >=1: e.g., "123.45" -> b=3, exponent=2, which is right.]

            }
        }
        else 
        {
            printf("%c.",s[0]); // @@ [For integers (no decimal point), this prints "x." but spec says: if base is integer (only one digit), no decimal point. So "5" should become "5e0", not "5.e0". This violates output format.]
                for(int i=1;i<strlen(s);i++)
                {
                    printf("%c",s[i]);
                }
                printf("e%d",strlen(s)-1);
        }
    }
    return 0;
}