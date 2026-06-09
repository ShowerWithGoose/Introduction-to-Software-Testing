#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h> 
typedef struct{
	int beg[2];
	int end[2];
	int count;
}line;
int main(){
	int n,i,j,k;
	line a[100];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d %d %d",&a[i].beg[0],&a[i].beg[1],&a[i].end[0],&a[i].end[1]);
		a[i].count=1;		
	} 
	int num=n;
	int sign=1;
	while(sign!=0&&num>=1){
		sign=0;
		for(i=0;i<num;i++){
			for(j=0;j<num;j++){
				if(a[i].end[0]==a[j].beg[0]&&a[i].end[1]==a[j].beg[1]&&i!=j){
					a[i].count+=a[j].count;	
					a[i].end[0]=a[j].end[0];
					a[i].end[1]=a[j].end[1];
					if(j!=num-1)
						for(k=j;k<num-1;k++){
							a[k]=a[k+1];
						}
						num--;
						sign=1;
				}
			}			
		}
	}
	int max=1,maxcount=1;
	for(i=0;i<num;i++){
		if(a[i].count>maxcount){
			maxcount=a[i].count;
			max=i;
		} 
	}
	printf("%d %d %d",a[max].count,a[max].beg[0],a[max].beg[1]);
	return 0;
} 

