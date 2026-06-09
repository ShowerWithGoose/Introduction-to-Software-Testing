#include<stdio.h>
int a[10], ball[10], n;
void qpl(int step);
int main(){
scanf("%d",&n);
qpl(1);
return 0;
return 0;
} 
void qpl(int step){
	int i;
	if(step == n+1){
		for(i=1;i<=n;i++){
			printf("%d ",a[i]);
		}
		printf("\n");
		return;
	}
	for(i=1;i<=n;i++){
		if(ball[i]==0){
			a[step] = i;
			ball[i] = 1;
			qpl(step+1);
			ball[i] = 0;
		}
	}
	return;
}

