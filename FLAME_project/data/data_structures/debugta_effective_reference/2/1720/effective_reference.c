#include<stdio.h>
char c[100000];
int calc(int a,int b,char u){
    switch(u){
        case '+':{a+=b;break;}
        case '-':{a-=b;break;}
        case '*':{a*=b;break;}
        case '/':{a/=b;break;}
    }
    return a;
}
int main(){
    gets(c);
    int temp=0,sto=1,res=0;
    char sympre='+',d='*';
    for(int i=0;c[i]!='\0';i++){
        if(c[i]==' ') continue;
        if(c[i]<='9'&&c[i]>='0'){
            temp=temp*10+c[i]-'0';
        }
        else{
            sto=calc(sto,temp,d);
            d=c[i];
            if(c[i]=='+'||c[i]=='-'||c[i]=='='){
                res=calc(res,sto,sympre);
                sympre=c[i];
                sto=1,d='*';
            }
            temp=0;
        }
    }
    printf("%d\n",res);
    return 0;
}
