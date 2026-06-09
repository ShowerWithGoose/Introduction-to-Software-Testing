#include <stdio.h>
#define N 100010
int e[N][4];//0=x1,1=y1,2=x2,3=y2
int ne[N];
int st[N];
int main(){
	int n,j,i,flag,ans,tmp,judge;
	scanf("%d ",&n);
	for(i=1;i<=n;i++){
		scanf("%d %d %d %d",&e[i][0],&e[i][1],&e[i][2],&e[i][3]);	
	}
	
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){
			if((e[j][0]==e[i][0]&&e[j][1]==e[i][1])||(e[j][0]==e[i][2]&&e[j][1]==e[i][3])||(e[j][2]==e[i][0]&&e[j][3]==e[i][1])||(e[j][2]==e[i][2]&&e[j][3]==e[i][3])){
				if(e[j][2]>e[i][0]) ne[i]=j;
				if(e[j][2]<e[i][0]) ne[j]=i;
			}
		}
	}
	
	for(i=n;i>0;i--){
		for(j=i-1;j>0;j--){
			if((e[j][0]==e[i][0]&&e[j][1]==e[i][1])||(e[j][0]==e[i][2]&&e[j][1]==e[i][3])||(e[j][2]==e[i][0]&&e[j][3]==e[i][1])||(e[j][2]==e[i][2]&&e[j][3]==e[i][3])){
				if(e[j][2]>e[i][0]) ne[i]=j;
				if(e[j][2]<e[i][0]) ne[j]=i;
			}
		}
	}
	
	for(i=1;i<=n;i++){
		tmp=ne[i];
		st[i]=1;
		while(tmp!=0){
			st[i]++;
			tmp=ne[tmp];
		}
		judge=st[i]>ans?1:0;
		if(judge){
			ans=st[i];
			flag=i;
		}
	}
	
	printf("%d %d %d",ans,e[flag][0],e[flag][1]);
	return 0;
}

