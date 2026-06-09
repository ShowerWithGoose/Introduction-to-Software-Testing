#include<stdio.h>
struct line
	{
		int s1;
		int e1;
		int s2;
		int e2;
		int num;
	};
struct line a[132],tmp;
int main(){
	int n;
	struct line ; 
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d%d%d\n",&a[i].s1,&a[i].e1,&a[i].s2,&a[i].e2);
		a[i].num=1;
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i].s1<a[j].s1){
				tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;			
			}
		}
	}
	for(int i=0;i<n-1;i++){
		for(int j=i;j<n-1;j++){
			if((a[i].s1==a[j+1].s2)&&(a[i].e1==a[j+1].e2)){
				a[j+1].num+=a[i].num;
			}
		}
	}
	int max=-1;
	int flag=0;
	for(int i=0;i<n;i++){
		if(a[i].num>max){
			max=a[i].num;
			flag=i;
		}
	}
	printf("%d %d %d",max,a[flag].s1,a[flag].e1);
	return 0;
	
}

