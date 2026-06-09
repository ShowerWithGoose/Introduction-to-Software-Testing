#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
//#define m
char s[1000],t[1000];
int k,flag=0,g,cnt=0;
int main(){
   gets (s);
   int n=strlen(s);
   for(int i=0;i<n;i++)
   {
   	if(s[i]=='.')
	   {
	   k=i;	
	   }
	if(s[i]-'0'>=1&&s[i]-'0'<=9&&flag==0)
	{
	flag=1;
	g=i;	
	}
   }
   
   t[0]=s[g];
   if(g==n-1&&s[0]=='0'){putchar(t[0]);printf("e-%d",n-1-k);}
    if((k==1)&&(s[0]=='0')&&g!=(n-1)){
   	t[1]='.';putchar(t[0]);
   	putchar(t[1]);
   	for(int j=2;j<=n-g;j++)
   	{
	   	t[j]=s[g+j-1];putchar(t[j]);
	   }
	   printf("e-%d",g-k);
   }
   if(k>=1&&(s[0]!='0'))
   {
	 t[0]=s[0];
	 t[1]='.';
	 putchar(t[0]);
	 putchar(t[1]);
	 for(int i=2;i<=n-1;i++)
	 {
	 	if(s[i-1]=='.')
		 {
		 t[i]=s[i];
		 cnt=1;
		 		
		 }
	 	if(cnt==0)t[i]=s[i-1];
		else if(cnt==1)t[i]=s[i];
		putchar(t[i]);
	 }
	 printf("e%d",k-1);
   }
   
  
return 0;
}

