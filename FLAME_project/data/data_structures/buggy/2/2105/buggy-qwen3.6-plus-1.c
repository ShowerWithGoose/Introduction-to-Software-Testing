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
    number2[num2]='\0';
    int ope=0;
    char operation2[100];
    for(int i=z-1;i>=0;i--){
        operation2[ope]=operation[i];
        ope++;
    }
    operation2[ope]='\0';
    for(int i=0;i<ope;i++){
        if(operation2[i]=='*'){
            number2[i+1]=number2[i]*number2[i+1]; // @@ The result of the multiplication should be stored in number2[i] (the left operand's position) to correctly collapse the array, not number2[i+1]. Storing in i+1 leaves the original left operand at i, which corrupts subsequent calculations.
            for(int j=i;j<num2-1;j++){
                number2[j]=number2[j+1];
                operation2[j]=operation2[j+1];
            }
            num2=num2-1;
            ope=ope-1;
            i=i-1;
        }
        if(operation2[i]=='/'){
            number2[i+1]=number2[i]/number2[i+1]; // @@ Similarly, the result of the division should be stored in number2[i]. Storing in number2[i+1] is incorrect for the same reason as above.
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
        else sum=sum-number2[i+1];
    }
    printf("%d",sum);
    
    return 0;    
}