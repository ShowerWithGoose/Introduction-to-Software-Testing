#include<stdio.h>
#include<string.h>
int judge(char a){
    if(a<='9'&&a>='0') return 1;
    else return 0;
}
int cal(int a,int b,char t){
    switch (t)
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
    int answer=0,number[5000]={},temp=0,n=0,t=0,m=0;
    gets(str);
    for(int i=0;i<strlen(str);i++){
        if(str[i]==' '){
            for(int n=i;n<strlen(str);n++){
                str[n]=str[n+1];
            }
            i--;
        }
    }
    for(int i=0;i<strlen(str);i++){
        if(!judge(str[i]))fuhao[n++]=str[i];
    }
    for(int i=0;i<strlen(str);i++){
        if(judge(str[i])){
            temp=10*temp+str[i]-'0';
        }
        else{
            number[t++]=temp;
            temp=0;
        }
    }
    while(n>1){
        for(int i=0;i<n-1;i++){
            if(fuhao[i]=='*'||fuhao[i]=='/'){
                temp=cal(number[i],number[i+1],fuhao[i]);
                number[i]=temp;
                for(int y=i+1;y<t;y++){
                    number[y]=number[y+1];
                }
                t--;
                for(int y=i;y<n;y++){
                    fuhao[y]=fuhao[y+1];
                }
                n--;
                i--;
            }
        }
        break;
    }
    while(n>1){
        temp=cal(number[0],number[1],fuhao[m++]);
        number[0]=temp;
        for(int i=1;i<t;i++){
            number[i]=number[i+1];
        }
        t--;
        n--;
    }
    printf("%d",number[0]);
    getchar();
}
