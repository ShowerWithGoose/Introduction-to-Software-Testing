#include<stdio.h>
int cacu(int a,int b,int m)
{
	if(m==0)
		return (a+b);
	else if(m==1)
		return (a-b);
	else if(m==2)
		return (a*b);
	else if(m==3)
		return (a/b);
}
int decide(char c)
{
	if(c=='+')
		return 0;
	else if(c=='-')
		return 1;
	else if(c=='*')
		return 2;
	else if(c=='/')
		return 3;
}

int main()
{
	char c,number;
	char data[1000];
	int num[42];
	int di=0,i=0,s=0,m,j=0,result,ni=0;
	while(1){
		if(s==0){
			scanf("%d",&num[ni++]);
			data[di++]=ni-1;//在data中相应位置存储一个小于42的数，用于检索num数组中存储的int数（ascii42是*）
			s=1;
			continue;
		}
		else{
			scanf("%c",&c);
			if(c=='+'||c=='-'||c=='*'||c=='/'){
				data[di++]=c;
				s=0;
				continue;
			}
			else if(c=='=')
				break;
		}
	}
	while(i<di){
		if(data[i]=='*'||data[i]=='/'){
			m=decide(data[i]);
			result=cacu(num[data[i-1]],num[data[i+1]],m);
			num[data[i-1]]=result;num[data[i+1]]=result;data[i]='@';
			for(j=i;data[j-2]=='@';j-=2)
				num[data[j-3]]=result;
			for(j=i;data[j+2]=='@';j+=2)
				num[data[j+3]]=result;
			i=-1;//算过一次后重新开始循环
		}
		i++;
	}
	i=0;
	while(i<di){
		if(data[i]=='+'||data[i]=='-'){
			m=decide(data[i]);
			result=cacu(num[data[i-1]],num[data[i+1]],m);
			num[data[i-1]]=result;num[data[i+1]]=result;data[i]='@';
			for(j=i;data[j-2]=='@';j-=2)
				num[data[j-3]]=result;
			for(j=i;data[j+2]=='@';j+=2)
				num[data[j+3]]=result;
			i=-1;//算过一次后重新开始循环
		}
		i++;
	}
	printf("%d",num[0]);
	return 0;
}


