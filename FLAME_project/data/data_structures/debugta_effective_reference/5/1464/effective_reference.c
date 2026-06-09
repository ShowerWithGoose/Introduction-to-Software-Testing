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
	struct multi multi_1[1100],multi_2[1100];
	memset(multi_1,0,sizeof(multi_1));
	memset(multi_2,0,sizeof(multi_2));
	for(i=0;c!='\n';i++){//x第一个多项式
		scanf("%d%d%c",&multi_1[i].a,&multi_1[i].b,&c);
	}
	int len1=i;
	for(i=0;d!='\n';i++){//y第二个多项式
		scanf("%d%d%c",&multi_2[i].a,&multi_2[i].b,&d);
	}
	int len2=i;
	struct multi multi[41100];
	memset(multi,0,sizeof(multi));
	k=0;
	for(i=0;i<len1;i++){
		for(j=0;j<len2;j++){
			multi[k].a=(long long)multi_1[i].a*multi_2[j].a;
			multi[k].b=(long long)multi_1[i].b+multi_2[j].b;
			k++;
		}
	}
	int len3=k;
	for(i=0;i<len3;i++){//消除指数相同项 
		for(j=i+1;j<len3;j++){
			if(multi[i].b==multi[j].b)
			{
				multi[i].a+=multi[j].a;
				for(k=j+1;k<len3;k++){
					multi[k-1]=multi[k];
				}
				j--;
				len3--;
			}
		}
	}
	for(i=0;i<len3;i++){//消除系数为零项 
		if(multi[i].a==0)
		{
			for(j=i+1;j<len3;j++){
				multi[j-1]=multi[j];
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
			if(multi[j].b<multi[j+1].b)
			{
				temp=multi[j];
				multi[j]=multi[j+1];
				multi[j+1]=temp;
				flag=1;
			}
		}
		if(flag==0)
			break;
	}
	for(i=0;i<len3;i++){
		printf("%lld %lld ",multi[i].a,multi[i].b);
	}
	return 0;
}

