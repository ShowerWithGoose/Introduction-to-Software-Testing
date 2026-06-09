#include<stdio.h>
#include<string.h>

int main(){
    char num[1100];
    scanf("%s",num);
    //先判断e后面是负数还是正数
    if(num[0]=='0'&&num[1]=='.'){//是小数
        int cnt=1; 
         int l=strlen(num);
         for(int i=2;i<l;i++){
             if(num[i]=='0')cnt++;
        }
        printf("%c",num[1+cnt]);
        if(1+cnt<l-1)printf(".");
        for(int i=2+cnt;i<l;i++)printf("%c",num[i]);
        printf("e-%d",cnt);
        return 0;
    }
    if(strchr(num,'.')==NULL){
        int cnt=strlen(num)-1;
        printf("%c",num[0]);
        int cnt2; // @@ [变量cnt2未初始化，后续使用可能导致未定义行为；且当整数末尾有多个0时，循环不会给cnt2赋值]
        for(int i = strlen(num)-1;i>=1;i--)if(num[i]!='0')cnt2=i; // @@ [若整数所有位均为0（本不会出现），或末尾全部是0直到第一个非零位之前，cnt2可能得不到赋值；逻辑上未能正确处理整数中小数点后的有效数字，例如输入"120"会导致输出"1e2"而不是"1.2e2"]
        for(int i=2;i<=cnt2;i++)printf("%c",num[i]); // @@ [使用了未初始化的cnt2，可能导致越界访问或错误输出]
        printf("e%d",cnt);
        return 0;
    }
    int cnt=strchr(num,'.')-num;
    cnt--;
    printf("%c.",num[0]);
    for(int i = 1;i < strlen(num);i++)if(num[i]!='.')printf("%c",num[i]);
    printf("e%d",cnt);
    return 0;
}