#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define ll long long
char s[200];
int dot=0,flag=0,wa=0,sum=1;
int main(){
    gets(s); // @@ gets() is unsafe and may cause buffer overflow; also not standard in C11 and later
    int len=strlen(s);
    for(int i=0;i<len;i++){
        if(s[i]=='.')dot=i;
        if(dot>0){
            if(s[i]!='0')flag=1;
            if(!flag&&s[i]=='0')sum++;
        }
    }
    if(dot==1&&s[0]!='0'){
        printf("%se0",s); // @@ This prints the entire string including the decimal point, but the base should have only one digit before the decimal point; also trailing zeros may be present
    }
    else{
        if(s[0]=='0'){
            for(int i=dot+sum;i<len;i++){
                if(s[i]!='.')
                printf("%c",s[i]);
                if(i==dot+sum&&i!=len-1)printf(".");
            }
            printf("e-%d",sum); // @@ The exponent calculation is incorrect; sum counts zeros after the decimal point but does not account for the position of the first non-zero digit correctly
        }
        else{
            for(int i=0;i<len;i++){
                if(s[i]!='.'){
                    printf("%c",s[i]); 
                }
                if(i==0)printf("."); // @@ This adds a decimal point after the first digit even if the number has only one digit before the decimal point, which may be incorrect
            }
            printf("e%d",dot-1); // @@ The exponent calculation is incorrect; it should be based on the number of digits before the decimal point, not just dot-1
        }
    }
    return 0;
}