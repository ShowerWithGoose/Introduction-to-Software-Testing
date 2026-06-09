#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void killblanks(char s[])   //清除空格
{
    char *p1=&s[0];
    char *p2=&s[0];
    while(*p1!='\0')
    {
        if(*p2!=' ')
            *p1++=*p2++;
        else
            *p2++;
    }
}

int main()
{
    int i,strlens,k=0,j=0,ans=0;
    char s[1000]="";
    gets(s);
    killblanks(s);
    strlens=strlen(s);
    int op[1000]={0};
    int num[1000]={0};
    for(i=0;i<=strlens-1;i++)
    {
        if(s[i]=='+'){op[k]=1;j++;k++;}
        else if(s[i]=='-'){op[k]=2;j++;k++;}
        else if(s[i]=='*'){op[k]=3;j++;k++;}
        else if(s[i]=='/'){op[k]=4;j++;k++;}
        else if(s[i]=='='){op[k]=-1;j++;k++;}
        else{num[j]=num[j]*10+(s[i]-'0');}
    }//此时已经提取出数字num[]与符号op[]

    for(i=0;op[i]!=-1;i++)
    {
        if(op[i]==3){num[i+1]=num[i]*num[i+1];num[i]=0;}
        else if(op[i]==4){num[i+1]=num[i]/num[i+1];num[i]=0;}
        else if(op[i]==2){num[i+1]=0-num[i+1];}
    }//此时已经算出乘除法

    for(i=0;i<=999;i++)
        ans=ans+num[i];
    printf("%d\n",ans);
    return 0;
}



