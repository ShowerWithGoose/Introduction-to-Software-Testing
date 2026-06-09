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
             if(num[i]=='0')cnt++; // @@ The loop should break when a non-zero digit is encountered; otherwise, it counts all zeros in the string instead of just the leading zeros after the decimal point.
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
        int cnt2;
        for(int i = strlen(num)-1;i>=1;i--)if(num[i]!='0')cnt2=i;
        for(int i=2;i<=cnt2;i++)printf("%c",num[i]); // @@ The loop starts at index 2, which skips the second digit of the number. It should start from i=1 to correctly print all significant digits after the first one.
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