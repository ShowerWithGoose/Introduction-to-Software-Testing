#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
char s[10000],n[10000],clt[10000];
int num1[10000],num2[10000];

int cal(int a,int b,char c){
    switch(c){
        case '+' :
            return a+b;
        case '-' :
            return a-b;
        case '*' :
            return a*b;
        case '/' :
            return a/b;
    }
}

int main()
{
    int i,j=0,k=0,m,n0=0,p=0;
    char c='0';
    gets(s);
    for(i=0;s[i]!='\0';i++){
        if(s[i]!=' '){
            n[j++]=s[i];
            if(n[j-1]<'0'||n[j-1]>'9')
                clt[n0++]=n[j-1];
        }
    }j=0;n0--;
    //去除空格

    for(i=0;n[i]!='\0';i++){
        if((n[i]>='0')&&(n[i]<='9'))
            num1[j++]=n[i]-'0';
        else{
            j--;num2[p]=0;
            for(m=j,k=0;m>=0;m--,k++){
                    num2[p] += num1[m] * pow(10,k);
            }p++;j=0;
        }

    }
    //数字转换

    for(i=0;clt[i]!='\0';i++){
        if(clt[i]=='=')
            printf("%d",num2[i]);
        else if((clt[i]!='*'&&clt[i]!='/'&&clt[i+1]!='*'&&clt[i+1]!='/')||((clt[i]=='*')||(clt[i]=='/'))){
            num2[i+1] = cal(num2[i],num2[i+1],clt[i]);
        }
        else{
            num2[i+2] = cal(num2[i+1],num2[i+2],clt[i+1]);
            num2[i+1] = num2[i];
            clt[i+1]=clt[i];
        }
    }
	return 0;
}

