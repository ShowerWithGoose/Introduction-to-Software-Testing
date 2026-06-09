#include<stdio.h>
#include<string.h>
void print_s(int s[],int N){
	int i;
	printf("\n");
	for(i=0;i<N;i++)printf("%d ",s[i]);

}
int jiecheng(int N){
	int i,sum=1;
	for(i=1;i<=N;i++)sum*=i;
	return sum;
}
void quanpailie(int *s,int N){
	int i,j,lower=11,k;
	for(i=N-1;i>0;i--){
		if(s[i-1]<s[i])break;
	}
	
	j=i;
	//printf("%d\n",j);
	for(i=j;i<N;i++){
		if(lower>s[i]&&s[i]>s[j-1]){
			k=i;
			lower=s[i];
		}
	}
	s[k]=s[j-1];
	
	s[j-1]=lower;
	swap(s,j,N);
	//printf("%d %d\n",s[0],s[1]);
}
void swap(int *s,int j,int high){
	int i,temp;
	for(i=j;i<high-1;i++,high--){
		temp=s[i];
		s[i]=s[high-1];
		s[high-1]=temp;
	}
}
int main(){
	int s[11];
	int i,j,k,N,number;
	scanf("%d",&N);
	number=jiecheng(N);
	//printf("%d\n",number);
	for(i=0;i<N;i++)s[i]=i+1;
	if(N==1)printf("%d",N);
	else{
		for(i=0;i<N;i++)printf("%d ",s[i]);
		for(i=1;i<number;i++){
			quanpailie(s,N);
			print_s(s,N);
		}
	}
	return 0;
}

