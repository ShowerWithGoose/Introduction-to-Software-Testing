#include <ctype.h>
#include <iso646.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 1024
void put(int *arr,int n)
{
    int i;
    for (i = 1;i<=n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void order(int line[],int cont[],int dep,int n){
	int i;
	if(dep-1==n){
		put(line,n);
		return;
	}
	for(i=1;i<=n;i++){
		if(cont[i]==0){
			cont[i]=1;
			line[dep]=i;
			order(line,cont,dep+1,n);
			cont[i]=0;
		}
	}
}
int main()
{
	int line[100]={0};
	int cont[100]={0};
	int n;
	scanf("%d",&n);
	order(line,cont,1,n);
    return 0;
}


