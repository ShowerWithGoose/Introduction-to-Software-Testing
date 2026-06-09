#include <stdio.h>
#include <stdlib.h>

#define N 10000
int main()
{
    char s[N],fuh[N];
    int num[N];
    int i,j,k;
    gets(s); // @@ [Using `gets` is unsafe and deprecated; it was removed in C11 and causes compilation errors with modern compilers. Use `fgets` instead.]
    for(j=0,i=0;i<strlen(s);i++){            //清除空格
        if(s[i]!=' ')
            s[j++]=s[i];
    }
    s[j]='\0';
    for(i=0,j=0;i<strlen(s);i++){           //记录数字
        if(s[i]>='0'&&s[i]<='9'){
            num[k]=s[i]-'0'; // @@ [`k` is used uninitialized, leading to undefined behavior. It should be initialized to 0 before use.]
            while(s[i+1]>='0'&&s[i+1]<='9'){
                num[k]=num[k]*10+s[i+1]-'0';
                i++;
            }
            k++;
        }
        num[k]='\0'; // @@ [This line writes a null terminator into an integer array, which is logically incorrect and unnecessary. Also, `k` may be out of sync here.]
    }
    for(i=0,j=0;i<strlen(s);i++){           //记录符号
        if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
            fuh[j]=s[i];
            j++;
        }
    }
    for(i=0;i<strlen(fuh);i++){                //先乘除
        if(fuh[i]=='*'){
            num[i+1]=num[i]*num[i+1]; // @@ [Incorrect operand order: should be `num[i] = num[i] * num[i+1]`, but logic fails because `num[i]` might have been marked as ' ' or skipped. Also, using character ' ' as placeholder in int array is invalid.]
            num[i]=' '; // @@ [Storing character ' ' (ASCII 32) into int array as marker is semantically wrong and breaks arithmetic. Should use a different approach like shifting arrays.]
            i++;
        }
        if(fuh[i]=='/'){
            num[i+1]=num[i]/num[i+1]; // @@ [Same issue as multiplication: wrong assignment target and uses invalid placeholder.]
            num[i]=' '; // @@ [Same invalid use of character literal in integer array.]
            i++;
        }
    }
    for(j=0,i=0;i<k;i++){           //清除空格
        if(num[i]!=' ') // @@ [Comparing int array elements to character ' ' is incorrect; the placeholder value 32 may accidentally match valid numbers like 32.]
            num[j++]=num[i];
    }
    num[j]='\0'; // @@ [Again, placing null terminator in integer array is meaningless and corrupts data.]
    int an=num[0];
    for(i=0,j=0;i<strlen(fuh);i++){           //后加减
        if(fuh[i]=='+')
            an+=num[++j]; // @@ [Index `j` starts at 0 but pre-incremented, so first operand after initial is `num[1]`, which may be wrong if multiplication/division reduced the number count incorrectly.]
        if(fuh[i]=='-')
            an-=num[++j]; // @@ [Same indexing issue as above; also, the symbol array `fuh` wasn't updated after removing * and / operations, so its length doesn't match remaining numbers.]
    }
    printf("%d",an);
    return 0;
}