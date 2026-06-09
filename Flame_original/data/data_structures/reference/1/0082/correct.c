#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
void swap(int *a,int *b){
	int tmp=*a;
	*a=*b;
	*b=tmp;
} 
int a[20];
int cmp(const void*a,const void*b){
	return *(int *)a-*(int *)b; 
}
void fp(int start,int end){
	if(start==end){
		for(int j=0;j<end;j++){
			printf("%d ",a[j]);
		}
		printf("\n");
		return;
	}
	else{
		for(int i=start;i<end;i++){

		    swap(&a[start],&a[i]);
		    qsort(a+start+1,end-start-1,sizeof(int),cmp); 
			fp(start+1,end);
			qsort(a+start+1,end-start-1,sizeof(int),cmp); 
            swap(&a[start],&a[i]);
		}
	}
}
int main()
{   
    int n;
    scanf("%d",&n); 
    for(int i=0;i<n;i++){
    	a[i]=i+1;
	}
    fp(0,n);

    return 0;
}


