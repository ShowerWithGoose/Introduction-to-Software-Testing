//开始 
#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{ char s[105];
gets(s);
int a,b,i,m,n;//b是指数 
a=strlen(s)-1;
	for(i=0;i<=a;i++)
{ if(s[i]=='.')
n=i;}
	for(i=0;i<=a;i++)
 {
 if(s[i]!='0'&&s[i]!='.')
 { m=i;
 break;
 }
 }//m标记第一个不为零的数，n标记小数点 
 
 if(m<n)//
 { b=n-m-1;
	printf("%c.",s[m]);
	for(i=m+1;i<=a;i++)
		{ 	if(s[i]!='.')
		printf("%c",s[i]);
		
		}
 printf("e%d",b);
 }
 else//看底数是不是整数 
 { 
 b=m-n;
 if(m==a)//当底数为整数 
   printf("%ce-%d",s[a],b);
   else//底数不为整数 
   {printf("%c.",s[m]);
   for(i=m+1;i<=a;i++)
		{ 	if(s[i]!='.')
		printf("%c",s[i]);
		}
 printf("e-%d",b);}
 }

 
 return 0;
}


