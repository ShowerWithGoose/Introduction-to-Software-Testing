#include <stdio.h>
#include <string.h>

int calculate(char ch[]){
char sign[10]={NULL};
int num[10]={0};
int signnum=0,ans=0;
for(int i=0;i<strlen(ch);i++){
    int j=0;
    if(ch[i]!='*'&&ch[i]!='/'){
        num[signnum]*=10;
        num[signnum]+=ch[i]-'0';
    }
    else{
        sign[signnum]=ch[i];
        signnum++;
    }
}
ans=num[0];
for(int i=0;i<signnum;i++){
    if(sign[i]=='*')
        ans*=num[i+1];
    else
        ans/=num[i+1];
}
return ans;
}
int main(){
char ch1[1000]={NULL},ch2[1000]={NULL},sign[10]={NULL};
char ch[10][100]={NULL};
int partnum=0,ans=0;
gets(ch1);
int j=0;
    for(int i=0;i<strlen(ch1);i++){
            if(ch1[i]!=' '&&ch1[i]!='='){
                ch2[j]=ch1[i];
                j++;
            }
    }//去除空格和等号
    int pos=0;
    for(int i=0;i<strlen(ch2);i++){

        if(ch2[i]!='+'&&ch2[i]!='-'){
            ch[partnum][pos]=ch2[i];
            pos++;
        }
        else{
            sign[partnum]=ch2[i];
            partnum++;
            pos=0;
        }
    }//给每个乘除等式分组，并记录加减符号
int partans[10]={0};
    for(int i=0;i<=partnum;i++){
        partans[i]=calculate(ch[i]);
    }//计算每个乘除项的值并存储
ans=partans[0];
    for(int i=0;i<partnum;i++){
        if(sign[i]=='+')
            ans+=partans[i+1];
        else
            ans-=partans[i+1];
    }
printf("%d",ans);
return 0;
}



