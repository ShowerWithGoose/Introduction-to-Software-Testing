#include <stdio.h>
#include <stdlib.h>

#define N 10000
int main()
{
    char s[N],fuh[N];
    int num[N];
    int i,j,k;
    gets(s); // @@ [Using gets() is unsafe and deprecated; may cause compilation error with modern compilers]
    for(j=0,i=0;i<strlen(s);i++){            //清除空格
        if(s[i]!=' ')
            s[j++]=s[i];
    }
    s[j]='\0';
    for(i=0,j=0;i<strlen(s);i++){           //记录数字
        if(s[i]>='0'&&s[i]<='9'){
            num[k]=s[i]-'0'; // @@ [Variable 'k' is used uninitialized, leading to undefined behavior]
            while(s[i+1]>='0'&&s[i+1]<='9'){
                num[k]=num[k]*10+s[i+1]-'0';
                i++;
            }
            k++;
        }
        num[k]='\0'; // @@ [Incorrectly setting an integer array element to '\0'; also 'k' may be out of sync]
    }
    for(i=0,j=0;i<strlen(s);i++){           //记录符号
        if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
            fuh[j]=s[i];
            j++;
        }
    }
    for(i=0;i<strlen(fuh);i++){                //先乘除
        if(fuh[i]=='*'){
            num[i+1]=num[i]*num[i+1]; // @@ [Does not properly collapse the array after operation; leaves gaps]
            num[i]=' '; // @@ [Storing character ' ' in integer array is meaningless and causes issues later]
            i++;
        }
        if(fuh[i]=='/'){
            num[i+1]=num[i]/num[i+1]; // @@ [Same issue: does not collapse array; also skips next operator due to i++]
            num[i]=' '; // @@ [Same as above: invalid use of space in integer array]
            i++;
        }
    }
    for(j=0,i=0;i<k;i++){           //清除空格
        if(num[i]!=' ') // @@ [Comparing integer array elements to ' ', which was incorrectly assigned earlier]
            num[j++]=num[i];
    }
    num[j]='\0'; // @@ [Again, setting integer array to '\0' is incorrect]
    int an=num[0];
    for(i=0,j=0;i<strlen(fuh);i++){           //后加减
        if(fuh[i]=='+')
            an+=num[++j]; // @@ [Indexing into num with ++j assumes cleaned array aligns with original fuh, which it doesn't]
        if(fuh[i]=='-')
            an-=num[++j]; // @@ [Same indexing issue; logic fails when multiplication/division changed operand count]
    }
    printf("%d",an);
    return 0;
}