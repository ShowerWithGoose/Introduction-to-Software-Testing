#include<stdio.h> 
#include<string.h>
int top1;
int top2;
void signpush(char sign[],char newer)
{
	if(top1==299)
	{
		printf("error1 ");
		return;
	}
	top1++;
	sign[top1]=newer;
}
void signout()
{
	if(top1==-1)
	{
		printf("error2 ");
		return;
	}
	top1--;
	return;
}
void numpush(int num[],int fresher)
{
	if(top2==299)
	{
		printf("error3 ");
		return;
	}
	top2++;
	num[top2]=fresher;
}
int numout(int num[])
{
	int k;
	if(top2==-1)
	{
		printf("error4 ");
		return -1;
	}
	k=top2;
	top2--;
	return num[k];
}
int transform(char a[],int k)
{
	int i;
	int num=0;
	for(i=k;a[i]>='0'&&a[i]<='9';i++)
	{
		num=num*10+a[i]-'0';
	}
	return num;
} 
int main()
{
	char str[505];
	char a;
	int k=0;
	char expre[505];
	char sign[305];
	int i;
	int readlevel,toplevel;
	int num[505];
	int lnum,rnum;
	int tmp;
	top1=-1;
	top2=-1;
	while((a=getchar())!='=')
	{
		if(a!=' ')
		{
			str[k]=a;
			//printf("%c\n",str[k]);
			k++;
		}
	}
	str[k]='\0';
	//printf("%s\n",str);
	k=0;
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]==' ')
		{
			continue;
		}
		if(str[i]>='0'&&str[i]<='9')
		{
			for(;str[i]>='0'&&str[i]<='9';i++)
			{
				expre[k]=str[i];
				k++;
			}
			expre[k]=' ';
			k++;
			i--;
			continue;
		}
		if(top1==-1)
		{
			if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'||str[i]=='(')
			{
				signpush(sign,str[i]);
				continue;
			}
		}
		if(str[i]==')')
		{
			while(sign[top1]!='(')
			{
				expre[k]=sign[top1];
				k++;
				signout();
			}
			signout();
			continue;
		}
		if(str[i]=='(')
		{
			signpush(sign,str[i]);
			continue;
		}
		if(sign[top1]=='(')
		{
			signpush(sign,str[i]);
			continue;
		}
		if(str[i]=='+'||str[i]=='-')
		{
			readlevel=1;
		}
		if(str[i]=='*'||str[i]=='/')
		{
			readlevel=2;
		}
		if(sign[top1]=='+'||sign[top1]=='-')
		{
			toplevel=1;
		}
		if(sign[top1]=='*'||sign[top1]=='/')
		{
			toplevel=2;
		}
		if(readlevel>toplevel)
		{
			signpush(sign,str[i]);
			continue;
		}
		else
		{
			while(readlevel<=toplevel&&top1!=-1)
			{
				expre[k]=sign[top1];
				k++;
				signout();
				if(top1!=-1)
				{
					switch(sign[top1])
					{
						case '+':
						case '-':
						{
							toplevel=1;
							break;
						}
						case '*':
						case '/':
						{
							toplevel=2;
							break;		
						}	
						case '(':
						{
							toplevel=0;
							break;
						}
						default:
						break;	
					}
				}
			}
			signpush(sign,str[i]);
		}
	}
	while(top1!=-1)
	{
		expre[k]=sign[top1];
		k++;
		signout();
	}
	expre[k]='\0';
	//printf("%s\n",expre);
	for(i=0;expre[i]!='\0';i++)
	{
		if(expre[i]>='0'&&expre[i]<='9')
		{
			numpush(num,transform(expre,i));
			while(expre[i]>='0'&&expre[i]<='9')
			{
				i++;
			}
			continue;
		}
		switch(expre[i])
		{
			case '+':
			case '-':
			case '*':
			case '/':
			{
				rnum=numout(num);
				lnum=numout(num);
				if(expre[i]=='+')
				{
					tmp=lnum+rnum;
				}
				else if(expre[i]=='-')
				{
					tmp=lnum-rnum;
				}
				else if(expre[i]=='*')
				{
					tmp=lnum*rnum;
				}
				else if(expre[i]=='/')
				{
					tmp=lnum/rnum;
				}
				numpush(num,tmp);
				break;
			}
			default:
			break;
		}
	}
	if(top2==0)
	{
		printf("%d",num[top2]);
	}
	else
	{
		printf("wrong!");
	}
	return 0;
}

