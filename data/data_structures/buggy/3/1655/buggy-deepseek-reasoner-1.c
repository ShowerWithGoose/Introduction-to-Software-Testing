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
        k=len-1; // @@ Error: For integer input (no decimal point), the decimal point should be after the last digit, so k should be len (not len-1). Setting k=len-1 causes exponent off by one for integers. Also, if the decimal point is at index 0 (unlikely but possible for numbers like ".123"? but problem says digits before decimal exist), this case would incorrectly rewrite k.
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
        printf("e%d",k-j1-1); // @@ Error: This exponent formula is incorrect when the decimal point appears before the first non-zero digit (i.e., when k < j1). For example, input "0.123" gives exponent -2 instead of -1. The correct exponent should be: if (k < j1) exponent = -(j1 - k); else exponent = k - j1 - 1.
    }
    return 0;
}