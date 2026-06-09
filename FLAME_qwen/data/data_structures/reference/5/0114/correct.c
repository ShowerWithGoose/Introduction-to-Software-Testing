#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct po{
    int xi;
    int zhi;
};

int check(struct po a[],int n,int zhi,int xi){
    int i;
    for(i=0;i<n;i++){
        if(zhi==a[i].zhi){
            a[i].xi+=xi;
            return 1;
        }
    }
    if(i==n)  return 0;
}

void pai(struct po c[],int n){
    int i,j;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			struct po tmp;
			if(c[i].zhi<c[j].zhi){
				tmp=c[i];
				c[i]=c[j];
				c[j]=tmp;
			}
		}
	}
}

int main(){
    struct po a[10000],b[10000],c[10000];
    int i=0,j=0,m,n,k=0;
    char ch;
    for(m=0;m<10000;m++){c[m].zhi=0;}
    do{
        scanf("%d %d",&a[i].xi,&a[i].zhi);
        i++;
    }
    while((ch=getchar())!='\n');
    m=i;
    do{
        scanf("%d %d",&b[j].xi,&b[j].zhi);
        j++;
    }
    while((ch=getchar())!='\n');
    n=j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(check(c,k,a[i].zhi+b[j].zhi,a[i].xi*b[j].xi)==1){;}
            else if(check(c,k,a[i].zhi+b[j].zhi,a[i].xi*b[j].xi)==0){
                c[k].xi=a[i].xi*b[j].xi;
                c[k].zhi=a[i].zhi+b[j].zhi;
                k++;
            }
        }
    }
    pai(c,k);
    for(i=0;i<k;i++){
        printf("%d %d ",c[i].xi,c[i].zhi);
    }
    return 0;
}
