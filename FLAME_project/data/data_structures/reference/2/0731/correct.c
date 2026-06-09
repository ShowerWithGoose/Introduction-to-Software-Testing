#include<stdio.h>

char in[10000];
int num[10000],nn;
char c[10000];
int ans,inter,inte;
void delblank(){
    int j=0;
    for(int i=0;in[i];i++){
        if(in[i]!=' ')in[j++]=in[i];
    }
    in[j]=0;
}
void getnumber(){
    int non=0;
    for(int i=0;in[i];i++){
        if(in[i]<='9'&&in[i]>='0'){
           num[non]+=in[i]-'0';
           if(in[i+1]<='9'&&in[i+1]>='0'){
               num[non]*=10;
           }else non++;
        }
    }
    nn=non;
}
void gettc(){
    c[0]='+';
    int j=0;
    for(int i=0;in[i];i++){
        if(in[i]=='+'||in[i]=='-'||in[i]=='*'||in[i]=='/'){
            c[++j]=in[i];
        }
    }
}
int main(void){
    gets(in);
    delblank();
    getnumber();
    gettc();
    for(int i=0;i<nn;i++){
        switch (c[i]){
            case '+':
                if(c[i+1]!='*'&&c[i+1]!='/'){
                    ans+=num[i];
                }
                break;
            case '-':
                if(c[i+1]!='*'&&c[i+1]!='/'){
                    ans-=num[i];
                }
                break;
            default:
                inter=(c[i-1]=='+'?1:-1);
                inte=num[i-1];
                while(c[i]!='+'&&c[i]!='-'&&i<nn){
                    if(c[i]=='*')inte*=num[i];
                    else inte/=num[i];
                    i++;
                }
                i--;
                if(inter==1)ans+=inte;
                else ans-=inte;
                break;
        }
    }
    printf("%d",ans);
    return 0;
}


