#include<stdio.h>
#include<string.h>
int main(){
    int i,j=0,j1=-1,k=0,len,a,b;
    char str[105];
    gets(str);
    len=strlen(str);
    for(i=0;i<len;i++){
        if(str[i]>'0'&&str[i]<='9'){
            j=i;
            if(j1<0)
            j1=j;    
        }
        if(str[i]=='.')
            k=i;
    }
    if(k==0){
        k=len-1;
    }
    if(j1==j){
        printf("%ce%d",str[j1],k-j1);
    }
    else{
        printf("%c.",str[j1]);
        for(i=j1+1;i<=j;i++){
            if(str[i]!='.')
                printf("%c",str[i]);
        }
        printf("e%d",k-j1-1); // @@ The exponent formula is incorrect for numbers with a leading zero. For example, input "0.00000009123456789012" yields exponent -9 instead of -8. The correct exponent should be k - j1 when the first digit is '0' (i.e., leading zero), and k - j1 - 1 otherwise. Here, the code always subtracts 1, causing the off-by-one error.
    }
    return 0;
}