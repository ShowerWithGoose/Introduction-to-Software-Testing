#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#define Div 1000000007
#define E 2.71828
#define Pi 3.1415926
#define eps 1e-7
#define ElementType int
#define WeightType int
#define MAXSIZE 10000
char in[MAXSIZE],a[MAXSIZE],stackop[MAXSIZE];
int stacknum[MAXSIZE],sizenum,sizeop,l,la;
int pd(char a,char b)
{
	if(b=='*'||b=='/'){
		if(a=='+'||a=='-')return 1;
		else return 0;
	}
	else {
		if(a=='+'||a=='-')return 0;
		else return -1;
	}
}
int jisuan(int a,int b,char c)
{
	switch(c)
	{
		case '+':
			return a+b;
			break;
		case '-':
			return a-b;
			break;
		case '*':
			return a*b;
			break;
		case '/':
			return a/b;
			break;	
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n,i,temp=0,flag,Tmp,j;
	gets(in);
	l=strlen(in);
	for(i=0;i<l;i++)
	if(in[i]!=' ')
	a[la++]=in[i];
	a[la]='\0';
	//puts(a);
	i=0;
	while(i<la)
	{
		if(a[i]<='9'&&a[i]>='0')
		{
			temp=temp*10+a[i]-'0';
		}
		else {
			stacknum[++sizenum]=temp;
			temp=0;
			if(!sizeop)
			stackop[++sizeop]=a[i];
			else {
				flag=pd(stackop[sizeop],a[i]);
				while(flag!=1&&sizeop>0)
				{
					Tmp=jisuan(stacknum[sizenum-1],stacknum[sizenum],stackop[sizeop]);
					stackop[sizeop--]='\0';
					stacknum[sizenum]=0;
					stacknum[--sizenum]=Tmp;
					flag=pd(stackop[sizeop],a[i]);
				}
				stackop[++sizeop]=a[i];
			}
		}
		//printf("%d:\n",i);
		/*for(j=1;j<=sizenum;j++)
		printf("%d ",stacknum[j]);
		printf("\n");
		for(j=1;j<=sizeop;j++)
		printf("%c",stackop[j]);
		printf("\n");*/
		i++;
	}
	printf("%d",stacknum[1]); 
	return 0;
}




