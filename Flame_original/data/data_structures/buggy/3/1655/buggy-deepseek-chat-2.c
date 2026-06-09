#include<stdio.h>
#include<string.h>
int main(){
    int i,j=0,j1=-1,k=0,len,a,b;
    char str[105];
    gets(str);
    len=strlen(str);
    for(i=0;i<len;i++){
        if(str[i]>'0'&&str[i]<='9'){ // @@ The condition should be str[i] >= '0' && str[i] <= '9' to include '0' as a significant digit when it is the only digit before decimal point
            j=i;
            if(j1<0)
            j1=j;    
        }
        if(str[i]=='.')
            k=i;
    }
    if(k==0){
        k=len-1; // @@ This incorrectly sets k to len-1 when no decimal point is found, but the problem expects input to always have a decimal point; also, if the first character is '.', k=0 is correct but the logic is flawed
    }
    if(j1==j){
        printf("%ce%d",str[j1],k-j1); // @@ The exponent calculation is incorrect; it should be k-j1-1 when there is a decimal point, and the base should not include trailing zeros after the decimal point
    }
    else{
        printf("%c.",str[j1]);
        for(i=j1+1;i<=j;i++){
            if(str[i]!='.')
                printf("%c",str[i]);
        }
        printf("e%d",k-j1-1); // @@ The exponent calculation is incorrect; it should be k-j1-1 only when the decimal point is after the first significant digit, but the logic does not handle cases where the decimal point is before the first significant digit (e.g., 0.001)
    }
    return 0;
}