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
        digit[k+1]=digit[k]*digit[k+1]; // @@ Error: This modifies digit[k+1] in place, but when there are consecutive * or / operators, the left operand should be the result of the previous operation, not the original digit[k]. For example, in "24 / 4 / 3 / 2", after processing the first '/', digit[1] becomes 6, but then for the second '/', digit[2] is still 3, and digit[1] is 6, so digit[2] becomes 6/3=2, which is correct. However, the issue is that this approach does not handle operator precedence correctly when mixing + and - with * and /, because the loop processes * and / left-to-right but does not account for the fact that later * and / operations should use the updated values from previous * and / operations in the same sequence. The real problem is that the code does not properly handle the order of operations when there are multiple * and / operators in a row, and also fails to correctly compute the final result when + and - are involved because the digit array is being overwritten in a way that loses the original values needed for addition/subtraction.
        }
        else if(symbol[k]=='/'){
        digit[k+1]=digit[k]/digit[k+1]; // @@ Error: Same issue as above. This modifies digit[k+1] in place, but the left operand digit[k] may have already been modified by a previous * or / operation, which is correct for consecutive * and /, but the problem is that the code later uses digit[l] for addition/subtraction, and digit[l] may have been overwritten incorrectly. For example, in "24 / 4 / 3 / 2", after the loop, digit[3] becomes 1 (24/4=6, 6/3=2, 2/2=1), but digit[0] is still 24, digit[1] is 6, digit[2] is 2, digit[3] is 1. Then for addition/subtraction, the code tries to use digit[l] where l is the index of the next operator, but this logic is flawed because it does not correctly map the result of the * and / chain to the correct position for addition/subtraction.
        }
    }
    sum=digit[0];
    for(k=0;k<j;k++){
        
        if(symbol[k]=='+'){
            for(l=k+1;symbol[l]!='+'&&symbol[l]!='-'&&symbol[l]!='=';l++); // @@ Error: This loop finds the next +, -, or =, but l ends up at the index of that operator, not the digit after it. Then sum+=digit[l] adds the digit at the operator index, which is incorrect because digit[l] corresponds to the number before that operator, not after. For example, in "100 - 50 - 40", after processing the first '-', l should point to the digit after the next operator, but instead it points to the operator itself, leading to incorrect values.
        //printf("l=%d ", l);
        //printf("%d ", digit[l]);
        sum+=digit[l];b--; // @@ Error: digit[l] is the digit at the operator index, which is wrong. It should be digit[l+1] or the result of the * and / chain ending at that position.
            
            //printf("%d\n", sum);
        }
        else if(symbol[k]=='-'){
            for(l=k+1;symbol[l]!='+'&&symbol[l]!='-'&&symbol[l]!='=';l++); // @@ Error: Same issue as above. l ends at the operator index, not the digit index.
        //printf("l=%d ", l);
        sum-=digit[l];    b--; // @@ Error: digit[l] is the digit at the operator index, which is wrong.
        
            //printf("%d\n", sum);    
        }
        
    }    
    if(b==j){
        sum=digit[j-1];
    }
    printf("%d", sum);
    return 0;}