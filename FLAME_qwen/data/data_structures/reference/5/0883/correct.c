#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 10000

struct multi{
	long long a,n;
}mul[N],a[N];

int turn(char []);  //提取出第一个多项式到a[]中 
int search(long long,int);
int compare(const void*,const void*);  //降序 

int main()
{
	long long a_num,n_num;
	int i,sum=0,number=0;  //sum记录已有乘积多项式的项数,number记录第一个多项式的项数 
	char s[1000];
	
	for(i=0;i<=3000;i++){
		mul[i].a=0;mul[i].n=0;
	}
	
	gets(s);
	number=turn(s);
	
	//printf("\n%d\n",number);
	
	scanf("%lld%lld",&a_num,&n_num);
	for(i=1;i<=number;i++){
		mul[i].a=a[i].a*a_num;
		mul[i].n=a[i].n+n_num;
		sum++;
	}
	
	//printf("\n%d %d\n",number,sum);
	//for(i=1;i<=sum;i++)printf("%lld %lld ",mul[i].a,mul[i].n);
	
	
	int flag;
	while(scanf("%lld%lld",&a_num,&n_num)!=EOF){
		for(i=1;i<=number;i++){
			flag=search(a[i].n+n_num,sum);
			if(flag>0){
				mul[flag].a+=a[i].a*a_num;
			}
			else{
				mul[sum+1].a=a[i].a*a_num;
				mul[sum+1].n=a[i].n+n_num;
				sum++;
				qsort(mul+1,sum,sizeof(mul[1]),compare);
			}
		}
	//printf("\n");
	//for(i=1;i<=sum;i++)printf("%lld %lld ",mul[i].a,mul[i].n);
	
	
	}
	for(i=1;i<=sum;i++)
	printf("%lld %lld ",mul[i].a,mul[i].n);
	//printf("\n%lld %lld\n",mul[10].a,mul[10].n);
	return 0;
}

int compare(const void *a,const void *b)
{
	return (*(struct multi *)b).n-(*(struct multi *)a).n;
}

int turn(char s[])
{
	int number=1,i=0;
	long long sum=0;
	while(s[i]!='\0'){
		while(s[i]!=' '){
			sum*=10;
			sum+=(long long)(s[i]-'0');
			i++;
		}
		a[number].a=sum;  sum=0;
		i++;
		while((s[i]!=' ')&&(s[i]!='\0')){
			sum*=10;
			sum+=(long long)(s[i]-'0');
			i++;
		}
		a[number].n=sum;   sum=0;
		number++;		i++;
	}
	number--;
	return number;
}

int search(long long mul_num,int sum)
{
	int low=1,high=sum,mid;	
	while(low<=high){
		mid=(low+high)/2;
		if(mul[mid].n==mul_num) 	return mid;
		else if(mul[mid].n>mul_num)  low=mid+1;
		else  high=mid-1;
	}
	return 0;
}

