#include <stdio.h>
#include <stdlib.h>

#define N 10000
int main()
{
    char s[N],fuh[N];
    int num[N];
    int i,j,k;
    gets(s);
    for(j=0,i=0;i<strlen(s);i++){            //清除空格
        if(s[i]!=' ')
            s[j++]=s[i];
    }
    s[j]='\0';
    for(i=0,j=0;i<strlen(s);i++){           //记录数字
        if(s[i]>='0'&&s[i]<='9'){
            num[k]=s[i]-'0'; // @@ k not initialized; undefined behavior
            while(s[i+1]>='0'&&s[i+1]<='9'){
                num[k]=num[k]*10+s[i+1]-'0';
                i++;
            }
            k++;
        }
        num[k]='\0'; // @@ misplaced; null-terminating int array is meaningless; also executed for every loop iteration
    }
    for(i=0,j=0;i<strlen(s);i++){           //记录符号
        if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
            fuh[j]=s[i];
            j++;
        }
    }
    // fuh is not null-terminated, causing strlen(fuh) undefined behavior later
    for(i=0;i<strlen(fuh);i++){                //先乘除
        if(fuh[i]=='*'){
            num[i+1]=num[i]*num[i+1];
            num[i]=' '; // @@ assigning character ' ' to int array; intended as marker but logically incorrect
            i++;
        }
        if(fuh[i]=='/'){
            num[i+1]=num[i]/num[i+1];
            num[i]=' '; // @@ assigning character ' ' to int array; intended as marker but logically incorrect
            i++;
        }
    }
    for(j=0,i=0;i<k;i++){           //清除空格
        if(num[i]!=' ') // @@ comparing int with character ' '; unreliable; k no longer represents correct count after multiplication/division
            num[j++]=num[i];
    }
    num[j]='\0'; // @@ null-terminating int array is meaningless
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