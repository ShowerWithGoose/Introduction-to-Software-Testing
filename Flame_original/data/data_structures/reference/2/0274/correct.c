#include<stdio.h>
#include<ctype.h>
#include<string.h>
char s0[1111],s[1111];
int main(){
    int a=0,b=0,i[111][2],sum=0,n=1,k,x,y=0,z=2,flag=0;
    gets(s0);
    for(a=0;a<strlen(s0);a++)
        if(isdigit(s0[a])||s0[a]=='='||s0[a]=='+'||s0[a]=='-'||s0[a]=='*'||s0[a]=='/')
            s[b]=s0[a],b++;
    s[b]='\0';
    if(s[0]=='-')
        i[0][0]=1,i[0][1]=-1;
    else
        i[0][0]=0,i[0][1]=1;
    for(a=i[0][0];a<b;a++){
        if(s[a]=='+')
            i[n][0]=a+1,i[n][1]=1,n++;
        if(s[a]=='-')
            i[n][0]=a+1,i[n][1]=-1,n++;
    }
    i[n][0]=b,i[n][1]=1;
    for(a=0;a<n;a++){
        x=1,z=2;
        for(k=i[a][0];k<=i[a+1][0]-1;k++){
            if(isdigit(s[k])){
                y=y*10+s[k]-'0';
                if(y==0){
                    x=0;
                    break;
                }
            }
            if(!isdigit(s[k])) flag=1;
            if(y!=0&&flag==1){
                if(z==2) x*=y;
                if(z==-2) x/=y;
                flag=0,y=0;
            }
            if(s[k]=='*') z=2;
            if(s[k]=='/') z=-2;
        }
        sum+=i[a][1]*x;
    }
    printf("%d",sum);
    return 0;
}
