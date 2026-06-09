#include<stdio.h>
#include<string.h>
int main()
{char a[10000]="\0",b[10000]="\0",c[10000]="\0",f[10000]="\0";
int d[10000]={0},e[10000]={0};
gets(a);
int i=0,m=0,p=0,t=0,flag=0,cnt=0,x=0;
for(i=0;a[i]!='\0';i++)
{if(a[i]!=' ')
{b[m]=a[i];
m++;
}
 } 
 for(m=0;b[m]!='\0';m++)
 {if(b[m]=='+'||b[m]=='-'||b[m]=='*'||b[m]=='/'||b[m]=='=')
 {c[p]=b[m];
 p++;
 }
 }
 for(m=0;b[m]!='=';m++)
 {flag=0;
 while(b[m]>='0'&&b[m]<='9')
 {d[t]=d[t]*10+(b[m]-'0');
 m++;
 flag=1;
 }
 if(flag==1)
 t++;
 }
 for(i=0,p=0;c[i]!='\0';i++)
 {if(c[i]=='+'||c[i]=='-'||c[i]=='=')
 {e[p]=d[i];
 p++;
 }
 else if(c[i]=='*'||c[i]=='/')
 { x=d[i];
 while(c[i]=='*'||c[i]=='/')
 {if(c[i]=='*')
 x=x*d[i+1];
 else
 x=x/d[i+1];
 i++;
 }
 e[p]=x;
 p++;
 }
  } 
  for(i=0,m=0;c[i]!='\0';i++)
  {if(c[i]=='+'||c[i]=='-'||c[i]=='=')
  {f[m]=c[i];
  m++;
  }
  }
  cnt=e[0];
  for(i=1;f[i]!='\0';i++)
  {if(f[i-1]=='+')
  cnt+=e[i];
  else if(f[i-1]=='-')
  cnt-=e[i];
  }
  printf("%d",cnt);
    return 0;
}

