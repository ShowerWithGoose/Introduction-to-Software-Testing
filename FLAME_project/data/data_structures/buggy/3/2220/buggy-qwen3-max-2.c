#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    gets(str);
    int len;
    len=strlen(str);
        int i=2; // @@ [Incorrect initialization: assumes '0.' prefix and skips first two characters, but should start scanning after the decimal point (i=2 is arbitrary and fails for inputs like "0.001")]
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
        int m=i-1; // @@ [Wrong exponent calculation: m should represent how many places the decimal moved, which is (i - 2), not (i - 1), because the first non-zero digit is at position i, and original decimal is at position 1]
        printf("e-%d",m);    
    }
    else if(str[0]!=0){ // @@ [Redundant condition: str[0]!=0 always true since str[0] is a char; should be str[0]!='0' or just else]
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
        printf("e%d",a); // @@ [Wrong exponent: 'a' is the index of '.', so number of digits before decimal is 'a', but scientific notation exponent should be (a - 1). For "87899.99...", a=5, but exponent should be 4, not 5]
    }
     
return 0;
}