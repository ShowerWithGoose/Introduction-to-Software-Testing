#include<stdio.h>
#include<string.h>
#include<math.h>
int jisuan(int a,int b,char c)
{
    if(c=='*')
        return a*b;
    else if(c=='/')
        return (int)a/b;
    else if(c=='+')
        return a+b;
    else if(c=='-')
        return a-b;
}
int main(){
    int a[100000];
    int flag;
    int m=0,n=0;
    int x,y,c,d;
    x=y=c=d=0;
    char b[100000];
    char s[100000];
    gets(s);
    for(int i=0,j=0;i<=strlen(s);i++)
    {
        if(s[i]!=' ')
        {
            s[j]=s[i];
            j++;
        }
    }
    for(int i=0;i<=strlen(s);i++)
    {
        if(s[i]=='+')
            x++;
        else if(s[i]=='-')
            y++;
        else if(s[i]=='*')
            c++;
        else if(s[i]=='/')
            d++;
    }
    for(int i=0;i<strlen(s);i=i+flag)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            for(int k=1;k<100000;k++)
            {
                if(s[i+k]=='+'||s[i+k]=='-'||s[i+k]=='*'||s[i+k]=='/'||s[i+k]=='=')
                {
                    flag=k;
                    break;
                }
            }
            for(int y=0;y<flag;y++)
            {
            a[m]=a[m]*10+(s[i+y]-'0');
            }
            m++;
        }
        else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
        {
            b[n]=s[i];
            n++;
            flag=1;
        }
        if(s[i]=='=')
            break;
    }
  for(int o=d+c;o>0;o--)
 {
    for(int i=0;i<strlen(b);i++)
    {
       if(b[i]=='/'||b[i]=='*')
     {
        a[i]=jisuan(a[i],a[i+1],b[i]);
        for(int j=i;j<strlen(b);j++)
        {
            b[j]=b[j+1];
            a[j+1]=a[j+2];
        }
        break;
     }
   }
 }
  for(int o=x+y;o>0;o--)
 {
    for(int i=0;i<strlen(b);i++)
    {
       if(b[i]=='+'||b[i]=='-')
     {
        a[i]=jisuan(a[i],a[i+1],b[i]);
        for(int j=i;j<strlen(b);j++)
        {
            b[j]=b[j+1];
            a[j+1]=a[j+2];
        }
        break;
     }
   }
 }
   printf("%d",a[0]);
   return 0;
}

