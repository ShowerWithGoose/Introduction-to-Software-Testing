#include <stdio.h>
#include <ctype.h>
int main(void){
    char s1[1000],s[1000],op[1000],op2[1000];
    int num[1000],value,num2[1000];
    gets(s1);
    int k=0;
    for(int i=0;s1[i]!='\0';i++){
        if(s1[i]!=' '){
            s[k]=s1[i];
            k++;
        }
    }
    s[k]='\0';
    int m=0,q=0;
    do{
        value=0;
        while(isdigit(s[m])){
            value=value*10+s[m]-'0';
            m++;
        }
        num[q]=value;
        op[q]=s[m];
        m++;
        q++;
    }while(op[q-1]!='=');
    int p=0,h=0;
    num2[0]=num[0]; // @@ [This initialization assumes the first number is always part of a '+'/'-' term, but it fails to handle cases where the expression starts with multiplication/division chains that should be evaluated first. However, the real issue is in how subsequent terms are processed.]
    for(int i=0;i<q-1;i++){
        if((op[i]=='+')||(op[i]=='-')){
            op2[h]=op[i];
            h++;
            if((i==0)||(op[i-1]=='+')||(op[i-1]=='-')){
                num2[p]=num[i]; // @@ [This assigns num[i] (the left operand of op[i]) to num2[p], but when op[i] is '+' or '-', the correct left operand for the next additive term should actually be the result of any preceding multiplicative chain ending at num[i]. Also, note that num[i] here is the number BEFORE op[i], which is correct, but the logic fails when multiplicative operations follow.]
            }
            p++;
        }
        if((op[i]=='*')||(op[i]=='/')){
            if((op[i-1]=='+')||(op[i-1]=='-')||(i==0)){
                if(op[i]=='*'){
                    num2[p]=num[i]*num[i+1];
                }else{
                    num2[p]=num[i]/num[i+1];
                }
            }else{
                if(op[i]=='*'){
                    num2[p]=num2[p]*num[i+1]; // @@ [This line and the one below assume that num2[p] already holds the accumulated product from previous multiplications, but p may not have been incremented correctly in all cases, especially when transitioning from additive to multiplicative operators. Moreover, the index p is shared between additive and multiplicative terms, leading to overwriting or incorrect accumulation.]
                }else{
                    num2[p]=num2[p]/num[i+1];
                }
            }
        }
    }
    int sum=num2[0];
    for(int i=0;i<p;i++){ // @@ [The loop runs for i from 0 to p-1, using op2[i] and num2[i+1]. However, the number of additive operations is h, not p. The variable p counts both additive and multiplicative term slots, so using p here leads to reading uninitialized or incorrect values in num2 and op2. This causes wrong final summation.]
        if(op2[i]=='+'){
            sum+=num2[i+1];
        }else if(op2[i]=='-'){
            sum-=num2[i+1];
        }
    }
    printf("%d",sum);
}