#include<stdio.h>
#include<string.h>
char input[1000];
char stay[1000];
char sym[1000];
int a[1000];
int number[1000]={0};
int ncifang(int x){
	int ji=1;
	if(x!=0){
		for(int i=1;i<=x;i++){
			ji=10*ji;	
		}
	}
	return ji;
}
int main()
{
	int length,result=0,mid=0;
	int i=0,j=0,k=0,num=0,num2=0,sum=0,cha=0,m=0;
	gets(input);
	length=strlen(input);
	//去除空格（已测试，无误
	for(i=0,j=0;i<length;i++){
		if(input[i]!=' '){
			stay[j]=input[i];
			j++;
		}
	}
	num=j;
	//可以设一计数器用来记录已读取但未参加运算的运算符的个数，根据该计数器来判断如何进行运算；
	for(i=0,j=0;i<=num;i++){
		if(stay[i]=='+'||stay[i]=='*'||stay[i]=='-'||stay[i]=='/'||stay[i]=='='){
			sym[j]=stay[i];
			a[j]=i;
			j++;
		}
	}
	num2=j-1;
	if(sym[0]=='=')//直接"="不做运算
	{
		for(i=0;i<a[0];i++){
			printf("%c",stay[i]);
		}
	}
	else
	{
		for(i=0;i<=num;i++){
			if(i==0){
				sum=0;
				cha=a[i]-1;
				for(j=0,k=cha;j<=cha;j++,k--){
					sum=(stay[k]-'0')*ncifang(j)+sum;
				}
				number[i]=sum;
			}
			else{
				sum=0;
				cha=a[i]-a[i-1]-1;
				for(j=0,k=a[i]-1;j<cha;j++,k--){
					sum=(stay[k]-'0')*ncifang(j)+sum;
				}
				number[i]=sum;				
			}
		}
		result=number[0];
		for(i=0;i<=num2;i++){
			if(sym[i]=='*'||sym[i]=='/')
			{
				if(sym[i]=='*')
				{
					result=result*number[i+1];
				}
				else{
					result=result/number[i+1];
				}
			}
			else if(sym[i]=='+'||sym[i]=='-')
			{
				for(j=i+1;j<num2;j++){
					if(sym[j]=='+'||sym[j]=='-')
					{
						break;
					}
				}
				if(j==i+1){
					if(sym[i]=='+')
					{
						result=result+number[i+1];
					}
					else{
						result=result-number[i+1];
					}
				}
				else{
					mid=number[i+1];
					for(m=i+1;m<j;m++){
						if(sym[m]=='*')
						{
							mid=mid*number[m+1];
						}
						else if(sym[m]=='/')
						{
							mid=mid/number[m+1];
						}				
					}
					if(sym[i]=='+')
					{
						result=result+mid;
					}
					else{
						result=result-mid;
					}					
				}
				i=j-1;
			}
			else
				break;
		}
		printf("%d",result);
	}
	
	return 0;
}

