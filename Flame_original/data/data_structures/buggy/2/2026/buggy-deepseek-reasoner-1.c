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
    num2[0]=num[0];
    for(int i=0;i<q-1;i++){ // @@ This loop does not handle the last number (the one before '='). That number should be stored in num2[p] after the loop; its omission leads to missing term in the final sum.
        if((op[i]=='+')||(op[i]=='-')){
            op2[h]=op[i];
            h++;
            if((i==0)||(op[i-1]=='+')||(op[i-1]=='-')){ // @@ This condition incorrectly determines when to store the term for a +- operator. For a +- operator that follows a */, the condition fails, leaving num2[p] uninitialized after incrementing p.
                num2[p]=num[i]; // @@ Stores the original number before the operator, which may not be the correct term result (especially after a */ chain). Should store the accumulated result of the preceding term.
            }
            p++; // @@ Increments p without initializing the next term's starting value (which should be num[i+1]).
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
                    num2[p]=num2[p]*num[i+1];
                }else{
                    num2[p]=num2[p]/num[i+1];
                }
            }
        }
    }
    int sum=num2[0];
    for(int i=0;i<p;i++){
        if(op2[i]=='+'){
            sum+=num2[i+1];
        }else if(op2[i]=='-'){
            sum-=num2[i+1];
        }
    }
    printf("%d",sum);
}