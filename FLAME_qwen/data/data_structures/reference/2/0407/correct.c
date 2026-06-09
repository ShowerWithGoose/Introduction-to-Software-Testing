#include<stdio.h>
#include<string.h>
#include<math.h>

int a1[1000],num[1000],flag[1000];
char s1[1000];

int cal(int a,int b,char c)
{
	if(c=='+') return(a+b);
	if(c=='-') return(a-b);
	if(c=='*') return(a*b);
	if(c=='/') return(a/b);
	else return 0;
}

int main()
{
	char s[1000]; 
    gets(s);
    int i,j=1,k=0,l,m,n=0,t,count1=0,count2=0;
    int ans=0;
    l=strlen(s);
    s1[0]='+';
    for(i=0; i<l; i++)
    {
    	if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/') s1[j++]=s[i];
	}
	
	for(i=0; i<l; i++)
	{
		if(s[i]>='0'&&s[i]<='9') count1=1;
		else count1=0;
		
		if(count1==1&&count2==0)
		{
			count2=1;
			num[n++]=s[i]-'0';	
		}
		else if(count1==1&&count2==1)
		{
			num[n++]=s[i]-'0';
		}
		else if(count1==0&&count2==1)
		{
			for(m=0;m<n;m++)
			{
				a1[k]+=num[m]*pow(10,n-m-1);
			}
			k++;
			count2=0;
			n=0;
		}
	}
    k=0;
	for(i=0; i<j; i++)
	{
		if(s1[i]=='+'||s1[i]=='-') flag[k++]=i;
	}
	flag[k]=j;
    
	for(i=0; i<k; i++)
	{
		t=a1[flag[i]];
		for(j=flag[i]+1; j<flag[i+1]; j++)
		{
			t=cal(t,a1[j],s1[j]);
		}
		ans=cal(ans,t,s1[flag[i]]);
	}

	printf("%d",ans);
	return 0;
}


