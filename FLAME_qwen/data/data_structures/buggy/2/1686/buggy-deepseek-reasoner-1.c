#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
char s[99999999];int a[99999],n[99999];char b[99999],m[99999];
int main()
{int i,j,t,l,sum=0,temp,f=0;

gets(s);
for(i=0,j=0;s[i]!='\0';i++) 
if(s[i]!=' ')s[j++]=s[i];
s[j]='\0';//去空格 

/*for(i=0;i<=j;i++)
{printf("%c",s[i]);
}*/

j=0;
for(i=0;i<=strlen(s)-1;i++) // @@ 循环条件导致等号被当作运算符存入b数组，且可能访问越界（实际上不会越界，但等号被纳入后续处理）
{if(s[i]<'0'||s[i]>'9') 
{b[j++]=s[i];}
else 
{while(s[i]>='0'&&s[i]<='9')
{a[j]=a[j]*10+s[i]-'0';i++;}
i--;
}
}l=j-1; // @@ l包含了等号运算符的索引，导致后续循环错误处理等号

/*for(i=0;i<=l;i++)
printf("%d%c",a[i],b[i]);
printf("\n");//提数字与字符 */

j=0;t=0;
for(i=0;i<=l;i++) // @@ 循环范围包含等号，后续将等号当作运算符处理
{if (b[i]=='*'||b[i]=='/') 
   {n[j]=a[i]; // @@ 乘除处理中，n[j]初始化为左操作数，后续访问a[i+1]可能越界
      while(b[i]=='*'||b[i]=='/') // @@ 当连续乘除时，i可能增加到超出数组范围，造成越界
     {if(b[i]=='*') n[j]=n[j]*a[i+1];
      else  n[j]=n[j]/a[i+1];
      i++;
     }
            i--;j++; // @@ while循环后i--逻辑错误，导致索引混乱
    }
    else  {m[t++]=b[i];n[j++]=a[i];} // @@ 只存储左操作数，遗漏右操作数，且对于等号也存储

}


/*for(i=0;i<=t-1;i++)
{printf("%d%c",n[i],m[i]);
 }printf("\n"); //进行乘除*/

sum=n[0];
for(i=0;i<t-1;i++) // @@ 循环条件错误，导致最后一个操作数未被使用，且t可能因等号而包含多余项
{
if(m[i]=='+') sum=sum+n[i+1];
else sum=sum-n[i+1];
 } 
 printf("%d",sum);//计算和
  
return 0;
}