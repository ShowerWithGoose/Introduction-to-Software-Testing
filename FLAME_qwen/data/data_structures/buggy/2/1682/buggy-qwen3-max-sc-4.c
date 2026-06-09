#include <stdio.h>
#include <stdlib.h>

#define N 10000
int main()
{
    char s[N],fuh[N];
    int num[N];
    int i,j,k;
    gets(s); // @@ [Using `gets` is unsafe and deprecated; it may cause buffer overflow. However, the immediate error is that `k` is uninitialized before use in the next loop.]
    for(j=0,i=0;i<strlen(s);i++){            //清除空格
        if(s[i]!=' ')
            s[j++]=s[i];
    }
    s[j]='\0';
    for(i=0,j=0;i<strlen(s);i++){           //记录数字
        if(s[i]>='0'&&s[i]<='9'){
            num[k]=s[i]-'0'; // @@ [`k` is used uninitialized here. It should be initialized to 0 before this loop.]
            while(s[i+1]>='0'&&s[i+1]<='9'){
                num[k]=num[k]*10+s[i+1]-'0';
                i++;
            }
            k++;
        }
        num[k]='\0'; // @@ [This line is misplaced: it overwrites the next number slot with '\0' (which is 0) after every digit group, corrupting the number array. Also, `k` may be out of sync.]
    }
    for(i=0,j=0;i<strlen(s);i++){           //记录符号
        if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
            fuh[j]=s[i];
            j++;
        }
    }
    fuh[j]='\0'; // @@ [Missing null-termination for `fuh`, which causes `strlen(fuh)` to read garbage later.]
    for(i=0;i<strlen(fuh);i++){                //先乘除
        if(fuh[i]=='*'){
            num[i+1]=num[i]*num[i+1]; // @@ [Incorrect indexing: after removing spaces, the `num` array and `fuh` array are not aligned by original positions. Also, `num[i]` might have been marked as ' ' (space character = 32), not a valid number.]
            num[i]=' '; // @@ [Storing space character (ASCII 32) in integer array to mark deletion is logically wrong and causes issues in later arithmetic. Should use a different method like shifting elements.]
            i++;
        }
        if(fuh[i]=='/'){
            num[i+1]=num[i]/num[i+1]; // @@ [Same indexing and logic errors as above; also, if `num[i]` is ' ' (32), division uses wrong value.]
            num[i]=' ';
            i++;
        }
    }
    for(j=0,i=0;i<k;i++){           //清除空格
        if(num[i]!=' ')
            num[j++]=num[i];
    }
    num[j]='\0';
    int an=num[0];
    for(i=0,j=0;i<strlen(fuh);i++){           //后加减
        if(fuh[i]=='+')
            an+=num[++j]; // @@ [Indexing mismatch: `j` starts at 0, but `++j` skips `num[0]` and uses `num[1]` for first operator, which may be correct only if there's one number before first op. However, due to earlier corruption in `num` and lack of synchronization between `fuh` and `num` after multiplication/division pass, this is unreliable.]
        if(fuh[i]=='-')
            an-=num[++j]; // @@ [Same indexing issue as above.]
    }
    printf("%d",an);
    return 0;
}