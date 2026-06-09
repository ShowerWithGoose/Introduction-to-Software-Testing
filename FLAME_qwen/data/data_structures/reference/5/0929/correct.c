#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct multi{
	long long a;
	long long b;
};
int main()
{
	int n,i,j,k=0;
	char c,d;
	struct multi x[1100],y[1100];
	memset(x,0,sizeof(x));
	memset(y,0,sizeof(y));
	for(i=0;c!='\n';i++){//x第一个多项式
		scanf("%d%d%c",&x[i].a,&x[i].b,&c);
	}
	int len1=i;
	for(i=0;d!='\n';i++){//y第二个多项式
		scanf("%d%d%c",&y[i].a,&y[i].b,&d);
	}
	int len2=i;
	struct multi z[41100];
	memset(z,0,sizeof(z));
	k=0;
	for(i=0;i<len1;i++){
		for(j=0;j<len2;j++){
			z[k].a=(long long)x[i].a*y[j].a;
			z[k].b=(long long)x[i].b+y[j].b;
			k++;
		}
	}
	int len3=k;
	for(i=0;i<len3;i++){//消除指数相同项 
		for(j=i+1;j<len3;j++){
			if(z[i].b==z[j].b)
			{
				z[i].a+=z[j].a;
				for(k=j+1;k<len3;k++){
					z[k-1]=z[k];
				}
				j--;
				len3--;
			}
		}
	}
	for(i=0;i<len3;i++){//消除系数为零项 
		if(z[i].a==0)
		{
			for(j=i+1;j<len3;j++){
				z[j-1]=z[j];
			}
			i--;
			len3--;
		}
	}
	int flag;
	struct multi temp;
	for(i=0;i<len3-1;i++){//指数从大到小排序 
		flag=0;
		for(j=0;j<len3-1-i;j++){
			if(z[j].b<z[j+1].b)
			{
				temp=z[j];
				z[j]=z[j+1];
				z[j+1]=temp;
				flag=1;
			}
		}
		if(flag==0)
			break;
	}
	for(i=0;i<len3;i++){
		printf("%lld %lld ",z[i].a,z[i].b);
	}
	return 0;
}

