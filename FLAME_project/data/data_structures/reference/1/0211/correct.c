#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define uint unsigned int
#define uchar unsigned char

int N;
int key[11];
int ans[10];

void init(){
	int i;
    key[0]=1;
    for(i=1;i<10;i++){
        key[i]=i*key[i-1];
    }
    return ;
}

void putans(){
    int i=0;
    for(i=0;i<N-1;i++)
        printf("%d ",ans[i]);
    printf("%d\n",ans[i]);
}

int main(){
	int i,j,k;
	int k1,temp,temp_low;
    init();
    scanf("%d",&N);
    
    for(k=0;k<N;k++){
        ans[k]=k+1;
    }
    putans();
    
    for(k=1;k<key[N];k++){
	    for(i=N-2;i>=0;i--){
	        if(ans[i]<ans[i+1])
	            break;
	    }
	    i++;
	    k1=i-1;
	    temp_low=i;
	    for(i=k1+1;i<N;i++){
	        if(ans[i]>ans[k1]&&ans[i]<ans[temp_low])
	            temp_low=i;
	    }
	    
	    temp=ans[k1];
	    ans[k1]=ans[temp_low];
	    ans[temp_low]=temp;
	    
	    for(j=k1+1,i=N-1;i>j;i--,j++){
	        temp=ans[i];
	        ans[i]=ans[j];
	        ans[j]=temp;
	    }
        putans();
    }
    return 0;
}


