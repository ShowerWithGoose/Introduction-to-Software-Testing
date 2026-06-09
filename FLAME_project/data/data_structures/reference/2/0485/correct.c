#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define pri printf

void outspace(char s[]) ;
long compu(int x,int y);
long change(int x,int y);
long ans(long num1,long mid,long num2);

char s[BUFSIZ];
char c[BUFSIZ]="+";
int main()
{
	long len,sum=0,temp=0;
	
	gets(s);
	outspace(s);
	strcat(c,s); 			//Æ´½Ó 
	
	len=strlen(c);
	
	//pri("%ld",len);			//test right
	
	for(int i=1,j=0;i<len;i++)
	{
		if((c[i]=='+')||(c[i]=='-')||(c[i]=='='))		//find '+' or '-'
		{
			temp=compu(j,i);		//compute it (j or i is '+' or '-' )
			//	pri("1 ");				//test right	
			sum=(c[j]=='+')?sum+temp:sum-temp;				//add sum
			j=i;
		//	pri("%ld",sum);					//test right
		}	
	}
	pri("%ld",sum);
	return 0;
}

void   outspace(char a[])
{
	int j=0;
	for(int i=0;a[i]!='\0';i++)
	{
		if(!isspace(a[i]))
			a[j++]=a[i];
		
	
	}
	a[j]='\0';
}

long compu(int x,int y)
{
	long num1=0,mid=0,num2=0,ans1,time=0,flag=0;

	for(int i=x+1;i<y;i++)
	{
		if((isdigit(c[i]))&&(!time))
		{
			num1=num1*10+(c[i]-'0');
			continue;
		}
		time++;
		
		if((c[i]=='*')||(c[i]=='/'))
		{
			flag++;
			mid=(c[i]=='*')?1:2;
			continue;
		}
		
		if(isdigit(c[i]))
		{
			num2=num2*10+(c[i]-'0');
		}
	
		
		
		if((!isdigit(c[i+1]))&&(flag))
		{
			flag=0;
			ans1=ans(num1,mid,num2);
					
			num1=ans1;
			num2=0;
		}
		
	}
	return num1;
}
long ans(long num1,long mid,long num2)
{
	long sum=0;
	
	sum=(mid==1)?num1*num2:num1/num2;
	
	return sum;
}
