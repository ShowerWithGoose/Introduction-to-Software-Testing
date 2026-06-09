#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()  {           
    char s[100000]={"0"};
    int digit[100000]={0};
    char symbol[100000]={"0"};
    gets(s); // @@ gets() is removed in the C11 standard and causes a compilation error in modern compilers; use fgets() instead.
    int i, k,b,l,j=0,a=0; // @@ variable 'b' is declared but not initialized, which may cause a compilation error with strict warning flags.
    int sum; // @@ variable 'sum' is declared but not initialized, which may cause a compilation error or undefined behavior.
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