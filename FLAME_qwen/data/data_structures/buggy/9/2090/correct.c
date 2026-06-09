#include<stdio.h>
#include<string.h>
typedef struct {
		int x1;
		int y1;
		int x2;
		int y2;
	}line;
int calculate(line l[],int n,int i){
	int j,flag=0;
		for(j=i+1;j<n;j++){
			if(l[i].x2==l[j].x1&&l[i].y2==l[j].y1){
				flag=1;
				break;
			}
		}
		if(flag==1) return calculate(l,n,j)+1;
		else return 1;
}
int main(){
	line l[100],a;
	int i,j,n,max,flag;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",&l[i].x1,&l[i].y1,&l[i].x2,&l[i].y2);
	}
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(l[j].x1>l[j+1].x1){
				a=l[j];
				l[j]=l[j+1];
				l[j+1]=a;
			}
			else if(l[j].x1==l[j+1].x2&&l[j].x2>l[j+1].x2){
				a=l[j];
				l[j]=l[j+1];
				l[j+1]=a;
			}
		}
	}
	max=calculate(l,n,0),flag=0;
	for(i=0;i<n;i++){
		if(max<calculate(l,n,i)){
			max=calculate(l,n,i);
			flag=i;
		}
	}
	printf("%d %d %d",max,l[flag].x1,l[flag].y1);
	return 0;
}

