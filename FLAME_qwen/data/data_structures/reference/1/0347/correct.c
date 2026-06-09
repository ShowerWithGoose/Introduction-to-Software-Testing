#include<stdio.h>
int book[15]={0};
int arr[15]={0}; 
void fullArray(int N,int step);
int main()
{
	int N;
	scanf("%d",&N);
    fullArray(N,1);
	return 0;
}

void fullArray(int N,int step){
	int i;
	if(step==N+1){
		for(i=1;i<=N;i++){
			printf("%d ",arr[i]);
		}
		printf("\n");
		return;
	}
	for(i=1;i<=N;i++){
	    if(book[i]==0){
	    	arr[step] = i;
	    	book[i] = 1;
	    	fullArray(N,step+1);
	    	book[i] = 0;
		}
    }
    return;
}



