#include<stdio.h>
#include<string.h>

struct l{
    int x1;
    int y1;
    int x2;
    int y2;
    int num;
};

void pai_1(struct l a[],int n){
    int i,j;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			struct l tmp;
			if(a[i].x1>a[j].x1){
				tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
		}
	}
}

void pai_2(struct l a[],int n){
    int i,j;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			struct l tmp;
			if(a[i].num<a[j].num){
				tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
		}
	}
}

int main(){
    int n,i,j;
    scanf("%d",&n);
    struct l a[1000];
    for(i=0;i<n;i++)  {a[i].num=1;}
    for(i=0;i<n;i++){
        scanf("%d %d %d %d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
    }
    pai_1(a,n);
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(a[i].x2==a[j].x1&&a[i].y2==a[j].y1){
                a[i].x2=a[j].x2;
                a[i].y2=a[j].y2;
                a[i].num++;
            }
        }
    }
    pai_2(a,n);
    printf("%d %d %d",a[0].num,a[0].x1,a[0].y1);
    return 0;
}
