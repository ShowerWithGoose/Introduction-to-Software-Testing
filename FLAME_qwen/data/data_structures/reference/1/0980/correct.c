#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>

int n;
int arr[10];

int next(){
	for(int i=n-1;i>0;i--){
		if(arr[i-1]<arr[i]){
			int min = i;
			for(int j=i+1;j<n;j++){
				if(arr[j]>arr[i-1]){
					min = j;
				}
				else{
					break;
				}	
			}
			int tem=arr[min];
			arr[min]=arr[i-1];
			arr[i-1]=tem;
			for(int j=i,k=n-1;j<k;j++,k--){
				tem=arr[j];
				arr[j]=arr[k];
				arr[k]=tem;
			} 
			return 1;
		}
	}
	return 0;
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		arr[i]=i+1;
	}
	
	do{
		for(int i=0;i<n;i++){
			printf("%d ",arr[i]);
		}
		printf("\n");
	}while(next()==1);
 	return 0;
 }



