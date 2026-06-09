#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
char str[120];
int main(){
    gets(str); // @@ gets() is removed in the C11 standard and will cause a compilation error in modern compilers. Use fgets() instead.
    int i;
    int k=0;
    if(str[0]=='0'){

    for(i=0;str[i]!='\0';i++){
    if(str[i]=='0'){
    k++;
    }
    if(str[i]!='0'&&str[i]!='.')
    break;
    }
    printf("%c.",str[i]); // @@ Unconditionally prints a decimal point. If the converted base is an integer (e.g., input "0.1" becomes "1"), it incorrectly outputs "1.e-1" instead of "1e-1". Should only print '.' if there are digits following str[i].
    for(i++;str[i]!='\0';i++){
    printf("%c",str[i]);
    }
    printf("e-%d",k);
    }
    else{
    for(i=0;str[i]!='.'&&str[i]!='\0';i++)
    {}
    printf("%c.",str[0]); 
    for(k=1;str[k]!='\0';k++){
    if(str[k]!='.')printf("%c",str[k]);
    }
    printf("e%d",i-1);
    }

 
}