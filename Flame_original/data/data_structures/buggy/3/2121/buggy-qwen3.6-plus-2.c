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
        int cnt2; // @@ Uninitialized variable. If the subsequent loop does not assign a value (e.g., input "10"), using cnt2 leads to undefined behavior.
        for(int i = strlen(num)-1;i>=1;i--)if(num[i]!='0')cnt2=i; // @@ Logic error: attempts to strip trailing zeros which contradicts "all digits are significant". Also fails to assign cnt2 if all digits from index 1 are '0'.
        for(int i=2;i<=cnt2;i++)printf("%c",num[i]); // @@ Loop incorrectly starts at index 2, skipping num[1]. Additionally, if the base should be an integer per problem statement, no extra digits should be printed; if it should be a decimal, a '.' is missing.
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