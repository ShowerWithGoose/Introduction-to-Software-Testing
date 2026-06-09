#include <stdio.h>
#include <ctype.h>
int main(void){
    char s1[1000],s[1000],op[1000],op2[1000];
    int num[1000],value,num2[1000];
    gets(s1); // @@ gets() is removed in the C11 standard and causes a compilation error; use fgets() instead.
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
    for(int i=0;i<q-1;i++){
        if((op[i]=='+')||(op[i]=='-')){
            op2[h]=op[i];
            h++;
            if((i==0)||(op[i-1]=='+')||(op[i-1]=='-')){ // @@ Logical error: fails to assign num[i] to num2[p] when the previous operator is '*' or '/', leaving num2[p] uninitialized.
                num2[p]=num[i];
            }
            p++;
        }
        if((op[i]=='*')||(op[i]=='/')){
            if((op[i-1]=='+')||(op[i-1]=='-')||(i==0)){ // @@ Accessing op[-1] when i=0 causes undefined behavior; check i==0 first to prevent out-of-bounds access.
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
        }else if(op[i]=='-'){ // @@ Typo: should be op2[i] to correctly check the stored operator for subtraction.
            sum-=num2[i+1];
        }
    }
    printf("%d",sum);
}