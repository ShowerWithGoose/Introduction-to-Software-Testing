#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int main(){
	int a[1000];
	int k=0,i,m,s[100];
	for(i=0;;i++){
		scanf("%d",&a[i]);
		if(a[i]==-1){
			break;
		}
	}
	m=i;
	for(i=0;i<m;i++){
		if(a[i]==-1){
			return 0;
		}
		if(a[i]==1){
			s[k]=a[i+1];
			k++;
			i++;
		}
		else if(a[i]==0&&k!=0){
			printf("%d ",s[k-1]);
			k=k-1;
		}
		else if(a[i]==1&&k==99){
			printf("error ");
		}
		else if(a[i]==0&&k==0){
			printf("error ");
		}
	}
	
} 

