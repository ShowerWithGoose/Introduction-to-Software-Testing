#include <stdio.h>
char c[500],t[500],p[500];
int a[20]={0},b[5]={0};
int main()
{
    int i,j=0,k,m=0,x,y=0,sum=0,l=0,ji=1,jia=0,jian=0;
    gets(c);
    k=strlen(c);
    for(i=0;i<k;i++)
        {
            if(c[i]!=' '){t[j]=c[i];j++;}//t[]是保存无空格的公式char型数组，最后j将到达'='的地方
        if(c[i]=='+'||c[i]=='-'||c[i]=='/'||c[i]=='*'){p[l]=c[i];l++;}//p[]保存运算符号,l是运算符号出现的总次数
        }
    for(i=0;i<j;i++)//计算每个运算符号出现次数
    {
        if(t[i]=='+')b[0]++;
        if(t[i]=='-')b[1]++;
        if(t[i]=='*')b[2]++;
        if(t[i]=='/')b[3]++;
        if(t[i]=='=')break;
    }
    if(b[0]==0&&b[1]==0&&b[2]==0&&b[3]==0)
        for(i=0;i<j-1;i++)printf("%c",t[i]);//无运算符号时直接输出数字
    else
    {
        for(i=0;t[i]!='=';i++)//存储每个数
        {
            if(t[i]!='+'&&t[i]!='-'&&t[i]!='*'&&t[i]!='/')
            a[m]=a[m]*10+(int)t[i]-48;
            else m++;
        }
        for(i=0;i<l;i++)//开始进行运算,ji用来存储每个*和/得出的数据；
        {
            if(p[i]=='*'&&p[i+1]!='*'&&p[i-1]!='/'){ji=ji*a[i]*a[i+1];}
            if(p[i]=='*'&&p[i+1]!='*'&&p[i-1]=='/'){ji=ji*a[i+1];}
            if(p[i]=='*'&&p[i+1]=='*'&&p[i-1]!='/'){ji=ji*a[i];}

            if(p[i]=='/'&&p[i-1]!='*'&&p[i-1]!='/'){ji=ji*a[i]/a[i+1];}
            if(p[i]=='/'&&(p[i-1]=='*'||p[i-1]=='/')){ji=ji/a[i+1];}

            if((p[i]=='*'||p[i]=='/')&&p[i-1]=='+')jia=1;
            if((p[i]=='*'||p[i]=='/')&&p[i-1]=='-')jian=1;

            if((p[i]=='*'||p[i]=='/')&&p[i+1]!='*'&&p[i+1]!='/'&&jia==1){sum=sum+ji;ji=1;jia=0;continue;}
            if((p[i]=='*'||p[i]=='/')&&p[i+1]!='*'&&p[i+1]!='/'&&jian==1){sum=sum-ji;ji=1;jian=0;continue;}

            if(i==0&&(p[i]=='*'||p[i]=='/')&&p[i+1]!='*'&&p[i+1]!='/'){sum=sum+ji;ji=1;continue;}
            if(i==0&&(p[i]=='*'||p[i]=='/')){jia=1;continue;}

            if(i==0&&p[i]=='+'&&(p[i+1]=='+'||p[i+1]=='-')){sum=sum+a[0]+a[1];continue;}
            if(i==0&&p[i]=='-'&&(p[i+1]=='+'||p[i+1]=='-')){sum=sum+a[0]-a[1];continue;}

            if(i==0&&l==1&&p[i]=='+'){sum=sum+a[0]+a[1];break;}
            if(i==0&&l==1&&p[i]=='-'){sum=sum+a[0]-a[1];break;}

            if(i==0&&(p[i]=='+'||p[i]=='-')&&(p[i+1]=='*'||p[i+1]=='/')){sum=sum+a[0];continue;}

            if(p[i]=='+'&&p[i+1]!='*'&&p[i+1]!='/'){sum=sum+a[i+1];continue;}
            if(p[i]=='-'&&p[i+1]!='*'&&p[i+1]!='/'){sum=sum-a[i+1];continue;}
        }
        printf("%d",sum);//输出计算结果
    }
    return 0;
}

