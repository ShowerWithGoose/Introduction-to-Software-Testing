#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define ll long long 
#define ull unsigned long long
int num[2000005],topn=0,topo=0,g;
char st[2000005],ops[2000005];
int you(char ch){
    if(ch=='+') return 2;
    if(ch=='*') return 3;
    if(ch=='-') return 2;
    if(ch=='/') return 3;
    return 1;
}
int js(int a){
	int sum=0;
	int f=a;
	while(st[a]>='0'&&st[a]<='9')
		a++;
	g=a;
	for(int i=f;i<g;i++)
	sum=sum*10+(st[i]-'0');
	return sum;
}
void jia(){
	topo--;
	int sum=num[topn]+num[topn-1];
	topn--;
	num[topn]=sum;
}
void cheng(){
	topo--;
	int sum=num[topn-1]*num[topn];
	topn--;
	num[topn]=sum;
}
void jian(){
	topo--;
	int sum=num[topn-1]-num[topn];
	topn--;
	num[topn]=sum;
}
void chu(){
	topo--;
	int sum=num[topn-1]/num[topn];
	topn--;
	num[topn]=sum;
}
int main()
{
	gets(st);
	int len=strlen(st);
	len--;
	st[len]=')';
	ops[++topo]='(';
	for(int i=0;i<=len;i++)
	{
		if(st[i]>='0'&&st[i]<='9')
		{
			int x=js(i);i=g-1;
			num[++topn]=x;
		}
		else if((st[i]=='-'&&i==0)||(st[i]=='-'&&st[i-1]=='('))
		{
			num[++topn]=0;
			ops[++topo]='-';
		}
		else if(st[i]=='+'||st[i]=='*'||st[i]=='-'||st[i]=='/')
		{
			while(you(ops[topo])>=you(st[i]))
			{
				if(ops[topo]=='+') jia();
				else if(ops[topo]=='*') cheng();
				else if(ops[topo]=='-') jian();
				else if(ops[topo]=='/') chu();
			}
			ops[++topo]=st[i];
		}
		else if(st[i]==')')
		{
			while(ops[topo]!='(')
			{
				if(ops[topo]=='+') jia();
				else if(ops[topo]=='*') cheng();	
				else if(ops[topo]=='-') jian();
				else if(ops[topo]=='/') chu();	
			}
			topo--;
		}
	}
	printf("%d",num[topn]);
	return 0;
}

