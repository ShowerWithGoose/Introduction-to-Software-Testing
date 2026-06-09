#include <stdio.h>
#include <string.h>
int main(){
char a[10000],b[10000],c[10000];
int d[1000];
gets(a);
int i,j,len=strlen(a);
for(i=0,j=0;i<len;i++)
{
    if(a[i]!=' '&&a[i]!='=')
        b[j++]=a[i];
}
b[j]='\0';

int t,k,q;
for(t=0,k=0,q=0;t<j;t++)
{
    int x=0,y=0;
while(b[t]!='+'&&b[t]!='-'&&t<j)
{
    while(b[t]!='*'&&b[t]!='/'&&b[t]!='+'&&b[t]!='-'&&t<j)
        {x=x*10+b[t]-'0';
    t++;
        }
        if(b[t]=='+'||b[t]=='-')
        {
            break;
        }
        int p=t+1;
            while(b[p]!='*'&&b[p]!='/'&&b[p]!='+'&&b[p]!='-'&&p<j)
        {y=y*10+b[p]-'0';
    p++;
        }
    if(b[t]=='*')
        x=x*y;
    else if(b[t]=='/')
        x=x/y;
    t=p;
    y=0;

}
d[q++]=x;
c[k++]=b[t];
}
c[k]='\0';



int m;

for(m=0;m<k-1;m++)
{
    if(c[m]=='+')
        d[m+1]=d[m]+d[m+1];
         if(c[m]=='-')
        d[m+1]=d[m]-d[m+1];


}
printf("%d",d[m]);



}



