#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void fenxi(char s[],char p[]);

int main()
{ char Shulie[200]={};
char ans[200]={};

gets(Shulie);

fenxi(Shulie,ans);
puts(ans);
return 0;
}

void fenxi(char s[],char p[])
{char zhengshu[200]={};
char xiaoshu[200]={};

int a,b=0,c=0,d=0,e=0,f=0;
int flag=0;
int cou=0;
int ter=0;
    for(a=0;s[a+1]!='\0';a++)
    {if(s[a]=='.')
    flag=1;
    
        if(flag==0)
        {zhengshu[b]=s[a];
        b=b+1;
        }
        if(flag==1)
        {xiaoshu[c]=s[a+1];
        c=c+1;
        }
    }@@ // The loop stops at s[a+1] != '\0', so the last character of input (e.g., '9' in "0.9") is never processed into xiaoshu.

d=strlen(zhengshu)+1;
    if(flag==0)
    {s[d]='.';
    s[d+1]='\0';
     } 
if(d!=2)
 d=d-1;
if(d==1)
{if(zhengshu[0]=='0')
 flag=2;
 else
  flag=3;
}
else
 flag=4;

 if(flag==2)
 {for(e=0;s[e]!='\0';e++)
  {
  if(s[e]=='0' && flag==2)
  {cou++;
  }
  if(flag==0)
  {p[1+ter]=s[e];
  ter++;
  }
  
  if(s[e]!='0' && s[e]!='.' && flag==2)
  {flag=0;
  p[0]=s[e];
  p[1]='.';
  ter++;
  }
 }
 p[1+ter]='e';
 p[2+ter]='-';
if(cou/100!=0)
{p[3+ter]=cou/100+'0';
p[4+ter]=cou/10%10+'0';
p[5+ter]=cou%100+'0';@@ // Incorrect: should be cou%10, not cou%100.
p[6+ter]='\0';
}
else if(cou/10!=0)
{p[3+ter]=cou/10+'0';
p[4+ter]=cou%10+'0';
p[5+ter]='\0';
}
else
{p[3+ter]=cou+'0';
p[4+ter]='\0';
}
}

if(flag==3)
{for(a=0;s[a]!='\0';a++)
{p[a]=s[a];
b=a;
}
p[b+1]='e';
p[b+2]='0';
p[b+3]='\0';
}@@ // This produces "0.9e0" for input "0.9", but expected is "9e-1". The logic for numbers < 1 starting with 0 is handled in flag==2, but due to earlier loop bug, it may not trigger correctly.

if(flag==4)
{d=strlen(s)-1;
a=2;
b=2;
p[0]=s[0];
p[1]='.';
while(d--)
{if(s[a-1]!='.')
{p[b]=s[a-1];
b++;
}
a++;
}@@ // This loop incorrectly copies digits; it uses a-1 and decrements d, leading to wrong digit order or missing digits.
a=strlen(s);
p[a]='e';
for(c=0;s[c]!='.';c++)
{cou++;
}
cou=cou-1;
if(cou/100!=0)
{p[1+a]=cou/100+'0';
p[2+a]=cou/10%10+'0';
p[3+a]=cou%100+'0';@@ // Again, should be cou%10.
p[4+a]='\0';
}
else if(cou/10!=0)
{p[1+a]=cou/10+'0';
p[2+a]=cou%10+'0';
p[3+a]='\0';
}
else
{p[1+a]=cou+'0';
p[2+a]='\0';
}
}

for(a=0;p[a]!='\0';a++)
{if(p[a]=='.' && p[a+1]=='e')
{flag=5;
}
if(flag==5 &&p[a]!='\0')
{p[a]=p[a+1];
}@@ // This attempts to remove trailing '.' before 'e', but doesn't properly shift all subsequent characters and doesn't null-terminate correctly. Also, it runs even when flag!=5 was set earlier, causing corruption.
}
}