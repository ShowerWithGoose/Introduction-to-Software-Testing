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
            num[k]=s[i]-'0'; // @@ [k is uninitialized, leading to undefined behavior; should initialize k=0 before this loop]
            while(s[i+1]>='0'&&s[i+1]<='9'){
                num[k]=num[k]*10+s[i+1]-'0';
                i++;
            }
            k++;
        }
        num[k]='\0'; // @@ [overwrites next number slot with '\0', corrupting integer array; also k may be out of bounds]
    }
    for(i=0,j=0;i<strlen(s);i++){           //记录符号
        if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
            fuh[j]=s[i];
            j++;
        }
    }
    fuh[j]='\0'; // @@ [missing null-termination for fuh array, causing strlen(fuh) to read garbage later]
    for(i=0;i<strlen(fuh);i++){                //先乘除
        if(fuh[i]=='*'){
            num[i+1]=num[i]*num[i+1]; // @@ [does not handle operator precedence correctly across multiple * and /; processes left-to-right but skips updating fuh or shifting num properly]
            num[i]=' '; // @@ [stores space character in integer array; invalid for integer arithmetic]
            i++;
        }
        if(fuh[i]=='/'){ // @@ [after i++ in '*' case, this may skip checking '/' at new i; also same issues as '*' case]
            num[i+1]=num[i]/num[i+1];
            num[i]=' ';
            i++;
        }
    }
    for(j=0,i=0;i<k;i++){           //清除空格
        if(num[i]!=' ') // @@ [comparing integer array elements to space character ' ' is incorrect; num[i] holds integers, not chars]
            num[j++]=num[i];
    }
    num[j]='\0'; // @@ [unnecessary and incorrect: num is int array, not string; also breaks subsequent logic]
    int an=num[0];
    for(i=0,j=0;i<strlen(fuh);i++){           //后加减
        if(fuh[i]=='+')
            an+=num[++j]; // @@ [indexing into num with j assumes num was compacted correctly, but due to earlier errors, num may have wrong values or length]
        if(fuh[i]=='-')
            an-=num[++j]; // @@ [same indexing issue; also doesn't account for reduced number of operands after * and / processing]
    }
    printf("%d",an);
    return 0;
}