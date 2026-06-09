#include<stdio.h>
#include<string.h>
int a[1001],b[1001];
int main()
{
	int i,m,n,j=0,k=0;
	char c=' ';
	while(c!='\n'){
		scanf("%d%c",&a[i],&c);
		i++;
		k++;
	}
	for(i=0;i<k;i++){
		if(a[i]==1){
			b[j]=a[i+1];
			j++;
		}
		else if(a[i]==0){
			if(j>=1&&j<=100){
			printf("%d ",b[j-1]);
			j--;
		}
		else if(j<1||j>100){
			printf("error ");
		}
			
		}
	}
	return 0;
}

