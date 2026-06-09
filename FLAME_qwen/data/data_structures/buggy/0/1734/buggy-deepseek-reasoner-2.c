#include <stdio.h>
#include <string.h>
int main()
{
    char os[200];//原字符串
    char s[300];//扩展后字符串
    scanf("%s",os);
    int n=strlen(os);
    int i,j;
    for(i=0,j=0;i<n;i++){
        if(os[i]!='-'){
            s[j]=os[i];
            j++;
        }
        else{
            if((os[i-1]>='0'&&os[i+1]<='9'&&os[i-1]<os[i+1])||(os[i-1]>='a'&&os[i+1]<='z'&&os[i-1]<os[i+1])||(os[i-1]>='A'&&os[i+1]<='Z'&&os[i-1]<os[i+1])){ // @@ 数组越界风险（i=0或i=n-1时越界），且类型判断条件不完整（缺少对上界和下界的检查）
                //保证扩展符前后的字符同时为小写字母、大写字母或数字且后字符大于前字符
                for(int m=1;s[j-1]<os[i+1]-1;j++){
                   s[j]=s[j-1]+m;//扩展
                }

            }
            else{
                s[j]=os[i];
                j++;
            }
        }
    }
    
    printf("%s",s); // @@ 缺少字符串结束符，应在输出前添加 s[j]='\0';
    return 0;
}