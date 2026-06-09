#include<stdio.h>
	int m;
	int k[10],l[10];
	void dfs(int step) {
    int i;
    if(step==m){
        for(i=0;i<m;i++){
            printf("%d ",k[i]);
        }
        printf("\n");
        return;
    }
    for(i=0;i<m;i++){
        if(l[i]==0){           
            k[step]=i+1;
            l[i]=1;             
            dfs(step+1);
            l[i]=0;              
        }
    }
}

int main(){
	scanf("%d",&m);
	dfs(0);
	return 0;
}

