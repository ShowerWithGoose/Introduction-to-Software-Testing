#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int a[15]={0},hash[10]={0};
	int max_limit,min_limit,n,i,j,k,s;max_limit=min_limit=i=j=k=s=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		min_limit*=10;
		min_limit+=i;
	}
	i--;
	for(;i>0;i--){
		max_limit*=10;
		max_limit+=i;
	}
	for(i=min_limit;i<=max_limit;i++){
		j=i;
		while(j>0){
			a[k]=j%10;
			j/=10;
			k++;	
		}
		
		if(j==0){
			for(s=0;s<n;s++){
				hash[a[s]]++;
			}
			for(s=1;s<=n;s++){
				if(hash[s]==0||hash[s]==2){
					break;
				}
			}
			if(s==n+1){
				for(s=n-1;s>=0;s--){
					printf("%d",a[s]);
					printf(" ");
				}
				printf("\n");
			}
		}
		k=0;
		for(s=1;s<=n;s++){
			hash[s]=0;
		}
	}
 	return 0;
}

