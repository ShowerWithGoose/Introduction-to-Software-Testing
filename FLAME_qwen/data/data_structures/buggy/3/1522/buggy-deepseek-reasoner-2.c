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
    for(a=0;s[a+1]!='\0';a++) // @@ Loop stops one character early, missing last digit of input.
    {if(s[a]=='.')
    flag=1;
    
        if(flag==0)
        {zhengshu[b]=s[a];
        b=b+1;
        }
        if(flag==1)
        {xiaoshu[c]=s[a+1]; // @@ Reads ahead without proper indexing, likely misaligns decimal part.
        c=c+1;
        }
    }

d=strlen(zhengshu)+1; // @@ Incorrect length used for subsequent modifications.
    if(flag==0)
    {s[d]='.'; // @@ Modifies input string unnecessarily and index d may be wrong.
    s[d+1]='\0'; // @@ Same issue.
     } 
if(d!=2)
 d=d-1; // @@ Unclear logic, corrupts d.
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
  if(s[e]=='0' && flag==2) // @@ Counting zeros incorrectly; should count zeros after decimal before first non-zero.
  {cou++;
  }
  if(flag==0)
  {p[1+ter]=s[e];
  ter++;
  }
  
  if(s[e]!='0' && s[e]!='.' && flag==2) // @@ Changes flag inside loop, but later iterations use flag==0 incorrectly.
  {flag=0;
  p[0]=s[e];
  p[1]='.';
  ter++;
  }
 }
 p[1+ter]='e'; // @@ Index ter may not be correct after loop.
 p[2+ter]='-'; // @@ Possibly wrong for negative exponent.
if(cou/100!=0)
{p[3+ter]=cou/100+'0';
p[4+ter]=cou/10%10+'0';
p[5+ter]=cou%100+'0';
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
{for(a=0;s[a]!='\0';a++) // @@ Overwrites a used later; also copies entire string including decimal if present.
{p[a]=s[a];
b=a;
}
p[b+1]='e'; // @@ b is last index from loop, but if s had decimal, p will contain decimal then 'e0', incorrect.
p[b+2]='0';
p[b+3]='\0';
}

if(flag==4)
{d=strlen(s)-1; // @@ d set to length-1, used as loop counter, but loop logic is flawed.
a=2; // @@ Magic number, should start from 1 or other.
b=2; // @@ Should start from 2 after setting p[0] and p[1].
p[0]=s[0];
p[1]='.';
while(d--) // @@ Incorrect loop bounds; also d is modified.
{if(s[a-1]!='.') // @@ Accesses s[a-1] but a increments each iteration, may go out of bounds.
{p[b]=s[a-1]; // @@ Copies digits from s that include integer part and decimal part, resulting in extra digits.
b++;
}
a++;
}
a=strlen(s); // @@ Overwrites a but should use proper index for placing 'e'.
p[a]='e'; // @@ a is length of s, not the current length of p.
for(c=0;s[c]!='.';c++) // @@ This loop may run forever if no decimal point (but flag==4 implies there is a decimal?).
{cou++;
}
cou=cou-1;
if(cou/100!=0)
{p[1+a]=cou/100+'0'; // @@ Writing at p[1+a] may overwrite previous data because p may already have content beyond a.
p[2+a]=cou/10%10+'0';
p[3+a]=cou%100+'0';
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
{if(p[a]=='.' && p[a+1]=='e') // @@ Checks for '.' followed by 'e' to remove dot, but may remove incorrectly if exponent digits include 'e'.
{flag=5;
}
if(flag==5 &&p[a]!='\0') // @@ Shifts characters left, but does not handle null termination properly and may cause overlapping.
{p[a]=p[a+1];
}
}
}