#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    gets(str); // @@ [Deprecated function may cause compilation error in strict C standards]
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
        for(int k=i+1;k<len;k++){ // @@ [C99-style loop variable declaration may cause compilation error in C89 compilers]
            printf("%c",str[k]);
        }
        }
        int m=i-1;
        printf("e-%d",m);    
    }
    else if(str[0]!=0){
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
        for(int b=a+1;b<len;b++){ // @@ [C99-style loop variable declaration may cause compilation error in C89 compilers]
            printf("%c",str[b]);
        }
        printf("e%d",a); // @@ [Exponent should be a-1, not a; logical error]
    }
     
return 0;
}