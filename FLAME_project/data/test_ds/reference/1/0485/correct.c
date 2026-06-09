#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define pri printf

int  sta(int x);
void output(char a,char b);

char s[BUFSIZ];
int num[BUFSIZ]={0};

int main()
{	
	
	int len;
	
	scanf("%s",s);//input
	len=strlen(s);

	//output except last one
	for(int i=0;i<len ;i++)
	{
		if(s[i+1]!='-')//Dose '-' follow it?
		{
			pri("%c",s[i]);//output alph except last one 
			num[i]=1;
			continue;
		}
		
		if(sta(i))//Is the alph following '-'  right?
		{
			output(s[i],s[i+2]);	
			i+=1;	
		}
		else 
		{
			pri("%c%c%c",s[i],s[i+1],s[i+2]);
			num[i]=1;num[i+1]=1;num[i+2]=1;
			i+=2;
		}
	}
	
	//output last one
	
	if(!num[len-1])
	pri("%c",s[len-1]);
	
	return 0;
}

void output(char a,char b)
{
	int x,y;
	x=a;
	y=b;
	
	for(int i=0;i<y-x;i++)
	{
		pri("%c",x+i);
		num[x+i]=1;
	}
}

int  sta(int  x)
{
	if(islower(s[x]))
	{
		if((islower(s[x+2]))&&((s[x+2]-s[x])>0))//same type? and is bigger?
		return 1;
		else return 0;
	}
	else if (isupper(s[x]))
	{
		if((isupper(s[x+2]))&&((s[x+2]-s[x])>0))
				return 1;
				else return 0;
	}else 
	{
		if((isdigit(s[x+2]))&&((s[x+2]-s[x])>0))
				return 1;
				else return 0;
	}
}



