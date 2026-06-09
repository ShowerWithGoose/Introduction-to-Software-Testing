#include <stdio.h>
void paixu(int a[],int b[],int c[],int d[],int number){
		int i=0;
		int j=0;
		int temp=0;

		for(i=0;i<number;i++){
			for(j=i+1;j<number;j++){
				if(a[i]>a[j]){
					temp=a[i];
					a[i]=a[j];
					a[j]=temp;
					temp=b[i];
					b[i]=b[j];
					b[j]=temp;
					temp=c[i];
					c[i]=c[j];
					c[j]=temp;
					temp=d[i];
					d[i]=d[j];
					d[j]=temp;
				}
			}
		}
	}
int main(){
	int firsta=0;
	int firstb=0;
	int number=0;
	scanf("%d",&number);
	int x1[101]={0},x2[101]={0},y1[101]={0},y2[101]={0};
	int i;
	for(i=0;i<number;i++){
		scanf("%d%d",&x1[i],&y1[i]);
		scanf("%d%d",&x2[i],&y2[i]);
	}
	paixu(x1,x2,y1,y2,number);

	int max=1;
	for(i=0;i<number;i++){
		int k=i;
		int max1=1;
		int j=1;
		for(j=i+1;j<=number;j++){
				if(x2[k]==x1[j]&&y2[k]==y1[j]){
					max1=max1+1;
					k=j;
				}
		}
		if(max1>max){
			max=max1;
			firsta=x1[i];
			firstb=y1[i];
		}
	}
	printf("%d %d %d\n",max,firsta,firstb);
	return 0;
}

