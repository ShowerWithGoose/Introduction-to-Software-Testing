#include<stdio.h>
#include<string.h>
#include<math.h>
int num[101];
int main()
{
	int i=0,j=0,k=1,l1,l2,m,l=0,ans=0,c=0;
	char x[101],s[101];
	
	gets(x);
	l1=strlen(x);
	for(i=0;i<101;i++){
		if(x[i]!=' '){
			s[j]=x[i];
			j++;
		}
		else
		continue;
	}
	
for(i=0;i<l1;i++)
	{
		if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='=')
		{
			m=i-l;
			while(m>0)
			{
				
				num[k]=num[k]+pow(10,m-1)*(s[l]-'0');
				l++;
				m--;
				
			}
			l=i+1;
			k++;
			
		}
	}
	
	ans=num[1];
	for(i=0;i<l1;i++){
		if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='=')
		{
			c++;
		if(s[i]=='*'){
			
			num[c]=num[c]*num[c+1];
			for(j=c;j<k;j++){
				num[j+1]=num[j+2];
			}
			c--;
			k--;
		}
		else if(s[i]=='/'){
			
			num[c]=num[c]/num[c+1];
			for(j=c;j<k;j++){
				num[j+1]=num[j+2];
			}
			c--;
			k--;
		}
	}
}
	c=1;
	ans=num[1];
	for(i=0;i<l1;i++){
		if(s[i]=='+'){
			c++;
			ans+=num[c];
			
		}
		else if(s[i]=='-'){
			c++;
			ans-=num[c];
			
		}
	}

	printf("%d",ans);
	return 0;
}

