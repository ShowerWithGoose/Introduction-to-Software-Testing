#include<stdio.h>
#include<string.h>
int a[12],book[12];
int n;
void fullArray(int step)
{
    int i;
	if(step == n){
		for(i = 0; i < n; i++){
			printf("%d ",a[i]);
		}
		printf("\n");
		return;
	}
		for(i = 0; i < n; i++){
			if(book[i] == 0){
				a[step]=i+1;
				book[i]=1;
				fullArray(step+1);
				book[i]=0;
		}
	}
		
}
int main()
{

	scanf("%d",&n);
	fullArray(0);
	return 0;
 } 



