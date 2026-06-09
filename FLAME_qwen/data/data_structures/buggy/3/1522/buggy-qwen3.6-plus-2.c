#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void fenxi(char s[],char p[]);

int main()
{ char Shulie[200]={};
char ans[200]={};

gets(Shulie); // @@ gets is deprecated/removed in C11, causing compilation errors in modern environments; use fgets instead.
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
    for(a=0;s[a+1]!='\0';a++) // @@ Loop condition s[a+1]!='\0' skips processing the last character of the input string.
    {if(s[a]=='.')
    flag=1;

        if(flag==0)
        {zhengshu[b]=s[a];
        b=b+1;
        }
        if(flag==1)
        {xiaoshu[c]=s[a+1]; // @@ Incorrectly copies the character after the current index instead of the current character, corrupting the fractional part extraction.
        c=c+1;
        }
    }

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
p[5+ter]=cou%100+'0'; // @@ cou%100 can yield values >=10, adding '0' produces non-digit characters; should be cou%10.
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
}

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
}
a=strlen(s);
p[a]='e';
for(c=0;s[c]!='.';c++)
{cou++;
}
cou=cou-1;
if(cou/100!=0)
{p[1+a]=cou/100+'0';
p[2+a]=cou/10%10+'0';
p[3+a]=cou%100+'0'; // @@ Same error: cou%100 can be >=10, resulting in invalid ASCII characters instead of digits.
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
{p[a]=p[a+1]; // @@ Modifying the string while iterating forward causes character shifting to skip elements and fails to correctly remove the decimal point.
}
}
}