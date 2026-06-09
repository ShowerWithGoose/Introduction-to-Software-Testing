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
    for(int i=0;i<strlen(input);i++){
        if(input[i]!=' '&&input[i]!='\n'){
            res=res*10+input[i]-'0';
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
    for(int i=0;i<strlen(input2);i++){
        if(input2[i]!=' '&&input2[i]!='\n'){
            res=res*10+input2[i]-'0';
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
            str1[m].coef=str[i].coef*str2[j].coef;
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
        printf("%d %d ",str1[i].coef,str1[i].index); // @@ [Error: The program outputs all terms including those with zero coefficients after multiplication, but the problem expects only non-zero coefficient terms to be printed. Additionally, the program does not combine terms with the same exponent, leading to duplicate entries and incorrect coefficients. The expected output requires merging like terms (e.g., 150 10 and 210 10 should become 360 10).]
    }
    return 0;
}