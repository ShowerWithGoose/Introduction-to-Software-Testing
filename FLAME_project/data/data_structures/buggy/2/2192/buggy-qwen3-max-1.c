#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()  {           
    char s[100000]={"0"};
    int digit[100000]={0};
    char symbol[100000]={"0"};
    gets(s);
    int i, k,b,l,j=0,a=0;
    int sum;
    for(i=0; s[i]!='\0'; i++){
        if(isdigit(s[i])){
        a=a*10+(s[i]-'0');    }            
            
        else if(s[i]!=32){
            digit[j]=a;
            a=0;
            symbol[j]=s[i];
            j++;b=j;}
    }    
    
    for(k=0;k<j;k++){
        if(symbol[k]=='*'){
        digit[k+1]=digit[k]*digit[k+1];    // @@ [This left-to-right multiplication overwrites digit[k], but later additions/subtractions still reference earlier digit indices that may have been altered incorrectly. Also, it doesn't handle operator precedence correctly across sequences like a*b/c because it modifies digit[k+1] in place without isolating the multiplicative term.]
        }
        else if(symbol[k]=='/'){
        digit[k+1]=digit[k]/digit[k+1];    // @@ [Same issue as above: in-place division modifies digit[k+1], corrupting the original operand values needed for correct precedence handling in later steps. For example, in "24/4/3/2", this loop computes ((((24/4)/3)/2) correctly, but when mixed with + and -, the digit array no longer holds original numbers, causing misalignment in the addition/subtraction phase.]
        }
    }
    sum=digit[0];
    for(k=0;k<j;k++){
        
        if(symbol[k]=='+'){
            for(l=k+1;symbol[l]!='+'&&symbol[l]!='-'&&symbol[l]!='=';l++);
        //printf("l=%d ", l);
        //printf("%d ", digit[l]);
        sum+=digit[l];b--; 
            
            //printf("%d\n", sum);
        }
        else if(symbol[k]=='-'){
            for(l=k+1;symbol[l]!='+'&&symbol[l]!='-'&&symbol[l]!='=';l++);
        //printf("l=%d ", l);
        sum-=digit[l];    b--;
        
            //printf("%d\n", sum);    
        }
        
    }    
    if(b==j){
        sum=digit[j-1];
    }
    printf("%d", sum);
    return 0;}