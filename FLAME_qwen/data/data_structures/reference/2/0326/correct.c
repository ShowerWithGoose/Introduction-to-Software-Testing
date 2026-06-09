#include<stdio.h>
#include<string.h>
void skg(char c[])//删空格 
	{ int i=0,j=0;
	while(c[i]!='\0')
		{ if(c[i]==' ')
			{
			i++;
		continue;}
		c[j++]=c[i++];
		}
		c[j]='\0';
	}
	char s[205];
	int temp=0;
long long read()
{long long e=1;
long long a=0,b[20]={0};
int i=0,j;
while(1)
{ if(s[temp]<='9'&&s[temp]>='0')
b[i++]=s[temp++]-'0';
else
break;
}
for(j=i-1;j>=0;j--)
{ a=a+b[j]*e;
e=e*10;
}
return a;
}

int main()
{ gets(s);
skg(s);
long long sum=0,num=0,mid=0;
int mark=1;//标记加减 
num=read();
while(1)
{ if(s[temp]=='*')
	{ temp++;
	mid=read();
		  num*=mid;
	}
		else if(s[temp]=='/')
		{ temp++;
		mid=read();
		  num/=mid;
		}
			else if(s[temp]=='+')
			{ temp++;
			if(mark==1)
			sum=sum+num;
			else
			{sum=sum-num;
			
			}	
			mark=1;
			num=read();
			}
				else if(s[temp]=='-')
				{ temp++;
				if(mark==1)
				sum=sum+num;
				else
				{sum=sum-num;
				
				}
				mark=0;	
				
				num=read();
				}
					else
					{ if (mark == 1) {
    					sum += num;
   						} else
    						sum -= num;
   							break;
						}	
}
printf("%lld",sum);
return 0;
}

