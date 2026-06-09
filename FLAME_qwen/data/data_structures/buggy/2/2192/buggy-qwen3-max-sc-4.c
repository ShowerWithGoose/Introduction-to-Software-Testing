#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()  {           
    char s[100000]={"0"};
    int digit[100000]={0};
    char symbol[100000]={"0"};
    gets(s); // @@ [Using `gets()` is unsafe and deprecated; however, the primary issue is logical errors in parsing and operator precedence handling.]
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
        digit[k+1]=digit[k]*digit[k+1];    // @@ [This overwrites digit[k+1], but doesn't remove or skip the used operand, leading to incorrect reuse in later operations.]
        }
        else if(symbol[k]=='/'){
        digit[k+1]=digit[k]/digit[k+1];    // @@ [Same issue as multiplication: modifies digit[k+1] but leaves symbol[k] and digit[k] in place, causing double-counting or wrong associations in addition/subtraction phase.]
        }
    }
    sum=digit[0];
    for(k=0;k<j;k++){
        
        if(symbol[k]=='+'){
            for(l=k+1;symbol[l]!='+'&&symbol[l]!='-'&&symbol[l]!='=';l++); // @@ [This loop finds the next operator, but `digit[l]` may have been altered by prior * or / operations, and `l` can go out of bounds if no such operator exists before end. Also, it skips intermediate results from * and / that should already be collapsed.]
        //printf("l=%d ", l);
        //printf("%d ", digit[l]);
        sum+=digit[l];b--; 
            
            //printf("%d\n", sum);
        }
        else if(symbol[k]=='-'){
            for(l=k+1;symbol[l]!='+'&&symbol[l]!='-'&&symbol[l]!='=';l++); // @@ [Same as above: incorrect indexing and potential out-of-bounds access; also logic fails to account for collapsed terms after * and /.]
        //printf("l=%d ", l);
        sum-=digit[l];    b--;
        
            //printf("%d\n", sum);    
        }
        
    }    
    if(b==j){
        sum=digit[j-1]; // @@ [This fallback is arbitrary and not aligned with expression evaluation logic; it may overwrite correct result or use uninitialized/incorrect value.]
    }
    printf("%d", sum);
    return 0;}