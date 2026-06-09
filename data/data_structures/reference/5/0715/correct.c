#include<stdio.h>
#include<math.h>
#include<string.h>

void getarr(char ch[],int a[],int len,int lens[])
{
	int num=1;
	int tmp[100005];
	memset(tmp,0,sizeof(tmp));
	for(int i=0;i<len;i++)
	{
		if(ch[i]==' ')
		{
			tmp[num]=i;
			num++;
		}
	}
	tmp[0]=-1;
	tmp[num]=len;
	for(int i=0;i<num;i++)
	a[i+1]=change(ch,tmp[i]+1,tmp[i+1]-1);
	lens[0]=num;
}

int change(char ch[],int l,int r)
{
	int num=0;
	int ans=0;
	for(int i=r;i>=l;i--)
	{
		int chi_num=ch[i]-'0';
		ans+=(chi_num*pow(10,num));
		num++;
	}
	return ans;
}

int size(int a[])
{
	int num;
	for(int i=1;;i++)
	{
		if(a[i]==0)
		{
			num=i;
			break;
		}
	}
	return num-1;
}

char ch1[1000005];
char ch2[1000005];
int a1[1000005];
int a2[1000005];
int coef1[1000005];
int powe1[1000005];
int coef2[1000005];
int powe2[1000005];
int coef_ans[1000005];
int powe_ans[1000005];
int lens1[3];
int lens2[3];

int main()
{
	gets(ch1);
	gets(ch2);
	int len1=strlen(ch1);
	int len2=strlen(ch2);
	getarr(ch1,a1,len1,lens1);
	getarr(ch2,a2,len2,lens2);
	for(int i=1;i<=lens1[0];i++)
	{
		if(i%2)
		coef1[i/2+1]=a1[i];
		else
		powe1[i/2]=a1[i];
	}
	for(int i=1;i<=lens2[0];i++)
	{
		if(i%2)
		coef2[i/2+1]=a2[i];
		else
		powe2[i/2]=a2[i];
	}
	int num=1;
	for(int i=1;i<=size(coef1);i++)
	{
		for(int j=1;j<=size(coef2);j++)
		{
			powe_ans[num]=powe1[i]+powe2[j];
			coef_ans[num]=coef1[i]*coef2[j];
			num++;
		}
	}
	num--;
	for(int i=1;i<=num;i++)
	{
		for(int j=i+1;j<=num;j++)
		{
			if(powe_ans[i]>powe_ans[j])
			{
				int tmp_powe=powe_ans[i];
				powe_ans[i]=powe_ans[j];
				powe_ans[j]=tmp_powe;
				int tmp_coef=coef_ans[i];
				coef_ans[i]=coef_ans[j];
				coef_ans[j]=tmp_coef; 
			}
			else if(powe_ans[i]==powe_ans[j]&&powe_ans[i]>=0)
			{
				coef_ans[j]+=coef_ans[i];
				powe_ans[i]=-1;
			}
		}
	}
	for(int i=1;i<=num;i++)
	{
		for(int j=i+1;j<=num;j++)
		{
			if(powe_ans[i]>powe_ans[j])
			{
				int tmp_powe=powe_ans[i];
				powe_ans[i]=powe_ans[j];
				powe_ans[j]=tmp_powe;
				int tmp_coef=coef_ans[i];
				coef_ans[i]=coef_ans[j];
				coef_ans[j]=tmp_coef; 
			}
		}
	}
	for(int i=num;powe_ans[i]!=-1&&i>0;i--)
	{
		if(coef_ans[i]!=0)
		printf("%d %d ",coef_ans[i],powe_ans[i]);
	}
	return 0;
}

