#include <stdio.h>
#include <stdlib.h>

#define N 10000
int main()
{
    char s[N],fuh[N];
    int num[N];
    int i,j,k;
    gets(s); // @@ [Using gets() is unsafe and may cause compilation errors or warnings in modern compilers; it was removed in C11. Use fgets instead.]
    for(j=0,i=0;i<strlen(s);i++){            //清除空格
        if(s[i]!=' ')
            s[j++]=s[i];
    }
    s[j]='\0';
    for(i=0,j=0;i<strlen(s);i++){           //记录数字
        if(s[i]>='0'&&s[i]<='9'){
            num[k]=s[i]-'0'; // @@ [Variable 'k' is used uninitialized, leading to undefined behavior. It should be initialized to 0 before use.]
            while(s[i+1]>='0'&&s[i+1]<='9'){
                num[k]=num[k]*10+s[i+1]-'0';
                i++;
            }
            k++;
        }
        num[k]='\0'; // @@ [This line incorrectly writes a null terminator into the integer array 'num', which is unnecessary and corrupts data. Also, 'k' may be out of sync here.]
    }
    for(i=0,j=0;i<strlen(s);i++){           //记录符号
        if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
            fuh[j]=s[i];
            j++;
        }
    }
    for(i=0;i<strlen(fuh);i++){                //先乘除
        if(fuh[i]=='*'){
            num[i+1]=num[i]*num[i+1]; // @@ [Incorrectly accesses num[i] and num[i+1] without accounting for previously processed operations; logic fails because 'num' indices don't align with remaining operators after prior reductions.]
            num[i]=' '; // @@ [Storing a space character (ASCII 32) into an integer array is meaningless and corrupts numeric data. Should mark for deletion differently or use a proper reduction strategy.]
            i++;
        }
        if(fuh[i]=='/'){
            num[i+1]=num[i]/num[i+1]; // @@ [Same issue as multiplication: incorrect indexing and data corruption due to storing ' ' in integer array.]
            num[i]=' ';
            i++;
        }
    }
    for(j=0,i=0;i<k;i++){           //清除空格
        if(num[i]!=' ') // @@ [Comparing integer array elements to space character ' ' is invalid; this condition will almost always be true since numbers are not ASCII spaces, but the earlier assignment of ' ' makes this unpredictable.]
            num[j++]=num[i];
    }
    num[j]='\0'; // @@ [Again, writing '\0' into integer array is incorrect and unnecessary.]
    int an=num[0];
    for(i=0,j=0;i<strlen(fuh);i++){           //后加减
        if(fuh[i]=='+')
            an+=num[++j]; // @@ [Index 'j' may go out of bounds because the number of operators (strlen(fuh)) may not match the reduced count of numbers after multiplication/division cleanup.]
        if(fuh[i]=='-')
            an-=num[++j]; // @@ [Same as above: potential out-of-bounds access due to mismatch between operator count and available operands.]
    }
    printf("%d",an);
    return 0;
}