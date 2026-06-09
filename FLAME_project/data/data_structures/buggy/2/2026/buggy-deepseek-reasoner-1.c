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
    for(int i=0;i<q-1;i++){ // @@ Loop ends before processing the last number (num[q-1]), which should be added to the final sum. For the test case, the number 12000 is never included.
        if((op[i]=='+')||(op[i]=='-')){
            op2[h]=op[i];
            h++;
            if((i==0)||(op[i-1]=='+')||(op[i-1]=='-')){ // @@ Condition fails when the previous operator is '*' or '/', so the accumulated product from multiplication/division is not stored into num2[p]; the result of the term is lost.
                num2[p]=num[i]; // @@ Incorrect: should assign the accumulated value from the previous multiplication/division chain, not the original num[i].
            }
            p++; // @@ Incrementing p here without ensuring num2[p] is properly set leads to missing terms; after a '*' chain, the product remains at num2[p-1] and is not carried forward.
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