#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
char str[120];
int main(){
    gets(str);
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
    printf("%c.",str[i]); // @@ [Always prints a decimal point after the first significant digit, even when there are no more digits (e.g., "0.001" yields "1.e-3" instead of "1e-3"). Should conditionally print '.' only if there are remaining digits after str[i].]
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