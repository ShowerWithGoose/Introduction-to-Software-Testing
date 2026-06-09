#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct multi
{
    int coef;
    int index;
};
char input[1000],input2[1000];
int main(){
    int res=0;
    struct multi str[1000],str1[1000],str2[1000];
    fgets(input,1000,stdin);
    int flag=0,num=0,num2=0;
    for(int i=0;i<strlen(input);i++){ // @@ Declaring loop variable inside for loop is not supported in C89/C90, which may cause a compilation error on strict compilers.
        if(input[i]!=' '&&input[i]!='\n'){
            res=res*10+input[i]-'0'; // @@ Does not handle negative coefficients; will produce incorrect values or fail if the input contains negative numbers.
        }
        else{
            if(flag==0){
                str[num].coef=res;
                flag=1;
            }
            else{
                str[num].index=res;
                num++;
                flag=0;
            }
            res=0;
        }
    }
    fgets(input2,1000,stdin);
    res=0;flag=0;
    for(int i=0;i<strlen(input2);i++){ // @@ Declaring loop variable inside for loop is not supported in C89/C90, which may cause a compilation error on strict compilers.
        if(input2[i]!=' '&&input2[i]!='\n'){
            res=res*10+input2[i]-'0'; // @@ Does not handle negative coefficients; will produce incorrect values or fail if the input contains negative numbers.
        }
        else{
            if(flag==0){
                str2[num2].coef=res;
                flag=1;
            }
            else{
                str2[num2].index=res;
                num2++;
                flag=0;
            }
            res=0;
        }
    }
    int m=0;
    for(int i=0;i<num;i++){
        for(int j=0;j<num2;j++){
            str1[m].coef=str[i].coef*str2[j].coef; // @@ Fails to combine like terms (terms with the same exponent) during multiplication. Also, m can easily exceed the array size of 1000, causing a buffer overflow.
            str1[m].index=str[i].index+str2[j].index;
            m++;
        }
    }
    int temp=0,ans=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<m-1;j++){
             if(str1[j].index<str1[j+1].index){
                   ans=str1[j].coef;
                   str1[j].coef=str1[j+1].coef;
                   str1[j+1].coef=ans;
                   temp=str1[j].index;
                   str1[j].index=str1[j+1].index;
                   str1[j+1].index=temp; 
             }
        }
    }
    for(int i=0;i<m;i++){
        printf("%d %d ",str1[i].coef,str1[i].index); // @@ Outputs duplicate terms instead of summing coefficients for identical exponents, violating the standard polynomial output format.
    }
    return 0;
}