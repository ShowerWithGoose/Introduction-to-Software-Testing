#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void fun(char *str)
{
	char *str_c=str;
	int i,j=0;
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]!=' ')
			str_c[j++]=str[i];
	}
	str_c[j]='\0';
	str=str_c;	
}
int ji(int a,int b,char c)
{
	int z;
	switch(c)
	{
		case'+':z=a+b;break;
		case'-':z=a-b;break;
		case'*':z=a*b;break;
		case'/':z=a/b;break;}

	
	return z;
	}
int suan(char s[])
{
	char q[9999];
	int e[9999];
	int i,n,k=0;
	int m,a1,a2;
	char op,b1;
	n=strlen(s);
	fun(s);
	for(i=0;i<=n;i++)
	{
		if((s[i]=='+')||(s[i]=='-')||(s[i]=='*')||(s[i]=='/')||(s[i]=='=')){
			q[k]=s[i];
			k++;
		}
	}
 int count=0;
 int num=0; 
for(i=0;i<strlen(s);i++){ 
  	if(s[i]>47&&s[i]<58){   
   		num=num*10+s[i]-48;
  	}else{
  	 	if((s[i-1]=='0')||num!=0){
    			e[count++]=num;
    			num=0;
   		}

 	}
 }

	q[k]='\0';
	k=0;
	i=0;
	a1=e[0];
	b1=q[0];
	if(b1!='=')
		a2=e[1];
	while(b1!='=')
	{
		if(b1=='*'||b1=='/')
		{
			a1=ji(a1,a2,b1);
			b1=q[i+1];
			
			if(b1!='=')
				a2=e[i+2];
			
		}
		else
		{
		op=q[i+1];
		if(op == '+' || op == '-' || op == '=')
		{
			a1=ji(a1,a2,b1);
			b1=op;
			e[i+1]=a1;

			if(op!='=')
				a2=e[i+2];
		}
		else if(op!='=')
		{
			m=e[i+2];
			a2=ji(a2,m,op);
		}
		else
			b1=op;
		}
		i++;
	}
	return a1;
}
int main()
{
	char a[9999];
	int x,z;
	gets(a);
	fun(a);
	z=suan(a);
	printf("%d",z);
	return 0;
	
	}



