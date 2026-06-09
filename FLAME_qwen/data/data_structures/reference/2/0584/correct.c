#include<stdio.h>
#include<string.h>
void plus();
int main(){
    int i=1,k=0,j=0,s,sum[1000]={0},flag[1000]={0};
    int ans=0;
	char c;
	flag[0]=1;
	while(1){
		if(k==0){
			scanf("%d",&s);
		    sum[i]=s;
		}
		scanf("%c",&c);
		if(c=='+'){
			flag[i]=1;
			i++;
			k=0;
		}
		if(c=='-'){
			flag[i]=2;
			i++;
			k=0;
		}
		if(c=='='){
			break;
		}
		if(c==' '){
			k=1;
		}
		if(c=='*'){
			scanf("%d",&s);
			sum[i]=sum[i]*s;
			k=1;
		}
		if(c=='/'){
			scanf("%d",&s);
			sum[i]=sum[i]/s;
			k=1;
		}
	}
	for(j=0;j<i;j++){
		if(flag[j]==1){
			ans=ans+sum[j+1];
		}
		if(flag[j]==2){
			ans=ans-sum[j+1];
		}
	}
	printf("%d\n",ans);
	
}






