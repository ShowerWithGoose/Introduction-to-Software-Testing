#include<stdio.h>
#include<string.h>
int main(){
    char E1[10000],E2[10000],E3[10000];
    gets(E1);
    int len1=strlen(E1);
    int k=0;
    for (int i=0;i<len1;i++){
        if(E1[i]!=' '){
            E2[k]=E1[i];
            k++;
        }
    }
    E2[k]='\0';
    int len2=strlen(E2);
    int number[100]={0};
    char operation[100];
    int x=0,y=1;
    int z=0;
    for(int num=len2-1;num>=0;num--){
        if((E2[num]!='+')&&(E2[num]!='-')&&(E2[num]!='*')&&(E2[num]!='/')){
            number[x]=number[x]+(E2[num]-48)*y;
            y=y*10;
        }
        else{y=1;
            x=x+1;
            operation[z++]=E2[num];
        }
    }
    operation[z]='\0';
    int num2=0;
    int number2[100];
    for(int i=x;i>=0;i--){
        number2[num2]=number[i];
        num2++;
    }
    number2[num2]='\0'; // @@ [This line incorrectly treats number2 as a string by assigning '\0', but number2 is an int array. This doesn't cause runtime error but is logically wrong and unnecessary. However, the real critical error is in parsing multi-digit numbers from right to left without resetting `number[x]` properly when moving to a new number.]
    int ope=0;
    char operation2[100];
    for(int i=z-1;i>=0;i--){
        operation2[ope]=operation[i];
        ope++;
    }
    operation2[ope]='\0';
    for(int i=0;i<ope;i++){
        if(operation2[i]=='*'){
            number2[i+1]=number2[i]*number2[i+1]; // @@ [The logic here assumes that after processing operator at position i, the result is stored at i+1 and then shifts everything left. However, this approach fails when multiple operators of same precedence are adjacent because it modifies the array while iterating, and the index adjustment (i=i-1) may not correctly handle all cases, especially with more than two operands. More critically, the initial parsing of numbers is flawed.]
            for(int j=i;j<num2-1;j++){
                number2[j]=number2[j+1];
                operation2[j]=operation2[j+1];
            }
            num2=num2-1;
            ope=ope-1;
            i=i-1;
        }
        if(operation2[i]=='/'){
            number2[i+1]=number2[i]/number2[i+1]; // @@ [Same issue as multiplication: incorrect operand order and array shifting logic. Also, integer division is used correctly per problem, but the overall evaluation order is broken due to flawed parsing and reduction strategy.]
            for(int j=i;j<num2-1;j++){
                number2[j]=number2[j+1];
                operation2[j]=operation2[j+1];
            }
            num2=num2-1;
            ope=ope-1;
            i=i-1;
        }
        
    }
    int sum=number2[0];
    for(int i=0;i<ope;i++){
        if(operation2[i]=='+')sum=sum+number2[i+1];
        else sum=sum-number2[i+1]; // @@ [This assumes all remaining operations are + or -, which is correct after handling * and /, but because the earlier parsing and reduction is flawed, the operands are incorrect. The core issue originates from how numbers are parsed from right to left without initializing each number slot to 0 before accumulation.]
    }
    printf("%d",sum);
    
    return 0;    
}