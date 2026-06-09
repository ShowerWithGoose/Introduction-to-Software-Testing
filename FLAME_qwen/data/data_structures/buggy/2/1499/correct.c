#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int deletespace(char *s){
    for(int i=0;i<strlen(s); ){
        if(*(s+i)==' '){
            memmove(s+i,s+i+1,strlen(s)-i-1);
            *(s+strlen(s)-1)='\0';
        }else{
            i++;
        }
    }
}

int calculate(int a,int b,char c){
    if(c=='+'){
        return (a+b);
    }else if(c=='-'){
        return (a-b);
    }else if(c=='*'){
        return (a*b);
    }else if(c=='/'){
        return (a/b);
    }
}

int main(void){
    char s[1000];
    for(int i=0;i<1000;i++){
        s[i]=0;
    }
    gets(s);
    deletespace(s);
    int num1=0,num2=0,num3=0;
    char cnum2[10],cnum3[10];
    for(int i=0;i<10;i++){
        cnum2[i]=cnum3[i]=0;
    }
    char sign1='+',sign2=0,sign3=0;
    int j=0,a2=0,a3=0,flag=1;
    while(sign1!='='){
        while(1){
            if(s[j]=='+'||s[j]=='-'||s[j]=='*'||s[j]=='/'||s[j]=='='){
                sign2=s[j];
                j++;
                a2=0;
                num2=atoi(cnum2);
                break;
            }else{
                cnum2[a2]=s[j];
                a2++;
                j++;
            }
        }
        while(sign2=='*'||sign2=='/'){
            while(1){
                if(s[j]=='+'||s[j]=='-'||s[j]=='*'||s[j]=='/'||s[j]=='='){
                    sign3=s[j];
                    j++;
                    a3=0;
                    break;
                }else{
                    cnum3[a3]=s[j];
                    a3++;
                    j++;
                }
            }
            if(flag==1){
                num2=atoi(cnum2);
                flag=0;
            }
            num3=atoi(cnum3);
            for(int k=0;k<10;k++){
                cnum3[k]=0;
            }
            num2=calculate(num2,num3,sign2);
            sign2=sign3;
        }
        flag=1;
        num1=calculate(num1,num2,sign1);
        for(int k=0;k<10;k++){
            cnum2[k]=0;
        }
        sign1=sign2;
    }
    printf("%d",num1);
}

