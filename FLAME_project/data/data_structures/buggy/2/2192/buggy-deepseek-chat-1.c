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
        digit[k+1]=digit[k]*digit[k+1]; // @@ Error: This modifies digit[k+1] but does not account for the fact that digit[k] may have already been modified by a previous multiplication/division, leading to incorrect chained operations. For example, in "24 / 4 / 3 / 2", after processing '/', digit[1]=6, then digit[2]=2, then digit[3]=1, but the loop processes sequentially and overwrites values incorrectly for chained operators.
        }
        else if(symbol[k]=='/'){
        digit[k+1]=digit[k]/digit[k+1]; // @@ Error: Same issue as above; chained division like "24 / 4 / 3 / 2" should compute left-to-right, but this overwrites digit[k+1] using the already-modified digit[k], which is correct for left-to-right, but the problem is that the loop does not skip already processed positions, causing incorrect results when mixed with addition/subtraction later.
        }
    }
    sum=digit[0];
    for(k=0;k<j;k++){
        
        if(symbol[k]=='+'){
            for(l=k+1;symbol[l]!='+'&&symbol[l]!='-'&&symbol[l]!='=';l++); // @@ Error: This loop finds the next '+' or '-' or '=', but it does not correctly handle the case where there are multiple consecutive '*' or '/' operators. It should find the digit corresponding to the result of the entire multiplication/division chain, but instead it finds the index of the next operator, not the correct digit index.
        //printf("l=%d ", l);
        //printf("%d ", digit[l]);
        sum+=digit[l];b--; // @@ Error: digit[l] is the digit at index l, but l is the index of the next operator, not the index of the result digit. For example, in "10*20*30*40", after the multiplication loop, digit[0]=10, digit[1]=200, digit[2]=6000, digit[3]=240000, but the '+' loop will set l to the index of the next '+' or '-', which is wrong.
            
            //printf("%d\n", sum);
        }
        else if(symbol[k]=='-'){
            for(l=k+1;symbol[l]!='+'&&symbol[l]!='-'&&symbol[l]!='=';l++); // @@ Error: Same issue as above; l is set to the index of the next operator, not the correct digit index.
        //printf("l=%d ", l);
        sum-=digit[l];    b--; // @@ Error: Same issue as above; uses wrong index for digit.
        
            //printf("%d\n", sum);    
        }
        
    }    
    if(b==j){
        sum=digit[j-1];
    }
    printf("%d", sum);
    return 0;}