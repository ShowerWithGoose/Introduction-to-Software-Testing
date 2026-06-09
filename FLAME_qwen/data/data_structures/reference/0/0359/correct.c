#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
typedef long long ll;
int Max(int a,int b){return a>b?a:b;}
int Min(int a,int b){return a<b?a:b;}
int gcd(int a,int b)
{
	if(a==1||b==1)return 1;
	if(a%b==0||b%a==0)return Min(a,b);
	for(ll i=Min(a,b)-1;i>=1;i--)
	{
		if(a%i==0&&b%i==0)return i;
	}
}
//快速幂
int pow1(ll x,ll p,ll m)
{
	ll result=1;
	while(p)
	{
		if(p%2==1)
		{
			result=((result%m)*(x%m))%m;
		}
		p/=2;
		x=((x%m)*(x%m))%m;
	}
	return result;
}
//线性筛
short isPrime[30100001];
int Prime[10000001];
int cnt=0;
void GetPrime(int n)
{
	memset(isPrime,1,sizeof(isPrime));
	isPrime[1] = 0;
	for(int i = 2; i <= n; i++)
	{
		if(isPrime[i])
			Prime[++cnt] = i;
		for(int j = 1; j <= cnt && i*Prime[j] <= n; j++)
		{
			isPrime[i*Prime[j]] = 0;
			if(i % Prime[j] == 0)
				break;
		}
	}
}
void Swap(int *a,int *b)/*Swap(&a,&b)*/
{
	int tmp=*a;
	*a=*b;
	*b=tmp;
}
/*qsort(arr,num,sizeof(),cmp)*/
/*小到大*/int cmp1(const void*a,const void*b)
{
	return *(int*)a-*(int*)b;
}
/*大到小*/int cmp2(const void*a,const void*b)
{
	return *(int*)b-*(int*)a;
}
/*exgcd(&x,&y,a,b)*/void exgcd(ll *x,ll *y,ll a,ll b)
{
    if(!b)
    {
        *x=1;
        *y=0;
        return;
    }
    exgcd(x,y,b,a%b);
    ll t=*x;
    *x=*y;
    *y=t-a/b*(*y);
}
int main()
{
	char a[10001];
	gets(a);
	for(int i=0;i<=strlen(a)-1;i++)
	{
		if(a[i]=='-')
		{
			if(48<=a[i-1]&&a[i-1]<=57&&48<=a[i+1]&&a[i+1]<=57)
			{
				for(int j=a[i-1]+1;j<a[i+1];j++)
				{
					printf("%c",j);
				}
			}
			else if(65<=a[i-1]&&a[i-1]<=90&&65<=a[i+1]&&a[i+1]<=90)
			{
				for(int j=a[i-1]+1;j<a[i+1];j++)
				{
					printf("%c",j);
				}
			}
			else if(97<=a[i-1]&&a[i-1]<=122&&97<=a[i+1]&&a[i+1]<=122)
			{
				for(int j=a[i-1]+1;j<a[i+1];j++)
				{
					printf("%c",j);
				}
			}
			else printf("-");
		}
		else printf("%c",a[i]);
		
	}
	return 0;
}



