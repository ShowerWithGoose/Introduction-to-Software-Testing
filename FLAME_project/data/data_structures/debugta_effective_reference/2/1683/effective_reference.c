#include<stdio.h>
#include<string.h>
int judge(char a){
    if(a<='9'&&a>='0') return 1;
    else return 0;
}
int cal(int a,int b,char w){
    switch (w)
    {
    case '+':
        return a+b;
    case '-':
        return a-b;
    case '*':
        return a*b;
    case '/':
        return a/b;
    default:
        return a;
    }
}
int main(){
    char str[8000]={},fuhao[2000]={};
    int answer=0,sum[5000]={},temp=0,count=0,w=0,m=0;
    gets(str);
    for(int i=0;i<strlen(str);i++){
        if(str[i]==' '){
            for(int count=i;count<strlen(str);count++){
                str[count]=str[count+1];
            }
            i--;
        }
    }
    for(int i=0;i<strlen(str);i++){
        if(!judge(str[i]))fuhao[count++]=str[i];
    }
    for(int i=0;i<strlen(str);i++){
        if(judge(str[i])){
            temp=10*temp+str[i]-'0';
        }
        else{
            sum[w++]=temp;
            temp=0;
        }
    }
    while(count>1){
        for(int i=0;i<count-1;i++){
            if(fuhao[i]=='*'||fuhao[i]=='/'){
                temp=cal(sum[i],sum[i+1],fuhao[i]);
                sum[i]=temp;
                for(int y=i+1;y<w;y++){
                    sum[y]=sum[y+1];
                }
                w--;
                for(int y=i;y<count;y++){
                    fuhao[y]=fuhao[y+1];
                }
                count--;
                i--;
            }
        }
        break;
    }
    while(count>1){
        temp=cal(sum[0],sum[1],fuhao[m++]);
        sum[0]=temp;
        for(int i=1;i<w;i++){
            sum[i]=sum[i+1];
        }
        w--;
        count--;
    }
    printf("%d",sum[0]);
    getchar();
}
