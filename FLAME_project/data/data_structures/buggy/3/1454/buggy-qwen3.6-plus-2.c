#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>


int main()
{
    char s[200]={0},tmp;
    gets(s);
    int i,num=-1,sum=0,flag=1,j;
    for(i=0;s[i];i++){
        if(s[i]=='.'){
            if(sum==1&&s[i-1]!=0){ // @@ [Logic error: The condition `s[i-1]!=0` checks if the character code is non-zero (always true for digits), not if the digit is non-zero. Also, this branch handles numbers like "5.0" incorrectly as it prints the whole string including the dot if not handled, but specifically for 0.9, sum is 1. However, the main issue is the else branch logic below.]
                printf("%se0",s);
                break;
            }else if(sum>1){
                for(j=0;s[j];j++){
                    if(j==1){
                        printf(".%c",s[j]);
                    }else if(s[j]=='.'){
                        continue;
                    }else{
                        printf("%c",s[j]);
                    }
                }
                printf("e%d",num);
            }else {
                for(j=i;s[i];j++){ // @@ [Logical error: The loop condition `s[i]` depends on `i`, which is not incremented inside this inner loop, potentially causing an infinite loop or incorrect termination. It should likely be `s[j]`. Furthermore, the logic inside fails to correctly strip leading zeros after the decimal point for scientific notation conversion of small numbers like 0.9.]
                    if(s[j+1]!='0'&&s[j+2]!=NULL){
                            printf("%c.%se-%d",s[j+1],&s[j+2],flag); // @@ [Format error: `%s` expects a string, but `&s[j+2]` might include trailing garbage or newlines if not null-terminated properly in context, and more importantly, the problem requires no trailing zeros. This simple slice doesn't guarantee significant digits only. Also, for input "0.9", j starts at 1 (index of '.'), s[j+1] is '9'. s[j+2] is '\0'. The condition `s[j+2]!=NULL` (which is 0) fails because s[j+2] IS NULL/0. So it goes to else if.]
                            break;
                    }else if(s[j+1]!='0'){
                            printf("%ce-%d",s[j+1],flag); // @@ [For input "0.9": i=1. j=1. s[j+1] is s[2]='9'. s[j+2] is s[3]='\0'. The first if fails because s[j+2] is NULL. This else-if checks s[j+1]!='0' ('9'!='0' is true). It prints "9e-1". This specific line actually produces the correct output for this specific case, BUT the loop condition `s[i]` is dangerous. However, looking closely at the provided buggy output "0.9e0", it seems the code entered the FIRST if block `if(sum==1&&s[i-1]!=0)`. Let's re-evaluate. Input "0.9". i=0, s[0]='0', sum=0, num=-1. i=1, s[1]='.', sum=1, num=0. Condition `sum==1` is true. `s[i-1]` is s[0]='0'. `'0' != 0` is TRUE (ASCII 48 != 0). So it enters the first block. It prints `printf("%se0", s)` which outputs "0.9e0". This is the error.]
                            break;
                        }
                    flag++;
                }
                break;
            }
        }
        sum++;
        num++;
    }

    return 0;
}