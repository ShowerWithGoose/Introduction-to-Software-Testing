#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    gets(str);
    int len;
    len=strlen(str);
        int i=2;
    if(str[0]=='0'){
        while(1){
            if(str[i]!='0'){
                break;
            }    
            i++;    
        }
        if(i==(len-1)){
            printf("%c",str[i]);
        }
        else{
        printf("%c.",str[i]);
        for(int k=i+1;k<len;k++){
            printf("%c",str[k]);
        }
        }
        int m=i-1;
        printf("e-%d",m);    
    }
    else if(str[0]!=0){ // @@ This condition is always true because str[0] is a character, not an integer. It should be str[0]!='0' to check if the first character is not '0'. However, since the if already handles str[0]=='0', this else if is redundant and will always execute for non-zero first digits, but the logic inside has errors.
        printf("%c.",str[0]);
        int a=1;
        while(1){
            if(str[a]!='.'){
                printf("%c",str[a]);
                a++; 
            }
            else if(str[a]=='.'){
                break;
            }
        }
        for(int b=a+1;b<len;b++){
            printf("%c",str[b]);
        }
        printf("e%d",a); // @@ The exponent should be (a-1) because a counts the number of digits before the decimal point (including the first digit). For example, for "87899.999...", a will be 5 after the loop, but the exponent should be 4 (since 87899 = 8.7899e4). The correct exponent is a-1.
    }
     
return 0;
}