#include<stdio.h>
int main()
{
	int x1[100],x2[100],y1[100],y2[100],num[100]={0};
	int i=1,j=1,max=0,k=1,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
		num[i]=1;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i==j)
			continue;
			if(x2[i]==x1[j]&&y2[i]==y1[j]){
				x2[i]=x2[j];
				y2[i]=y2[j];
				num[i]+=num[j];
				j=0;
				}
	    }
    }
	for(i=1;i<=n;i++){
		if(num[i]>max){
			max=num[i];
			k=i;
		}
	}
	printf("%d %d %d",max,x1[k],y1[k]);
	
return 0;
}


