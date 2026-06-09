#include<string.h>
#include<stdio.h>
#include<ctype.h>

char a[10005][1005],c[10005][1005],ch;
int n=0,bo=0,s0=0;

void merge_sort(int l,int r)
{
	if(l>=r) return;
	int mid=(l+r)>>1;
	merge_sort(l,mid);
	merge_sort(mid+1,r);
	int s1=l,s2=mid+1,s3=l;
	while((s1<=mid)&&(s2<=r))
	{
		if(strcmp(a[s1],a[s2])>0) strcpy(c[s3++],a[s2++]);else strcpy(c[s3++],a[s1++]);
	}
	while(s1<=mid) strcpy(c[s3++],a[s1++]);
	while(s2<=r) strcpy(c[s3++],a[s2++]);
	for(int i=l;i<=r;i++) strcpy(a[i],c[i]);
}

int main()
{
	freopen("article.txt","r",stdin);
	ch=getchar();
	while(ch!=EOF)
	{
		if(isalpha(ch)) 
		{
			if(ch>='A'&&ch<='Z') ch+=32;
			bo=1;a[n][s0++]=ch;
		}else if(bo) {n++;bo=s0=0;}
		ch=getchar();
	}
	merge_sort(0,n-1);
	s0=1;
	for(int i=0;i<n;i++)
	{
		if(strcmp(a[i],a[i+1])==0) s0++;else 
		{
			printf("%s %d\n",a[i],s0);
			s0=1;
		}
	}
	return 0;
}

