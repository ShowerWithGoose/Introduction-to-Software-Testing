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
            if(s[i+1]==0){ // @@ The condition `s[i+1]==0` checks if the character after the first non-zero digit is the null terminator. This implies the number has only one significant digit (e.g., 0.005). However, the problem states "all digits are significant" and implies there can be multiple digits. More critically, if the loop `for(i=k+1;s[i]=='0';i++);` stops at the first non-zero digit, `s[i]` is that digit. The code then tries to print just that digit. But the `else` branch for `k!=1` handles the general case. The specific issue here is that this branch `if(s[i+1]==0)` is incomplete or incorrect for numbers like `0.00000009123...`. If `s[i+1]` is not 0 (i.e., there are more digits), this `if` block is skipped, and nothing is printed for the `k==1 && s[0]=='0'` case where there are multiple significant digits. The code falls through without outputting anything for the mantissa and exponent in this specific sub-case.
                printf("%de%d",s[i]-'0',1-i);
            }
            // @@ Missing else block to handle cases where there are more significant digits after the first non-zero digit found in the fractional part. For input 0.00000009123456789012, k=1, s[0]='0'. The loop finds i such that s[i] is '9'. s[i+1] is '1' (not 0). So the if condition fails. No output is produced.
        }
    }else{
        printf("%d.",s[0]-'0');
        for(i=1;i<k;i++){
            printf("%d",s[i]-'0');
        }
        for(i=k+1;s[i]!=0;i++){
            printf("%d",s[i]-'0');
        }
        printf("e%d",k-1); 
    } 
    return 0;
}