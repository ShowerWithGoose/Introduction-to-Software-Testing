#include <stdio.h>
#include <ctype.h>
#include <string.h>
	 char s[200];
	 int len;
char get_op(int now)
{
	 while(isdigit(s[now-1])&&now<=len)
	 {
	 	now++;
	 }
	 return s[now-1];
}
int update1(int now)
{
	 while(isdigit(s[now-1]))
	 {
	 	 now++;
	 }
	 return now+1;
}
int update2(int now)
{
	  while(s[now-1]!='+'&&s[now-1]!='-'&&now<=len)
	  {
	  	now++;
	  }
	  return now;
}
int get_num(int now)
{
	 int n;
	 sscanf(s+now-1,"%d",&n);
	 char op;
	 char c;
     while( (c=get_op(now))!='+'&& (c=get_op(now))!='-'&&(c=get_op(now))!=0 )
     {      
     	      now=update1(now);
     	      if(now>len) break;
     	      int num;
			  sscanf(s+now-1,"%d",&num);
			  if(c=='*')   n*=num;
			  else     n/=num;
	 }
	 return n;
}
int main()
{
	 gets(s);
	 int i,j;
	 len=strlen(s);
	 for(i=1,j=1;i<len;i++)
	 {
	 	  if(!isspace(s[i-1]))
	 	  {
	 	  	 s[(j++)-1]=s[i-1];
		   }
	 }
	 s[j-1]=0;
	 len=strlen(s);
	 int now=1;
	 int flag=0,flag1;
	 int sum=0;
	 int n;
	 while(now<=len)
	 {      
	 	    if(!flag)
	 	    {
	 	    	 sum+=get_num(now);
	 	    	 flag++;
			 }
			 else
			 {
			 	  sum+=get_num(now)*flag1;
			 }
			 now=update2(now);
			 if(now>len) break;
			 char op=s[now-1];
			 if(op=='+')  flag1=1;
			 else   flag1=-1;
			 now++;
	 }
	 printf("%d",sum);
 } 

