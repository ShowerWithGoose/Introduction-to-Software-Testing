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
    else if(str[0]!=0){ // @@ This condition is always true because str[0] is a character, not an integer 0. It should be str[0]!='0' to check for non-zero digit.
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
        printf("e%d",a); // @@ The exponent should be (a-1) because a counts from 1, and the decimal point position determines the exponent. For input like "87899.999...", a will be 5 (position of '.'), but exponent should be 4 (number of digits before decimal minus 1).
    }
     
return 0;
}