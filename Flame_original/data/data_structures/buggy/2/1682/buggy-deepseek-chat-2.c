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
            num[k]=s[i]-'0'; // @@ [变量k未初始化，导致未定义行为]
            while(s[i+1]>='0'&&s[i+1]<='9'){
                num[k]=num[k]*10+s[i+1]-'0';
                i++;
            }
            k++;
        }
        num[k]='\0'; // @@ [这一行在循环内每次迭代都会执行，但k可能未定义或超出范围，且赋值'\0'给整数数组不合理]
    }
    for(i=0,j=0;i<strlen(s);i++){           //记录符号
        if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
            fuh[j]=s[i];
            j++;
        }
    }
    for(i=0;i<strlen(fuh);i++){                //先乘除
        if(fuh[i]=='*'){
            num[i+1]=num[i]*num[i+1];
            num[i]=' '; // @@ [将整数数组元素赋值为空格字符，逻辑错误，应标记为已处理]
            i++;
        }
        if(fuh[i]=='/'){
            num[i+1]=num[i]/num[i+1];
            num[i]=' '; // @@ [同上，逻辑错误]
            i++;
        }
    }
    for(j=0,i=0;i<k;i++){           //清除空格
        if(num[i]!=' ')
            num[j++]=num[i];
    }
    num[j]='\0'; // @@ [整数数组不应以'\0'结尾，且后续使用strlen(fuh)可能不匹配]
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