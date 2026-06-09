#include <stdio.h>
#include <stdlib.h>

#define N 10000
int main()
{
    char s[N],fuh[N];
    int num[N];
    int i,j,k;
    gets(s); // @@ [Using `gets` is unsafe and deprecated; it was removed in C11. This may cause compilation errors with modern compilers.]
    for(j=0,i=0;i<strlen(s);i++){            //清除空格
        if(s[i]!=' ')
            s[j++]=s[i];
    }
    s[j]='\0';
    for(i=0,j=0;i<strlen(s);i++){           //记录数字
        if(s[i]>='0'&&s[i]<='9'){
            num[k]=s[i]-'0'; // @@ [`k` is used uninitialized, leading to undefined behavior. It should be initialized to 0 before this loop.]
            while(s[i+1]>='0'&&s[i+1]<='9'){
                num[k]=num[k]*10+s[i+1]-'0';
                i++;
            }
            k++;
        }
        num[k]='\0'; // @@ [This line incorrectly writes a null terminator into the integer array `num`, which is unnecessary and corrupts data. Also, `k` may be out of sync here.]
    }
    for(i=0,j=0;i<strlen(s);i++){           //记录符号
        if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
            fuh[j]=s[i];
            j++;
        }
    }
    for(i=0;i<strlen(fuh);i++){                //先乘除
        if(fuh[i]=='*'){
            num[i+1]=num[i]*num[i+1]; // @@ [This logic is flawed: it modifies `num[i+1]` but leaves `num[i]` intact, then later tries to skip it using `' '` marker, but indices get misaligned. Also, `i++` after modifies loop index incorrectly.]
            num[i]=' ';
            i++;
        }
        if(fuh[i]=='/'){ // @@ [Same issue as above: incorrect indexing and use of `' '` in integer array. Also, after `i++` in previous block, this may access invalid `fuh[i]`.]
            num[i+1]=num[i]/num[i+1];
            num[i]=' ';
            i++;
        }
    }
    for(j=0,i=0;i<k;i++){           //清除空格
        if(num[i]!=' ')
            num[j++]=num[i];
    }
    num[j]='\0'; // @@ [Again, writing `\0` into integer array is meaningless and corrupts the last element. Should not be done.]
    int an=num[0];
    for(i=0,j=0;i<strlen(fuh);i++){           //后加减
        if(fuh[i]=='+')
            an+=num[++j]; // @@ [The index `j` starts at 0, but `++j` makes it 1 on first use, skipping `num[0]` which is already in `an`. However, due to earlier corruption and misalignment in `num`, this may access wrong or uninitialized values.]
        if(fuh[i]=='-')
            an-=num[++j]; // @@ [Same indexing issue as above; also, if there were multiplicative operations, the `fuh` array length hasn't been updated to match reduced `num` size, causing mismatch between operators and operands.]
    }
    printf("%d",an);
    return 0;
}