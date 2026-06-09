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
        digit[k+1]=digit[k]*digit[k+1];    // @@ Error: multiplication updates digit[k+1] but leaves digit[k] unchanged, causing later addition/subtraction to use incorrect operands.
        }
        else if(symbol[k]=='/'){
        digit[k+1]=digit[k]/digit[k+1];    // @@ Error: division has the same issue as multiplication.
        }
    }
    sum=digit[0];
    for(k=0;k<j;k++){
        
        if(symbol[k]=='+'){
            for(l=k+1;symbol[l]!='+'&&symbol[l]!='-'&&symbol[l]!='=';l++); // @@ Error: this loop finds the index after the next operator, but after multiplication/division, the digit at that index may not be the correct operand for the current '+'.
        //printf("l=%d ", l);
        //printf("%d ", digit[l]);
        sum+=digit[l];b--; // @@ Error: addition uses digit[l] which is likely incorrect due to previous multiplication/division modifications.
            
            //printf("%d\n", sum);
        }
        else if(symbol[k]=='-'){
            for(l=k+1;symbol[l]!='+'&&symbol[l]!='-'&&symbol[l]!='=';l++); // @@ Error: same issue as above for subtraction.
        //printf("l=%d ", l);
        sum-=digit[l];    b--; // @@ Error: subtraction uses digit[l] incorrectly.
        
            //printf("%d\n", sum);    
        }
        
    }    
    if(b==j){
        sum=digit[j-1];
    }
    printf("%d", sum);
    return 0;}