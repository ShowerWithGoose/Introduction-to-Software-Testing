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
    else if(str[0]!=0){ // @@ Error: This condition should be `str[0]!='0'` to check for non-zero character, not integer 0. As written, it compares the character to integer 0, which may cause incorrect behavior for non-zero digits.
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
        printf("e%d",a); // @@ Error: The exponent should be `a-1` (the number of digits before the decimal point), not `a`. For example, input "12.34" should output "1.234e1", but this prints "e2".
    }
     
return 0;
}