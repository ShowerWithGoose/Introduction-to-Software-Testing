#include<stdio.h>

int main(){
    char s[105];
    int i,k;
    scanf("%s",s);
    for(i=0;s[i]!='.';i++);
    k=i;//小数点的位置
    if(k==1){
        if(s[0]!='0'){
            char str[300]={0};
            sprintf(str,"%se0",s);//sprintf()
            printf("%s",str);
        }else{
            for(i=k+1;s[i]=='0';i++);
            if(s[i+1]==0){
                printf("%de%d",s[i]-'0',1-i);
            }@@ // Missing else clause to handle numbers like 0.00123 where more than one digit follows the first non-zero digit after decimal
        }
    }else{
        printf("%d.",s[0]-'0');@@ // Should print character s[0], not convert to int and print as %d (e.g., '5' becomes 53)
        for(i=1;i<k;i++){
            printf("%d",s[i]-'0');@@ // Same issue: should print s[i] as char, not as integer digit
        }
        for(i=k+1;s[i]!=0;i++){
            printf("%d",s[i]-'0');@@ // Same issue: printing digits as integers instead of characters
        }
        printf("e%d",k-1); 
    } 
    return 0;
}