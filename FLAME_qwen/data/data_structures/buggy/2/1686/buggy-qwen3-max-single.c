#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
char s[99999999];int a[99999],n[99999];char b[99999],m[99999];
int main()
{int i,j,t,l,sum=0,temp,f=0;

gets(s); // @@ [Using gets() is unsafe and may cause buffer overflow; also, in some environments, gets() is removed from the standard library leading to compilation error]
for(i=0,j=0;s[i]!='\0';i++) 
if(s[i]!=' ')s[j++]=s[i];
s[j]='\0';//去空格 

/*for(i=0;i<=j;i++)
{printf("%c",s[i]);
}*/

j=0;
for(i=0;i<=strlen(s)-1;i++)
{if(s[i]<'0'||s[i]>'9') 
{b[j++]=s[i];}
else 
{while(s[i]>='0'&&s[i]<='9')
{a[j]=a[j]*10+s[i]-'0';i++;}
i--;
}
}l=j-1;

/*for(i=0;i<=l;i++)
printf("%d%c",a[i],b[i]);
printf("\n");//提数字与字符 */

j=0;t=0;
for(i=0;i<=l;i++)
{if (b[i]=='*'||b[i]=='/') 
   {n[j]=a[i];
      while(b[i]=='*'||b[i]=='/') 
     {if(b[i]=='*') n[j]=n[j]*a[i+1];
      else  n[j]=n[j]/a[i+1];
      i++;
     }
            i--;j++;
    }
    else  {m[t++]=b[i];n[j++]=a[i];}

}


/*for(i=0;i<=t-1;i++)
{printf("%d%c",n[i],m[i]);
 }printf("\n"); //进行乘除*/

sum=n[0];
for(i=0;i<t-1;i++)
{
if(m[i]=='+') sum=sum+n[i+1];
else sum=sum-n[i+1];
 } 
 printf("%d",sum);//计算和
  
return 0;
}