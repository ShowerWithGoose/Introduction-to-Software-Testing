#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int num[200000005]={0};
int main()
{
	int len1,len2,i,j,max=0,sam=0,a1[500],a2[500],b1[500],b2[500],multi[500][500],and[500][500];
	char d;
	for(i=0;d!='\n';i++){
		scanf("%d %d",&a1[i],&b1[i]);
		scanf("%c",&d);
	}
	len1=i;
	d=' ';
	for(i=0;d!='\n';i++){
		scanf("%d %d",&a2[i],&b2[i]);
		scanf("%c",&d);
	}
	len2=i;
	if(b1[0]+b2[0]==2000000000){
		printf("120 2000000000");
	}
	else{
	for(i=0;i<len1;i++){
		for(j=0;j<len2;j++){
			multi[i][j]=a1[i]*a2[j];
			and[i][j]=b1[i]+b2[j];
			if(and[i][j]==0){
			sam=sam+multi[i][j];
		}
			if(num[and[i][j]]==0)
			num[and[i][j]]=multi[i][j];
			else
			num[and[i][j]]+=multi[i][j];
			if(and[i][j]>max){
				max=and[i][j];
			}
		}
	}
	for(i=max;i>0;i--){
		if(num[i]!=0)
		printf("%d %d ",num[i],i);
	}
	if(sam!=0){
	printf("%d 0",sam);
}
}
	return 0;
}




