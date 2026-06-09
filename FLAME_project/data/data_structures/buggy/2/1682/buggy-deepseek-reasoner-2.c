#include <stdio.h>
#include <stdlib.h>

#define N 10000
int main()
{
    char s[N],fuh[N];
    int num[N];
    int i,j,k; // @@ k is uninitialized, causing undefined behavior when used to index num array.
    gets(s);
    for(j=0,i=0;i<strlen(s);i++){            //清除空格
        if(s[i]!=' ')
            s[j++]=s[i];
    }
    s[j]='\0';
    for(i=0,j=0;i<strlen(s);i++){           //记录数字
        if(s[i]>='0'&&s[i]<='9'){
            num[k]=s[i]-'0';
            while(s[i+1]>='0'&&s[i+1]<='9'){
                num[k]=num[k]*10+s[i+1]-'0';
                i++;
            }
            k++;
        }
        num[k]='\0'; // @@ Setting num[k] to '\0' (0) inside the loop may introduce unintended zero values, corrupting the number array.
    }
    for(i=0,j=0;i<strlen(s);i++){           //记录符号
        if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
            fuh[j]=s[i];
            j++;
        }
    }
    // Missing null-termination for fuh array; the next line uses strlen(fuh) which will read garbage.
    for(i=0;i<strlen(fuh);i++){                // @@ fuh is not null-terminated, so strlen(fuh) may read beyond array bounds, leading to incorrect loop iterations.
        if(fuh[i]=='*'){
            num[i+1]=num[i]*num[i+1];
            num[i]=' '; // @@ Using character constant ' ' as a sentinel in an int array is error-prone; it may interfere with actual values.
            i++; // @@ Incrementing i inside the loop causes skipping of the next operator, disrupting the intended left-to-right processing.
        }
        if(fuh[i]=='/'){
            num[i+1]=num[i]/num[i+1];
            num[i]=' '; // @@ Same sentinel issue as above.
            i++; // @@ Same issue: the loop index increment inside the block leads to missed operators.
        }
    }
    for(j=0,i=0;i<k;i++){           //清除空格 // @@ The variable k was not updated after combining numbers, so the loop may not process all valid numbers.
        if(num[i]!=' ')
            num[j++]=num[i];
    }
    num[j]='\0'; // @@ Assigning '\0' (0) to an integer array element as a sentinel is unnecessary and may remove a valid zero result.
    int an=num[0];
    for(i=0,j=0;i<strlen(fuh);i++){           //后加减
        if(fuh[i]=='+')
            an+=num[++j];
        if(fuh[i]=='-')
            an-=num[++j];
    }
    printf("%d",an);
    return 0;
}