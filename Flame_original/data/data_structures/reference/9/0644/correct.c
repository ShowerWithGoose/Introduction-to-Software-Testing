#include <stdio.h>
typedef struct{
	int x1,y1,x2,y2;
}line;
line a[100];
int jud[100];
void givmax(int item[]);
int main(){
	int n,i=0,j=0,key=1;
	for(j=0;j<100;j++){
		jud[j]=1;
	}
	line temp;
	scanf("%d",&n);
	while(i<n){
		scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
		i++;
	}
	
	for(j=0;j<n;j++){
		for(i=0;i<n;i++){
			if(a[j].x2==a[i].x1&&a[j].y2==a[i].y1){
				//jud[i]++;
				jud[j]+=jud[i];
				a[j].x2=a[i].x2;
				a[j].y2=a[i].y2;
				
			}
			
		}
	}
	for(j=0;j<n;j++){
		for(i=0;i<n;i++){
			if(a[j].x2==a[i].x1&&a[j].y2==a[i].y1){
				//jud[i]++;
				jud[j]+=jud[i];
				a[j].x2=a[i].x2;
				a[j].y2=a[i].y2;
				
			}
			
		}
	}
	/*for(j=0;j<n;j++){
		printf("%d\n",jud[j]);
	}*/
	givmax(jud);
	return 0;
}
void givmax(int item[]){
	int k=0,max=0,maxn=0;
	for(k=0;k<100;k++){
		if(item[k]>max){
			max=item[k];
		maxn=k;
		}
		
	}
	printf("%d %d %d",max,a[maxn].x1,a[maxn].y1);
}

