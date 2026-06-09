#include<stdio.h>
#include<string.h>
int main(){
	int N,i=0,j=0,m=0,n=0,x=0,y=0;
	int a[11],b[11];
	scanf("%d",&N);
	b[0]=1;
	for(i=1;i<10;i++){
    b[i]=i*b[i-1];
    }
	for(i=0;i<N;i++){
	a[i]=i+1;}
	a[i]='\0';
	printf("%d",a[0]);
	for(i=1;i<N;i++){
	printf(" %d",a[i]);}
	printf("\n");
	for(j=1;j<b[N];j++){
        for(i=N-2;i>=0;i--){
        if(a[i]<a[i+1]){
        m=i;
        n=i+1;
        break;}
    }
    for(i=m+1;i<N;i++){
        if(a[i]>a[m]&&a[i]<a[n])
            n=i;
    }
    x=a[m];
    a[m]=a[n];
    a[n]=x;
    for(y=m+1,i=N-1;i>y;i--,y++){
        x=a[i];
        a[i]=a[y];
        a[y]=x;
    }
    printf("%d",a[0]);
	for(i=1;i<N;i++){
	printf(" %d",a[i]);}
	printf("\n");
    }
	return 0;
}

