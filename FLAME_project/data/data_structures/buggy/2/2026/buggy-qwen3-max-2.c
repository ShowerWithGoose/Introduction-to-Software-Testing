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
    num2[0]=num[0]; // @@ [This initialization assumes the first number is always part of a '+'/'-' term, but it should only be used if the expression starts with a number followed by '+' or '-', or if it's the only number. However, the real issue is in how multiplication/division chains are handled.]
    for(int i=0;i<q-1;i++){
        if((op[i]=='+')||(op[i]=='-')){
            op2[h]=op[i];
            h++;
            if((i==0)||(op[i-1]=='+')||(op[i-1]=='-')){
                num2[p]=num[i]; // @@ [This assigns num[i] (the left operand of '+'/'-') to num2[p], but num[i] might have already been consumed by a previous '*'/'/' operation. Also, when i==0, num[0] was already assigned to num2[0], so this duplicates it incorrectly.]
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
                    num2[p]=num2[p]*num[i+1]; // @@ [This line and the one below assume that num2[p] holds the accumulated result of prior multiplications/divisions, but p may not be correctly updated when consecutive '*'/'/' appear after a '+'/'-'. Also, p is only incremented in the '+'/'-' block, so for expressions like "a*b*c", p remains 0 and overwrites num2[0], but then later '+' processing uses wrong indices.]
                }else{
                    num2[p]=num2[p]/num[i+1];
                }
            }
        }
    }
    int sum=num2[0];
    for(int i=0;i<p;i++){ // @@ [The loop runs for i from 0 to p-1, but num2 has p+1 elements (indices 0..p). The correct number of terms to combine is h (number of '+'/'-' operators), and there should be h+1 terms. Also, p is incremented only when encountering '+'/'-', but not aligned with actual term count due to flawed logic above.]
        if(op2[i]=='+'){
            sum+=num2[i+1];
        }else if(op2[i]=='-'){
            sum-=num2[i+1];
        }
    }
    printf("%d",sum);
}