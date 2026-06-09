#include<stdio.h>
int N;
int i,j,k;
int a[15];
int output[10];
void min(int b[15]){
	int k,p=b[i+1];
	for(k=i+1;k<N;k++){
		if(b[k+1]<p)
		p=b[k+1];
	}
	
}
int jiecheng(int n){
    if(n==1)
    return 1;
    else {
    	return n*jiecheng(n-1);
	}
}
void print(){
    int i=0;
    for(i=0;i<N-1;i++)
        printf("%d ",output[i]);
    printf("%d\n",output[i]);
}
void pai(){
    for(i=N-2;i>=0;i--){
        if(output[i]<output[i+1])
            break;
    }
    int head=i;
    int flag=i+1;
    for(i=head+1;i<N;i++){
        if(output[i]>output[head]&&output[i]<output[flag])
            flag=i;
    }
    int huan;
    huan=output[flag];
    output[flag]=output[head];
    output[head]=huan;
    for(j=head+1,i=N-1;i>j;i--,j++){
        huan=output[j];
        output[j]=output[i];
        output[i]=huan;
    }
}
// 1 2 4 3
int main(){
    scanf("%d",&N);
    int i;
    for(i=0;i<N;i++){
        output[i]=i+1;
    }
    print();
    k=2;
    while(k<=jiecheng(N)){
        pai();
        print();
        k++;
    }
}



