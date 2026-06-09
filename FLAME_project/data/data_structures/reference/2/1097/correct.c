#include<stdio.h>
#include<string.h>
char s[10000];
int i=0,j=0,k=0;
int x,y,z;
void squeez(char s[],char c)
{
int i,j;
for(i=j=0;i<strlen(s);i++)
{
	if(s[i]!=c)s[j++]=s[i];

	}	
		s[j]='\0';
}

int main()

{
gets(s);
squeez(s,' ');
k=strlen(s);
int flag=0;
char fuhao1=' ',fuhao2=' ',fuhao3=' ';
for(i=0;i<k;i++)
{
	
	if(s[i]>='0'&&s[i]<='9')
	{
		if(flag==0)
		x=x*10+s[i]-'0';
		else if(flag==1) y=y*10+s[i]-'0'; 
		else if(flag==2) z=z*10+s[i]-'0';
	}
	else 
	{
	
		
if(fuhao1==' '){
flag=1;fuhao1=s[i];
if(fuhao1=='=')
{
	printf("%d",x);return 0;
}}
else if(flag==1){

 if(fuhao1=='*')
{
	x=x*y;y=0;
	fuhao1=s[i];
	if(fuhao1=='=')
	{
		printf("%d",x);
		return 0;
	}
}
else if(fuhao1=='/')
{x=x/y;y=0;
fuhao1=s[i];
	if(fuhao1=='=')
	{
		printf("%d",x);
		return 0;
	}
}

else if(fuhao1=='+'||fuhao1=='-'){
fuhao2=s[i];if(fuhao2=='+'||fuhao2=='-')
{
	if(fuhao1=='+')
{
	x=x+y;y=0;
	fuhao1=fuhao2;
	fuhao2=' ';
	flag=1;
}
else if(fuhao1=='-')
{

	x=x-y;y=0;
	fuhao1=fuhao2;
	fuhao2=' ';
	flag=1;

}
}else if (fuhao2=='*'||fuhao2=='/')flag=2;
else if(fuhao2=='='){	if(fuhao1=='+')
{
	x=x+y;y=0;
	fuhao1=fuhao2;
	fuhao2=' ';
	flag=1;
}
else if(fuhao1=='-')
{

	x=x-y;y=0;
	fuhao1=fuhao2;
	fuhao2=' ';
	flag=1;

}printf("%d",x);return 0;}
}}
else if(flag==2){
fuhao3=s[i];

if(fuhao2=='*')
{
	y=y*z;z=0;
	fuhao2=fuhao3;
	fuhao3=' ';
	
}
else if(fuhao2=='/')
{
	y=y/z;z=0;
		fuhao2=fuhao3;
	fuhao3=' ';
}
if(fuhao2=='+'||fuhao2=='-')
{
		if(fuhao1=='+')
{
	x=x+y;y=0;
	fuhao1=fuhao2;
	fuhao2=' ';
	flag=1;
}
else if(fuhao1=='-')
{

	x=x-y;y=0;
	fuhao1=fuhao2;
	fuhao2=' ';
	flag=1;

}

}
else if(fuhao2=='=')
{
	if(fuhao1=='+')
	{
		printf("%d",x+y);
		return 0;
	}
		else if(fuhao1=='-')
	{
		printf("%d",x-y);
		return 0;
	}
}





	}

}}return 0;}

