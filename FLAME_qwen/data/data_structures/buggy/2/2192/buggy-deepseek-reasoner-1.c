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
        digit[k+1]=digit[k]*digit[k+1];    
        }
        else if(symbol[k]=='/'){
        digit[k+1]=digit[k]/digit[k+1];    
        }
    }
    sum=digit[0]; // @@ [This assumes the first number is always the leftmost operand. If the first operator is '*' or '/', the left operand for the first '+' or '-' should be the result of the preceding multiplication/division chain, not digit[0].]
    for(k=0;k<j;k++){
        
        if(symbol[k]=='+'){
            for(l=k+1;symbol[l]!='+'&&symbol[l]!='-'&&symbol[l]!='=';l++);
        sum+=digit[l];b--; 
            
        }
        else if(symbol[k]=='-'){
            for(l=k+1;symbol[l]!='+'&&symbol[l]!='-'&&symbol[l]!='=';l++);
        sum-=digit[l];    b--;
        
        }
        
    }    
    if(b==j){
        sum=digit[j-1]; // @@ [Should be digit[j] to get the final result when there are no '+' or '-' operators. For expressions with only '*' or '/', the correct result is stored at digit[j] after the multiplication/division loop.]
    }
    printf("%d", sum);
    return 0;}