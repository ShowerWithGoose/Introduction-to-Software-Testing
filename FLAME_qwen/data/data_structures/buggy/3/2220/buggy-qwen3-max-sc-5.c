#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    gets(str); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings in modern compilers.]
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
    else if(str[0]!=0){ // @@ [This condition should compare with '0' character (i.e., '0'), not integer 0. It should be str[0] != '0'. As written, it always evaluates to true for any non-null character because ASCII values are non-zero.]
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
        printf("e%d",a); // @@ [The exponent calculation is incorrect. The exponent should be the number of digits between the original decimal point and the new position after normalization minus one. Here, 'a' is the index of '.', so exponent should be a - 1, not a.]
    }
     
return 0;
}