#include <stdio.h>
#include <memory.h>
int n;
int flag=0;
void f( int *via,int len,char *past)
{
	int i=1;
	int via1[10][10];
	char past1[10][30]={};
	int sum=0;
	while(i<=n)
	{
		 sum+=via[i-1];
		 i++;
	}
	if(sum==n)
	{
		 printf("%s",past);
		 puts("");
		 return ;
	}
	for(i=1;i<=n;i++)
	{    
		 if(!via[i-1])
		 {   	 
		 	 memcpy(via1[i-1],via,sizeof(int)*10);
		 	 via1[i-1][i-1]=1;
		 	 if(i<=9)
		 	 {
		 	 past1[i-1][len]=(char) (i+48);
		 	 past1[i-1][len+1]=' ';
		 }
		      else
		      {
		      	 past1[i-1][len]='1';
		      	 past1[i-1][len+1]='0';
		      	 past1[i-1][len+2]=' ';
			  }
		 	 memcpy(past1[i-1],past,len);
		 	if(i<=9) f(via1[i-1],len+2,past1[i-1]); else f(via1[i-1],len+3,past1[i-1]);
		 }
	}
}
int main()
{
	 scanf("%d",&n);
	 int i=1;
	 int via[10][10]={};
	 char past[10][30]={};
	 for(i=1;i<=n;i++)
	 {   
	 	 via[i-1][i-1]=1;
	 	 if(i<=9)
		  {
		  past[i-1][0]=(char)(i+48);
		  past[i-1][1]=' ';
		  f(via[i-1],2,past[i-1]);}
		  else  
		  {
		  	 past[i-1][0]='1';
		  	 past[i-1][1]='0';past[i-1][2]=' ';f(via[i-1],3,past[i-1]);
		  }
	 }
}


