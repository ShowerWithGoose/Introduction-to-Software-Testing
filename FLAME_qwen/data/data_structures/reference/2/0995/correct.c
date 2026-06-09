#include <stdio.h>
#include <string.h>
#include <ctype.h>
void move_forw(char*,int);
void move_forwi(int*,int);
int main()
{
    char expr_o[1000],expr[1000],sign[1000];
    int num[1000];
    fgets(expr_o,1000,stdin);
    int i,j=0,k=0;
    for(i=0;expr_o[i];i++){
        if(expr_o[i]!=' '){
            expr[j++]=expr_o[i];
        }
    }
    int flag=0;
    for(i=0;i<1000;i++){
        num[i]=0;
    }
    for(i=0,j=0;expr[i];i++){
        if(expr[i]=='+'||expr[i]=='-'||expr[i]=='*'||expr[i]=='/'||expr[i]=='='){
            sign[j++]=expr[i];
            flag=1;
        }else{
            if(flag){
                k++;
                flag=0;
            }
            num[k]=num[k]*10+expr[i]-48;
        }
    }
    int num_n=j;
    num[++k]=-1;
    for(j=0;j<num_n;j++){
        if(sign[j]=='*'){
            num[j]=num[j]*num[j+1];
            move_forwi(num,j+2);
            move_forw(sign,j+1);
            j=-1;
        }else if(sign[j]=='/'){
            num[j]=num[j]/num[j+1];
            move_forwi(num,j+2);
            move_forw(sign,j+1);
            j=-1;
        }
    }//计算乘除法
    for(j=0;j<num_n;j++){
        if(sign[j]=='+'){
            num[j]=num[j]+num[j+1];
            move_forwi(num,j+2);
            move_forw(sign,j+1);
            j=-1;
        }else if(sign[j]=='-'){
            num[j]=num[j]-num[j+1];
            move_forwi(num,j+2);
            move_forw(sign,j+1);
            j=-1;
        }//计算加减法
    }
    printf("%d",num[0]);
    return 0;
}

void move_forw(char* s,int posi)
{
    int i;
    for(i=0;s[posi+i];i++){
        s[posi+i-1]=s[posi+i];
    }
    s[posi+i-1]='\0';
}
void move_forwi(int* s,int posi)
{
    int i;
    for(i=0;s[posi+i]!=-1;i++){
        s[posi+i-1]=s[posi+i];
    }
}
