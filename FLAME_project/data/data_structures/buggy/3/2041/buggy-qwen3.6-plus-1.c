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
            if(s[i+1]==0){ // @@ The condition `s[i+1]==0` checks if the character after the first non-zero digit is the null terminator. This implies the number has only one significant digit (e.g., 0.005). However, the problem states "all digits are significant" and implies there can be multiple digits. More critically, if there are more digits (like in the test case 0.00000009123456789012), this branch is skipped entirely because `s[i+1]` is not 0. The code lacks an `else` block to handle numbers with multiple significant digits after the leading zeros. Consequently, for the input `0.00000009123456789012`, the program produces no output for the `k==1` and `s[0]=='0'` case if it doesn't enter the `if` or if the logic is flawed. Actually, looking closely: if `s[i]` is the first non-zero digit, `s[i+1]` is the next digit. If it's not 0 (null), the `if` fails. There is no `else`. So nothing is printed.
                printf("%de%d",s[i]-'0',1-i);
            }
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