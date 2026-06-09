#include<stdio.h>
int x;
int i,j,m;
int a[15];
int p[10];
void min(int b[15]){
	int m,p=b[i+1];
	for(m=i+1;m<x;m++){
		if(b[m+1]<p)
		p=b[m+1];
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
    for(i=0;i<x-1;i++)
        printf("%d ",p[i]);
    printf("%d\n",p[i]);
}
void pai(){
    for(i=x-2;i>=0;i--){
        if(p[i]<p[i+1])
            break;
    }
    int a=i;
    int b=i+1;
    for(i=a+1;i<x;i++){
        if(p[i]>p[a]&&p[i]<p[b])
            b=i;
    }
    int huan;
    huan=p[b];
    p[b]=p[a];
    p[a]=huan;
    for(j=a+1,i=x-1;i>j;i--,j++){
        huan=p[j];
        p[j]=p[i];
        p[i]=huan;
    }
}
// 1 2 4 3
int main(){
    scanf("%d",&x);
    int i;
    for(i=0;i<x;i++){
        p[i]=i+1;
    }
    print();
    m=2;
    while(m<=jiecheng(x)){
        pai();
        print();
        m++;
    }
}



