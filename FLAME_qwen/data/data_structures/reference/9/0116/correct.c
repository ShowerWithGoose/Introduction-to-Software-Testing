#include<stdio.h>
#include<math.h>
int main(){
	int n,a[100],b[100],c[100],d[100],max=1,t=1,mm,nn;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		scanf("%d%d",&c[i],&d[i]);
	}
	
	
	
for(int p=0;p<n;p++)
{
	int ls1=c[p],ls2=d[p],tt=1;
	for(int ww=0;ww<n;ww++)
		for(int i=0;i<n;i++)
			if(a[i]==ls1&&b[i]==ls2) {ls1=c[i];ls2=d[i];tt++;break;}		

	if(t<tt) {t=tt;mm=a[p],nn=b[p];}
}

	printf("%d %d %d",t,mm,nn);
	
	
	return 0;
}

