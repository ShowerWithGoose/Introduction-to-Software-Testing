#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    gets(str); // @@ gets() is removed in the C11 standard and will cause a compilation error in modern compilers; use fgets() instead.
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
        for(int k=i+1;k<len;k++){ // @@ Declaring loop variables inside the for statement is not supported in the C89/C90 standard, causing a compilation error.
            printf("%c",str[k]);
        }
        }
        int m=i-1;
        printf("e-%d",m);    
    }
    else if(str[0]!=0){ // @@ Compares the character to integer 0 (null terminator) instead of character literal '0', which is a semantic/logical error.
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
        for(int b=a+1;b<len;b++){ // @@ Declaring loop variables inside the for statement is not supported in the C89/C90 standard, causing a compilation error.
            printf("%c",str[b]);
        }
        printf("e%d",a);
    }
     
return 0;
}