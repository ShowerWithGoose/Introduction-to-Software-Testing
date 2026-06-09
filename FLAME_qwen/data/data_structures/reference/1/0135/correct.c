#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

int n,a[10],list[11];

void scan(int i,int j){
	if(j==0){
		for(int m=0;m<n;m++){
			printf("%d ",a[m]);
		}
		printf("\n");
		return;
	}
	else{
		for(int m=1;m<=n;m++){   //层控制第几位，循环保证每一位都可以从1到n 
			if(list[m]==0){
				list[m] = 1;
				a[i] = m;
				scan(i+1,j-1);
				list[m] = 0;
			}
		}
	}
}

int main(){
	scanf("%d",&n);
	scan(0,n);
	return 0;
}

