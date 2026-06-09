#include<stdio.h>
#include<string.h>
int main(){
	int xishu1[100],mi1[100],xishu2[100],mi2[100]; 
	int line1[200],line2[200];
	int i=0,j,k;
	int num;
	char ch;
	int len1,len2;
	while(1){
		scanf("%d",&num);
		ch=getchar();
		line1[i]=num;
		i++;
		if(ch=='\n'){
			break;
		}
	}
	len1=i;
	i=0;
	while(1){
		scanf("%d",&num);
		ch=getchar();
		line2[i]=num;
		i++;
		if(ch=='\n'){
			break;
		}
	}
	len2=i;
	i=0;
	j=0;
	while(i<len1){
		xishu1[j]=line1[i];//第一行的系数存入数组 
		i=i+2;
		j++;
	}
	int n1;//第一行的系数的个数(幂的个数) 
	n1=j;
	i=0;
	j=0;
	while(i<len1){
		mi1[j]=line1[i+1];//第一行的幂存入数组 
		i=i+2;
		j++;
	}
	i=0;
	j=0;
	while(i<len2){
		xishu2[j]=line2[i];//第二行的系数存入数组 
		i=i+2;
		j++;
	}
	int n2;//第二行的系数的个数(幂的个数) 
	n2=j;
	i=0;
	j=0;
	while(i<len2){
		mi2[j]=line2[i+1];//第二行的幂存入数组 
		i=i+2;
		j++;
	}
	int xishu[100],mi[100];
	k=0;
	for(i=0;i<n1;i++){
		for(j=0;j<n2;j++){
			xishu[k]=xishu1[i]*xishu2[j];
			mi[k]=mi1[i]+mi2[j];
			k++;//k为化简前的项数 
		}
	} 
	for(i=0;i<k;i++){
		for(j=i;j<k;j++){
			if(mi[j]==mi[i]&&i!=j){
				xishu[i]=xishu[i]+xishu[j];
				xishu[j]=0;
			}
		}
	}
	int XISHU[100];
	int MI[100];
	for(i=0;i<100;i++){
		XISHU[i]=0;
		MI[i]=0;
	}
	j=0;
	int count=0;
	for(i=0;i<n1*n2;i++){
		if(xishu[i]!=0){
			XISHU[j]=xishu[i];
			MI[j]=mi[i];
			j++;
		}
	}
	int n=j;
	int t,p;
	for(i=0;i<n-1;++i){
		for(j=0;j<n-i-1;++j){
			if(MI[j]<MI[j+1]){
				t=MI[j];
				MI[j]=MI[j+1];
				MI[j+1]=t;
				p=XISHU[j];
				XISHU[j]=XISHU[j+1];
				XISHU[j+1]=p;
			}
		}
	}
	for(i=0;i<n;i++){
		if(XISHU[i]==0){
			i=i+1;
		}
		printf("%d %d ",XISHU[i],MI[i]);
	}
	return 0;
} 

