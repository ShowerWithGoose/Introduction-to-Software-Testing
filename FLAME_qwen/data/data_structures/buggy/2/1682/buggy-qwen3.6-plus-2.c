#include <stdio.h>
#include <stdlib.h> // @@ Missing #include <string.h>, which causes a compilation error due to implicit declaration of strlen.

#define N 10000
int main()
{
    char s[N],fuh[N];
    int num[N];
    int i,j,k; // @@ Variable k is uninitialized, leading to undefined behavior when used as an array index.
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
        num[k]='\0'; // @@ This assignment is inside the loop and incorrectly overwrites num[k] repeatedly; it should be placed after the loop to properly terminate the array.
    }
    for(i=0,j=0;i<strlen(s);i++){           //记录符号
        if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
            fuh[j]=s[i];
            j++;
        }
    }
    for(i=0;i<strlen(fuh);i++){                //先乘除 // @@ fuh array is not null-terminated, causing strlen to read out of bounds and potentially crash or loop incorrectly.
        if(fuh[i]=='*'){
            num[i+1]=num[i]*num[i+1];
            num[i]=' ';
            i++;
        }
        if(fuh[i]=='/'){
            num[i+1]=num[i]/num[i+1];
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
            an+=num[++j];
        if(fuh[i]=='-')
            an-=num[++j];
    }
    printf("%d",an);
    return 0;
}