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
    printf("%c.",str[i]); // @@ [When the number is of the form 0.d (like 0.9), the output should be an integer base (e.g., "9e-1"), not a decimal base ("9.e-1"). The code incorrectly prints a decimal point after the first non-zero digit even when there are no following digits or when it should be omitted per scientific notation rules.]
    for(i++;str[i]!='\0';i++){
    printf("%c",str[i]);
    }
    printf("e-%d",k);
    }
    else{
    for(i=0;str[i]!='.'&&str[i]!='\0';i++)
    {}
    printf("%c.",str[0]); // @@ [For numbers with more than one digit before the decimal (e.g., "123.45"), the base should be a single digit followed by a decimal and the rest, which is correct. However, if the number has only one non-zero digit before the decimal (e.g., "5.6"), it should output "5.6e0", but the problem states that if it's an integer base (only one significant digit and nothing after), it should omit the decimal point. However, in this branch, the input never has trailing zeros and always has digits after the decimal, so this may not be the main issue. The primary error is in the first branch.]
    for(k=1;str[k]!='\0';k++){
    if(str[k]!='.')printf("%c",str[k]);
    }
    printf("e%d",i-1);
    }

 
}