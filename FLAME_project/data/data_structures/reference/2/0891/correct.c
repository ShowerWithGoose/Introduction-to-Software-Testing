#include<stdio.h>
#include<string.h>
int i,j,sum[1000],sign=1,k=0,flag=0,summ=0,t;
char s[1000];
int main(){
    gets(s);
    for(i=0,j=0;i<strlen(s);i++){
        if(s[i]!=' '){
            s[j]=s[i],j++;
        }
    }
    s[j]='\0';

    for(i=0;s[i]!='=';i++){
        if(s[i]=='+'){
            sign=1;
            k++;
            i++;
        }
        if(s[i]=='-'){
            sign=-1;
            k++;
            i++;
        }
        if(s[i]>='0'&&s[i]<='9'&&(s[i-1]=='+'||s[i-1]=='-'||i==0)){
            sum[k]=sign*(s[i]-48);
            for(int m=i+1;s[m]>='0'&&s[m]<='9';m++){
                if(s[m]=='0'){
                    sum[k]*=10;
                    i++;
                    continue;
                }
                sum[k]=sum[k]*10+s[m]-48,i++;
            }
        }
        if(s[i]=='*'){
            t=s[i+1]-48;
            for(int m=i+2;s[m]>='0'&&s[m]<='9';m++){
                i++;
                if(s[m]=='0'){
                    t*=10;
                    continue;
                }
            }
            sum[k]*=t,i++;
        }
        if(s[i]=='/'){
            t=s[i+1]-48;
            for(int m=i+2;s[m]>='0'&&s[m]<='9';m++){
                i++;
                if(s[m]=='0'){
                    t*=10;
                    continue;
                }
            }
            sum[k]/=t,i++;
        }
    }
    for(i=0;i<=k;i++)summ+=(sum[i]);
    printf("%d",summ);

}

