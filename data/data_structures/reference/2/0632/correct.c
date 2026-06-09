#include<stdio.h>
char s[10005],b[10005];
int i,j,len,flag;
int as=1,bs=0;
int a[10005];
int main()
{
	gets(s);
	for(i=0,len=0;s[i]!='=';i++)
	 if(s[i]!=' ') s[len++]=s[i];
	s[len]='=';
	s[++len]='\0';
	
	//puts(s);
	
	
	
	for(i=0;s[i]!='+'&&s[i]!='-'&&s[i]!='/'&&s[i]!='*'&&s[i]!='=';i++)
	 {
	 	a[as]=a[as]*10+s[i]-'0';
	 }
	for(;s[i]!='\0';i++)
	 {
	 	if(!(s[i]>='0'&&s[i]<='9'))
	 	 {
	 	 	if(flag==1) 
			 {
			 	if(b[bs]=='*')
			 	 {
			 	 	a[as-1]=a[as-1]*a[as];
			 	 	a[as]=0;
			 	 	as--;
				  }
				else
				 {
				 	a[as-1]=a[as-1]/a[as];
				 	a[as]=0;
			 	 	as--;
				 }
				bs--;
			 	flag=0;
			 }
			
			
			b[++bs]=s[i];
			if(s[i]=='/'||s[i]=='*')  flag=1;
	 	 	as++;
		  }
	 	else
		 {
		 	
			a[as]=a[as]*10+s[i]-'0';
		  } 
		
		/*for(j=1;j<=bs;j++)
		 printf("%d%c",a[j],b[j]);
		printf("%c\n",a[as]);*/
	 }
	
	/*for(j=1;j<=bs;j++)
		 printf("%d%c",a[j],b[j]);
		printf("%c\n",a[as]);*/
	
	for(i=2;i<=as;i++)
	 if(b[i-1]=='+')  a[1]=a[1]+a[i];
	 else a[1]=a[1]-a[i];
	printf("%d",a[1]);
	return 0;
 } 

