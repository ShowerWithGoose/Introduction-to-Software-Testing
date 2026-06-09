#include<stdio.h>
#include<string.h>
int a[100],x[100];
int m,n;
void bubblesort(int a[],int n){
 	int i,j,hold,flag;
 	for(i=0;i<n-1;i++){
 		flag=0;
 		for(j=0;j<n-1-i;j++){
 			if(x[a[j]]<x[a[j+1]]){
 				hold=a[j];
 				a[j]=a[j+1];
 				a[j+1]=hold;
 				flag=1;
			 }
		 }
		if(flag==0){
			break;
		}	 
	 }
 } 
void pailie(int count,int a[]){
	int i,j,k;
	if(count>1){
		for(i=0;i<n;i++){
			if(x[a[i]]==0){
				x[a[i]]=count;
				//printf(" q%d %dq ",a[i],count);
				pailie(count-1,a);
				//for(i=0;i<n;i++)printf(" d%dd ",a[i]);
				for(j=0;j<n;j++){
					if(x[a[j]]<=count) x[a[j]]=0;
					//printf("j%dj ",x[a[j]]);
				}
			}
		}
	}
	else if(count==1){
		//printf(" s%d %d %ds ",x[a[0]],x[a[1]],x[a[2]]);
		bubblesort(a,n);
		printf("%d",a[0]);
		for(i=1;i<n;i++){
				printf(" %d",a[i]);
		}printf("\n");
		//mems et(x,0,sizeof(x[0]));
		for(i=0;i<n;i++) a[i]=i+1;
		//return;
	}
}
int main()
{
	int i,j,k;
	scanf("%d",&n);
	int count=n;
	for(i=0;i<n;i++){
		a[i]=i+1;
	}
	pailie(count,a);
	return 0;
}

