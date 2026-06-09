#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    gets(str); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors with modern compilers that do not support it by default.]
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
    else if(str[0]!=0){ // @@ [This condition should compare against the character '0' (i.e., str[0] != '0'), not the integer 0. As written, it will always be true because str[0] is a char (non-zero ASCII value), leading to incorrect logic flow.]
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
        printf("e%d",a);
    }
     
return 0;
}