#include<stdio.h> 
#include<math.h>
#include<stdlib.h> 
#include<string.h> 
#include<stdbool.h> 
void dfs(int );
bool status [20]={0};
int stc[20];
int n,top;
int a[20]={1,2,3,4,5,6,7,8,9,10};

int main(){
int i; 
scanf("%d",&n);
top=0;
dfs(0);
return 0;
}

void dfs(int depth){
int i;
if(depth==n){
	for(i=0;i<n;i++){
	printf("%d ",stc[i]);
	}
	printf("\n");
}
 for(i=0;i<n;++i){
        if(status[i] == 0){
            status[i] = 1;
            stc[top++] = a[i];
            dfs(depth+1);
            top--;
            status[i] = 0;
        }
    }

	
}



