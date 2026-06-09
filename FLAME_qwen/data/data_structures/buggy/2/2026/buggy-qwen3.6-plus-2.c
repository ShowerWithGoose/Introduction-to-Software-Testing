#include <stdio.h>
#include <ctype.h>
int main(void){
    char s1[1000],s[1000],op[1000],op2[1000];
    int num[1000],value,num2[1000];
    gets(s1); // @@ Compilation error: gets() is deprecated and removed in the C11 standard, causing compilation failure in modern environments. Use fgets() instead.
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
            if((i==0)||(op[i-1]=='+')||(op[i-1]=='-')){
                num2[p]=num[i];
            }
            p++;
        }
        if((op[i]=='*')||(op[i]=='/')){
            if((op[i-1]=='+')||(op[i-1]=='-')||(i==0)){
                if(op[i]=='*'){
                    num2[p]=num[i]*num[i+1]; // @@ Logical error: The index p is not incremented after storing the multiplication result, causing subsequent + or - operations to overwrite this value.
                }else{
                    num2[p]=num[i]/num[i+1]; // @@ Logical error: The index p is not incremented after storing the division result, leading to incorrect indexing and data overwriting.
                }
            }else{
                if(op[i]=='*'){
                    num2[p]=num2[p]*num[i+1]; // @@ Logical error: Accumulating results into num2[p] without incrementing p causes the value to be overwritten when the next + or - branch executes.
                }else{
                    num2[p]=num2[p]/num[i+1]; // @@ Logical error: Accumulating results into num2[p] without incrementing p causes the value to be overwritten when the next + or - branch executes.
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