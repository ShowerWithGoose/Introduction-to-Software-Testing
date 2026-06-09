#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
//#define m
char w[1000],h[1000];
int g,flag=0,i,t=0;
int main(){
   gets (w);
   int len_w=strlen(w);
   for(int i=0;i<len_w;i++)
   {
   	if(w[i]=='.')
	   {
	   g=i;	
	   }
	if(w[i]-'0'>=1&&w[i]-'0'<=9&&flag==0)
	{
	flag=1;
	i=i;	
	}
   }
   
   h[0]=w[i];
   if(i==len_w-1&&w[0]=='0'){putchar(h[0]);printf("e-%d",len_w-1-g);}
    if((g==1)&&(w[0]=='0')&&i!=(len_w-1)){
   	h[1]='.';putchar(h[0]);
   	putchar(h[1]);
   	for(int j=2;j<=len_w-i;j++)
   	{
	   	h[j]=w[i+j-1];putchar(h[j]);
	   }
	   printf("e-%d",i-g);
   }
   if(g>=1&&(w[0]!='0'))
   {
	 h[0]=w[0];
	 h[1]='.';
	 putchar(h[0]);
	 putchar(h[1]);
	 for(int i=2;i<=len_w-1;i++)
	 {
	 	if(w[i-1]=='.')
		 {
		 h[i]=w[i];
		 t=1;
		 		
		 }
	 	if(t==0)h[i]=w[i-1];
		else if(t==1)h[i]=w[i];
		putchar(h[i]);
	 }
	 printf("e%d",g-1);
   }
   
  
return 0;
}

