#include<stdio.h>
#include<string.h>
char s[10000],ops[1000]={'a'};
long long nums[1000]={0},sum,ans;
int main()
{
	gets(s);
	int j=0,k=0,i;
	for(i=0;s[i]!='=';i++)
	{
		if(s[i]==' ')
			continue;
		if(s[i]>='0'&&s[i]<='9')
		{
			sum=0;
			while(s[i]>='0'&&s[i]<='9')
			{
				sum=sum*10+s[i]-'0';
				i++;
			}
			i--;
			nums[++j]=sum;
		}
		else{
			if((ops[k]=='*'||ops[k]=='/')&&j>=2&&k>=1){
				if(ops[k]=='*'){
					nums[j-1]=nums[j-1]*nums[j];
				}
				else{
					nums[j-1]=nums[j-1]/nums[j];
				}
				k--;
				j--;
			}
			ops[++k]=s[i];
		}			
	}
	if((ops[k]=='*'||ops[k]=='/')&&j>=2&&k>=1){
		if(ops[k]=='*'){
			nums[j-1]=nums[j-1]*nums[j];
		}
		else{
			nums[j-1]=nums[j-1]/nums[j];
		}
		j--;
		k--;
	}
	ans=nums[1];
	for(int p=1;p<j;p++){
		if(ops[p]=='+')
			ans+=nums[p+1];
		else if(ops[p]=='-')
			ans-=nums[p+1];
	} 
	printf("%lld",ans);
	return 0;
}

