#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define ll long long
char s[200];
int dot=0,flag=0,wa=0,sum=1;
int main(){
    gets(s); // @@ gets() is unsafe and deprecated; it can cause buffer overflow and is not standard C. Use fgets() instead.
    int len=strlen(s);
    for(int i=0;i<len;i++){
        if(s[i]=='.')dot=i;
        if(dot>0){
            if(s[i]!='0')flag=1;
            if(!flag&&s[i]=='0')sum++;
        }
    }
    if(dot==1&&s[0]!='0'){
        printf("%se0",s); // @@ This prints the entire string including the decimal point, but the base should have only one digit before the decimal point. For example, "1.23" should become "1.23e0", but this prints "1.23e0" which is correct only if the input has exactly one digit before the decimal point. However, the problem requires the base to have one significant digit before the decimal point, which this handles, but it does not handle cases where there are trailing zeros or other formatting issues.
    }
    else{
        if(s[0]=='0'){
            for(int i=dot+sum;i<len;i++){
                if(s[i]!='.')
                printf("%c",s[i]);
                if(i==dot+sum&&i!=len-1)printf(".");
            }
            printf("e-%d",sum);
        }
        else{
            for(int i=0;i<len;i++){
                if(s[i]!='.'){
                    printf("%c",s[i]); 
                }
                if(i==0)printf(".");
            }
            printf("e%d",dot-1);
        }
    }
    return 0;
}