#include <stdio.h>
#include <stdlib.h>

#define N 10000
int main()
{
    char s[N],fuh[N];
    int num[N];
    int i,j,k;
    gets(s); // @@ [Using gets() is unsafe and may cause compilation error in modern compilers as it was removed in C11; also k is uninitialized]
    for(j=0,i=0;i<strlen(s);i++){            //清除空格
        if(s[i]!=' ')
            s[j++]=s[i];
    }
    s[j]='\0';
    for(i=0,j=0;i<strlen(s);i++){           //记录数字
        if(s[i]>='0'&&s[i]<='9'){
            num[k]=s[i]-'0'; // @@ [k is used uninitialized, leading to undefined behavior; should initialize k=0 before this loop]
            while(s[i+1]>='0'&&s[i+1]<='9'){
                num[k]=num[k]*10+s[i+1]-'0';
                i++;
            }
            k++;
        }
        num[k]='\0'; // @@ [This line is misplaced; it overwrites the next number slot with '\0' (0), corrupting data; should be removed]
    }
    for(i=0,j=0;i<strlen(s);i++){           //记录符号
        if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
            fuh[j]=s[i];
            j++;
        }
    }
    for(i=0;i<strlen(fuh);i++){                //先乘除
        if(fuh[i]=='*'){
            num[i+1]=num[i]*num[i+1]; // @@ [Incorrectly uses current index; should process from left to right and collapse array properly]
            num[i]=' '; // @@ [Storing space character in integer array is invalid; should mark for deletion differently or shift array]
            i++;
        }
        if(fuh[i]=='/'){
            num[i+1]=num[i]/num[i+1]; // @@ [Same issue as multiplication: incorrect indexing and array management]
            num[i]=' '; // @@ [Same issue: storing char in int array]
            i++;
        }
    }
    for(j=0,i=0;i<k;i++){           //清除空格
        if(num[i]!=' ') // @@ [Comparing int to space character is logically wrong; ' ' is 32, but deleted entries were set to 32, which may conflict with actual number 32]
            num[j++]=num[i];
    }
    num[j]='\0'; // @@ [Unnecessary and potentially harmful; integer arrays don't need null termination like strings]
    int an=num[0];
    for(i=0,j=0;i<strlen(fuh);i++){           //后加减
        if(fuh[i]=='+')
            an+=num[++j]; // @@ [Indexing mismatch: j starts at 0, but ++j skips num[0]; should use j++ after using num[j]]
        if(fuh[i]=='-')
            an-=num[++j]; // @@ [Same indexing error as above]
    }
    printf("%d",an);
    return 0;
}