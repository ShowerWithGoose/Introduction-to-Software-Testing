#include<stdio.h>

void fun(int s[],int m); 

int main()
{
	int N,a[15],i,ch=1,l;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		a[i]=i+1;
		printf("%d ",a[i]);
	}
	printf("\n");
	for(i=1;i<=N;i++){
		ch=ch*i;
	}

	   
	for(i=1;i<ch;i++){
		fun(a,N);
		for(l=0;l<N;l++){
			printf("%d ",a[l]);
		}
		printf("\n");
	}
	
	
	return 0;
	
	
 }
 
void fun(int s[],int m){
	int j,r;
	for(j=m-2;j>=0;j--){
		if(s[j]<s[j+1])
		break;
	}
	int k1=j,k2=j+1,temp;
	for(j=k1+1;j<m;j++){
		if(s[j]>s[k1]&&s[j]<s[k2])
		  k2=j;
	}
	temp=s[k1];
	s[k1]=s[k2];
	s[k2]=temp;
	for(r=k1+1,j=m-1;j>r;j--,r++){
		temp=s[r];
    	s[r]=s[j];
    	s[j]=temp;
	}
	
	
} 



