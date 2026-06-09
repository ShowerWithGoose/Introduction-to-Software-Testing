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
            }@@ // Missing else branch to handle numbers like 0.00000009123456789012 where there are digits after the first non-zero digit
        }
    }else{
        printf("%d.",s[0]-'0');@@ // Should print as character, not integer (e.g., '1' vs 49), and this branch doesn't handle cases where leading digit is zero but k != 1
        for(i=1;i<k;i++){
            printf("%d",s[i]-'0');@@ // Same issue: printing integer values instead of characters
        }
        for(i=k+1;s[i]!=0;i++){
            printf("%d",s[i]-'0');@@ // Same issue: should print s[i] directly as char, not converted to int then printed as digit
        }
        printf("e%d",k-1); 
    } 
    return 0;
}