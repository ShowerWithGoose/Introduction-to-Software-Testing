#include <stdio.h>
#include <stdlib.h>

#define N 10000
int main()
{
    char s[N],fuh[N];
    int num[N];
    int i,j,k;
    gets(s); // @@ [Using `gets` is unsafe and deprecated; may cause compilation error in modern compilers due to removal from standard library]
    for(j=0,i=0;i<strlen(s);i++){            //清除空格
        if(s[i]!=' ')
            s[j++]=s[i];
    }
    s[j]='\0';
    for(i=0,j=0;i<strlen(s);i++){           //记录数字
        if(s[i]>='0'&&s[i]<='9'){
            num[k]=s[i]-'0'; // @@ [`k` is used uninitialized; leads to undefined behavior and incorrect number parsing]
            while(s[i+1]>='0'&&s[i+1]<='9'){
                num[k]=num[k]*10+s[i+1]-'0';
                i++;
            }
            k++;
        }
        num[k]='\0'; // @@ [Incorrectly setting an integer array element to '\0' (0), which corrupts numeric data]
    }
    for(i=0,j=0;i<strlen(s);i++){           //记录符号
        if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
            fuh[j]=s[i];
            j++;
        }
    }
    for(i=0;i<strlen(fuh);i++){                //先乘除
        if(fuh[i]=='*'){
            num[i+1]=num[i]*num[i+1]; // @@ [Does not properly collapse the array after operation; leaves stale values and misaligns operands]
            num[i]=' '; // @@ [Storing character ' ' (32) into integer array; should use a marker like -1 or handle via index shifting]
            i++;
        }
        if(fuh[i]=='/'){
            num[i+1]=num[i]/num[i+1]; // @@ [Same issue: no array compaction, leading to wrong operand alignment in subsequent operations]
            num[i]=' '; // @@ [Same as above: storing space character in integer array is logically wrong]
            i++;
        }
    }
    for(j=0,i=0;i<k;i++){           //清除空格
        if(num[i]!=' ') // @@ [Comparing integer array elements to ' ' (32); but earlier assignment was `num[i] = ' '` which is 32, so this works numerically but is conceptually flawed and fragile]
            num[j++]=num[i];
    }
    num[j]='\0'; // @@ [Again, setting integer array to '\0'; unnecessary and misleading]
    int an=num[0];
    for(i=0,j=0;i<strlen(fuh);i++){           //后加减
        if(fuh[i]=='+')
            an+=num[++j]; // @@ [Index `j` starts at 0, then pre-incremented; skips num[0] correctly, but logic assumes all operators correspond directly to remaining numbers after filtering, which may not hold due to prior flawed compaction]
        if(fuh[i]=='-')
            an-=num[++j]; // @@ [Same indexing issue; also, if multiplication/division steps didn't properly reduce operator count, `fuh` length doesn't match remaining numbers]
    }
    printf("%d",an);
    return 0;
}