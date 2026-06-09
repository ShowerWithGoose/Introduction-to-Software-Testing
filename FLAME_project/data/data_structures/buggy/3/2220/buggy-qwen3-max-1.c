#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    gets(str);
    int len;
    len=strlen(str);
        int i=2; // @@ [Incorrect initialization: assumes the first non-zero digit after '0.' is at index 2, but it could be later if there are multiple zeros like "0.00..."]
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
        int m=i-1; // @@ [Wrong exponent calculation: m should represent how many places the decimal point moved left from original position (which is at index 1), so exponent = -(i - 1) but code uses m = i - 1 and prints e-%d, which gives wrong magnitude]
        printf("e-%d",m);    
    }
    else if(str[0]!=0){ // @@ [Redundant condition: str[0]!=0 always true since str[0] is a char; should compare with '0' instead of 0 (null character)]
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
        printf("e%d",a); // @@ [Exponent is off by one: for input like "87899.99...", the decimal moves from after first digit (8.) to original position after 5 digits, so exponent should be 4, not 5. The variable 'a' counts digits before '.', which equals number of digits minus 1, so exponent = a - 1, not a]
    }
     
return 0;
}