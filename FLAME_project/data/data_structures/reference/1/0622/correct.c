#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int a[10]={1,2,3,4,5,6,7,8,9,10};

void print(int a[10],int stl){
	int i;
	for(i=0;i<stl;i++)
	    printf("%d ",a[i]);
	printf("\n");
}

int cmp(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}

void row(int *a,int start,int end,int stl){
	qsort(a+start,end-start+1,sizeof(int),cmp);
	int i;
	if(start==end)
	    print(a,stl);
	else{
	    for(i=start;i<=end;i++){
	        int temp=0;
	        temp=a[i];
	        a[i]=a[start];
	        a[start]=temp;
	        row(a,start+1,end,stl);
	        temp=a[i];
	        a[i]=a[start];
	        a[start]=temp;
	        qsort(a+start,end-start+1,sizeof(int),cmp);
	
	    }
	}
}

int main(){
	int n,i;
	scanf("%d",&n);
	row(a,0,n-1,n);
	return 0;
}


