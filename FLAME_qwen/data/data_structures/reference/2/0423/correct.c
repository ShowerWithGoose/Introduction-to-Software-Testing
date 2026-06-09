#include<stdio.h>
#include<string.h>

char s[1000];
char *find,*front,*last,*fingzero;
int num1,num2,ans;
int i,j;
char number[10];
char calculation;

void deblank(char string[]);
char *findrc(char *);
char *findc(char *);
char *findcplus(char *);
char *findcmultiple(char *);
void reverse(char *);
void mystrcpy(char *,char *);

int main()
{
	gets(s);
	while((find=strchr(s,' '))!=NULL)
	{
		deblank(s);	
	}
	
	while((find=findcmultiple(s))!=NULL)
	{
		calculation=*find;
		
		*find='\0';
		front=findrc(s);
		last=findc(find+1);
		
		do
		{
			num1=num1*10+(*(front+i)-'0');
			i++;
		}while(front+i<find)
			;//把*前面的一个数放到num1中
		do
		{
			num2=num2*10+(*(++find)-'0');
		}while(find<last)
			;//把*后面的一个数放到num2中
		
		if(calculation=='*') ans=num1*num2;//完成运算
		else ans=num1/num2;//完成运算
		
		num1=num2=i=0;//清零
		//先从低位到高位放进字符数组，然后逆转，再放入原来数组
		if(ans)
		{
			while(ans)
			{
				number[i++]=ans%10+'0';
				ans/=10;
			}
		}
		else
		{
			number[i++]='0';
		}
		reverse(number);
		mystrcpy(front,number);
		memset(number,'\0',10);
		//此时i记录了位数
		
		//再把原来的数组中间多余的清掉
		int a=strlen(last);//临时一个变量 为了让strlen(last)前后不发生变化
		memmove(front+i,last+1,a);
		*(front+i+a)='\0';
		i=0;//i清零
	}
	
	int subone,subnext;
	sscanf(s,"%d",&subone);
	find=s;
	while((find=findcplus(find+1))!=NULL)
	{
		sscanf(find,"%d",&subnext);
		subone+=subnext;
	}
	
	printf("%d",subone);
	return 0;
}

char *findrc(char *s)
{
	char *max=s,*tmp;
	if((tmp=strrchr(s,'+'))!=NULL)
	{
		if(tmp>max) max=tmp;
	}
	if((tmp=strrchr(s,'-'))!=NULL)
	{
		if(tmp>max) max=tmp;
	}
	if((tmp=strrchr(s,'*'))!=NULL)
	{
		if(tmp>max) max=tmp;
	}
	if((tmp=strrchr(s,'/'))!=NULL)
	{
		if(tmp>max) max=tmp;
	}
	
	//这里的意图就是
	//如果前面没找到字符，那就让它指向开头的数
	//如果找到了，就指向运算符后面一个
	//统一了之后方便后面的运算
	if(max==s) return max;
	return max+1;
}

char *findc(char *s)
{
	char *max=s+strlen(s)-1,*tmp;
	if((tmp=strchr(s,'+'))!=NULL)
	{
		if(tmp<max) max=tmp;
	}
	if((tmp=strchr(s,'-'))!=NULL)
	{
		if(tmp<max) max=tmp;
	}
	if((tmp=strchr(s,'*'))!=NULL)
	{
		if(tmp<max) max=tmp;
	}
	if((tmp=strchr(s,'/'))!=NULL)
	{
		if(tmp<max) max=tmp;
	}
	
	return max-1;
}

char *findcplus(char *s)
{
	char *max=NULL,*tmp;
	if((tmp=strchr(s,'+'))!=NULL)
	{
		if(max==NULL) max=tmp;
	}
	if((tmp=strchr(s,'-'))!=NULL)
	{
		if((max==NULL)||(tmp<max)) max=tmp;
	}
	
	return max;
}

char *findcmultiple(char *s)
{
	char *max=NULL,*tmp;
	if((tmp=strchr(s,'*'))!=NULL)
	{
		if(max==NULL) max=tmp;
	}
	if((tmp=strchr(s,'/'))!=NULL)
	{
		if((max==NULL)||(tmp<max)) max=tmp;
	}
	
	return max;
}

void deblank(char string[])
{
	char *p1=string;
	int flag=0;
	
	A:
	p1=strchr(p1+flag,' ');
	flag=1;
	
	if(p1!=NULL)
	{
		int length=strlen(p1+1);
		memmove(p1,p1+1,length);
		*(p1+length)=0;
		
		goto A;
	}
}

void reverse(char *string)
{
	char *first=string;
	char *last;
	char tmp;
	
	last=first+strlen(string)-1;
	
	while(first<last)
	{
		tmp=*first;
		*first=*last;
		*last=tmp;
		
		first++;
		last--;
	}
}

void mystrcpy(char *str1, char *str2)
{
	while(*str2)
	{
		*str1=*str2;
		str1++;
		str2++;
	}
}
