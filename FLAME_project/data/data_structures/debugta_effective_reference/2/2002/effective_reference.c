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
	char temp[205];
	int i=0;
long long read()
{long long e=1;
long long a=0,b[20]={0};
int i=0,j;
while(1)
{ if(temp[i]<='9'&&temp[i]>='0')
b[i++]=temp[i++]-'0';
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
{ gets(temp);
skg(temp);
long long jie_guo=0,number_before=0,number_after=0;
int op=1;//标记加减 
number_before=read();
while(1)
{ if(temp[i]=='*')
	{ i++;
	number_after=read();
		  number_before*=number_after;
	}
		else if(temp[i]=='/')
		{ i++;
		number_after=read();
		  number_before/=number_after;
		}
			else if(temp[i]=='+')
			{ i++;
			if(op==1)
			jie_guo=jie_guo+number_before;
			else
			{jie_guo=jie_guo-number_before;
			
			}	
			op=1;
			number_before=read();
			}
				else if(temp[i]=='-')
				{ i++;
				if(op==1)
				jie_guo=jie_guo+number_before;
				else
				{jie_guo=jie_guo-number_before;
				
				}
				op=0;	
				
				number_before=read();
				}
					else
					{ if (op == 1) {
    					jie_guo += number_before;
   						} else
    						jie_guo -= number_before;
   							break;
						}	
}
printf("%lld",jie_guo);
return 0;
}

